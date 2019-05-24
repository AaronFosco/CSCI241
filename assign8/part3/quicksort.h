/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-241      Assignment #: 9    Semester: Fall2017  ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
||                                                               ||
||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
||                                                               ||
||  Due: Wedneday 11/29/2017 by 11:59PM                          ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||      This header file contains functions used to perform the  ||
||      quick sort algorithm on a vector containing varables of  ||
||      template datatype T.                                     ||
 \_______________________________________________________________/
*/

#ifndef QUICKSORT_H
#define QUICKSORT_H
using namespace std;

//function prototypes

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));

template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));



/*
Function: quickSort

Use: initial call of the quick sort algorithm, This will call the
     recursive qickSort function
     
Parameters: set: a vector of varables of the template data type T

            compare: a pointer to a function that has two parameters
	    of a refrence to the template data type T and returns a
	    bool. This will either be the greaterThan or lessThan
	    function.
	    
Returns: Nothing
*/

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
   quickSort(set, 0, set.size()-1, compare);
}

/*
Function: quickSort

Use: The recursive call to the quicksort function that will call
     the partition function until it hits the end of 'set' which 
     will happen when the pivot point for the start and the end is
     the same.
     
Parameters: set: a vector of varables of the template data type T

            start: an int that is the start of the list or partition
	    
	    end: an int that is the end of the list or partition
	    
            compare: a pointer to a function that has two parameters
	    of a refrence to the template data type T and returns a
	    bool. This will either be the greaterThan or lessThan
	    function.
	    
Returns: Nothing
*/

template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
   int pivotPoint;

   if (start < end)
   {
      pivotPoint = partition(set, start, end, compare);
      quickSort(set, start, pivotPoint - 1, compare);
      quickSort(set, pivotPoint + 1, end, compare);
   }
}

/*
Function: partition

Use: will sort a partition that is created by the recursive quick
     sort function

Parameters: set: a vector of varables of the template data type T

            start: an int that is the start of the list or partition
	    
	    end: an int that is the end of the list or partition
	    
            compare: a pointer to a function that has two parameters
	    of a refrence to the template data type T and returns a
	    bool. This will either be the greaterThan or lessThan
	    function.

Returns: an int that serves as the pivot point for the quicksort 
         function
*/

template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{


   int pivotIndex, mid;
   T pivotValue, hold;
   
   mid = (start + end) / 2;

   hold = set[start];
   set[start] = set[mid];
   set[mid] = hold;
 
   pivotIndex = start;
   pivotValue = set[start];
 
   for (int scan = start + 1; scan <= end; scan++)
   {
      if (compare(set[scan], pivotValue))
      {
         pivotIndex++;
	 
	 hold = set[pivotIndex];
	 set[pivotIndex] = set[scan];
	 set[scan] = hold;
      }
   }

   hold = set[start];
   set[start] = set[pivotIndex];
   set[pivotIndex] = hold;

   return pivotIndex;
}

#endif
