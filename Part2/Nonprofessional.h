#ifndef Nonprofessional_H
#define Nonprofessional_H

#include <iostream>
#include <string> 
#include "Employee.h"

using namespace std;

class Nonprofessional : public Employee
{
public:

    void setSalary(double wages, double hours); // sets the salary values for a nonprofessional employee

    double totalSalary() const; // re-defined virtual function in class Nonprofessional to calculate salary for said class
    double healthCare() const; // re-defined virtual function in class Nonprofessional to calculate health care for said class
    int vacationDays() const; // re-defined virtual function in class Nonprofessional to calculate vacation days for said class 
    void printInfo() const; // re-defined virtual function in class Nonprofessional to print out all into for said class
    
    Nonprofessional(); // default constructor 
    Nonprofessional(string first, string last, long id = 0, double wages = 0, double hours = 0); //parametrized constructor 

private:
    // nonprofessional employees are paid an hourly rate.
    double pay; // double datatype to store how much a nonprofessional employee gets paid
    double rate; // double datetype to store how many hours a nonprofessional employee worked 
    double weeklySalary; // double datatype to store the result of how much a nonprofessional employee makes
    // nonprofessional employees receive vacation hours based on the number of hours they have worked
    int NPPTO; // integer datatype to store the result of how many paid vacation days should a nonprofessional employee get 
    // nonprofessional employees receive certain percentage of health care based on there hours worked
    double insurancePercentage = 0.03; // double datatype to store the percentage of a nonprofessional employees salary that goes to health care  

};

#endif