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
||     directory and output the information in formated style    ||
||     The input file must be named "providers.csv" and contain  ||
||     12 sets of data seperated by commas.                      || 
 \_______________________________________________________________/
*/
#ifndef PROVIDER_H
#define PROVIDER_H
Provider();
Provider(char* tname, char* tphonenum, char* tspec,
         char* tadress1, char* tadress2, char* tcity,
         char* tstate, char* tzpic, char* phonenum);
void print();
#endif
