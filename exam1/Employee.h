#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
    {
    // Employee data members
    private:
       char name[31];
       double salary;   
    // Employee member function prototypes
    public:

       Employee();
       Employee(char[], double);

       const char* getName() const;
       double getSalary() const;

       void setName(char[]);
       void setSalary(double);
       
       void print();
    };

#endif
