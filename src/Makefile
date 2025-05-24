# Makefile for test folder

CFLAGS = --std=c++20 -fdiagnostics-color=never -Wall
#-fpermissive
DEBUG = -g
INC =


a_solution : a_solution.cpp
	#@echo "a_solution - Clearing"
	clear
	g++ $(CFLAGS) $(DEBUG) $@.cpp $(INC) -o ../bin/$@
	@ln -frs ../bin/a_solution ../bin/bin_link
	@symlinks -v ../bin

# ============================================

phony: run gdb

run :
	@echo ""
	@../bin/bin_link

gdb :
	gdb ../bin/bin_link
