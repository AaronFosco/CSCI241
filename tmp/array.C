#include <iostream>
using namespace std;
int main()
{
   int scores[6] = {85, 79, 100, 95, 68, 89};
   cout << &scores << endl << scores << endl;
   cout << scores+4 << endl << *(scores+4) << endl;
   return 0;
}
