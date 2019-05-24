#include <iostream>
using namespace std;
int main()
{
   double pir = 3.14159;
   double* piptr = &pir;
   cout << *piptr << endl;
   cout << piptr << endl;
   cout << &pir << endl;
   return 0;
}
