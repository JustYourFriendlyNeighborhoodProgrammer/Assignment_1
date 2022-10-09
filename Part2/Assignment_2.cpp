/*
A company has two different kinds of employees:
 professional and nonprofessional.
 Generally, professional employees have a monthly salary,
 whereas nonprofessional employees are paid an hourly rate. 
 Similarly, professional employees have a certain number of days of vacation,
 whereas nonprofessional employees receive vacation hours based on the number of hours they have worked.
 The amount contributed for health insurance is also different for each kind of employee. 

1.	Use an abstract class Employee to store information common to all employees and to declare member 
 functions for calculating weekly salary (number of hours worked * hourly rate) and computing health care
 contributions and vacation days earned that week (come up with some rules for these 2).
 You need 3 functions (calculating weekly salary, health care contributions, and Vacation days). 

2.	 Define derived classes Professional and Nonprofessional. Create instance for them. 

3.	Test your classes.

*/

#include <iostream>
#include "Professional.h"
#include "Nonprofessional.h"

using namespace std;

int main() {

    // asking the user if they are a professional or nonprofessional employee
    string temp;
    cout << "Are you a Professional employee (P/p) or are you a Nonprofessional employee (NP/np): ";
    cin >> temp;
    if (temp == "P" || temp == "p") // the user is a professional employee
    {
    Professional myPro; 
    myPro.printInfo();
    } else if (temp == "NP" || temp == "np") // the user is a nonprofessional employee
    {
    Nonprofessional myNonPro;        
    myNonPro.printInfo();    
    } else {
        // error the user is neither or did not follow instructions, try again
        cout << "Sorry we didn't quite get that, can you try again." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        main();
    }
    
    return 0;
}










// default constructor 
Professional::Professional()
{
    string temp, temp2;
    long num;
    cout << "Running..." << endl;
    cout << "what is your first name:"; // get the professional employees first name
    cin >> temp;
    cout << "what is your last name:"; // get the professional employees last name
    cin >> temp2;
    setName(temp,temp2); // set first ane last name
    cout << "what is your id number: "; // get the professional employees id number 
    cin >> num;
    setId(num); // set id 

}

//parametrized constructor
Professional::Professional(string first, string last, long id, double wages, int pto, int health)
{
    firstName = first;
    lastName = last;
    personId = id;
    monthlySalary = wages;
    PPTO = pto;
    insurancePercentage = health;
}

// re-defined virtual function in class professional to print out all info for said class
void Professional::printInfo() const
{
    cout << "\nName: " << firstName << " " << lastName << endl; // display the professional employee name
    cout << "Id: " << personId << endl; // display the professional employee id
    cout << "Wages: $" << totalSalary() << endl; // display the professional employee salary
    cout << "Insurance: $"  << healthCare() << endl; //display the professional employee health care
    cout << "Payed time off (in hours): " << vacationDays() << "\n" << endl; // display the professional employee vacation days
}

// re-defined virtual function in class professional to calculate salary for said class
double Professional::totalSalary() const
{
    return monthlySalary; // return salary
}
// re-defined virtual function in class professional to calculate health care for said class
double Professional::healthCare() const
{
    return monthlySalary * insurancePercentage; //return health care
}
// re-defined virtual function in class professional to calculate vacation days for said class
int Professional::vacationDays() const
{
    return PPTO; // return vacation days
}
















Nonprofessional::Nonprofessional()
{
    string temp, temp2;
    long num;
    double num2, num3;
    cout << "Running..." << endl;
    cout << "what is your first name:"; // get the nonprofessional employee first name
    cin >> temp;
    cout << "what is your last name:"; // get the nonprofessional employee last name
    cin >> temp2;
    setName(temp,temp2); // set the first and last name 
    cout << "what is your id number: "; // get the nonprofessional employee id number
    cin >> num;
    setId(num); // set the id number
    cout << "How much do you make per hour: "; // get how much a nonprofessional employee makes per hour
    cin >> num2;
    cout << "How many hours have you worked the past two weeks: "; // get how many hours a nonprofessional employee worked
    cin >> num3;
    setSalary(num2,num3); // set salary values 

}

Nonprofessional::Nonprofessional(string first, string last, long id, double wages, double hours)
{
    firstName = first;
    lastName = last;
    personId = id;
    pay = wages;
    rate = hours;
}
// re-defined virtual function in class Nonprofessional to print out all into for said class
void Nonprofessional::printInfo() const
{
    cout << "\nName: " << firstName << " " << lastName << endl; // display the nonprofessional employee name
    cout << "Id: " << personId << endl; // display the nonprofessional employee id
    cout << "Wages: $" << totalSalary() << endl; // display the nonprofessional employee salary
    cout << "Insurance: $"  << healthCare() << endl; //display the nonprofessional employee health care
    cout << "Payed time off (in hours): " << vacationDays() << "\n" << endl; // display the nonprofessional employee vacation days
}
// re-defined virtual function in class Nonprofessional to calculate salary for said class
double Nonprofessional::totalSalary() const
{
    return pay * rate;
}
// re-defined virtual function in class Nonprofessional to calculate health care for said class
double Nonprofessional::healthCare() const
{
    return weeklySalary * insurancePercentage;
}
// re-defined virtual function in class Nonprofessional to calculate vacation days for said class 
int Nonprofessional::vacationDays() const
{
    return rate / 60;
}
// sets the salary values for a nonprofessional employee
void Nonprofessional::setSalary(double wages, double hours)
{
    pay = wages;
    rate = hours;
    weeklySalary = wages * hours;
}














// set the name of an employee used by both professional and nonprofessional employees
void Employee::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}
// set the id of an employee used by both professional and nonprofessional employees
void Employee::setId(long id)
{
    personId = id;
}
/*
Submission guidelines:

1)	You should have a header file and .cpp file.
 The header file should provide the function declaration
 and .cpp file should have implementation details.

2)	All the functionality of the program should be implemented as functions and methods.

3)	The code should be well commented.

4)	Create a report (readme file) that contains 
 instruction on how to run the code and screen shots of the outputs

5)	Upload your report and code files to GitHub.

6)	Submit the GitHub link on Canvas by due date. 
*/