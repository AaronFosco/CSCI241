#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::left;
using std::setprecision;
using std::setw;
using std::string;
using std::vector;

// Data files

#define D1 "data1.txt"
#define D2 "data2.txt"
#define D3 "data3.txt"

// Output formatting constants

#define INT_SZ 4    // width of integer
#define FLT_SZ 7    // width of floating-pt number
#define STR_SZ 12   // width of string

#define INT_LN 15   // no of integers on single line
#define FLT_LN 9    // no of floating-pt nums on single line
#define STR_LN 5    // no of strings on single line

template <class T> void buildList(vector<T>&, const char*);
template <class T> void printList(const vector<T>&, int, int);
template <class T> void selectionSort(vector<T>&, bool (*)(const T&, const T&));
template <class T> bool lessThan(const T&, const T&);
template <class T> bool greaterThan(const T&, const T&);

int main()
   {
   vector<int> v1;
   vector<double> v2;
   vector<string> v3;
   
   // sort and print first list

   cout << "First list - ascending order:\n\n";
   buildList(v1, D1);
   selectionSort(v1, &lessThan);
   printList(v1, INT_SZ, INT_LN);

   v1.clear();
   
   cout << "\nFirst list - descending order:\n\n";
   buildList(v1, D1);
   selectionSort(v1, &greaterThan);
   printList(v1, INT_SZ, INT_LN);

   cout << "\nSecond list - ascending order:\n\n";
   buildList(v2, D2);
   selectionSort(v2, &lessThan);
   printList(v2, FLT_SZ, FLT_LN);

   v2.clear();
   
   cout << "\nSecond list - descending order:\n\n";
   buildList(v2, D2);
   selectionSort(v2, &greaterThan);
   printList(v2, FLT_SZ, FLT_LN);

   cout << left;
   
   cout << "\nThird list - ascending order:\n\n";
   buildList(v3, D3);
   selectionSort(v3, lessThan);
   printList(v3, STR_SZ, STR_LN);

   v3.clear();
   
   cout << "\nThird list - descending order:\n\n";
   buildList(v3, D3);
   selectionSort(v3, greaterThan);
   printList(v3, STR_SZ, STR_LN);

   return 0;
   }

template <class T>
void buildList(vector<T>& set, const char* fileName)
   {
   T item;
   ifstream inFile;

   inFile.open(fileName);
   if (!inFile)
      {
      cout << "Unable to open input file " << fileName << endl;
      exit(1);
      }

   inFile >> item;
   while (inFile)
      {
      set.push_back(item);
      
      inFile >> item;
      }

   inFile.close();
   }

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
   {
   int i = 0;
   while (i < (int) set.size())
      {
      cout << setw(itemWidth) << set[i] << ' ';
      i++;
      if (i % numPerLine == 0)
         cout << endl;
      }

   if (i % numPerLine != 0)
      cout << endl;
   }

template <class T>
void selectionSort(vector<T>& set, bool (*compare)(const T&, const T&))
   {
   int i, j, min;
   T temp;
 
   for (i = 0; i < (int)(set.size() - 1); i++)
      {
      min = i;

      for (j = i+1; j < (int) set.size(); j++)
         {
         if (compare(set[j], set[min]))
            min = j;
         }

      temp = set[min];
      set[min] = set[i];
      set[i] = temp;
      }
   }

template <class T>
bool lessThan(const T& a, const T& b)
   {
   return (a < b);
   }

template <class T>
bool greaterThan(const T& a, const T& b)
   {
   return (a > b);
   }

