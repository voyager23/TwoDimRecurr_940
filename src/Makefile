# Makefile for test folder

CFLAGS = --std=c++20 -fdiagnostics-color=never -Wall
#-fpermissive
DEBUG = -g

b_src : b_src.cpp
	#@echo "b_src - Clearing"
	clear
	g++ $(CFLAGS) $(DEBUG) $@.cpp  -o ../bin/$@
	@ln -frs ../bin/b_src ../bin/bin_link
	@symlinks -v ../bin

a_src : a_src.cpp
	#@echo "a_src - Clearing"
	clear
	g++ $(CFLAGS) $(DEBUG) $@.cpp $(INC) -o ../bin/$@
	@ln -frs ../bin/a_src ../bin/bin_link
	@symlinks -v ../bin

# ============================================

phony: run gdb

run :
	@echo ""
	@../bin/bin_link

gdb :
	gdb ../bin/bin_link
