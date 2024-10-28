/******************************
  Program "mosi.m" compiled by "Murphi Release 3.1"

  Murphi Last Modefied Date: "Jan 29 1999"
  Murphi Last Compiled date: "Oct 24 2024"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Murphi Release 3.1"
#define MURPHI_DATE "Jan 29 1999"
#define PROTOCOL_NAME "mosi"
#define BITS_IN_WORLD 8560
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_node_n: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_node_n& val) { return mu__byte::operator=((int) val); };
  mu_1_node_n (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_node_n (void): mu__byte(0, 3, 3) {};
  mu_1_node_n (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_node_n mu_1_node_n_undefined_var;

class mu_1_value_t: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_value_t& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_value_t& val)
    {
      if (val.defined())
        return ( s << mu_1_value_t::values[ int(val) - 1 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_value_t (char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu_1_value_t (void): mu__byte(1, 2, 2) {};
  mu_1_value_t (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_value_t& a, mu_1_value_t& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_value_t::values[] =
  { "value_t_1","value_t_2",NULL };

/*** end scalarset declaration ***/
mu_1_value_t mu_1_value_t_undefined_var;

class mu_1_channel_t: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_channel_t& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_channel_t& val)
  {
    if (val.defined())
      return ( s << mu_1_channel_t::values[ int(val) - 3] );
    else return ( s << "Undefined" );
  };

  mu_1_channel_t (char *name, int os): mu__byte(3, 5, 2, name, os) {};
  mu_1_channel_t (void): mu__byte(3, 5, 2) {};
  mu_1_channel_t (int val): mu__byte(3, 5, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -3]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -3] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_channel_t::values[] = {"req","resp","fwd",NULL };

/*** end of enum declaration ***/
mu_1_channel_t mu_1_channel_t_undefined_var;

class mu_1_mtype_req_t: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_mtype_req_t& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_mtype_req_t& val)
  {
    if (val.defined())
      return ( s << mu_1_mtype_req_t::values[ int(val) - 6] );
    else return ( s << "Undefined" );
  };

  mu_1_mtype_req_t (char *name, int os): mu__byte(6, 10, 3, name, os) {};
  mu_1_mtype_req_t (void): mu__byte(6, 10, 3) {};
  mu_1_mtype_req_t (int val): mu__byte(6, 10, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -6]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -6] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_mtype_req_t::values[] = {"GetS","GetM","PutS","PutM","PutO",NULL };

/*** end of enum declaration ***/
mu_1_mtype_req_t mu_1_mtype_req_t_undefined_var;

class mu_1_mtype_resp_t: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_mtype_resp_t& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_mtype_resp_t& val)
  {
    if (val.defined())
      return ( s << mu_1_mtype_resp_t::values[ int(val) - 11] );
    else return ( s << "Undefined" );
  };

  mu_1_mtype_resp_t (char *name, int os): mu__byte(11, 14, 3, name, os) {};
  mu_1_mtype_resp_t (void): mu__byte(11, 14, 3) {};
  mu_1_mtype_resp_t (int val): mu__byte(11, 14, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -11]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -11] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_mtype_resp_t::values[] = {"DataAck","InvAck","PutAck","FwdAck",NULL };

/*** end of enum declaration ***/
mu_1_mtype_resp_t mu_1_mtype_resp_t_undefined_var;

class mu_1_mtype_fwd_t: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_mtype_fwd_t& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_mtype_fwd_t& val)
  {
    if (val.defined())
      return ( s << mu_1_mtype_fwd_t::values[ int(val) - 15] );
    else return ( s << "Undefined" );
  };

  mu_1_mtype_fwd_t (char *name, int os): mu__byte(15, 17, 2, name, os) {};
  mu_1_mtype_fwd_t (void): mu__byte(15, 17, 2) {};
  mu_1_mtype_fwd_t (int val): mu__byte(15, 17, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -15]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -15] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_mtype_fwd_t::values[] = {"Inv","FwdGetS","FwdGetM",NULL };

/*** end of enum declaration ***/
mu_1_mtype_fwd_t mu_1_mtype_fwd_t_undefined_var;

class mu_1_mtype_t: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_mtype_t& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_mtype_t& val)
    {
      if (val.defined())
        return ( s << mu_1_mtype_t::values[ val.indexvalue() ] );
      else
        return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_mtype_t (char *name, int os): mu__byte(0, 11, 4, name, os) {};
  mu_1_mtype_t (void): mu__byte(0, 11, 4) {};
  mu_1_mtype_t (int val): mu__byte(0, 11, 4, "Parameter or function result.", 0)
    { operator=(val); };
  int indexvalue()
  {
    if ((value() >= 6) && (value() <= 10)) return (value() - 6);
    if ((value() >= 11) && (value() <= 14)) return (value() - 6);
    if ((value() >= 15) && (value() <= 17)) return (value() - 6);
  };
  inline int unionassign(int val)
  {
    if (val >= 0 && val <= 4) return value(val+6);
    if (val >= 5 && val <= 8) return value(val+6);
    if (val >= 9 && val <= 11) return value(val+6);
  };
  char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_mtype_t& a, mu_1_mtype_t& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
char *mu_1_mtype_t::values[] = {"GetS","GetM","PutS","PutM","PutO","DataAck","InvAck","PutAck","FwdAck","Inv","FwdGetS","FwdGetM",NULL };

/*** end union declaration ***/
mu_1_mtype_t mu_1_mtype_t_undefined_var;

class mu_1_proc_state_t: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_proc_state_t& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_proc_state_t& val)
  {
    if (val.defined())
      return ( s << mu_1_proc_state_t::values[ int(val) - 18] );
    else return ( s << "Undefined" );
  };

  mu_1_proc_state_t (char *name, int os): mu__byte(18, 32, 4, name, os) {};
  mu_1_proc_state_t (void): mu__byte(18, 32, 4) {};
  mu_1_proc_state_t (int val): mu__byte(18, 32, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -18]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -18] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_proc_state_t::values[] = {"Proc_M","Proc_O","Proc_S","Proc_I","Proc_IS_D","Proc_IM_A","Proc_IM_AD","Proc_II_A","Proc_SM_A","Proc_SM_AD","Proc_SI_A","Proc_MI_A","Proc_OM_AC","Proc_OM_A","Proc_OI_A",NULL };

/*** end of enum declaration ***/
mu_1_proc_state_t mu_1_proc_state_t_undefined_var;

class mu_1_dir_state_t: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_dir_state_t& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_dir_state_t& val)
  {
    if (val.defined())
      return ( s << mu_1_dir_state_t::values[ int(val) - 33] );
    else return ( s << "Undefined" );
  };

  mu_1_dir_state_t (char *name, int os): mu__byte(33, 36, 3, name, os) {};
  mu_1_dir_state_t (void): mu__byte(33, 36, 3) {};
  mu_1_dir_state_t (int val): mu__byte(33, 36, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -33]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -33] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_dir_state_t::values[] = {"Dir_M","Dir_O","Dir_S","Dir_I",NULL };

/*** end of enum declaration ***/
mu_1_dir_state_t mu_1_dir_state_t_undefined_var;

class mu_1_message_t
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_mtype_t mu_mtype;
  mu_1_value_t mu_value;
  mu_1_node_n mu_src;
  mu_1_node_n mu_dest;
  mu_1_node_n mu_fwdTo;
  mu_1_node_n mu_numAck;
  mu_1_message_t ( char *n, int os ) { set_self(n,os); };
  mu_1_message_t ( void ) {};

  virtual ~mu_1_message_t(); 
