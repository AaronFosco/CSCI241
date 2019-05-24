#/*
#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-241      Assignment #: 8    Semester: Fall2017  ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
#||                                                               ||
#||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
#||                                                               ||
#||  Due: Wedneday 11/29/2017 by 11:59PM                          ||
#||                                                               ||
#||  Description:                                                 ||
#||                                                               ||
#||     This is the makefile for the assignment 8, which will     ||
#||     implement a way to make a vector of elements, print them  ||
#||     and sort them using either merge sort or quick sort.      ||
# \_______________________________________________________________/
#*/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign8: assign8.o
	g++ $(CCFLAGS) -o assign8 assign8.o

# Rules to compile source code file to object code
assign8.o: assign8.cpp sorts.h quicksort.h mergesort.h
	g++ $(CCFLAGS) -c assign8.cpp

# Pseudo-target to remove object code and executable files
clean: 
	-rm *.o assign8
