#include <iostream>
#include <iomanip>
#include <cstring>
#include "Employee.h"

using namespace std;

// Default Employee constructor
Employee::Employee()
{
   name[0] = '\0';
   salary = 0;
}

// TODO: Alternate Employee constructor
Employee::Employee(char tmpname[], double tmpsal)
{
   strcpy(name, tmpname);
   salary = tmpsal;
}

// TODO: getName() accessor method
const char* Employee::getName() const
{
   return name;
}
// TODO: setName() accessor method
void Employee::setName(char newName[])
{
   strcpy(name, newName);
}

// getSalary() accessor method
double Employee::getSalary() const
    {
    return salary;
    }

// setSalary() accessor method
void Employee::setSalary(double newSalary)
{
    salary = newSalary;
}

// TODO: print() method
void Employee::print()
{
   cout << "Name: " << name << endl
        << "Salary: $" << salary << endl;
}
