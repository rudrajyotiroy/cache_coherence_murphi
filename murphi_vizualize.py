import re
from tabulate import tabulate
from collections import deque
from rich.console import Console
from rich.table import Table
from io import StringIO
import copy

class CacheCoherenceVisualizer:
    def __init__(self):
        self.nodes = {
            1: {"state": "Proc_I", "request": {"incoming": [], "outgoing": []}, 
                "response": {"incoming": [], "outgoing": []}, 
                "forward": {"incoming": [], "outgoing": []}},
            2: {"state": "Proc_I", "request": {"incoming": [], "outgoing": []}, 
                "response": {"incoming": [], "outgoing": []}, 
                "forward": {"incoming": [], "outgoing": []}},
            3: {"state": "Proc_I", "request": {"incoming": [], "outgoing": []}, 
                "response": {"incoming": [], "outgoing": []}, 
                "forward": {"incoming": [], "outgoing": []}},
            7: {"state": "Dir_I", "request": {"incoming": [], "outgoing": []}, 
                "response": {"incoming": [], "outgoing": []}, 
                "forward": {"incoming": [], "outgoing": []}},
        }
        self.snapshots = deque()  # Store snapshots for navigation
        self.current_index = -1  # Track current snapshot

    def parse_log_file(self, file_path):
        """Read and parse the log from a file."""
        try:
            with open(file_path, "r") as file:
                log = file.read()
            self.parse_log(log)
        except FileNotFoundError:
            print(f"Error: File '{file_path}' not found.")
        except Exception as e:
            print(f"Error: {e}")

    def parse_log(self, log):
        pattern = r"(Create|Receive|Clear) Msg (\d+):: type: (\w+), src: (\d+), dst: (\d+), .*?src_state: (\w+), dst_state: (\w+)"
        matches = re.finditer(pattern, log)

        for match in matches:
            action, msg_id, msg_type, src, dst, src_state, dst_state = match.groups()
            src, dst = int(src), int(dst)
            msg_id = int(msg_id)

            # Print the log entry
            print(f"Log Entry: {match.group(0)}")

            if action == "Create":
                self.create_message(msg_id, msg_type, src, dst, src_state, dst_state)
            elif action == "Receive":
                self.receive_message(msg_id, msg_type, src, dst, src_state, dst_state)
            elif action == "Clear":
                self.clear_message(msg_id, msg_type, src, dst, src_state, dst_state)
        self.current_index = -1  # Track current snapshot

    def create_message(self, msg_id, msg_type, src, dst, src_state, dst_state):
        channel = self.get_channel(msg_type)
        # Add message to the outgoing list of the source node
        self.nodes[src][channel]["outgoing"].append({"id": msg_id, "type": msg_type, "dst": dst})
        # Update source and destination states
        self.nodes[src]["state"] = src_state
        self.nodes[dst]["state"] = dst_state
        # Take a snapshot
        self.take_snapshot(f"Create Msg {msg_id}: {msg_type} from {src} to {dst}")

    def receive_message(self, msg_id, msg_type, src, dst, src_state, dst_state):
        channel = self.get_channel(msg_type)
        # Remove the corresponding message from the source's outgoing list
        outgoing = self.nodes[src][channel]["outgoing"]
        message = next((m for m in outgoing if m["id"] == msg_id), None)
        if message:
            outgoing.remove(message)
        # Add message to the destination's incoming list
        self.nodes[dst][channel]["incoming"] = [{"id": msg_id, "type": msg_type, "src": src}]
        # Update source and destination states
        self.nodes[src]["state"] = src_state
        self.nodes[dst]["state"] = dst_state
        # Take a snapshot
        self.take_snapshot(f"Receive Msg {msg_id}: {msg_type} from {src} to {dst}")

    def clear_message(self, msg_id, msg_type, src, dst, src_state, dst_state):
        channel = self.get_channel(msg_type)
        # Remove the corresponding message from the destination's incoming list
        outgoing = self.nodes[dst][channel]["incoming"]
        message = next((m for m in outgoing if m["id"] == msg_id), None)
        if message:
            outgoing.remove(message)
        # Update source and destination states
        self.nodes[src]["state"] = src_state
        self.nodes[dst]["state"] = dst_state
        # Take a snapshot
        self.take_snapshot(f"Clear Msg {msg_id}: {msg_type} from {src} to {dst}")

    def get_channel(self, msg_type):
        if msg_type in {"GetS", "GetM", "PutS", "PutM"}:
            return "request"
        elif msg_type in {"Data", "NACK", "PutAck", "InvAck", "FwdAck"}:
            return "response"
        elif msg_type in {"Inv", "FwdGetS", "FwdGetM"}:
            return "forward"
        else:
            raise ValueError("Invalid message type")

    def take_snapshot(self, header):
        snapshot = {
            "header": header,
            "nodes": {k: v.copy() for k, v in self.nodes.items()},
        }
        self.snapshots.append(copy.deepcopy(snapshot))
        self.current_index = len(self.snapshots) - 1

    def previous(self):
        if self.current_index > 0:
            self.current_index -= 1
            # self.display_snapshot()
            self.display_snapshot_rich()
            return 0
        else:
            return -1

    def next(self):
        if self.current_index < len(self.snapshots) - 1:
            self.current_index += 1
            # self.display_snapshot()
            self.display_snapshot_rich()
            return 0
        else:
            return -1

    def display_snapshot(self):
        snapshot = self.snapshots[self.current_index]
        print(f"\n=== {snapshot['header']} ===\n")

        # Node titles for side-by-side display
        node_titles = ["Proc_1", "Proc_2", "Proc_3", "Dir"]
        node_ids = [1, 2, 3, 7]

        # Print the titles for nodes
        print("   ".join(f"{title:<30}" for title in node_titles))
        print("=" * 115)

        # Loop through channels (request, response, forward)
        for channel_name in ["request", "response", "forward"]:
            print(f"{channel_name.capitalize()}" + " Outgoing")

            # Prepare outgoing rows for each node
            outgoing_rows = [
                tabulate(
                    snapshot["nodes"][node_id][channel_name]["outgoing"],
                    headers="keys",
                    tablefmt="plain",
                    showindex=False
                ) or "[Empty]"
                for node_id in node_ids
            ]

            # Print outgoing lists side-by-side
            self.print_side_by_side(outgoing_rows)

            # Prepare incoming rows for each node
            print(f"{channel_name.capitalize()}" + " Incoming")
            incoming_rows = [
                tabulate(
                    snapshot["nodes"][node_id][channel_name]["incoming"],
                    headers="keys",
                    tablefmt="plain",
                    showindex=False
                ) or "[Empty]"
                for node_id in node_ids
            ]

            # Print incoming lists side-by-side
            self.print_side_by_side(incoming_rows)
            print("-" * 115)

    def print_side_by_side(self, tables):
        """Helper function to print multiple tables side by side."""
        table_lines = [table.splitlines() for table in tables]
        max_lines = max(len(lines) for lines in table_lines)
        padded_tables = [
            lines + [""] * (max_lines - len(lines)) for lines in table_lines
        ]
        for row in zip(*padded_tables):
            print("   ".join(f"{col:<30}" for col in row))


    def format_list(self, lst):
        """Format the list to make it compact and readable."""
        if not lst:
            return "[]"
        return "\n".join(f"{item['id']}:{item['type']}" for item in lst)

    def display_snapshot_rich(self):
        snapshot = self.snapshots[self.current_index]
        console = Console(height=1)
        console.print(str(self.current_index) + " : " + f"[bold yellow]=== {snapshot['header']} ===[/bold yellow]\n")

        # Node titles for side-by-side display
        node_titles = ["Proc_1", "Proc_2", "Proc_3", "Dir"]
        node_ids = [1, 2, 3, 7]
        node_headers = [node_titles[i] + " (" + snapshot["nodes"][node_ids[i]]["state"] + ")" for i in range(4)]

        # Print the titles for nodes
        header_row = "   ".join(f"[bold orange]{title:<30}[/bold orange]" for title in node_headers)
        console.print(header_row)
        console.print("[bold red]=" * 115)

        # Loop through channels (request, response, forward)
        for channel_name in ["request", "response", "forward"]:
            console.print(f"[bold green]{channel_name.upper()+" OUTGOING"}[/bold green]")

            # Prepare outgoing rows for each node
            outgoing_rows = [
                self.format_table_with_rich(
                    snapshot["nodes"][node_id][channel_name]["outgoing"], False
                )
                for node_id in node_ids
            ]

            # Print outgoing lists side-by-side
            self.print_side_by_side_with_rich(console, outgoing_rows)

            # Prepare incoming rows for each node
            console.print(f"[bold green]{channel_name.upper()+" INCOMING"}[/bold green]")
            incoming_rows = [
                self.format_table_with_rich(
                    snapshot["nodes"][node_id][channel_name]["incoming"], True
                )
                for node_id in node_ids
            ]

            # Print incoming lists side-by-side
            self.print_side_by_side_with_rich(console, incoming_rows)
            console.print("[bold red]-[/bold red]" * 115)

    def format_table_with_rich(self, data, incoming):
        """Format a list as a rich table."""
        if not data:
            return "[dim]"+f"{"Empty":<30}"+"[/dim]"
        table = Table(box=None, show_header=True, header_style="bold blue")
        table.add_column("ID", justify="center")
        table.add_column("Type", justify="center")
        if incoming:
            table.add_column("Src", justify="center")
        else:
            table.add_column("Des", justify="center")
        for item in data:
            if incoming:
                table.add_row(str(item["id"]), item["type"], str(item["src"]))
            else:
                table.add_row(str(item["id"]), item["type"], str(item["dst"]))
        return table

    def print_side_by_side_with_rich(self, console, tables):
        # def print_side_by_side_with_rich(self, console, tables):
        """Helper function to print multiple rich tables side by side."""
        # Render each table to a string buffer and split lines
        table_lines = []
        for table in tables:
            if isinstance(table, Table):
                buffer = StringIO()
                temp_console = Console(file=buffer, width=30)
                temp_console.print(table)
                table_lines.append(buffer.getvalue().splitlines())
            else:
                table_lines.append(table.splitlines())

        # Determine the maximum number of lines for alignment
        max_lines = max(len(lines) for lines in table_lines)
        padded_tables = [
            lines + [""] * (max_lines - len(lines)) for lines in table_lines
        ]

        # Print lines side by side
        for row in zip(*padded_tables):
            console.print("   ".join(f"{col:<30}" for col in row))

visualizer = CacheCoherenceVisualizer()
visualizer.parse_log_file('msi_opt_sim_cache.log')
# visualizer.previous()  # Navigate to previous snapshot
# visualizer.next()      # Navigate to next snapshot
while(visualizer.next()==0):
    pass