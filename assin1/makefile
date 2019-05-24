#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-241      Assignment #: 1    Semester: Fall2017  ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
#||                                                               ||
#||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
#||                                                               ||
#||  Due: Thursday 9/14/2017 by 11:59PM                           ||
#||                                                               ||
#||  Description:                                                 ||
#||                                                               ||
#||     This program will take input from a file in the same      ||
#||     directory and output the information in formated style.   ||
#||     The input file must be named "providers.csv" and contain  ||
#||     12 sets of data seperated by commas.                      || 
# \_______________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
Provider: Provider.o
	g++ $(CCFLAGS) -o Provider Provider.o

# Rule to compile source code file to object code
Provider.o: Provider.cpp
	g++ $(CCFLAGS) -c Provider.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Provider
