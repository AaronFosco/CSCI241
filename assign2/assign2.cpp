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
||     This is a simple Main routine that creates a new          ||
||     ProviderDB object and prints data from the object.        ||
||     Further documentation is in the makefile.
 \_______________________________________________________________/
*/

#include <iostream>
#include "ProviderDB.h"
using namespace std;
int main()
{
   ProviderDB pdb("providerdb");
   pdb.print();
   
   //extra spacing to make sorted data more distinguishable
   
   cout << endl << endl << endl
        << "Sorted By Provider Number" << endl;
   pdb.sortByProNum();
   pdb.print();
   
   //extra spacing to make sorted data more distinguishable
   
   cout << endl << endl << endl
        << "Sorted By Provider Specilization" << endl;
   pdb.sortBySpec();
   pdb.print();
   
   //extra spacing to make sorted data more distinguishable
   
   cout << endl << endl << endl
        << "Sorted By Provider Name" << endl;
   pdb.sortByName();
   pdb.print();
   return 0;
}
