# make is a unix tool that we will use to simpifying the C compilation
# process.  Instead of typing in 'gcc -g -Wall -Wextra -o outfile sourcefile.c'
# to build a single executable file.  You can just type in 'make' to 
# build one or more executable files.  Typing in 'make clean' will remove
# all executable files (this should be done prior to submitting lab
# assignments).
#
# This makefile has rules for building 11 different executable files,
# one for each of the .c files in this directory.
#
# We will talk about makefile syntax over the course of the semester, for
# now you can just use this makefile, but note that there are "rules" that
# look very similar to the gcc commands you would type in by hand.

# define some makefile variables: which compiler and complier flags to use
CC = gcc
CFLAGS = -g -Wall

EXECUTABLES = testprog arrays structs types_scanf 

# these are the compilation rules:  
all:  $(EXECUTABLES)

testprog: testprog.c
	$(CC) $(CFLAGS) -o testprog testprog.c

arrays: arrays.c
	$(CC) $(CFLAGS) -o arrays arrays.c

structs: structs.c
	$(CC) $(CFLAGS) -o structs structs.c

types_scanf: types_scanf.c
	$(CC) $(CFLAGS) -o types_scanf types_scanf.c

clean:
	$(RM) $(EXECUTABLES)
