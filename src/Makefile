# Makefile for test folder

CFLAGS = --std=c++20 -fdiagnostics-color=never -Wall
#-fpermissive
DEBUG = -g
INC =

b_solution : b_solution.cpp
	#@echo "b_solution - Clearing"
	clear
	g++ $(CFLAGS) $(DEBUG) $@.cpp $(INC) -o ../bin/$@
	@ln -frs ../bin/b_solution ../bin/bin_link
	@symlinks -v ../bin

a_solution : a_solution.cpp
	#@echo "a_solution - Clearing"
	clear
	g++ $(CFLAGS) $(DEBUG) $@.cpp $(INC) -o ../bin/$@
	@ln -frs ../bin/a_solution ../bin/bin_link
	@symlinks -v ../bin

c_src : c_src.cpp
	#@echo "c_src - Clearing"
	clear
	g++ $(CFLAGS) $(DEBUG) $@.cpp $(INC) -o ../bin/$@
	@ln -frs ../bin/c_src ../bin/bin_link
	@symlinks -v ../bin

# ============================================

phony: run gdb

run :
	@echo ""
	@../bin/bin_link

gdb :
	gdb ../bin/bin_link
