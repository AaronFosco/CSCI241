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
||     C standard library. This class allows for storages of     ||
||     intergers in a Stack ADT type format. This will allow     ||
||     for deletions, insertions, dynamic memory allocation      ||
||     as well as operator overloading for assignment, ostream   ||
||     insertions, compairson, and subsript operations. For      ||
||     operator overloading comments, LHO and RHO stand for      ||
||     Left/Right hand operand.                                  ||
 \_______________________________________________________________/
*/

#include "Stack.h"
#include <iostream>
using namespace std;

/*
Constructor: Stack

Use: Sets unsigned ints to 0
     sets stkArPtr to nullptr

Parameters: none

*/

Stack::Stack()
{
   stkSize = 0;
   stkCap = 0;
   stkArPtr = nullptr;
}

/*
Deconstructor: Stack

Use: deletes the dynamic member of the stack class when called

Parameters: none

*/

Stack::~Stack()
{
   delete[] stkArPtr;
}

/*
Constructor: Stack

Use: Copy constuctor

Parameters: Stack Object

*/

Stack::Stack(const Stack& other) 
{
   stkCap = other.stkCap;
   stkSize = other.stkSize;
   
   if (stkCap == 0)
      stkArPtr = nullptr;
   else
      stkArPtr = new int[stkCap];
      
   for (unsigned int i = 0; i < stkSize; ++i)
      stkArPtr[i] = other.stkArPtr[i];
}

/*
Operator: =

Use: Assigns the RHO to the LHO

Parameters: LHO/RHO are Stack Objects only.

*/

Stack& Stack::operator=(const Stack& other)
{
   if (stkArPtr != other.stkArPtr)
   {
      stkCap = other.stkCap;
      stkSize = other.stkSize;
   
      if (stkCap == 0)
         stkArPtr = nullptr;
      else
         stkArPtr = new int[stkCap];
      
      for (unsigned int i = 0; i < stkSize; ++i)
         stkArPtr[i] = other.stkArPtr[i];
   }
      
   return *this;
}

/*
Operator: << 

Use: overloads the insertion operators when the parameters match

Parameters: LHO: an ostream such as cout 
            RHO: the Stack Object needing to be outputted

Returns: The LHO
*/

ostream& operator<<(ostream& lhs, const Stack& rhs)
{
   if (rhs.stkCap != 0)
      for (unsigned int i = 0; i < rhs.stkSize; ++i)
         lhs << rhs.stkArPtr[i] << ' ';
   
   return lhs;
}

/*
Function: clear, Stack class

Use: clears the stack

Parameters: none

Returns: nothing

*/

void Stack::clear()
{
   stkSize = 0;
}

/*
Function: size, Stack class

Use: returns the size of the stack

Parameters: none

Returns: Size of the stack
*/

size_t Stack::size() const
{
   return stkSize;
}

/*
Function: capacity, Stack class

Use: returns the stack capacity

Parameters: none

Returns: The stack capacity
*/

size_t Stack::capacity() const
{
   return stkCap;
}

/*
Function: empty, Stack class

Use: Checks to see if the stack size is zero

Parameters: none

Returns: true if the stack is empty, false if not empty
*/

bool Stack::empty() const
{
   return (stkSize == 0)? true : false;
}

/*
Function: top, Stack class

Use: returns the element at the top of the stack

Parameters: None

Returns: The element at the top of the stack
*/

int Stack::top() const
{
   return stkArPtr[stkSize-1];
}

/*
Function: push, Stack class

Use: This function will call the Reserve function if the stack has
     reached max capacity. It will then push an int to the top of 
     the stack.

Parameters: An int to be pushed to the top of the stack

Returns: nothing
*/

void Stack::push(int val)
{
   if (stkSize == stkCap)
   {
      if (stkCap == 0)
         reserve(1);
      else
         reserve (stkCap * 2); 
   }
   
   stkArPtr[stkSize] = val;
   stkSize++;
}

/*
Function: pop, Stack class

Use: 'deletes' an element at the top of the stack

Parameters: None

Returns: nothing
*/

void Stack::pop()
{
   stkSize--;
}

/*
Function: reserve, Stack class

Use: If the stack has reached its max capacity, then this function
     will dynamically re-allocate space for a larger stack

Parameters: the size of the new stack

Returns: nothing
*/

void Stack::reserve(size_t n)
{
   if (n > stkCap)
   {
      stkCap = n;
      int * tempPtr;
      /*
      in the steps, it said:
      If the stack capacity is 0, 
      set the temporary array pointer to nullptr.
      
      this comes after:
      Set the stack capacity to n.
      
      the only case where stkCap will = 0 after being set to n
      is when stkCap was originally less than zero, which is not
      possible for size_t or unsigned int...
      
      The code is added in anyways with an if statement
      */
      if (stkCap != 0)
      {
         tempPtr = new int[n];
	 
	 for (unsigned int i = 0; i < stkSize; i++)
	    tempPtr[i] = stkArPtr[i];
	    
	 stkCap = n;
	 delete[] stkArPtr;
	 stkArPtr = tempPtr;
	 
      } else
         stkArPtr = nullptr; 

   }  
}

/*
Operator: []

Use: Gets the int at requested position n

Parameters: the requested position in the stack

Return: the int that is at the requested position in the stack
*/

int Stack::operator[](size_t n) const // "get"
{
   return stkArPtr[n];
}

/*
Operator: [] 

Use: gets the pointer to the requested position in the stack 
     in order to set that requested position to somthing else

Parameters: requested postition

Returns: a pointer to the requested postion n in the stack
*/

int& Stack::operator[](size_t n) // "set"
{
   return stkArPtr[n];
}

/*
Operator: ==

Use: compairson between two stack objects

Parameters: LHO/RHO: Stack object

Returns: true if the objects are the same, false otherwise
*/

bool Stack::operator==(const Stack& rhs) const
{
   bool samerv = false;
   if (stkSize == rhs.stkSize)
   {
      samerv = true;
      for (unsigned int i = 0; i < stkSize && samerv != false; i++)
         samerv = (stkArPtr[i] == rhs.stkArPtr[i]);
   }
   return samerv;
}
