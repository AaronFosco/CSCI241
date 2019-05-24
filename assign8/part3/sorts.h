/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-241      Assignment #: 8    Semester: Fall2017  ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
||                                                               ||
||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
||                                                               ||
||  Due: Wedneday 11/29/2017 by 11:59PM                          ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||     This a header file for template functions that build and  ||
||     gets lists held inside a vector of template data type T.  ||
||     This header also holds greaterThan and lessThan           ||
||     functions for compairsions between two varables of data   ||
||     type T.
 \_______________________________________________________________/
*/

#ifndef SORTS_H
#define SORTS_H

#include <fstream>

using namespace std;

//function prototypes

template <class T>
void buildList(vector<T>& set, const char* fileName);

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine);

template <class T>
bool lessThan(const T& item1, const T& item2);

template <class T>
bool greaterThan(const T& item1, const T& item2);

/*
Function: buildList

Use: builds a vector filled with values of the template data type T

Parameters: set: a refrence to a vector to be filled
            fileName: the name of a file to extract data from
	    
Returns: nothing
*/

template <class T>
void buildList(vector<T>& set, const char* fileName)
{
   T buffer;
   ifstream inFile;
	
   inFile.open(fileName);
   if (!inFile)
   {
      cerr << "File not found!\n";
      exit(1);
   }
	
   inFile >> buffer;
   while (inFile)
   { 
      set.push_back(buffer);
      
      inFile >> buffer;
   }
   
   inFile.close();
}

/*
Function: printList

Use: prints the vector 'set' that was passed onto cout

Parameters: set: a refrence to a const vector that will be printed out
            itemWidth: the width to be set for cout
	    numPerLine: the number of elements to be printed per line
	    
Returns: nothing
*/

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
   int i = 0;
   while (i < (int) set.size())
   {
      cout << setw(itemWidth) << set[i] << ' ';
      i++;
      if (i % numPerLine == 0)
         cout << endl;
   }
   
   if (i % numPerLine != 0)
      cout << endl;
      
}

/*
Function: lessThan

Use: compairs item1 to item2 using the less than relational operator

Parameters: item1 & item2: a refrence to a constant varable of template 
            datatype T.
	    
Returns: True if item1 is smaller than item2, false otherwise
*/

template <class T>
bool lessThan(const T& item1, const T& item2)
{
   return (item1 < item2) ? true : false;
}

/*
Function: lessThan

Use: compairs item1 to item2 using the greater than relational operator

Parameters: item1 & item2: a refrence to a constant varable of template 
            datatype T.
	    
Returns: True if item1 is larger than item2, false otherwise
*/

template <class T>
bool greaterThan(const T& item1, const T& item2)
{
   return (item1 > item2) ? true : false;
}
#endif
