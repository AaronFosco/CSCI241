#
# PROGRAM:    StudentExample
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
StudentExample: StudentExample.o
	g++ $(CCFLAGS) -o StudentExample StudentExample.o

# Rule to compile source code file to object code
StudentExample.o: StudentExample.cpp
	g++ $(CCFLAGS) -c StudentExample.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o StudentExample
