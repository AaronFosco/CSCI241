#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::left;
using std::setprecision;
using std::setw;

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

int buildList(int[], const char*);
void printList(int[], int, int, int);
void selectionSort(int[], int);

int main()
   {
   int v1[100];
   
   // sort and print first list

   cout << "First list - ascending order:\n\n";
   int count = buildList(v1, D1);
   selectionSort(v1, count);
   printList(v1, count, INT_SZ, INT_LN);

   return 0;
   }

int buildList(int set[], const char* fileName)
   {
   int item, count = 0;
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
      set[count] = item;
      count++;
      
      inFile >> item;
      }

   inFile.close();
   
   return count;
   }

void printList(int set[], int count, int itemWidth, int numPerLine)
   {
   int i = 0;
   while (i < count)
      {
      cout << setw(itemWidth) << set[i] << ' ';
      i++;
      if (i % numPerLine == 0)
         cout << endl;
      }

   if (i % numPerLine != 0)
      cout << endl;
   }
   
void selectionSort(int set[], int count)
   {
   int i, j, min;
   int temp;
 
   for (i = 0; i < (count - 1); i++)
      {
      min = i;

      for (j = i+1; j < count; j++)
         {
         if (set[j] < set[min])
            min = j;
         }

      temp = set[min];
      set[min] = set[i];
      set[i] = temp;
      }
   }

