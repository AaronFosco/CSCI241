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
||     This file is named ProviderDB.h, it will declare the      ||
||     Class definitions for later implimentation.               ||
 \_______________________________________________________________/
*/

#ifndef PROVIDERDB_H
#define PROVIDERDB_H
#include "Provider.h"
#include <fstream>

/*
Class: ProviderDB

Use: Contains data members for storing information
     from a DB file, As well as displaying said data members
     
*/

class ProviderDB
{
   private:
      Provider pArray[40];
      int pObjInArray;
   public:
   
      //constructors
      
      ProviderDB();
      ProviderDB(const char*);
      
      //Prints everything in pArray using
      //Provider's Print command
      
      void print();
      
      //sort methods
   
      void sortByProNum();
      void sortBySpec();
      void sortByName();
      
      //other methods
      
      void processTransactions(const char*);
      
      //search methods
      
      void findProviderSpec(const char*);
      int searchForProNum(const char*);
      
      //splitting methods
      
      void handleNum(std::ifstream&, char*);
      void handleSpec(std::ifstream&, char*);
};

#endif
