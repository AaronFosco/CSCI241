#include <iostream>

using namespace std;

class BaseClass
   {
   private:

      int y;
   
   public:
   
      BaseClass(int y)
         {
         this->y = y;
  
         cout << "BaseClass object created with y = " << this->y << "\n";
         }
	  
      ~BaseClass()
         {
         cout << "BaseClass destructor with y = " << y << "\n";
         }
   };

class DerivedClass : public BaseClass
   {
   private:

      int x;

   public:
   
      DerivedClass(int x, int y) : BaseClass(y)
         {
         this->x = x;
	  
         cout << "DerivedClass object created with x = " << this->x << "\n";
         }
  
      ~DerivedClass()
         {
         cout << "DerivedClass destructor\n";
         }
   };

int main()
   {
   cout << "Creating BaseClass object\n\n";
   
   BaseClass b1(10);

   cout << "\nCreating DerivedClass object\n\n";
   
   DerivedClass d1(5, 7);

   cout << "\nProgram ending\n";

   return 0;
   }   
