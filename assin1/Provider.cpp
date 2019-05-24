/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-241      Assignment #: 1    Semester: Fall2017  ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
||                                                               ||
||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
||                                                               ||
||  Due: Thursday 9/14/2017 by 11:59PM                           ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||     This program will take input from a file in the same      ||
||     directory and output the information in formated style.   ||
||     The input file must be named "providers.csv" and contain  ||
||     12 sets of data seperated by commas.                      || 
 \_______________________________________________________________/
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;


/*
Class: Provider

Use: Contains data for providers such as name, adress, phone, etc,
     as well as Constuctors and a function to print out said data.
*/
class Provider 
{
   private:
      //Char arrays with +1 space for null char
      char name[41];
      char pronum[7];
      char spec[41];
      char adress1[41];
      char adress2[31];
      char city [21];
      char state[3];
      char zipc[6];
      char phonenum[15];
   public:
      //Constuctors
      Provider();
      Provider(string& tname, 
               string& tpronum, 
	       string& tspec,
               string& tadress1, 
	       string& tadress2, 
	       string& tcity,
	       string& tstate, 
	       string& tzpic, 
	       string& tphonenum);
      //print function; Essentially the Get functions for each
      //data member
      void print();
};

// Function prototypes.
int buildProviderArray(Provider[]);
void printProviderArray(Provider[], int);

/*
Fucntion: main

Use: creates an array of "Providers" and excutes two 
     functions to build the array from a file & print
     out all the contents
     
Parameters: none

Returns: 0 if sucessful
*/

int main()
{
   Provider pArray[40];
   int size;
   size = buildProviderArray(pArray);
   printProviderArray(pArray, size);
   return 0;
}

/*
Function: buildProviderArray

Use: creates a ifstream and opns a file named "providers1.csv"
     it then extracts each part of data that is seperated by a
     comma, except for the last two pieces that have a whitespace,
     and stores the extracted data into the provided array.

Parameters: givePArray:A given array of Providers
     
Returns: ammount of spaces in the given array of Providers that
         have been filled
*/
int buildProviderArray(Provider givePArray[])
{
   ifstream inFile;
   string firstNames, 
          lastNames, 
	  midNames,
	  titles,
	  fullNames,
	  pronums,
	  specs,
	  adress1s,
	  adress2s,
	  citys,
	  states,
	  zipcs,
	  phonenum1s,
	  phonenum2s;
	  
   int count = 0;
   inFile.open("providers1.csv");
    
   if (!inFile) //Escape incase file dosn't exsist
   {
      cerr << "Error - unable to open input file\n";
      exit(1);
   }
   
   //inital getline to see if EOF will be hit immediatly
   getline(inFile, pronums, ',');
   
   while (!inFile.eof()) //Start of extraction
  {
      getline(inFile, specs, ',');
      getline(inFile, lastNames, ',');
      getline(inFile, firstNames, ',');
      getline(inFile, midNames, ',');
      getline(inFile, titles, ',');
      
      //concatenation of all names including title
      fullNames = lastNames + ", " + firstNames +" "+ midNames 
                 + ", " + titles; 
		 
      getline(inFile, adress1s, ',');
      getline(inFile, adress2s, ',');
      getline(inFile, citys, ',');
      getline(inFile, states, ',');
      getline(inFile, zipcs, ',');
      
      //Phone numbers have the area code + actual number 
      //They are seperated by spaces so >> is used here
      inFile >> phonenum1s;
      inFile >> phonenum2s;
      phonenum1s += phonenum2s; //cat of phone #
      
      //constucting new Provider by extracted data to be placed
      //into the given array
      Provider hold(fullNames,
                    pronums, 
                    specs, 
		    adress1s, 
		    adress2s, 
                    citys, 
		    states, 
		    zipcs, 
		    phonenum1s);
      givePArray[count] = hold;
      
      count++;
      inFile.ignore(1, '\0'); //ignore the 'return' space
      getline(inFile, pronums, ',');
  }    
  
   inFile.close();
   return count;
}

/*
Function: printProviderArray

Uses: calls the Provider print function for every piece of data
      in the given provider array

Parameters: 1) givePArray: Given array of Provider
            2) givecount: Given count of used spaces in Given 
	       array of provider

Returns: nothing
*/
void printProviderArray(Provider givePArray[], int givecount)
{
   for (int i = 0; i < givecount; i++)
      givePArray[i].print();
}

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
Function: Second Constuctor for Provider class

Uses: This will except multiple strings by refrence as parameters
      and copy them into each avalable Data members
      
Parameters: 1) tname: temporary holder for the name 
            2) tpronum: temporary holder for the provider num
	    3) tspec: temporary holder for the Specialty
	    4) tadress1: temporary holder for the 1st part of
	                 the address
	    5) tadress2: temporary holder for the 2nd part of
	                 the address
	    6) tcity: temporary holder for the city
	    7) tstate: temporary holder for the state
	    8) tzipc: temporary holder for the zip code
	    9) tphonenum: temporary holder for the phone num
Returns: nothing
*/
Provider::Provider(string& tname, 
                   string& tpronum, 
		   string& tspec,
                   string& tadress1, 
		   string& tadress2, 
		   string& tcity,
	           string& tstate, 
		   string& tzipc, 
		   string& tphonenum)
{
   strcpy(name, tname.c_str());
   strcpy(pronum, tpronum.c_str());
   strcpy(spec, tspec.c_str());
   strcpy(adress1, tadress1.c_str());
   strcpy(adress2, tadress2.c_str());
   strcpy(city, tcity.c_str());
   strcpy(state, tstate.c_str());
   strcpy(zipc, tzipc.c_str());
   strcpy(phonenum, tphonenum.c_str());
}
/*
Function: print

Use: Prints out each data member of this Provder class. This 
     Will add an extra endl to the end of the function to
     facilitate repeated calls to this function.

Parameters: none

Returns: nothing
*/
void Provider::print()
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


