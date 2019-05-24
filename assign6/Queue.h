/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-241      Assignment #: 6    Semester: Fall2017  ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
||                                                               ||
||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
||                                                               ||
||  Due: Tuesday 11/9/2017 by 11:59PM                            ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||     This class will imitate the real Queue class in the       ||
||     C standard library. This is the file that not only        ||
||     holds the method prototypes, but also the definitions.    ||
||     this is due to the fact that this is a template class.    ||
||     the template class Queue will allow for insertions via    ||
||     push, deletions via pop, as well as a circular Queue      ||
||     method of storage. LHO and RHO stand for Left/Right       ||
||     hand operand.                                             ||
 \_______________________________________________________________/
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

//class prototype
template <class T>
class Queue;

//Prototyping insertion operator for ostream and Queue
template <class T>
ostream& operator<<(ostream&, const Queue<T>&);


/*
Class: Queue

Use: A template class used to hold a varable type of choice using
     a circular queue ADT. Will also keep track of the size and
     Capacity of the queue as well as the "first" and "last" 
     element.
*/

template <class T>
class Queue
{
   //friend for allowing insertions
   friend ostream& operator<< <>(ostream&, const Queue<T>&);

   private:
   
      //pointer to an item of the template parameter type
      T* qArr;
      
      //queue cap (max numb of elements) Size_t
      size_t qCap;
      
      //queue size (current numb of elements) Size_t
      size_t qSize;
      
      //qfront (queue front subscript)
      int qFront;
      
      //qback (queue back subscript)
      int qBack;
      
   public:
      //constuctor and deconstuctors
      Queue();
      Queue(const Queue& other);
      ~Queue();
      
      //method operators
      Queue<T>& operator=(const Queue<T> other);
      
      //regular acessor and manipulator methods
      void clear();
      size_t size() const;
      size_t capacity() const;
      bool empty() const;
      const T& front() const;
      const T& back() const;
      void push(T& val);
      void pop();
      void reserve(size_t n);
   
   

};

/*
Constructor: Queue

Use: Sets size_t variables to 0
     Sets qBack to qCap-1
     sets qArr to nullptr

Parameters: none

*/

template <class T>
Queue<T>::Queue()
{
   qSize = 0;
   qCap = 0;
   qArr = nullptr;
   qFront = 0;
   qBack = qCap-1;
}

/*
Constructor: Queue

Use: Copy constructor

Parameters: a Queue object

*/

template <class T>
Queue<T>::Queue(const Queue& other)
{
   qSize = other.qSize;
   qCap = other.qCap;
   
   if (qCap == 0)
      qArr = nullptr;
   else
      qArr = new T[qCap];
      
   for (size_t i = 0; i < qCap; i++)
      qArr[i] = other.qArr[(other.qFront + i) % (qCap)];
   
   qFront = 0;
   qBack = qSize-1;
   
}

/*
Deconstructor: Queue

Use: deletes the dynamic member of the Queue template class 
     when called

Parameters: none

*/

template <class T>
Queue<T>::~Queue()
{
   delete[] qArr;
}

/*
Operator: << 

Use: overloads the insertion operators when the parameters match

Parameters: LHO: an ostream such as cout 
            RHO: the Queue Object needing to be outputted

Returns: The LHO
*/

template <class T>
ostream& operator<<(ostream& lhs, const Queue<T>& rhs)
{
   if (rhs.qCap != 0)
      for (size_t i = 0; i < rhs.qSize; i++)
         lhs << rhs.qArr[(rhs.qFront + i) % (rhs.qCap)] << ' ';
	 
   return lhs;
}

/*
Operator: =

Use: Assigns the RHO to the LHO

Parameters: LHO/RHO are Queue Objects only.

*/

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T> other)
{
   if (qArr != other.qArr)
   {
      qCap = other.qCap;
      qSize = other.qSize;
      
      if (qCap == 0)
         qArr = nullptr;
      else
         qArr = new T[qCap];
	 
      for (size_t i = 0; i < qCap; i++)
         qArr[i] = other.qArr[(other.qFront + i) % (qCap)];
	 
      qFront = 0;
      qBack = qSize-1;
   }
   
   return *this;
}

/*
Function: clear, Queue class

Use: clears the Queue

Parameters: none

Returns: nothing

*/

template <class T>
void Queue<T>::clear()
{
   qSize = 0;
   qFront = 0;
   qBack = -1;
}

/*
Function: size, Queue class

Use: returns the size of the Queue

Parameters: none

Returns: Size of the Queue
*/

template <class T>
size_t Queue<T>::size() const
{
   return qSize;
}

/*
Function: capacity, Queue class

Use: returns the Queue capacity

Parameters: none

Returns: The Queue capacity
*/

template <class T>
size_t Queue<T>::capacity() const
{
   return qCap;
}

/*
Function: empty, queue class

Use: Checks to see if the queue size is zero

Parameters: none

Returns: true if the queue is empty, false if not empty
*/

template <class T>
bool Queue<T>::empty() const
{
   return (qSize == 0) ? true : false; 
}

/*
Function: front, Queue class

Use: returns the element at the Beginning of the Queue

Parameters: None

Returns: The element at the Beginning of the Queue
*/

template <class T>
const T& Queue<T>::front() const
{
   if (empty() == true)
      throw underflow_error("Queue underflow on front()");
   
   return qArr[qFront];
}

/*
Function: back, Queue class

Use: returns the element at the end of the Queue

Parameters: None

Returns: The element at the end of the Queue
*/

template <class T>
const T& Queue<T>::back() const
{
   if (empty() == true)
      throw underflow_error("Queue underflow on back()");
   
   return qArr[qBack];  
}

/*
Function: push, Queue class

Use: This function will call the Reserve function if the Queue has
     reached max capacity. It will then push the requested value to
     the end of the queue

Parameters: A value to be pushed to the end of the queue

Returns: nothing
*/

template <class T>
void Queue<T>::push(T& val)
{
   if (qSize == qCap)
   {
      if (qCap == 0)
         reserve(1);
      else
         reserve(qCap * 2);
   }
   qBack = (qBack + 1) % (qCap);
   qArr[qBack] = val;
   qSize++;
}

/*
Function: pop, Queue class

Use: 'deletes' an element at the beggining of the queue

Parameters: None

Returns: nothing
*/

template <class T>
void Queue<T>::pop()
{
   if (empty() == true)
   {
      throw underflow_error("Queue underflow on pop()");
   } else
   {
      qFront = (qFront+1) % (qCap); 
      qSize--;
   }
}

/*
Function: reserve, Queue class

Use: If the Queue has reached its max capacity, then this function
     will dynamically re-allocate space for a larger Queue

Parameters: the size of the new Queue

Returns: nothing
*/

template <class T>
void Queue<T>::reserve(size_t n)
{
   if (n > qCap)
   {
      T * tempPtr;
      
      tempPtr = new T[n];
      
      
      for (size_t i = 0; i < qCap; i++)
         tempPtr[i] = qArr[(qFront + i) % (qCap)];
	 
      qSize = qCap;
      qCap = n;
      
      if (qSize == 0)
         qBack = 0;
      else
         qBack = qSize-1;
	 
      qFront = 0;
      delete[] qArr;
      qArr = tempPtr;
   }
}

#endif
