#
# Makefile for compiling the Murphi verifier for a given protocol 
#          from its .C file
#
# Make sure that you set INCLUDEPATH and CXX according to your system
#
# Author:               Ulrich Stern
# Version:              1
# Creation Date:        Sat May 25 15:13:39 PDT 1996
# Filename:             Makefile
# History:
#
# Experiences compiling the Murphi verifier:
#  There are two things that caused problems in this Muphi release:
#  - Some compilers - especially those based on cfront - can only generate
#   very simple inline code. One has to turn off inlining in this case. The
#   options are typically +d (CC, OCC, DCC) or -fno-default-inline (g++).
#   The compilation is much faster then as well.
#  - The "signal" system call used in Murphi for defining an own handler
#   to catch division by zero seems to be system dependent. Two different
#   ways to use this call can be selected by defining or not-defining
#   CATCH_DIV. See below for when defining CATCH_DIV was needed.
#
# Tested on the following machines:
#  beet        SGI INDY    running IRIX 5.3
#  cabbage     Sun SPARC20 running SunOS 4.1.3_U1
#  dawn        Sun SPARC20 running SunOS 5.4
#  elaine      Sun SPARC20 running SunOS 4.1.4
#
# Compiler versions:
#  g++    2.6.0 (cabbage), 2.6.3 (beet), 2.7.2 (dawn, elaine)
#  CC     3.0 or higher (elaine)
#  OCC    3.2.1 (beet)
#  DCC    4.0 (beet)
#

# path for including mu_verifier.C etc.
MURPHI_INSTALL_PATH = ../Murphi3.1

# choice of compiler (with REQUIRED options)
#CXX = g++ #                                 # for beet, elaines, dawns, cabbage
CXX = g++ -DCATCH_DIV #                   # for elaines
#CXX = OCC +d #                              # for beet
#CXX = DCC #                                 # for beet

# options (really OPTIONAL)
CFLAGS = -Wno-write-strings -m32
#CFLAGS = -fno-default-inline #              # for g++, only on beet and cabbage
#CFLAGS = +d -w #                            # for DCC

# optimization
# OFLAGS = -O4

# rules for compiling
msi_opt_verif:
	${MURPHI_INSTALL_PATH}/src/mu msi_opt.m;
	${CXX} ${CFLAGS} ${OFLAGS} -o bin_msi_opt msi_opt.C -I${MURPHI_INSTALL_PATH}/include -lm;
	./bin_msi_opt -k 999999 | tee msi_opt_verif.log;

msi_opt_violet:
	${MURPHI_INSTALL_PATH}/src/mu msi_opt.m;
	${CXX} ${CFLAGS} ${OFLAGS} -o bin_msi_opt msi_opt.C -I${MURPHI_INSTALL_PATH}/include -lm;
	./bin_msi_opt -tv -k 999999 > msi_violet.log;
	python3 murphi_vizualize.py;

msi_opt_sim:
	${MURPHI_INSTALL_PATH}/src/mu msi_opt.m;
	${CXX} ${CFLAGS} ${OFLAGS} -o bin_msi_opt msi_opt.C -I${MURPHI_INSTALL_PATH}/include -lm;
	./bin_msi_opt -k 999999 -s | tee msi_opt_sim.log;
	python3 murphi_vizualize.py;

vis:
	cp msi_opt_sim.log msi_opt_sim_cache.log
	python3 murphi_vizualize.py;

msi_verif:
	${MURPHI_INSTALL_PATH}/src/mu msi.m;
	${CXX} ${CFLAGS} ${OFLAGS} -o bin_msi msi.C -I${MURPHI_INSTALL_PATH}/include -lm;
	./bin_msi -k 999999 | tee msi_verif.log;

msi_verif_violet:
	${MURPHI_INSTALL_PATH}/src/mu msi.m;
	${CXX} ${CFLAGS} ${OFLAGS} -o bin_msi msi.C -I${MURPHI_INSTALL_PATH}/include -lm;
	./bin_msi -tv -k 999999 > msi_violet.log;
	python3 murphi_vizualize.py;

msi_sim:
	${MURPHI_INSTALL_PATH}/src/mu msi.m;
	${CXX} ${CFLAGS} ${OFLAGS} -o bin_msi msi.C -I${MURPHI_INSTALL_PATH}/include -lm;
	./bin_msi -s -k 999999 | tee msi_sim.log;

clean:
	rm -rf *.C
	rm -rf bin_*
# Command : make -B (filename without .m) ARG=(arguments for Murphi)