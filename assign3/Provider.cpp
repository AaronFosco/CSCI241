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
||     This file is named Provider.cpp, it will hold the         ||
||     code for all methods provided in the class declaration,   ||
||     Provider.h.                                               ||
 \_______________________________________________________________/
*/

#include <string>
#include <cstring>
#include <iostream>
#include "Provider.h"

using namespace std;

//Default constructor for Provider class
//Will fill data members with "Blank"

Provider::Provider()
{
   strcpy(name, "Blank");
   strcpy(pronum, "Blank");
   strcpy(spec, "Blank");
   strcpy(adress1, "Blank");
   strcpy(adress2, "Blank");
   strcpy(city, "Blank");
   strcpy(state, "Blank"); 
   strcpy(zipc, "Blank");
   strcpy(phonenum, "Blank");
}

/*
Function: print

Use: Prints out each data member of this Provder class. This 
     Will add an extra endl to the end of the function to
     facilitate repeated calls to this function.

Parameters: none

Returns: nothing
*/

void Provider::print() const
{
   cout << '#' << pronum << endl
        << name << endl
        << spec << endl
        << adress1 << endl
        << adress2 << endl
	<< city << ", " << state 
	<< ' ' << zipc << endl
	<< phonenum << endl << endl;
}

/*
Function: getProNum

Use: gets Provider number pointer.

Parameters: none

Returns: The pointer to the Provider number array
*/

const char* Provider::getProNum()
{
   return pronum;
}

/*
Function: getSpec

Use: Gets the Specialization

Parameters: none

Returns: The pointer to the Specialization array
*/

const char* Provider::getSpec()
{
   return spec;
}

/*
Function: getName

Use: Gets the name

Parameters: none

Returns: The pointer to the name array
*/

const char* Provider::getName()
{
   return name;
}
