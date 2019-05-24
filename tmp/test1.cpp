#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int startf(char[]);
int main()
{
   char ch;
   char * testr = &ch;
   *testr = 'c';
   cout << testr << endl;
   cout << *testr << endl;
   return 0;
}

int startf(char a[])
{
   int count = 0;
   for (int i = 0; a[i] != '\0'; i++)
      (isdigit(a[i]))?count++:0;
   return count;
}
