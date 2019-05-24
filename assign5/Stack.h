/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-241      Assignment #: 5    Semester: Fall2017  ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
||                                                               ||
||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
||                                                               ||
||  Due: Tuesday 10/31/2017 by 11:59PM                           ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||     This class will imitate the real stack class in the       ||
||     C standard library. This is the file will declare the     ||
||     class methods and members for later implimentation        ||
 \_______________________________________________________________/
*/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstring>

using namespace std;

/*
Class: Stack

Use: Holds a dynamic array of intergers and tracks the sizes and 
    capacitys of the class object. Also contains ways to manipulate
    and view data in the array.
*/

class Stack
{
   //friend for allowing insertions
   friend ostream& operator<<(ostream& lhs, const Stack& rhs);
   
   //private data members
   private:
      
      int * stkArPtr;
      unsigned int stkCap;
      unsigned int stkSize;
      
   //public data methods
   public:
      
      //constuctor and deconstuctors
      Stack();
      ~Stack();
      Stack(const Stack& other);
      
      //method operators
      Stack& operator=(const Stack& other);
      int operator[](size_t n) const;
      int& operator[](size_t n);
      bool operator==(const Stack& rhs) const;
      
      
      //regular acessor and manipulator methods
      void clear();
      size_t size() const;
      size_t capacity() const;
      bool empty() const;
      int top() const;
      void push(int val);
      void pop();
      void reserve(size_t n);
};

#endif
