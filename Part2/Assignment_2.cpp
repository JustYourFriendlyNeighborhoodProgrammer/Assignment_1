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
    string temp;
    cout << "Are you a Professional employee (P/p) or are you a Nonprofessional employee (NP/np): ";
    cin >> temp;

    if (temp == "P" || temp == "p")
    {
    Professional myPro;
    myPro.printInfo();
    } else if (temp == "NP" || temp == "np")
    {
    Nonprofessional myNonPro;        
    myNonPro.printInfo();    
    } else {
        cout << "Sorry we didn't quite get that, can you try again." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        main();
    }
    
    return 0;
}











Professional::Professional()
{
    string temp, temp2;
    long num;
    cout << "Running..." << endl;
    cout << "what is your first name:";
    cin >> temp;
    cout << "what is your last name:";
    cin >> temp2;
    setName(temp,temp2);
    cout << "what is your id number: ";
    cin >> num;
    setId(num);

}

Professional::Professional(string first, string last, long id, double wages, int pto, int health)
{
    firstName = first;
    lastName = last;
    personId = id;
    monthlySalary = wages;
    PPTO = pto;
    insurancePercentage = health;
}

void Professional::printInfo() const
{
    cout << "\nName: " << firstName << " " << lastName << endl;     
    cout << "Id: " << personId << endl;
    cout << "Wages: $" << totalSalary() << endl;
    cout << "Insurance: $"  << healthCare() << endl;
    cout << "Payed time off (in hours): " << vacationDays() << "\n" << endl;    
}

double Professional::totalSalary() const
{
    return monthlySalary;
}

double Professional::healthCare() const
{
    return monthlySalary * insurancePercentage;
}

int Professional::vacationDays() const
{
    return PPTO;
}
















Nonprofessional::Nonprofessional()
{
    string temp, temp2;
    long num;
    double num2, num3;
    cout << "Running..." << endl;
    cout << "what is your first name:";
    cin >> temp;
    cout << "what is your last name:";
    cin >> temp2;
    setName(temp,temp2);
    cout << "what is your id number: ";
    cin >> num;
    setId(num);
    cout << "How much do you make per hour: ";
    cin >> num2;
    cout << "How many hours have you worked the past two weeks: ";
    cin >> num3;
    setSalary(num2,num3);

}

Nonprofessional::Nonprofessional(string first, string last, long id, double wages, double hours)
{
    firstName = first;
    lastName = last;
    personId = id;
    pay = wages;
    rate = hours;
}

void Nonprofessional::printInfo() const
{
    cout << "\nName: " << firstName << " " << lastName << endl;     
    cout << "Id: " << personId << endl;
    cout << "Wages: $" << totalSalary() << endl;
    cout << "Insurance: $"  << healthCare() << endl;
    cout << "Payed time off (in hours): " << vacationDays() << "\n" << endl;    
}

double Nonprofessional::totalSalary() const
{
    return pay * rate;
}

double Nonprofessional::healthCare() const
{
    return weeklySalary * insurancePercentage;
}

int Nonprofessional::vacationDays() const
{
    return rate / 60;
}

void Nonprofessional::setSalary(double wages, double hours)
{
    pay = wages;
    rate = hours;
    weeklySalary = wages * hours;
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
