/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-241      Assignment #: 3    Semester: Fall2017  ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
||                                                               ||
||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
||                                                               ||
||  Due: Tuesday 10/10/2017 by 11:59PM                           ||
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

/*
Function: processTransactions, ProviderDB class

Use: opens a space seperated text file to obtain commands
     to either list all objects in pArray, find Providers
     with a certain Specialization, or search for a Provider
     with a specific provider number.

Parameters: a Pointer to a constant character

Returns: nothing
*/

void ProviderDB::processTransactions(const char* filen)
{
   //generates an ifstream object for file opening and creates 
   //character arrays for command reqests
   ifstream inFile;
   char hold[41];
   bool endflag = false;
   char all[] = "all", spec[] = "specialty", numb[] = "number";
   inFile.open(filen);
    
   if (!inFile) //Escape incase file dosn't exsist
   {
      cerr << "Error - unable to open input file\n";
      exit(1);
   }
   
   //inital check to see if EOF is hit right away
   inFile >> hold;
   endflag = (hold[0] == '\0')?true:false;
   
   //will run through the file untill eof is hit
   while (endflag == false)
   {
      if (strcmp(hold, all) == 0)
      {
         sortByName();
         print();
      } else if (strcmp(hold, spec) == 0)
         handleSpec(inFile, hold); 
	 
      else if (strcmp(hold, numb) == 0)
         handleNum(inFile, hold);
	 
      else
         endflag = true;
	 
      inFile >> hold;
   }
   
   inFile.close();
}

/*
Function: findProviderSpec, ProviderDB class

Use: Finds all Providers with a given Specialization and
     changes output based on weather or not a Provider with
     the given Specialization is found

Parameters: a pointer to a constant character

Returns: nothing
*/

void ProviderDB::findProviderSpec(const char* specSearch)
{
   int same; 
   bool anyOutP = false;
   for (int i = 0; i < pObjInArray; i++)
   {
      same = strcmp(pArray[i].getSpec(), specSearch);
      if (same == 0)
      {
         if (anyOutP == false)
	 {
	    cout << "Here is a list of Providers with " 
	         << specSearch << " as their Specialization\n";
	 }
         pArray[i].print();
	 anyOutP = true;
      }
   }
   if (anyOutP == false)
   {
      cout << "Unable to find a Provider with " << specSearch 
           << " as their Specialization...\n";
   }
}

/*
Function: searchForProNum, ProviderDB class

Use: Finds a provider with a given provider number
     passed into the function

Parameters: a pointer to a constant character

Returns: the index of the requested Provider that is in pArray
         or -1 if it cannot find the requested provider
*/

int ProviderDB::searchForProNum(const char* numSearch)
{
   int foundval = -1, low = 0, 
       high = pObjInArray-1, mid,
       checkval;
   while (low <= high)
   {
      mid = (low+high)/2;
      checkval = strcmp(pArray[mid].getProNum(), numSearch);
      
      if (checkval == 0)
      {
         foundval = mid;
	 low = pObjInArray;
      }
      
      if (checkval > 0)
      {
         high = mid - 1;
      } else if (checkval < 0)
      {
         low = mid + 1;
      }
   }
   
   return foundval;
}

/*
Function: handleNum, ProviderDB class

Use: will handle a request to search pArray for a given Provider
     number

Parameters: a filestream and a character array with a size of 41
            holding a provider number to be searched for in pArray

Returns:nothing
*/

void ProviderDB::handleNum(ifstream& inFile, char hold[41])
{
   int proNIndex;
   inFile >> hold;
   sortByProNum();
   proNIndex = searchForProNum(hold);
   
   if (proNIndex == -1)
   {
      cout << "The Provider with the number: " << hold
           << " Cannot be found!\n";
   } else
   {
      cout << "The Provider with the number: " << hold
           << " was found!\nHere is some information:\n";
      pArray[proNIndex].print();
   }
}

/*
Function: handleSpec, ProviderDB class

Use: will handle a request to search pArray for a given Provider
     Specialization

Parameters: a filestream and a character array with a size of 41
            holding a provider Specialization to be searched for 
	    in pArray

Returns:nothing
*/

void ProviderDB::handleSpec(ifstream& inFile, char hold[41])
{
   inFile >> ws;
   inFile.getline(hold, 40);
   sortBySpec();
   findProviderSpec(hold);
}
