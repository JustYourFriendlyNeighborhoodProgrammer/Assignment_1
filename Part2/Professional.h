#ifndef Professional_H
#define Professional_H

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class Professional : public Employee
{
public:
    
    double totalSalary() const;
    double healthCare() const;
    int vacationDays() const;
    void printInfo() const;
    
    Professional();
    Professional(string first, string last, long id = 0, double wages = 0, int pto = 0, int health = 0);

private:
    double monthlySalary = 12000;
    int PPTO = 150;
    double insurancePercentage = 0.12;
    /*
    professional employees have a monthly salary,
    professional employees have a certain number of days of vacation,
    professional employees have a certain percentage of there salary that goes health care.
    */  
};

#endif