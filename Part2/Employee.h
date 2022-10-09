#ifndef Employee_H
#define Employee_H

#include <iostream>
#include <string>

using namespace std;

// an abstract class called employee to store information common to all employees and to declare member functions for calculating salary, health care, vacation days
class Employee 
{
public:
    // member functions
    void setName(string first, string last); // member fuction to set the name of an employee
    void setId(long id); // member fuction to set the id of an employee
 
    
    // virtual functions 
    virtual double totalSalary() const = 0; // virtual function to calculate salary
    virtual double healthCare() const = 0; // virtual function to calculate health care 
    virtual int vacationDays() const = 0; // virtual function to calculate vacation days 
    virtual void printInfo() const = 0;  // virtual function to print out all info for a employee

protected:

    // information common to all employees 
    string firstName; // string datatype to store the first name of the employee
    string lastName; // string datatype to store the last name of the employee
    long personId; // long datatype to store an employees id number
};

#endif