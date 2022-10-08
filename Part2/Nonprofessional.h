#ifndef Nonprofessional_H
#define Nonprofessional_H

#include <iostream>
#include <string> 
#include "Employee.h"

using namespace std;

class Nonprofessional : public Employee
{
public:

    void setSalary(double wages, double hours);


    double totalSalary() const;
    double healthCare() const;
    int vacationDays() const;
    void printInfo() const;
    
    Nonprofessional();
    Nonprofessional(string first, string last, long id = 0, double wages = 0, double hours = 0);

private:
    double pay;
    double rate;
    double weeklySalary;
    int NPPTO;
    double insurancePercentage = 0.03;    
    /*
    nonprofessional employees are paid an hourly rate.
    nonprofessional employees receive vacation hours based on the number of hours they have worked
    nonprofessional employees receive certain percentage of health care based on there hours worked
    */
};

#endif