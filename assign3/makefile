#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-241      Assignment #: 3    Semester: Fall2017  ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
#||                                                               ||
#||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
#||                                                               ||
#||  Due: Tuesday 10/10/2017 by 11:59PM                           ||
#||                                                               ||
#||  Description:                                                 ||
#||                                                               ||
#||     This program will take input from a file in the same      ||
#||     directory and is able to output the information in a      ||
#||     formated style.                                           ||
#||     The input file must be named "providersdb" and contain    ||
#||     multiple sets of data in a specific format. The data,     ||
#||     in the form of an array of Providers, can then be         ||
#||     organized and sorted by three diffrent sort methods.      ||
#||     An extra input file named "transactions.txt" needs to     ||
#||     be inside the same directory as well, and contain         ||
#||     to either print all Providers, Search for a Provider      ||
#||     with a given Provider number, or Search for a Provider    ||
#||     with a given Specialization.                              ||
# \_______________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign3: assign3.o Provider.o ProviderDB.o
	g++ $(CCFLAGS) -o assign3 assign3.o Provider.o ProviderDB.o

# Rules to compile source code file to object code
assign3.o: assign3.cpp ProviderDB.h
	g++ $(CCFLAGS) -c assign3.cpp

Provider.o: Provider.cpp Provider.h
	g++ $(CCFLAGS) -c Provider.cpp
	
ProviderDB.o: ProviderDB.cpp ProviderDB.h
	g++ $(CCFLAGS) -c ProviderDB.cpp

#Header file dependency
ProviderDB.h: Provider.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign3
