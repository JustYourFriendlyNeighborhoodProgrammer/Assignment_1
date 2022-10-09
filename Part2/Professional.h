#ifndef Professional_H
#define Professional_H

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class Professional : public Employee
{
public:
    
    double totalSalary() const; // re-defined virtual function in class professional to calculate salary for said class  
    double healthCare() const; // re-defined virtual function in class professional to calculate health care for said class
    int vacationDays() const; // re-defined virtual function in class professional to calculate vacation days for said class
    void printInfo() const; // re-defined virtual function in class professional to print out all info for said class
    
    Professional(); // default constructor 
    Professional(string first, string last, long id = 0, double wages = 0, int pto = 0, int health = 0); // parametrized constructor 

private:
    // professional employees have a monthly salary
    double monthlySalary = 12000; // double datatype to store the salary of a professional employee
    // professional employees have a certain number of days of vacation
    int PPTO = 150; // integer datatype to store the paid vacation day for a professional employee
    // professional employees have a certain percentage of there salary that goes health care.
    double insurancePercentage = 0.12; // double datatype to store the percentage of a professional employees salary that goes to health care
};

#endif