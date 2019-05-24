#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "Provider.h"

using namespace std;

int buildProviderArray(Provider[]);
void printProviderArray(Provider[], int);

int main()
{
   Provider pArray[40];
   int count;
   count = buildProviderArray(pArray);
   printProviderArray(pArray, count)
   
}

int buildProviderArray(Provider givePArray[])
{
   ifstream inFile;
   String firstName, 
          lastName, 
	  midName, 
	  fullName,
	  spec,
	  adress1,
	  adress2,
	  city,
	  state,
	  zipc,
	  phonenum;
   int count = 0;
   inFile.open("providers.csv");
   if (!inFile)
   {
      cerr << "Error - unable to open input file\n";
      exit(1);
   }
      
   inFile >> firstName;
   while (inFile)
  {
  }    

   inFile.close();
   return count;
}
	  
}

void printProviderArray(Provider givePArray[], int givecount)
{

}
