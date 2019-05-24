#/*
#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-241      Assignment #: 6    Semester: Fall2017  ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
#||                                                               ||
#||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
#||                                                               ||
#||  Due: Tuesday 11/9/2017 by 11:59PM                            ||
#||                                                               ||
#||  Description:                                                 ||
#||                                                               ||
#||     This is the makefile for the Queue class, as well as      ||
#||     the untouched driver program written for the stack class. ||
# \_______________________________________________________________/
#*/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign6: assign6.o
	g++ $(CCFLAGS) -o assign6 assign6.o

# Rules to compile source code file to object code
assign6.o: assign6.cpp Queue.h
	g++ $(CCFLAGS) -c assign6.cpp

# Pseudo-target to remove object code and executable files
clean: 
	-rm *.o assign6
