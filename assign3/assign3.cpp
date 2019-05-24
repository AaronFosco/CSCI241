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
||     This is a simple Main routine that creates a new          ||
||     ProviderDB object and uses the function                   ||
||     "ProcessTransactions" from ProviderDB.                    ||
||     Further documentation is in the makefile.                 ||
 \_______________________________________________________________/
*/

#include <iostream>
#include "ProviderDB.h"
using namespace std;
int main()
{
   ProviderDB pdb("providerdb");
   pdb.processTransactions("transactions.txt");
   return 0;
}
