/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-241      Assignment #: 7    Semester: Fall2017  ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
||                                                               ||
||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
||                                                               ||
||  Due: Thursday 11/16/2017 by 11:59PM                          ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||     The Class Stack in this header file will store data using ||
||     the Linked Stack ADT. This header file contains both the  ||
||     method prototypes and the method definitions for the      ||
||     Stack class as well as a struct to facilitate the linking ||
||     and holding of data. The template class Stack allows for  ||
||     insertions via push, deletions via pop, as well accessors ||
||     for inspecting various parts of the Stack. LHO and RHO    ||
||     stand for left/right hand operand.                        ||
 \_______________________________________________________________/
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>

using namespace std;

//class prototype
template <class T>
class Stack;

//Prototyping insertion operator for ostream and Stack
template <class T>
ostream& operator<<(ostream&, const Stack<T>&);

/*
Struct: Node

Use: A template struct used to hold a variable type of choice
     and a pointer to another node struct object. 
*/

template <class T>
struct Node
{
   public:
      //data members of this struct
      T data;
      Node<T>* next;
      
      //constructor with default arguments
      Node(const T& = T(), Node<T>* next = nullptr);
};

/*
Constructor: Node

Use: On default:
     Sets data to the return of default constuctor of the template
     parameter type used for T
     Sets next to nullptr
     
     When passed Parameters:
     sets data to nData
     sets next to nNext

Parameters: 1) a datatype of the template parameter type T
            2) A pointer to the next linked Node
             
*/

template <class T>
Node<T>::Node(const T& nData, Node<T>* nNext)
{
   data = nData;
   next = nNext;
}

/*
Class: Stack

Use: A template Class used to hold a varible type of choice using
     linked Stack ADT. The linking and holding of data will be 
     performed by the Struct 'Node'. In addition, This class will
     keep track of the ammount of elements in the linked Stack.
*/

template <class T>
class Stack
{
   //friend for allowing insertions
   friend ostream& operator<< <>(ostream&, const Stack<T>&);
   
   private:
      //pointer to a Node object with the template parameter type
      Node<T>* stkTop;
      
      //size of the stack
      size_t stkSize;
      
      //private method for copying another stack
      void copyList(const Stack<T>&);
      
   public:
   
      //constuctors and deconstuctor
      Stack();
      ~Stack();
      Stack(const Stack<T>&);
      
      //method operators
      Stack<T>& operator=(const Stack<T>&);
      
      //regular accessor and manipulator methods
      void clear();
      size_t size() const;
      bool empty() const;
      const T& top() const;
      void push(const T&);
      void pop();
      
};

/*
Operator: << 

Use: overloads the insertion operators when the parameters match

Parameters: LHO: an ostream such as cout 
            RHO: the Stack Object needing to be outputted

Returns: The LHO
*/

template<class T>
ostream& operator<<(ostream& lhs, const Stack<T>& rhs)
{
   if (rhs.stkSize != 0)
      for (Node<T>* ptr = rhs.stkTop;
           ptr != nullptr;
	   ptr = ptr->next)
         lhs << ptr->data << ' ';
	 
   return lhs;
}

/*
Operator: =

Use: Assigns the RHO to the LHO

Parameters: LHO/RHO are Stack Objects only.

*/

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
   if (this != &other)
   {
      clear();
      copyList(other);
      stkSize = other.stkSize;   
   }
   
   return *this;
}

/*
Constuctor: Stack

Use: Default
     Sets stkTop to nullptr
     sets stkSize to zero

Parameters: none
*/

template<class T>
Stack<T>::Stack()
{
   stkTop = nullptr;
   stkSize = 0;
}

/*
Deconstuctor: Stack

Use: Uses the clear() method to delete the dynamic memory of
     the Stack class when called

Parameters: None
*/

template<class T>
Stack<T>::~Stack()
{
   clear();
}

/*
Constructor: Stack

Use: Copy constuctor

Parameters: a Stack object with the of the Template parameter type
*/

template<class T>
Stack<T>::Stack(const Stack<T>& other) //copy
{
   stkTop = nullptr;
   copyList(other);
   stkSize = other.stkSize;
}

/*
Function: copyList, Stack class

Use: A private method used to copy/assign the contents of one stack
     object to another
     

Parameters: A constant refrence to a stack object 

returns: nothing

*/

template<class T>
void Stack<T>::copyList(const Stack<T>& other)
{
   Node<T> * nNode; 
   Node<T> * last = nullptr;
   for (Node<T>* ptr = other.stkTop; 
        ptr != nullptr; 
	ptr = ptr->next)
   {
      nNode = new Node<T>(ptr->data);
      if(last == nullptr)
         stkTop = nNode;
      else
         last->next = nNode;
	 
      last = nNode;
   }
}

/*
Function: clear, Stack class

Use: will continue to call the pop method untill the stack is empty

Parameters: none

Returns: nothing
*/
template<class T>
void Stack<T>::clear()
{
   while (stkSize != 0)
      pop();
}

/*
Function: size, stack class

Use: returns the ammount of elements in the stack

Parameters: none

Retuns: the stack size
*/

template<class T>
size_t Stack<T>::size() const
{
   return stkSize;
}

/*
Function: empty

Use: checks to see if the stack is empty

Parameters: none

Returns: true if the stack is empty, false otherwise

*/

template<class T>
bool Stack<T>::empty() const
{
   return (stkSize == 0) ? true : false;
}

/*
Function: top, stack class

Use: Will obtain the data held at the top of the stack

Parameters: none

Returns: The data of the template parameter type at the top of the
         stack
*/

template<class T>
const T& Stack<T>::top() const
{
   return stkTop->data;
}

/*
Function: push, stack class

Use: will put new data of the template paramter type at the top of
     the stack
     
Parameters: Data of the template parameter type

Returns: nothing
*/

template<class T>
void Stack<T>::push(const T& val)
{
   Node<T>* nNode = new Node<T>(val, stkTop);
   stkTop = nNode;
   stkSize++;  
}

/*
Function: pop, stack class

Use: will delete the top element in the stack and deallocate the
     node object
     
Parameters:none

Returns: nothing
*/

template<class T>
void Stack<T>::pop()
{
   Node<T>* hold = stkTop->next;
   delete stkTop;
   stkTop = hold;
   stkSize--;
}

#endif
