#/*
#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-241      Assignment #: 5    Semester: Fall2017  ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
#||                                                               ||
#||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
#||                                                               ||
#||  Due: Tuesday 10/31/2017 by 11:59PM                           ||
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
assign5: assign5.o Stack.o
	g++ $(CCFLAGS) -o assign5 assign5.o Stack.o

# Rules to compile source code file to object code
Stack.o: Stack.cpp Stack.h
	g++ $(CCFLAGS) -c Stack.cpp
	
assign5.o: assign5.cpp Stack.h
	g++ $(CCFLAGS) -c assign5.cpp

# Pseudo-target to remove object code and executable files
clean: 
	-rm *.o assign5
