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
||     This file is named Provider.h, it will declare the        ||
||     Class definitions for later implimentation.               ||
 \_______________________________________________________________/
*/

#ifndef PROVIDER_H
#define PROVIDER_H

/*
Class: Provider

Use: Contains data for providers such as name, adress, phone, etc,
     as well as Constuctors and a function to print out said data.
*/

class Provider 
{
   private:
   
      //Char arrays with +1 space for null char
      
      char pronum[7];
      char spec[41];
      char name[41];
      char adress1[41];
      char adress2[31];
      char city [21];
      char state[3];
      char zipc[6];
      char phonenum[15];
   public:
   
      //Constuctor
      
      Provider();
      
      //acessor method prototypes
      
      const char* getProNum();
      const char* getSpec();
      const char* getName();
      
      //print function; Essentially the Get functions for each
      //data member
      
      void print() const;
      
};
#endif
