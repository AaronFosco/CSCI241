#/*
#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-241      Assignment #: 7    Semester: Fall2017  ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
#||                                                               ||
#||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
#||                                                               ||
#||  Due: Thursday 11/16/2017 by 11:59PM                          ||
#||                                                               ||
#||  Description:                                                 ||
#||                                                               ||
#||     This is the makefile for the stack class, as well as      ||
#||     the untouched driver program written for the stack class. ||
# \_______________________________________________________________/
#*/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign7: assign7.o
	g++ $(CCFLAGS) -o assign7 assign7.o

# Rules to compile source code file to object code
assign7.o: assign7.cpp Stack.h
	g++ $(CCFLAGS) -c assign7.cpp

# Pseudo-target to remove object code and executable files
clean: 
	-rm *.o assign7