friend int CompareWeight(mu_1_message_t& a, mu_1_message_t& b)
  {
    int w;
    w = CompareWeight(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = CompareWeight(a.mu_dest, b.mu_dest);
    if (w!=0) return w;
    w = CompareWeight(a.mu_fwdTo, b.mu_fwdTo);
    if (w!=0) return w;
    w = CompareWeight(a.mu_numAck, b.mu_numAck);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_message_t& a, mu_1_message_t& b)
  {
    int w;
    w = Compare(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = Compare(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = Compare(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = Compare(a.mu_dest, b.mu_dest);
    if (w!=0) return w;
    w = Compare(a.mu_fwdTo, b.mu_fwdTo);
    if (w!=0) return w;
    w = Compare(a.mu_numAck, b.mu_numAck);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_mtype.MultisetSort();
    mu_value.MultisetSort();
    mu_src.MultisetSort();
    mu_dest.MultisetSort();
    mu_fwdTo.MultisetSort();
    mu_numAck.MultisetSort();
  }
  void print_statistic()
  {
    mu_mtype.print_statistic();
    mu_value.print_statistic();
    mu_src.print_statistic();
    mu_dest.print_statistic();
    mu_fwdTo.print_statistic();
    mu_numAck.print_statistic();
  }
  void clear() {
    mu_mtype.clear();
    mu_value.clear();
    mu_src.clear();
    mu_dest.clear();
    mu_fwdTo.clear();
    mu_numAck.clear();
 };
  void undefine() {
    mu_mtype.undefine();
    mu_value.undefine();
    mu_src.undefine();
    mu_dest.undefine();
    mu_fwdTo.undefine();
    mu_numAck.undefine();
 };
  void reset() {
    mu_mtype.reset();
    mu_value.reset();
    mu_src.reset();
    mu_dest.reset();
    mu_fwdTo.reset();
    mu_numAck.reset();
 };
  void print() {
    mu_mtype.print();
    mu_value.print();
    mu_src.print();
    mu_dest.print();
    mu_fwdTo.print();
    mu_numAck.print();
  };
  void print_diff(state *prevstate) {
    mu_mtype.print_diff(prevstate);
    mu_value.print_diff(prevstate);
    mu_src.print_diff(prevstate);
    mu_dest.print_diff(prevstate);
    mu_fwdTo.print_diff(prevstate);
    mu_numAck.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_mtype.to_state(thestate);
    mu_value.to_state(thestate);
    mu_src.to_state(thestate);
    mu_dest.to_state(thestate);
    mu_fwdTo.to_state(thestate);
    mu_numAck.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_message_t& operator= (const mu_1_message_t& from) {
    mu_mtype.value(from.mu_mtype.value());
    mu_value.value(from.mu_value.value());
    mu_src.value(from.mu_src.value());
    mu_dest.value(from.mu_dest.value());
    mu_fwdTo.value(from.mu_fwdTo.value());
    mu_numAck.value(from.mu_numAck.value());
    return *this;
  };
};

  void mu_1_message_t::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_message_t::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_message_t::set_self(char *n, int os)
{
  name = n;
  mu_mtype.set_self_2(name, ".mtype", os + 0 );
  mu_value.set_self_2(name, ".value", os + 8 );
  mu_src.set_self_2(name, ".src", os + 16 );
  mu_dest.set_self_2(name, ".dest", os + 24 );
  mu_fwdTo.set_self_2(name, ".fwdTo", os + 32 );
  mu_numAck.set_self_2(name, ".numAck", os + 40 );
}

mu_1_message_t::~mu_1_message_t()
{
}

/*** end record declaration ***/
mu_1_message_t mu_1_message_t_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_0_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_0_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_0_id () : mu__byte(0,9,0) {};
  mu_1__type_0_id (int val) : mu__byte(0,9,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_0
{
 public:
  mu_1_message_t array[ 10 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 10 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_0 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_0 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_0 ();
  mu_1_message_t& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 9) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 10; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<10; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 10; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_0_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 10; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 10; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_message_t &element)
  {
    update_size();
    if (current_size >= 10) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 10; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_0_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_message_t temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 10; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 10; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 10; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_0::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_0::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_0::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 10; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 48 + os);
  k = os + i * 48;
  for(i = 0; i < 10; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_0::~mu_1__type_0()
{
}
/*** end multiset declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_1_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_1_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_1_id () : mu__byte(0,9,0) {};
  mu_1__type_1_id (int val) : mu__byte(0,9,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_1
{
 public:
  mu_1_message_t array[ 10 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 10 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_1 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_1 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_1 ();
  mu_1_message_t& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 9) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 10; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<10; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 10; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_1_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 10; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 10; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_message_t &element)
  {
    update_size();
    if (current_size >= 10) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 10; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_1_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_message_t temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 10; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 10; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 10; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_1::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_1::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_1::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 10; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 48 + os);
  k = os + i * 48;
  for(i = 0; i < 10; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_1::~mu_1__type_1()
{
}
/*** end multiset declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_2_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_2_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_2_id () : mu__byte(0,9,0) {};
  mu_1__type_2_id (int val) : mu__byte(0,9,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_2
{
 public:
  mu_1_message_t array[ 10 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 10 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_2 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_2 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_2 ();
  mu_1_message_t& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 9) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
    for (int i = 0; i < 10; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<10; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 10; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_2_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 10; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 10; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_message_t &element)
  {
    update_size();
    if (current_size >= 10) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 10; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_2_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_message_t temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 10; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 10; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 10; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_2::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_2::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_2::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 10; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 48 + os);
  k = os + i * 48;
  for(i = 0; i < 10; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_2::~mu_1__type_2()
{
}
/*** end multiset declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1_proc_t
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_proc_state_t mu_state;
  mu_1_value_t mu_value;
  mu_0_boolean mu_isStalled;
  mu_1__type_0 mu_req_queue;
  mu_1__type_1 mu_resp_queue;
  mu_1__type_2 mu_fwd_queue;
  mu_1_proc_t ( char *n, int os ) { set_self(n,os); };
  mu_1_proc_t ( void ) {};

  virtual ~mu_1_proc_t(); 
friend int CompareWeight(mu_1_proc_t& a, mu_1_proc_t& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = CompareWeight(a.mu_isStalled, b.mu_isStalled);
    if (w!=0) return w;
    w = CompareWeight(a.mu_req_queue, b.mu_req_queue);
    if (w!=0) return w;
    w = CompareWeight(a.mu_resp_queue, b.mu_resp_queue);
    if (w!=0) return w;
    w = CompareWeight(a.mu_fwd_queue, b.mu_fwd_queue);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_proc_t& a, mu_1_proc_t& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = Compare(a.mu_isStalled, b.mu_isStalled);
    if (w!=0) return w;
    w = Compare(a.mu_req_queue, b.mu_req_queue);
    if (w!=0) return w;
    w = Compare(a.mu_resp_queue, b.mu_resp_queue);
    if (w!=0) return w;
    w = Compare(a.mu_fwd_queue, b.mu_fwd_queue);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_value.MultisetSort();
    mu_isStalled.MultisetSort();
    mu_req_queue.MultisetSort();
    mu_resp_queue.MultisetSort();
    mu_fwd_queue.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_value.print_statistic();
    mu_isStalled.print_statistic();
    mu_req_queue.print_statistic();
    mu_resp_queue.print_statistic();
    mu_fwd_queue.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_value.clear();
    mu_isStalled.clear();
    mu_req_queue.clear();
    mu_resp_queue.clear();
    mu_fwd_queue.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_value.undefine();
    mu_isStalled.undefine();
    mu_req_queue.undefine();
    mu_resp_queue.undefine();
    mu_fwd_queue.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_value.reset();
    mu_isStalled.reset();
    mu_req_queue.reset();
    mu_resp_queue.reset();
    mu_fwd_queue.reset();
 };
  void print() {
    mu_state.print();
    mu_value.print();
    mu_isStalled.print();
    mu_req_queue.print();
    mu_resp_queue.print();
    mu_fwd_queue.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_value.print_diff(prevstate);
    mu_isStalled.print_diff(prevstate);
    mu_req_queue.print_diff(prevstate);
    mu_resp_queue.print_diff(prevstate);
    mu_fwd_queue.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_value.to_state(thestate);
    mu_isStalled.to_state(thestate);
    mu_req_queue.to_state(thestate);
    mu_resp_queue.to_state(thestate);
    mu_fwd_queue.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_proc_t& operator= (const mu_1_proc_t& from) {
    mu_state.value(from.mu_state.value());
    mu_value.value(from.mu_value.value());
    mu_isStalled.value(from.mu_isStalled.value());
    mu_req_queue = from.mu_req_queue;
    mu_resp_queue = from.mu_resp_queue;
    mu_fwd_queue = from.mu_fwd_queue;
    return *this;
  };
};

  void mu_1_proc_t::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_proc_t::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_proc_t::set_self(char *n, int os)
{
  name = n;
  mu_state.set_self_2(name, ".state", os + 0 );
  mu_value.set_self_2(name, ".value", os + 8 );
  mu_isStalled.set_self_2(name, ".isStalled", os + 16 );
  mu_req_queue.set_self_2(name, ".req_queue", os + 24 );
  mu_resp_queue.set_self_2(name, ".resp_queue", os + 584 );
  mu_fwd_queue.set_self_2(name, ".fwd_queue", os + 1144 );
}

mu_1_proc_t::~mu_1_proc_t()
{
}

/*** end record declaration ***/
mu_1_proc_t mu_1_proc_t_undefined_var;

class mu__subrange_16: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_16& val) { return mu__byte::operator=((int) val); };
  mu__subrange_16 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_16 (void): mu__byte(0, 3, 3) {};
  mu__subrange_16 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_16 mu__subrange_16_undefined_var;

class mu_1__type_3
{
 public:
  mu_0_boolean array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_3 (char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 3 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
        Error.Error("Indexing to %s using an undefined value.", name);
      else
        Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
    for (int i = 0; i < 4; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_3::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_3::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_3::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 8 + os);
    delete[] s;
  }
};
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_4_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_4_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_4_id () : mu__byte(0,9,0) {};
  mu_1__type_4_id (int val) : mu__byte(0,9,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_4
{
 public:
  mu_1_message_t array[ 10 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 10 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_4 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_4 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_4 ();
  mu_1_message_t& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 9) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_4& operator= (const mu_1__type_4& from)
  {
    for (int i = 0; i < 10; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<10; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 10; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_4_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 10; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 10; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_message_t &element)
  {
    update_size();
    if (current_size >= 10) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 10; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_4_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_message_t temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 10; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 10; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 10; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_4::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_4::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_4::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 10; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 48 + os);
  k = os + i * 48;
  for(i = 0; i < 10; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_4::~mu_1__type_4()
{
}
/*** end multiset declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_5_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_5_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_5_id () : mu__byte(0,9,0) {};
  mu_1__type_5_id (int val) : mu__byte(0,9,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_5
{
 public:
  mu_1_message_t array[ 10 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 10 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_5 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_5 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_5 ();
  mu_1_message_t& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 9) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
    for (int i = 0; i < 10; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<10; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 10; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_5_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 10; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 10; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_message_t &element)
  {
    update_size();
    if (current_size >= 10) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 10; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_5_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_message_t temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 10; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 10; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 10; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_5::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_5::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 10; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 48 + os);
  k = os + i * 48;
  for(i = 0; i < 10; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_5::~mu_1__type_5()
{
}
/*** end multiset declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_6_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_6_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_6_id () : mu__byte(0,9,0) {};
  mu_1__type_6_id (int val) : mu__byte(0,9,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_6
{
 public:
  mu_1_message_t array[ 10 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 10 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_6 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_6 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_6 ();
  mu_1_message_t& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 9) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_6& operator= (const mu_1__type_6& from)
  {
    for (int i = 0; i < 10; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<10; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 10; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_6_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 10; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 10; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_message_t &element)
  {
    update_size();
    if (current_size >= 10) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 10; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_6_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_message_t temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 10; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 10; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 10; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_6::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_6::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_6::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 10; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 48 + os);
  k = os + i * 48;
  for(i = 0; i < 10; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_6::~mu_1__type_6()
{
}
/*** end multiset declaration ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1_dir_t
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_dir_state_t mu_state;
  mu_1_value_t mu_value;
  mu_1_node_n mu_owner;
  mu_1__type_3 mu_sharers;
  mu_1__type_4 mu_req_queue;
  mu_1__type_5 mu_resp_queue;
  mu_1__type_6 mu_fwd_queue;
  mu_1_dir_t ( char *n, int os ) { set_self(n,os); };
  mu_1_dir_t ( void ) {};

  virtual ~mu_1_dir_t(); 
friend int CompareWeight(mu_1_dir_t& a, mu_1_dir_t& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = CompareWeight(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = CompareWeight(a.mu_sharers, b.mu_sharers);
    if (w!=0) return w;
    w = CompareWeight(a.mu_req_queue, b.mu_req_queue);
    if (w!=0) return w;
    w = CompareWeight(a.mu_resp_queue, b.mu_resp_queue);
    if (w!=0) return w;
    w = CompareWeight(a.mu_fwd_queue, b.mu_fwd_queue);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_dir_t& a, mu_1_dir_t& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = Compare(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = Compare(a.mu_sharers, b.mu_sharers);
    if (w!=0) return w;
    w = Compare(a.mu_req_queue, b.mu_req_queue);
    if (w!=0) return w;
    w = Compare(a.mu_resp_queue, b.mu_resp_queue);
    if (w!=0) return w;
    w = Compare(a.mu_fwd_queue, b.mu_fwd_queue);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_value.MultisetSort();
    mu_owner.MultisetSort();
    mu_sharers.MultisetSort();
    mu_req_queue.MultisetSort();
    mu_resp_queue.MultisetSort();
    mu_fwd_queue.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_value.print_statistic();
    mu_owner.print_statistic();
    mu_sharers.print_statistic();
    mu_req_queue.print_statistic();
    mu_resp_queue.print_statistic();
    mu_fwd_queue.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_value.clear();
    mu_owner.clear();
    mu_sharers.clear();
    mu_req_queue.clear();
    mu_resp_queue.clear();
    mu_fwd_queue.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_value.undefine();
    mu_owner.undefine();
    mu_sharers.undefine();
    mu_req_queue.undefine();
    mu_resp_queue.undefine();
    mu_fwd_queue.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_value.reset();
    mu_owner.reset();
    mu_sharers.reset();
    mu_req_queue.reset();
    mu_resp_queue.reset();
    mu_fwd_queue.reset();
 };
  void print() {
    mu_state.print();
    mu_value.print();
    mu_owner.print();
    mu_sharers.print();
    mu_req_queue.print();
    mu_resp_queue.print();
    mu_fwd_queue.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_value.print_diff(prevstate);
    mu_owner.print_diff(prevstate);
    mu_sharers.print_diff(prevstate);
    mu_req_queue.print_diff(prevstate);
    mu_resp_queue.print_diff(prevstate);
    mu_fwd_queue.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_value.to_state(thestate);
    mu_owner.to_state(thestate);
    mu_sharers.to_state(thestate);
    mu_req_queue.to_state(thestate);
    mu_resp_queue.to_state(thestate);
    mu_fwd_queue.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_dir_t& operator= (const mu_1_dir_t& from) {
    mu_state.value(from.mu_state.value());
    mu_value.value(from.mu_value.value());
    mu_owner.value(from.mu_owner.value());
    mu_sharers = from.mu_sharers;
    mu_req_queue = from.mu_req_queue;
    mu_resp_queue = from.mu_resp_queue;
    mu_fwd_queue = from.mu_fwd_queue;
    return *this;
  };
};

  void mu_1_dir_t::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_dir_t::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_dir_t::set_self(char *n, int os)
{
  name = n;
  mu_state.set_self_2(name, ".state", os + 0 );
  mu_value.set_self_2(name, ".value", os + 8 );
  mu_owner.set_self_2(name, ".owner", os + 16 );
  mu_sharers.set_self_2(name, ".sharers", os + 24 );
  mu_req_queue.set_self_2(name, ".req_queue", os + 56 );
  mu_resp_queue.set_self_2(name, ".resp_queue", os + 616 );
  mu_fwd_queue.set_self_2(name, ".fwd_queue", os + 1176 );
}

mu_1_dir_t::~mu_1_dir_t()
{
}

/*** end record declaration ***/
mu_1_dir_t mu_1_dir_t_undefined_var;

class mu_1__type_7
{
 public:
  mu_1_proc_t array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_7 (char *n, int os) { set_self(n, os); };
  mu_1__type_7 ( void ) {};
  virtual ~mu_1__type_7 ();
  mu_1_proc_t& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 3 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
        Error.Error("Indexing to %s using an undefined value.", name);
      else
        Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_7& operator= (const mu_1__type_7& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_7::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_7::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_7::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 1704 + os);
    delete[] s;
  }
};
mu_1__type_7::~mu_1__type_7()
{
}
/*** end array declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1__type_8: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_8& val) { return mu__byte::operator=((int) val); };
  mu_1__type_8 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_8 (void): mu__byte(0, 3, 3) {};
  mu_1__type_8 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_8 mu_1__type_8_undefined_var;

class mu_1__type_9: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_9& val) { return mu__byte::operator=((int) val); };
  mu_1__type_9 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_9 (void): mu__byte(0, 3, 3) {};
  mu_1__type_9 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_9 mu_1__type_9_undefined_var;

class mu__subrange_37: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_37& val) { return mu__byte::operator=((int) val); };
  mu__subrange_37 (char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu__subrange_37 (void): mu__byte(1, 3, 2) {};
  mu__subrange_37 (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_37 mu__subrange_37_undefined_var;

class mu__subrange_38: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_38& val) { return mu__byte::operator=((int) val); };
  mu__subrange_38 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu__subrange_38 (void): mu__byte(0, 1, 2) {};
  mu__subrange_38 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_38 mu__subrange_38_undefined_var;

class mu__subrange_41: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_41& val) { return mu__byte::operator=((int) val); };
  mu__subrange_41 (char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu__subrange_41 (void): mu__byte(1, 3, 2) {};
  mu__subrange_41 (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_41 mu__subrange_41_undefined_var;

const int mu_numProc = 3;
const int mu_numDir = 1;
const int mu_queueLen = 10;
const int mu_ValueCount = 2;
const int mu_verbosity = 1;
const int mu_dir_node = 0;
const int mu_value_t_1 = 1;
const int mu_value_t_2 = 2;
const int mu_req = 3;
const int mu_resp = 4;
const int mu_fwd = 5;
const int mu_GetS = 6;
const int mu_GetM = 7;
const int mu_PutS = 8;
const int mu_PutM = 9;
const int mu_PutO = 10;
const int mu_DataAck = 11;
const int mu_InvAck = 12;
const int mu_PutAck = 13;
const int mu_FwdAck = 14;
const int mu_Inv = 15;
const int mu_FwdGetS = 16;
const int mu_FwdGetM = 17;
const int mu_Proc_M = 18;
const int mu_Proc_O = 19;
const int mu_Proc_S = 20;
const int mu_Proc_I = 21;
const int mu_Proc_IS_D = 22;
const int mu_Proc_IM_A = 23;
const int mu_Proc_IM_AD = 24;
const int mu_Proc_II_A = 25;
const int mu_Proc_SM_A = 26;
const int mu_Proc_SM_AD = 27;
const int mu_Proc_SI_A = 28;
const int mu_Proc_MI_A = 29;
const int mu_Proc_OM_AC = 30;
const int mu_Proc_OM_A = 31;
const int mu_Proc_OI_A = 32;
const int mu_Dir_M = 33;
const int mu_Dir_O = 34;
const int mu_Dir_S = 35;
const int mu_Dir_I = 36;
/*** Variable declaration ***/
mu_1__type_7 mu_proc("proc",0);

/*** Variable declaration ***/
mu_1_dir_t mu_dir("dir",6816);

/*** Variable declaration ***/
mu_1_value_t mu_lastWrite("lastWrite",8552);

void mu_LogNodeState(const mu_1_node_n& mu_p, const mu_1__type_8& mu_vb)
{
if ( (mu_verbosity) >= (mu_vb) )
{
if ( (mu_p) > (0) )
{
cout << "node:  PROC ";
cout << ( mu_p );
cout << ", state: ";
mu_proc[mu_p].mu_state.print();
cout << ", value: ";
mu_proc[mu_p].mu_value.print();
cout << ", isStalled: ";
mu_proc[mu_p].mu_isStalled.print();
cout << ", req_queue_size: ";
/*** begin multisetcount 0 declaration ***/
  int mu__intexpr10 = 0;
  {
  mu_1__type_0_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_proc[mu_p].mu_req_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr10++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
cout << ( mu__intexpr10 );
cout << ", resp_queue_size: ";
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr11 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_proc[mu_p].mu_resp_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr11++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
cout << ( mu__intexpr11 );
cout << ", fwd_queue_size: ";
/*** begin multisetcount 2 declaration ***/
  int mu__intexpr12 = 0;
  {
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_proc[mu_p].mu_fwd_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr12++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
cout << ( mu__intexpr12 );
cout << "\n";
}
else
{
cout << "node:  DIR";
cout << ", state: ";
mu_dir.mu_state.print();
cout << ", value: ";
mu_dir.mu_value.print();
cout << ", req_queue_size: ";
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr13 = 0;
  {
  mu_1__type_4_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_dir.mu_req_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr13++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
cout << ( mu__intexpr13 );
cout << ", resp_queue_size: ";
/*** begin multisetcount 4 declaration ***/
  int mu__intexpr14 = 0;
  {
  mu_1__type_5_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_dir.mu_resp_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr14++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 4 declaration ***/
cout << ( mu__intexpr14 );
cout << ", fwd_queue_size: ";
/*** begin multisetcount 5 declaration ***/
  int mu__intexpr15 = 0;
  {
  mu_1__type_6_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_dir.mu_fwd_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr15++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 5 declaration ***/
cout << ( mu__intexpr15 );
cout << "\n";
}
}
};
/*** end procedure declaration ***/

void mu_LogMessage(mu_1_message_t& mu_msg, const mu_1__type_9& mu_vb)
{
if ( (mu_verbosity) >= (mu_vb) )
{
cout << "message:   mType ";
cout << ( mu_msg.mu_mtype );
cout << ", value: ";
cout << ( mu_msg.mu_value );
cout << ", src: ";
cout << ( mu_msg.mu_src );
cout << ", dest: ";
cout << ( mu_msg.mu_dest );
cout << ", fwdTo: ";
cout << ( mu_msg.mu_fwdTo );
cout << ", numAck: ";
cout << ( mu_msg.mu_numAck );
cout << "\n";
}
};
/*** end procedure declaration ***/

void mu_Send(const mu_1_mtype_t& mu_mtype, const mu_1_node_n& mu_src, const mu_1_node_n& mu_dest, const mu_1_channel_t& mu_chan, const mu_1_value_t& mu_value, const mu_1_node_n& mu_fwdTo, const mu_1_node_n& mu_numAck)
{
/*** Variable declaration ***/
mu_1_message_t mu_msg("msg",0);

if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_dest.isundefined())
  mu_msg.mu_dest.undefine();
else
  mu_msg.mu_dest = mu_dest;
if (mu_value.isundefined())
  mu_msg.mu_value.undefine();
else
  mu_msg.mu_value = mu_value;
if (mu_fwdTo.isundefined())
  mu_msg.mu_fwdTo.undefine();
else
  mu_msg.mu_fwdTo = mu_fwdTo;
if (mu_numAck.isundefined())
  mu_msg.mu_numAck.undefine();
else
  mu_msg.mu_numAck = mu_numAck;
mu_LogMessage ( mu_msg, 2 );
mu_LogNodeState ( mu_msg.mu_dest, 3 );
switch ((int) mu_chan) {
case mu_req:
if ( (mu_msg.mu_dest) > (0) )
{
/*** begin multisetcount 6 declaration ***/
  int mu__intexpr16 = 0;
  {
  mu_1__type_0_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_proc[mu_msg.mu_dest].mu_req_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr16++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 6 declaration ***/
if ( !((mu__intexpr16) < (mu_queueLen)) ) Error.Error("Assertion failed: Message queue is full");
mu_proc[mu_msg.mu_dest].mu_req_queue.multisetadd(mu_msg);
}
else
{
/*** begin multisetcount 7 declaration ***/
  int mu__intexpr17 = 0;
  {
  mu_1__type_4_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_dir.mu_req_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr17++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 7 declaration ***/
if ( !((mu__intexpr17) < (mu_queueLen)) ) Error.Error("Assertion failed: Message queue is full");
mu_dir.mu_req_queue.multisetadd(mu_msg);
}
break;
case mu_resp:
if ( (mu_msg.mu_dest) > (0) )
{
/*** begin multisetcount 8 declaration ***/
  int mu__intexpr18 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_proc[mu_msg.mu_dest].mu_resp_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr18++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 8 declaration ***/
if ( !((mu__intexpr18) < (mu_queueLen)) ) Error.Error("Assertion failed: Message queue is full");
mu_proc[mu_msg.mu_dest].mu_resp_queue.multisetadd(mu_msg);
}
else
{
/*** begin multisetcount 9 declaration ***/
  int mu__intexpr19 = 0;
  {
  mu_1__type_5_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_dir.mu_resp_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr19++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 9 declaration ***/
if ( !((mu__intexpr19) < (mu_queueLen)) ) Error.Error("Assertion failed: Message queue is full");
mu_dir.mu_resp_queue.multisetadd(mu_msg);
}
break;
case mu_fwd:
if ( (mu_msg.mu_dest) > (0) )
{
/*** begin multisetcount 10 declaration ***/
  int mu__intexpr20 = 0;
  {
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_proc[mu_msg.mu_dest].mu_fwd_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr20++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 10 declaration ***/
if ( !((mu__intexpr20) < (mu_queueLen)) ) Error.Error("Assertion failed: Message queue is full");
mu_proc[mu_msg.mu_dest].mu_fwd_queue.multisetadd(mu_msg);
}
else
{
/*** begin multisetcount 11 declaration ***/
  int mu__intexpr21 = 0;
  {
  mu_1__type_6_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_dir.mu_fwd_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr21++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 11 declaration ***/
if ( !((mu__intexpr21) < (mu_queueLen)) ) Error.Error("Assertion failed: Message queue is full");
mu_dir.mu_fwd_queue.multisetadd(mu_msg);
}
break;
}
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_proc.clear();
  mu_dir.clear();
  mu_lastWrite.clear();
}
void world_class::undefine()
{
  mu_proc.undefine();
  mu_dir.undefine();
  mu_lastWrite.undefine();
}
void world_class::reset()
{
  mu_proc.reset();
  mu_dir.reset();
  mu_lastWrite.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_proc.print();
  mu_dir.print();
  mu_lastWrite.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_proc.print_statistic();
  mu_dir.print_statistic();
  mu_lastWrite.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_proc.print_diff(prevstate);
    mu_dir.print_diff(prevstate);
    mu_lastWrite.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_proc.to_state( newstate );
  mu_dir.to_state( newstate );
  mu_lastWrite.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu__subrange_38 mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    static mu_1__type_4_id mu_msgId;
    mu_msgId.value((r % 10) + 0);
    r = r / 10;
    return tsprintf("I, n:%s, msgId:%s", mu_n.Name(), mu_msgId.Name());
  }
  bool Condition(unsigned r)
  {
    static mu__subrange_38 mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    static mu_1__type_4_id mu_msgId;
    mu_msgId.value((r % 10) + 0);
    r = r / 10;
  if (!mu_d.mu_req_queue.in(mu_msgId)) { return FALSE; }
  mu_1_dir_t& mu_d = mu_dir;
  mu_1_message_t& mu_i = mu_d.mu_req_queue[mu_msgId];
bool mu__boolexpr22;
  if (!((mu_d.mu_state) == (mu_Dir_I))) mu__boolexpr22 = FALSE ;
  else {
/*** begin multisetcount 12 declaration ***/
  int mu__intexpr23 = 0;
  {
  mu_1__type_4_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_d.mu_req_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr23++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 12 declaration ***/
  mu__boolexpr22 = (!((mu__intexpr23) == (0))) ; 
}
  return mu__boolexpr22;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu__subrange_38 mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    static mu_1__type_4_id mu_msgId;
    mu_msgId.value((r % 10) + 0);
    r = r / 10;
    while (what_rule < 20 && mu_msgId.value()<10 )
      {
        if ( ( TRUE  ) ) {
  mu_1_dir_t& mu_d = mu_dir;
  mu_1_message_t& mu_i = mu_d.mu_req_queue[mu_msgId];
bool mu__boolexpr24;
  if (!((mu_d.mu_state) == (mu_Dir_I))) mu__boolexpr24 = FALSE ;
  else {
/*** begin multisetcount 12 declaration ***/
  int mu__intexpr25 = 0;
  {
  mu_1__type_4_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_d.mu_req_queue.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr25++;
        }
      if (mu_i == 10-1) break;
    }
  }
/*** end multisetcount 12 declaration ***/
  mu__boolexpr24 = (!((mu__intexpr25) == (0))) ; 
}
              if (mu__boolexpr24) {
                if ( ( TRUE && mu_d.mu_req_queue.in(mu_msgId) ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 20;
        }
        else
          what_rule += 20;
    r = what_rule - 0;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    mu_msgId.value((r % 10) + 0);
    r = r / 10;
    }
  }

  void Code(unsigned r)
  {
    static mu__subrange_38 mu_n;
    mu_n.value((r % 2) + 0);
    r = r / 2;
    static mu_1__type_4_id mu_msgId;
    mu_msgId.value((r % 10) + 0);
    r = r / 10;
  mu_1_dir_t& mu_d = mu_dir;
  mu_1_message_t& mu_i = mu_d.mu_req_queue[mu_msgId];
switch ((int) mu_i.mu_mtype) {
case mu_GetS:
mu_Send ( (int)mu_DataAck, mu_dir_node, mu_i.mu_src, mu_resp, mu_1_value_t_undefined_var, mu_1_node_n_undefined_var, 0 );
mu_d.mu_sharers[mu_i.mu_src] = mu_true;
mu_d.mu_state = mu_Dir_S;
break;
case mu_GetM:
mu_Send ( (int)mu_DataAck, mu_dir_node, mu_i.mu_src, mu_resp, mu_1_value_t_undefined_var, mu_1_node_n_undefined_var, 0 );
mu_d.mu_owner = mu_i.mu_src;
mu_d.mu_state = mu_Dir_M;
break;
default:
cout << "Invalid message";
break;
}
mu_d.mu_req_queue.multisetremove(mu_msgId);
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_value_t mu_v;
    mu_v.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_37 mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("I ==(store)==> M, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_value_t mu_v;
    mu_v.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_37 mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_proc_t& mu_p = mu_proc[mu_n];
bool mu__boolexpr26;
  if (!((mu_p.mu_state) == (mu_Proc_I))) mu__boolexpr26 = FALSE ;
  else {
  mu__boolexpr26 = ((mu_p.mu_isStalled) == (mu_false)) ; 
}
  return mu__boolexpr26;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 20;
    static mu_1_value_t mu_v;
    mu_v.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_37 mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 26 )
      {
        if ( ( TRUE  ) ) {
  mu_1_proc_t& mu_p = mu_proc[mu_n];
bool mu__boolexpr27;
  if (!((mu_p.mu_state) == (mu_Proc_I))) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = ((mu_p.mu_isStalled) == (mu_false)) ; 
}
              if (mu__boolexpr27) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 2;
        }
        else
          what_rule += 2;
    r = what_rule - 20;
    mu_v.value((r % 2) + 1);
    r = r / 2;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_value_t mu_v;
    mu_v.value((r % 2) + 1);
    r = r / 2;
    static mu__subrange_37 mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_proc_t& mu_p = mu_proc[mu_n];
mu_LogNodeState ( (int)mu_n, 3 );
mu_p.mu_state = mu_Proc_IM_AD;
mu_Send ( (int)mu_GetM, (int)mu_n, mu_dir_node, mu_req, mu_1_value_t_undefined_var, mu_1_node_n_undefined_var, 0 );
mu_lastWrite = mu_v;
mu_LogNodeState ( (int)mu_n, 3 );
  };

  bool UnFair()
  { return FALSE; }
};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<20)
    { R0.NextRule(what_rule);
      if (what_rule<20) return; }
  if (what_rule>=20 && what_rule<26)
    { R1.NextRule(what_rule);
      if (what_rule<26) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=19) return R0.Condition(r-0);
  if (r>=20 && r<=25) return R1.Condition(r-20);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=19) { R0.Code(r-0); return; } 
  if (r>=20 && r<=25) { R1.Code(r-20); return; } 
}
int Priority(unsigned short r)
{
  if (r<=19) { return R0.Priority(); } 
  if (r>=20 && r<=25) { return R1.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=19) return R0.Name(r-0);
  if (r>=20 && r<=25) return R1.Name(r-20);
  return NULL;
}
};
const unsigned numrules = 26;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 26


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
mu_proc[mu_i].mu_state = mu_Proc_I;
mu_proc[mu_i].mu_isStalled = mu_false;
};
};
{
for(int mu_i = 0; mu_i <= 3; mu_i++) {
mu_dir.mu_sharers[mu_i] = mu_false;
};
};
mu_dir.mu_state = mu_Dir_I;
  };

  bool UnFair()
  { return FALSE; }
};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
const rulerec invariants[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numinvariants = 0;

/******************/
bool mu__true_live() { return TRUE; }
/******************/

/********************
  Liveness records
 ********************/
const liverec livenesses[] = {
{ NULL, NULL, NULL, NULL, E }};
const unsigned short numlivenesses = 0;

/********************
  Fairstates records
 ********************/
const rulerec fairnesses[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numfairnesses = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
lastWrite:ScalarsetVariable
dir:Complex
proc:Complex
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  int class_mu_1_value_t[2];
  int undefined_class_mu_1_value_t;// has the highest class number

  void Print_class_mu_1_value_t();
  bool OnlyOneRemain_mu_1_value_t;
  bool MTO_class_mu_1_value_t()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_value_t)
      return FALSE;
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_value_t[i]== class_mu_1_value_t[j])
	    return TRUE;
    OnlyOneRemain_mu_1_value_t = TRUE;
    return FALSE;
  }
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  int * in_mu_1_value_t;
  typedef int arr_mu_1_value_t[2];
  arr_mu_1_value_t * perm_mu_1_value_t;
  arr_mu_1_value_t * revperm_mu_1_value_t;

  int size_mu_1_value_t[2];
  bool reversed_sorted_mu_1_value_t(int start, int end);
  void reverse_reversed_mu_1_value_t(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_value_t* perm, int size, mu_1_value_t k);
  void GenPerm0(mu_1_value_t* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_value_t()
{
  cout << "class_mu_1_value_t:\t";
  for (int i=0; i<2; i++)
    cout << class_mu_1_value_t[i];
  cout << " " << undefined_class_mu_1_value_t << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_value_t[i]== class_mu_1_value_t[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_value_t Perm0[2];

  /********************
   declaration of class variables
  ********************/
  in = new bool[2];
 in_mu_1_value_t = new int[2];
 perm_mu_1_value_t = new arr_mu_1_value_t[2];
 revperm_mu_1_value_t = new arr_mu_1_value_t[2];

    // Set perm and revperm
    count = 0;
    for (i=1; i<=2; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=2)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<2; i++)
      for (j=1; j<=2; j++)
        for (k=1; k<=2; k++)
          if (revperm_mu_1_value_t[i][k-1]==j)   // k - base 
            perm_mu_1_value_t[i][j-1]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_value_t = 0;
    size = 2;
    count = 2;
    for (i=0; i<2; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_value_t[i] = i_mu_1_value_t;
      i_mu_1_value_t += carry;
      if (i_mu_1_value_t >= 2) { i_mu_1_value_t = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_value_t = new int[1];
 perm_mu_1_value_t = new arr_mu_1_value_t[1];
 revperm_mu_1_value_t = new arr_mu_1_value_t[1];
  in[0] = TRUE;
    in_mu_1_value_t[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<2; i++)
    class_mu_1_value_t[i]=0;
  undefined_class_mu_1_value_t=0;
  OnlyOneRemain_mu_1_value_t = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<2; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_value_t[2];
  int size_mu_1_value_t[2];
  bool should_be_in_mu_1_value_t[2];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_value_t; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_value_t[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_value_t[k]==j)
	  {
	    size_mu_1_value_t[k] = class_size;
	    start_mu_1_value_t[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<2; i++) // set up
    should_be_in_mu_1_value_t[i] = TRUE;
  for (i=0; i<2; i++) // to be in or not to be
    for (k=0; k<2; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_value_t[i][k]-1 >=start_mu_1_value_t[k] 
	     && perm_mu_1_value_t[i][k]-1 < start_mu_1_value_t[k] + size_mu_1_value_t[k]) )
  	    {
	      should_be_in_mu_1_value_t[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<2; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_value_t[in_mu_1_value_t[i]]) in[i] = FALSE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_value_t; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_value_t[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_value_t[k]==j)
	  {
	    size_mu_1_value_t[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_value_t; j++) // class number
    {
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_value_t[k]==j)
	      revperm_mu_1_value_t[0][start++] = k+1;
    }
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_value_t[0][k]==j+1)
        perm_mu_1_value_t[0][j]=k+1;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_value_t* Perm, int size, mu_1_value_t k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_value_t* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=2)
    {
      for (i=1; i<=2; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=1; i<=2; i++)
        revperm_mu_1_value_t[count][i-1]=Perm[i-1].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_value_t(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_value_t[0][i]<revperm_mu_1_value_t[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_value_t(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_value_t[0][j];
      revperm_mu_1_value_t[0][j] = revperm_mu_1_value_t[0][i];
      revperm_mu_1_value_t[0][i] = temp;
    }
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
  for (start = 0; start < 2; )
    {
      end = start-1+size_mu_1_value_t[revperm_mu_1_value_t[0][start]-1];
      if (reversed_sorted_mu_1_value_t(start,end))
	       {
	  reverse_reversed_mu_1_value_t(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_value_t(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_value_t[0][j]<revperm_mu_1_value_t[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_value_t[0][j];
			  revperm_mu_1_value_t[0][j] = revperm_mu_1_value_t[0][k];
			  revperm_mu_1_value_t[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_value_t(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) return FALSE;
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_value_t[0][k]==j+1)   // k - base 
	perm_mu_1_value_t[0][j]=k+1; // j - base 
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_lastWrite.MultisetSort();
        mu_dir.MultisetSort();
        mu_proc.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_node_n::Permute(PermSet& Perm, int i) {};
void mu_1_node_n::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_node_n::Canonicalize(PermSet& Perm) {};
void mu_1_node_n::SimpleLimit(PermSet& Perm) {};
void mu_1_node_n::ArrayLimit(PermSet& Perm) {};
void mu_1_node_n::Limit(PermSet& Perm) {};
void mu_1_node_n::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_value_t::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_value_t[Perm.in_mu_1_value_t[i]][value()-1]); // value - base
};
void mu_1_value_t::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_value_t[value()-1]==Perm.undefined_class_mu_1_value_t) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_value_t[i] == Perm.undefined_class_mu_1_value_t && i!=value()-1)
            Perm.class_mu_1_value_t[i]++;
        value(1 + Perm.undefined_class_mu_1_value_t++);
      }
    else 
      {
        value(Perm.class_mu_1_value_t[value()-1]+1);
      }
}
void mu_1_value_t::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_value_t::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_value_t[value()-1]==Perm.undefined_class_mu_1_value_t) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_value_t[i] == Perm.undefined_class_mu_1_value_t && i!=value()-1)
            Perm.class_mu_1_value_t[i]++;
        Perm.undefined_class_mu_1_value_t++;
      }
}
void mu_1_value_t::ArrayLimit(PermSet& Perm) {}
void mu_1_value_t::Limit(PermSet& Perm) {}
void mu_1_value_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_channel_t::Permute(PermSet& Perm, int i) {};
void mu_1_channel_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_channel_t::Canonicalize(PermSet& Perm) {};
void mu_1_channel_t::SimpleLimit(PermSet& Perm) {};
void mu_1_channel_t::ArrayLimit(PermSet& Perm) {};
void mu_1_channel_t::Limit(PermSet& Perm) {};
void mu_1_channel_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_mtype_req_t::Permute(PermSet& Perm, int i) {};
void mu_1_mtype_req_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_mtype_req_t::Canonicalize(PermSet& Perm) {};
void mu_1_mtype_req_t::SimpleLimit(PermSet& Perm) {};
void mu_1_mtype_req_t::ArrayLimit(PermSet& Perm) {};
void mu_1_mtype_req_t::Limit(PermSet& Perm) {};
void mu_1_mtype_req_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_mtype_resp_t::Permute(PermSet& Perm, int i) {};
void mu_1_mtype_resp_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_mtype_resp_t::Canonicalize(PermSet& Perm) {};
void mu_1_mtype_resp_t::SimpleLimit(PermSet& Perm) {};
void mu_1_mtype_resp_t::ArrayLimit(PermSet& Perm) {};
void mu_1_mtype_resp_t::Limit(PermSet& Perm) {};
void mu_1_mtype_resp_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_mtype_fwd_t::Permute(PermSet& Perm, int i) {};
void mu_1_mtype_fwd_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_mtype_fwd_t::Canonicalize(PermSet& Perm) {};
void mu_1_mtype_fwd_t::SimpleLimit(PermSet& Perm) {};
void mu_1_mtype_fwd_t::ArrayLimit(PermSet& Perm) {};
void mu_1_mtype_fwd_t::Limit(PermSet& Perm) {};
void mu_1_mtype_fwd_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_mtype_t::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
  }
}
void mu_1_mtype_t::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
  }
}
void mu_1_mtype_t::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_mtype_t::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
  }
}
void mu_1_mtype_t::ArrayLimit(PermSet& Perm) {}
void mu_1_mtype_t::Limit(PermSet& Perm) {}
void mu_1_mtype_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_proc_state_t::Permute(PermSet& Perm, int i) {};
void mu_1_proc_state_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_proc_state_t::Canonicalize(PermSet& Perm) {};
void mu_1_proc_state_t::SimpleLimit(PermSet& Perm) {};
void mu_1_proc_state_t::ArrayLimit(PermSet& Perm) {};
void mu_1_proc_state_t::Limit(PermSet& Perm) {};
void mu_1_proc_state_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_dir_state_t::Permute(PermSet& Perm, int i) {};
void mu_1_dir_state_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_dir_state_t::Canonicalize(PermSet& Perm) {};
void mu_1_dir_state_t::SimpleLimit(PermSet& Perm) {};
void mu_1_dir_state_t::ArrayLimit(PermSet& Perm) {};
void mu_1_dir_state_t::Limit(PermSet& Perm) {};
void mu_1_dir_state_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_message_t::Permute(PermSet& Perm, int i)
{
  mu_value.Permute(Perm,i);
};
void mu_1_message_t::SimpleCanonicalize(PermSet& Perm)
{
  mu_value.SimpleCanonicalize(Perm);
};
void mu_1_message_t::Canonicalize(PermSet& Perm)
{
};
void mu_1_message_t::SimpleLimit(PermSet& Perm)
{
  mu_value.SimpleLimit(Perm);
};
void mu_1_message_t::ArrayLimit(PermSet& Perm){}
void mu_1_message_t::Limit(PermSet& Perm)
{
};
void mu_1_message_t::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<10; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_0::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_0::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_0::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_0::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_message_t value[10];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_value_t, oldcount_mu_1_value_t;
  bool pos_mu_1_value_t[2][2];
  bool goodset_mu_1_value_t[2];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[10][10];
  bool goodset_multisetindex[10];
  mu_1_message_t temp;

  // compact
  for (i = 0, j = 0; i < 10; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 10; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 10; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_value_t[i][j]=FALSE;
  count_mu_1_value_t = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_value_t[i] == count_mu_1_value_t)
         {
           pos_mu_1_value_t[count_mu_1_value_t][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_value_t++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_value_t = count_mu_1_value_t;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      if ( ( count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if (!(*this)[k].mu_value.isundefined())
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_value_t; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_value_t[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_value.isundefined()
                          && pos_mu_1_value_t[j][(*this)[k].mu_value-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_value_t[(*this)[k].mu_value-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_value_t; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_value_t[z][k] = pos_mu_1_value_t[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j][k] = FALSE;
                                if (pos_mu_1_value_t[j+1][k] && goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j+1][k] = FALSE;
                              }
                            count_mu_1_value_t++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_value_t!=count_mu_1_value_t);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_value_t<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_value_t())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_value_t[i][j])
            Perm.class_mu_1_value_t[j] = i;
      Perm.undefined_class_mu_1_value_t=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_value_t[j]>Perm.undefined_class_mu_1_value_t)
          Perm.undefined_class_mu_1_value_t=Perm.class_mu_1_value_t[j];
    }
  }
}
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<10; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_message_t value[10];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_value_t, oldcount_mu_1_value_t;
  bool pos_mu_1_value_t[2][2];
  bool goodset_mu_1_value_t[2];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[10][10];
  bool goodset_multisetindex[10];
  mu_1_message_t temp;

  // compact
  for (i = 0, j = 0; i < 10; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 10; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 10; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_value_t[i][j]=FALSE;
  count_mu_1_value_t = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_value_t[i] == count_mu_1_value_t)
         {
           pos_mu_1_value_t[count_mu_1_value_t][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_value_t++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_value_t = count_mu_1_value_t;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      if ( ( count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if (!(*this)[k].mu_value.isundefined())
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_value_t; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_value_t[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_value.isundefined()
                          && pos_mu_1_value_t[j][(*this)[k].mu_value-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_value_t[(*this)[k].mu_value-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_value_t; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_value_t[z][k] = pos_mu_1_value_t[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j][k] = FALSE;
                                if (pos_mu_1_value_t[j+1][k] && goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j+1][k] = FALSE;
                              }
                            count_mu_1_value_t++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_value_t!=count_mu_1_value_t);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_value_t<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_value_t())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_value_t[i][j])
            Perm.class_mu_1_value_t[j] = i;
      Perm.undefined_class_mu_1_value_t=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_value_t[j]>Perm.undefined_class_mu_1_value_t)
          Perm.undefined_class_mu_1_value_t=Perm.class_mu_1_value_t[j];
    }
  }
}
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<10; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_message_t value[10];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_value_t, oldcount_mu_1_value_t;
  bool pos_mu_1_value_t[2][2];
  bool goodset_mu_1_value_t[2];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[10][10];
  bool goodset_multisetindex[10];
  mu_1_message_t temp;

  // compact
  for (i = 0, j = 0; i < 10; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 10; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 10; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_value_t[i][j]=FALSE;
  count_mu_1_value_t = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_value_t[i] == count_mu_1_value_t)
         {
           pos_mu_1_value_t[count_mu_1_value_t][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_value_t++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_value_t = count_mu_1_value_t;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      if ( ( count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if (!(*this)[k].mu_value.isundefined())
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_value_t; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_value_t[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_value.isundefined()
                          && pos_mu_1_value_t[j][(*this)[k].mu_value-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_value_t[(*this)[k].mu_value-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_value_t; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_value_t[z][k] = pos_mu_1_value_t[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j][k] = FALSE;
                                if (pos_mu_1_value_t[j+1][k] && goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j+1][k] = FALSE;
                              }
                            count_mu_1_value_t++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_value_t!=count_mu_1_value_t);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_value_t<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_value_t())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_value_t[i][j])
            Perm.class_mu_1_value_t[j] = i;
      Perm.undefined_class_mu_1_value_t=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_value_t[j]>Perm.undefined_class_mu_1_value_t)
          Perm.undefined_class_mu_1_value_t=Perm.class_mu_1_value_t[j];
    }
  }
}
void mu_1_proc_t::Permute(PermSet& Perm, int i)
{
  mu_value.Permute(Perm,i);
  mu_req_queue.Permute(Perm,i);
  mu_resp_queue.Permute(Perm,i);
  mu_fwd_queue.Permute(Perm,i);
};
void mu_1_proc_t::SimpleCanonicalize(PermSet& Perm)
{
  mu_value.SimpleCanonicalize(Perm);
};
void mu_1_proc_t::Canonicalize(PermSet& Perm)
{
};
void mu_1_proc_t::SimpleLimit(PermSet& Perm)
{
  mu_value.SimpleLimit(Perm);
};
void mu_1_proc_t::ArrayLimit(PermSet& Perm){}
void mu_1_proc_t::Limit(PermSet& Perm)
{
  mu_req_queue.Limit(Perm);
  mu_resp_queue.Limit(Perm);
  mu_fwd_queue.Limit(Perm);
};
void mu_1_proc_t::MultisetLimit(PermSet& Perm)
{
  mu_req_queue.MultisetLimit(Perm);
  mu_resp_queue.MultisetLimit(Perm);
  mu_fwd_queue.MultisetLimit(Perm);
};
void mu__subrange_16::Permute(PermSet& Perm, int i) {};
void mu__subrange_16::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_16::Canonicalize(PermSet& Perm) {};
void mu__subrange_16::SimpleLimit(PermSet& Perm) {};
void mu__subrange_16::ArrayLimit(PermSet& Perm) {};
void mu__subrange_16::Limit(PermSet& Perm) {};
void mu__subrange_16::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_3::Canonicalize(PermSet& Perm){};
void mu_1__type_3::SimpleLimit(PermSet& Perm){}
void mu_1__type_3::ArrayLimit(PermSet& Perm) {}
void mu_1__type_3::Limit(PermSet& Perm){}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
  static mu_1__type_4 temp("Permute_mu_1__type_4",-1);
  int j;
  for (j=0; j<10; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_4::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_message_t value[10];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_value_t, oldcount_mu_1_value_t;
  bool pos_mu_1_value_t[2][2];
  bool goodset_mu_1_value_t[2];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[10][10];
  bool goodset_multisetindex[10];
  mu_1_message_t temp;

  // compact
  for (i = 0, j = 0; i < 10; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 10; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 10; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_value_t[i][j]=FALSE;
  count_mu_1_value_t = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_value_t[i] == count_mu_1_value_t)
         {
           pos_mu_1_value_t[count_mu_1_value_t][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_value_t++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_value_t = count_mu_1_value_t;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      if ( ( count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if (!(*this)[k].mu_value.isundefined())
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_value_t; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_value_t[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_value.isundefined()
                          && pos_mu_1_value_t[j][(*this)[k].mu_value-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_value_t[(*this)[k].mu_value-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_value_t; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_value_t[z][k] = pos_mu_1_value_t[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j][k] = FALSE;
                                if (pos_mu_1_value_t[j+1][k] && goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j+1][k] = FALSE;
                              }
                            count_mu_1_value_t++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_value_t!=count_mu_1_value_t);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_value_t<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_value_t())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_value_t[i][j])
            Perm.class_mu_1_value_t[j] = i;
      Perm.undefined_class_mu_1_value_t=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_value_t[j]>Perm.undefined_class_mu_1_value_t)
          Perm.undefined_class_mu_1_value_t=Perm.class_mu_1_value_t[j];
    }
  }
}
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<10; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_5::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_5::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_5::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_message_t value[10];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_value_t, oldcount_mu_1_value_t;
  bool pos_mu_1_value_t[2][2];
  bool goodset_mu_1_value_t[2];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[10][10];
  bool goodset_multisetindex[10];
  mu_1_message_t temp;

  // compact
  for (i = 0, j = 0; i < 10; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 10; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 10; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_value_t[i][j]=FALSE;
  count_mu_1_value_t = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_value_t[i] == count_mu_1_value_t)
         {
           pos_mu_1_value_t[count_mu_1_value_t][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_value_t++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_value_t = count_mu_1_value_t;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      if ( ( count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if (!(*this)[k].mu_value.isundefined())
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_value_t; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_value_t[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_value.isundefined()
                          && pos_mu_1_value_t[j][(*this)[k].mu_value-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_value_t[(*this)[k].mu_value-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_value_t; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_value_t[z][k] = pos_mu_1_value_t[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j][k] = FALSE;
                                if (pos_mu_1_value_t[j+1][k] && goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j+1][k] = FALSE;
                              }
                            count_mu_1_value_t++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_value_t!=count_mu_1_value_t);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_value_t<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_value_t())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_value_t[i][j])
            Perm.class_mu_1_value_t[j] = i;
      Perm.undefined_class_mu_1_value_t=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_value_t[j]>Perm.undefined_class_mu_1_value_t)
          Perm.undefined_class_mu_1_value_t=Perm.class_mu_1_value_t[j];
    }
  }
}
void mu_1__type_6::Permute(PermSet& Perm, int i)
{
  static mu_1__type_6 temp("Permute_mu_1__type_6",-1);
  int j;
  for (j=0; j<10; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_6::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_6::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_6::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_6::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_message_t value[10];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_value_t, oldcount_mu_1_value_t;
  bool pos_mu_1_value_t[2][2];
  bool goodset_mu_1_value_t[2];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[10][10];
  bool goodset_multisetindex[10];
  mu_1_message_t temp;

  // compact
  for (i = 0, j = 0; i < 10; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 10; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 10; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_value_t[i][j]=FALSE;
  count_mu_1_value_t = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_value_t[i] == count_mu_1_value_t)
         {
           pos_mu_1_value_t[count_mu_1_value_t][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_value_t++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_value_t = count_mu_1_value_t;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      if ( ( count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_value_t() && count_mu_1_value_t<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if (!(*this)[k].mu_value.isundefined())
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_value_t; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_value_t[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_value.isundefined()
                          && pos_mu_1_value_t[j][(*this)[k].mu_value-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_value_t[(*this)[k].mu_value-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_value_t; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_value_t[z][k] = pos_mu_1_value_t[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_value_t[j][k] && !goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j][k] = FALSE;
                                if (pos_mu_1_value_t[j+1][k] && goodset_mu_1_value_t[k])
                                  pos_mu_1_value_t[j+1][k] = FALSE;
                              }
                            count_mu_1_value_t++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_value_t!=count_mu_1_value_t);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_value_t<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_value_t())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_value_t[i][j])
            Perm.class_mu_1_value_t[j] = i;
      Perm.undefined_class_mu_1_value_t=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_value_t[j]>Perm.undefined_class_mu_1_value_t)
          Perm.undefined_class_mu_1_value_t=Perm.class_mu_1_value_t[j];
    }
  }
}
void mu_1_dir_t::Permute(PermSet& Perm, int i)
{
  mu_value.Permute(Perm,i);
  mu_req_queue.Permute(Perm,i);
  mu_resp_queue.Permute(Perm,i);
  mu_fwd_queue.Permute(Perm,i);
};
void mu_1_dir_t::SimpleCanonicalize(PermSet& Perm)
{
  mu_value.SimpleCanonicalize(Perm);
};
void mu_1_dir_t::Canonicalize(PermSet& Perm)
{
};
void mu_1_dir_t::SimpleLimit(PermSet& Perm)
{
  mu_value.SimpleLimit(Perm);
};
void mu_1_dir_t::ArrayLimit(PermSet& Perm){}
void mu_1_dir_t::Limit(PermSet& Perm)
{
  mu_req_queue.Limit(Perm);
  mu_resp_queue.Limit(Perm);
  mu_fwd_queue.Limit(Perm);
};
void mu_1_dir_t::MultisetLimit(PermSet& Perm)
{
  mu_req_queue.MultisetLimit(Perm);
  mu_resp_queue.MultisetLimit(Perm);
  mu_fwd_queue.MultisetLimit(Perm);
};
void mu_1__type_7::Permute(PermSet& Perm, int i)
{
  static mu_1__type_7 temp("Permute_mu_1__type_7",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<4; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_7::Canonicalize(PermSet& Perm){};
void mu_1__type_7::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<4; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_7::ArrayLimit(PermSet& Perm) {}
void mu_1__type_7::Limit(PermSet& Perm){}
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{
  for (int j=0; j<4; j++) {
    array[j].MultisetLimit(Perm);
  }
}
void mu_1__type_8::Permute(PermSet& Perm, int i) {};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_8::Canonicalize(PermSet& Perm) {};
void mu_1__type_8::SimpleLimit(PermSet& Perm) {};
void mu_1__type_8::ArrayLimit(PermSet& Perm) {};
void mu_1__type_8::Limit(PermSet& Perm) {};
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_9::Permute(PermSet& Perm, int i) {};
void mu_1__type_9::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_9::Canonicalize(PermSet& Perm) {};
void mu_1__type_9::SimpleLimit(PermSet& Perm) {};
void mu_1__type_9::ArrayLimit(PermSet& Perm) {};
void mu_1__type_9::Limit(PermSet& Perm) {};
void mu_1__type_9::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_37::Permute(PermSet& Perm, int i) {};
void mu__subrange_37::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_37::Canonicalize(PermSet& Perm) {};
void mu__subrange_37::SimpleLimit(PermSet& Perm) {};
void mu__subrange_37::ArrayLimit(PermSet& Perm) {};
void mu__subrange_37::Limit(PermSet& Perm) {};
void mu__subrange_37::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_38::Permute(PermSet& Perm, int i) {};
void mu__subrange_38::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_38::Canonicalize(PermSet& Perm) {};
void mu__subrange_38::SimpleLimit(PermSet& Perm) {};
void mu__subrange_38::ArrayLimit(PermSet& Perm) {};
void mu__subrange_38::Limit(PermSet& Perm) {};
void mu__subrange_38::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_41::Permute(PermSet& Perm, int i) {};
void mu__subrange_41::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_41::Canonicalize(PermSet& Perm) {};
void mu__subrange_41::SimpleLimit(PermSet& Perm) {};
void mu__subrange_41::ArrayLimit(PermSet& Perm) {};
void mu__subrange_41::Limit(PermSet& Perm) {};
void mu__subrange_41::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_lastWrite.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_lastWrite.MultisetSort();
              mu_dir.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_dir.MultisetSort();
              mu_proc.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_proc.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_lastWrite.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_lastWrite.MultisetSort();
          mu_dir.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_dir.MultisetSort();
          mu_proc.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_proc.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_lastWrite.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_lastWrite.MultisetSort();
              mu_dir.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_dir.MultisetSort();
              mu_proc.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_proc.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_lastWrite.MultisetSort();
      mu_dir.MultisetSort();
      mu_proc.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_lastWrite.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_lastWrite.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_dir.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_dir.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_proc.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_proc.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_lastWrite.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_dir.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_proc.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_dir.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_proc.MultisetLimit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_dir.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_dir.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_proc.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_proc.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_lastWrite.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_dir.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_proc.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_dir.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_proc.MultisetLimit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_dir.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_dir.MultisetSort();
  mu_proc.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_proc.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_dir.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_dir.MultisetSort();
      mu_proc.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_proc.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_lastWrite.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_dir.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_proc.SimpleLimit(Perm);
  }

  Perm.SimpleToOne();

  mu_dir.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_dir.MultisetSort();

  mu_proc.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_proc.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
