**EECS570 PA2 Cache Coherence Verification using Murphi**

Running instructions :
1) Change MURPHI_INSTALL_PATH = ../Murphi3.1 to required absolute/relative location of Murphi3.1 directory (no symlinks used)
2) Change the constant gPercentActiveStates in mu_prolog.inc inside Murphi3.1 from 0.1 to 0.8 to avoid queue capacity overflow (since 3 procs and 3 data values used)
3) To compile and verify msi_opt.m: make msi_opt_verif 
4) To compile and verify msi.m: make msi_verif

To debug in simulation mode and generate snapshots, I have used "make msi_opt_sim". 
If running in this mode, ensure murphi_vizualizer.py is present in directory, configured to appropriate log file and enableMsgTrace: 0 set in Murphi code to generate state verbose
GitHub Link := https://github.com/rudrajyotiroy/cache_coherence_murphi/tree/master

In case state diagrams in report are unclear, state transition tables used to generate state_diagrams are present in state_diagram.ipynb
State diagram images are msi_proc.png, msi_dir.png, msi_opt_proc.png, msi_opt_dir.png