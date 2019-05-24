#ifndef SORTS_H
#define SORTS_H

#include <fstream>


using namespace std;

template <class T>
void buildList(vector<T>& set, const char* fileName);

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine);

template <class T>
void buildList(vector<T>& set, const char* fileName)
{
   T buffer;
   ifstream inFile;
	
   inFile.open(fileName);
   if (!inFile)
   {
      cerr << "File not found!\n";
      exit(1);
   }
	
   inFile >> buffer;
   while (inFile)
   { 
      set.push_back(buffer);
      
      inFile >> buffer;
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

#endif
