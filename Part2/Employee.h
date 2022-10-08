#ifndef Employee_H
#define Employee_H

#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    void setName(string first, string last)
    {
        firstName = first;
        lastName = last;
    }
    
    void setId(long id)
    {
        personId = id;
    }
    

    virtual double totalSalary() const = 0;
    virtual double healthCare() const = 0;
    virtual int vacationDays() const = 0;
    virtual void printInfo() const = 0;

protected:
    string firstName;
    string lastName;
    long personId;
};

#endif