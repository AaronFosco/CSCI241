/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-241      Assignment #: 8    Semester: Fall2017  ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 2          ||
||                                                               ||
||  TA's Name: Mohammed Abdul Hafeez Khan                        ||
||                                                               ||
||  Due: Wedneday 11/29/2017 by 11:59PM                          ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||     This header file contains functions used to perform the   ||
||     merge sort algorithm on a vector containing varables of   ||
||     template datatype T.                                      ||
 \_______________________________________________________________/
*/

#ifndef MERGESORT_H
#define MERGESORT_H
using namespace std;

//function prototypes

template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&));

template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&));

template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&));


/*
Function: mergeSort

Use: initial call of the merge sort algorithm, This will call the
     recursive mergeSort function
     
Parameters: set: a vector of varables of the template data type T

            compare: a pointer to a function that has two parameters
	    of a refrence to the template data type T and returns a
	    bool. This will either be the greaterThan or lessThan
	    function.
	    
Returns: Nothing
*/

template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
   mergeSort(set, 0, set.size()-1, compare);
}

/*
Function: mergeSort

Use: the recersive call to the mergeSort Function that will 
     continuosly split the vector 'set' into many smaller subvectors
     and then call the merge function to combine the split vectors.
     
Parameters: set: a vector of varables of the template data type T

            low: the start or 'low' position of a vector or 
	    sub-vector.
	    
	    high: the end or 'high' position of a vector or 
	    sub-vecot
	    
            compare: a pointer to a function that has two parameters
	    of a refrence to the template data type T and returns a
	    bool. This will either be the greaterThan or lessThan
	    function.
	    
Returns: Nothing
*/

template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
  int mid;
   
   if (low < high)
   {
      mid = (low + high) / 2;
      
      mergeSort(set, low, mid, compare);
      mergeSort(set, mid+1, high, compare);
      merge(set, low, mid, high, compare);
   }
}

/*
Function: merge

Use: will merge together two sub-vectors into a greater vector of
     sorted elements from both vectors.

Parameters: set: a vector of varables of the template data type T

            low: an int that is the index for the start or 'low'
	    of a subvector
	    
	    mid: an int that is the midpoint between two seperate 
	    sub-vectors. This is formerly known as the high of the 
	    first subvector, or the low of the second subvector.
	    
	    high: an int that is the index for the end or the 'high'
	    of a subvector
	    
            compare: a pointer to a function that has two parameters
	    of a refrence to the template data type T and returns a
	    bool. This will either be the greaterThan or lessThan
	    function.

Returns: Nothing
*/

template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
   vector<T> temp(high - low + 1);

   int i = low;
   int j = mid+1;
   int k = 0;

   while (i <= mid && j <= high)
   {
      if (compare(set[j], set[i]))
      {
	 temp[k] = set[j];
         j++;
         k++;
      }else
      {
	 temp[k] = set[i];
         i++;
         k++;
      }
   }

   while (i <= mid)
   {
      temp[k] = set[i];
      i++;
      k++;
   }

   while (j <= high)
   {
      temp[k] = set[j];
      j++;
      k++;
   }

   for (i = 0, j = low; j <= high; i++, j++)
      set[j] = temp[i];     
}

#endif
