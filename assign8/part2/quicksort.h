#ifndef QUICKSORT_H
#define QUICKSORT_H
using namespace std;

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));

template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));




template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
   quickSort(set, 0, set.size()-1, compare);
}

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
