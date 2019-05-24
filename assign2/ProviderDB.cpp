/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-241      Assignment #: 2    Semester: Fall2017  ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
||                                                               ||
||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
||                                                               ||
||  Due: Wednesday 9/27/2017 by 11:59PM                          ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||     This file is named ProviderDB.cpp, it will provide the    ||
||     code for all methods provided in the class declaration,   ||
||     ProviderDB.h                                              ||
 \_______________________________________________________________/
*/

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include "ProviderDB.h"
using namespace std;

//Default constructor for ProviderDB class

ProviderDB::ProviderDB()
{
   pObjInArray = 0;
}

/*
Constructor: ProviderDB

Use: filling the pArray inside the ProviderDB class by reading
     in a file

Parameters: A pointer to a character array that should contain
            the name of a database file

*/

ProviderDB::ProviderDB(const char * inpParam)
{
   ifstream inFile;
	  
   inFile.open(inpParam);
    
   if (!inFile) //Escape incase file dosn't exsist
   {
      cerr << "Error - unable to open input file\n";
      exit(1);
   }
   
   inFile.read((char*) this, sizeof(ProviderDB));
   
   inFile.close();
}

/*
Function: Print, ProviderDB class

Use: prints out all of the Providers using the Provider Class's
     print function
     
Parameters: none

Returns: nothing
*/

void ProviderDB::print()
{
   cout << "Health Care Provider Listing" << endl << endl;
   for (int i = 0; i < pObjInArray; i++)
      pArray[i].print();
}

/*
Function: sortByProNum, ProviderDB class

Use: Sorts the ProviderDB array (pArray) by it's provider number
     from smallest to greatest

Parameters: none

Returns: nothing
*/

void ProviderDB::sortByProNum()
{
   int i, j;
   Provider bucket;
   for (i = 1; i < pObjInArray; i++)
   {
      bucket = pArray[i];
      for (j = i; (j > 0) && (strcmp(pArray[j-1].getProNum(), 
                              bucket.getProNum()) > 0); j--)
      {
         pArray[j] = pArray[j-1];
      }
      pArray[j] = bucket; 
   }

}

/*
Function: sortBySpec, ProviderDB class

Use: sorts the ProvdierDB array (pArray) by specilization in 
     descending order

Parameters: none

Returns: nothing
*/

void ProviderDB::sortBySpec()
{
   int i, j;
   Provider bucket;
   for (i = pObjInArray; i >= 0; i--)
   {
      bucket = pArray[i];
      for (j = i; (j < (pObjInArray-1)) &&
          (strcmp(pArray[j+1].getSpec(), bucket.getSpec()) > 0); j++)
      {
         
         pArray[j] = pArray[j+1];
      }
      pArray[j] = bucket; 
   }
}

/*
Function: sortByName, ProviderDB class

Use: sorts the ProvdierDB array (pArray) by specilization in 
     ascending order

Parameters: none

Returns: nothing
*/

void ProviderDB::sortByName()
{
   int i, j;
   Provider bucket;
   for (i = 1; i < pObjInArray; i++)
   {
      bucket = pArray[i];
      for (j = i; (j > 0) && (strcmp(pArray[j-1].getName(), 
                              bucket.getName()) > 0); j--)
      {
         pArray[j] = pArray[j-1];
      }
      pArray[j] = bucket; 
   }
}
