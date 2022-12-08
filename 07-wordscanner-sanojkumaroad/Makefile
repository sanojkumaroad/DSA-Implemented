# //***************************************************************************
# //
# //  Sanoj Oad
# //  Z1980626
# //  CSCI 340 03
# //
# //  I certify that this is my own work and where appropriate an extension 
# //  of the starter code provided for the assignment.
# //
# //***************************************************************************

# Compiler variables
CXXFLAGS = -std=c++11 -Wall -Werror

# By default, make will try to satisfy the first recipie/rule that it finds.
# By convention, 99% of all Makefiles start with a rule named 'all' that
# simply names the target(s) that are to be (re)compiled like this:
all: wordscanner

# The 'all' rule lists the targets of interest... that have their own recipies:
wordscanner:	wordscanner.cc #parking.h
	g++ $(CXXFLAGS) -o wordscanner wordscanner.cc

# A 'phony' target named clean is used to remove all files that the Makefile
# can be used to re-create.
clean:
	rm -f wordscanner

# Some times another 'phony' target is provided to easily force a 'clean' and then
# a rebuild of 'all' the targets.
world: clean all

