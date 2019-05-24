//*************************************************************
// CSCI 241 - Student Class Example
//
// Progammer: Kurt McMahon
//
// Purpose: This program reads a series of student records from
// a file into an array of Student objects. The objects are
// printed, sorted by name, and then printed again.
//*************************************************************


//getline can be used to get upto a delim (a caractor to stop at)
//this will be used sicne the .cvs file has commas instead of spaces
//getline with string will be c++ strings and getline with isteam will
// be c string

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::setprecision;
using std::string;

// Student class declaration
class Student
   {
   private:
   
      char name[31];
      double gpa;
      
   public:

      // Constructors
      Student();
      Student(const char*, double);
      
      // Accessor methods   
      void setName(const char*);
      const char* getName();
      void setGPA(double);
      double getGPA();
      void print();
   };

// Function prototypes
int buildStudentArray(Student[]);
void printStudentArray(Student[], int); 
void sortStudentArray(Student[], int);

int main()
   {
   Student studentArray[10];
   int count;
  
   count = buildStudentArray(studentArray);

   cout << "Unsorted List of Students\n\n";
   
   printStudentArray(studentArray, count);

   sortStudentArray(studentArray, count);

   cout << "\nSorted List of Students\n\n";

   printStudentArray(studentArray, count);
   
   return 0;
   }

int buildStudentArray(Student studentArray[])
   {
   ifstream inFile;
   string firstName, lastName, name;
   double gpa;
   int count = 0;
   
   // Open the input file and test for failure
   inFile.open("students1.txt");
   if (!inFile)
      {
      cerr << "Error - unable to open input file\n";
      exit(1);
      }
      
   inFile >> firstName;
   while (inFile)
      {
      inFile >> lastName;
      inFile >> gpa;

      name = lastName + ", " + firstName;
          
      // Can do these two lines to put student in array
      Student newStudent(name.c_str(), gpa);
      
      studentArray[count] = newStudent;
      
      /* Could do these lines instead
      
      studentArray[count].setName(name.c_str());
      studentArray[count].setGPA(gpa); */
      
      count++;      

      inFile >> firstName;
      }

   inFile.close();
   
   return count;
   }

void printStudentArray(Student studentArray[], int size)
   {
   int i;
   cout << fixed << setprecision(2);
   
   for (i = 0; i < size; i++)
      {
      studentArray[i].print();
      cout << endl;
      }
   }

void sortStudentArray(Student studentArray[], int size)
   {
   int i, j, min;
   Student temp;
   
   for (i = 0; i < size - 1; i++)
      {
      min = i;
      
      for (j = i+1; j < size; j++)
         {
         if (strcmp(studentArray[j].getName(), studentArray[min].getName()) < 0)
            min = j;
         }
         
      temp = studentArray[i];
      studentArray[i] = studentArray[min];
      studentArray[min] = temp;
      }
   }

// Student constructors
Student::Student()
   {
   setName("None");
   setGPA(0.0);
   }
   
Student::Student(const char* newName, double newGPA)
   {
   setName(newName);
   setGPA(newGPA);
   }
   
// Student accessor methods   
void Student::setName(const char* newName)
   {
   strcpy(name, newName);
   }      

const char* Student::getName()
   {
   return name;
   }

void Student::setGPA(double newGPA)
   {
   if (newGPA < 0.0)
      gpa = 0.0;
   else if (newGPA > 4.0)
      gpa = 4.0;
   else
      gpa = newGPA;
   }      

double Student::getGPA()
   {
   return gpa;
   }

void Student::print()
   {
   cout << "Name: " << name << endl
        << "GPA: " << fixed << setprecision(2) << gpa << endl;
   }
