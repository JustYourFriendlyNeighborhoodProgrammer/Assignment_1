# Assignment_2

Q1: A way to indicate an error, especially if there are several possible errors in code, is through the use of exceptions. Exceptions are used to signal that an error has occurred. You can insert code in your program that throws an exception when a particular kind of error occurs. An exception handler allows the user to catch or handle the exception. To avoid uncaught exceptions, you write a try block that can throw an exception and follow it with a catch block that catches the exception and handles it. Using the array code from assignment 1 perform the following:
1)	(5 points) Add a try and catch blocks (refer to the slide 53 of chapter 2) to the user inputs for the following functions from assignment 1: 
- A function that can modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user.
-	A function that adds a new integer to the end of the array

![image](https://user-images.githubusercontent.com/83984148/196441356-1265122c-7cc8-4ee8-938b-7bf6754a9fbd.png)
![image](https://user-images.githubusercontent.com/83984148/196441509-39334210-0c59-48ed-8e3f-567807de0db4.png)
![image](https://user-images.githubusercontent.com/83984148/196441646-28e52acd-dba4-4930-a827-ea85e8ac142e.png)
![image](https://user-images.githubusercontent.com/83984148/196441714-2e200a53-12f1-42c3-ad99-3e5ddcd0effc.png)
![image](https://user-images.githubusercontent.com/83984148/196441990-06a115bc-113d-4e1e-8d1e-6386b0b7e8d3.png)


2)	(20 points) A company has two different kinds of employees: professional and nonprofessional. Generally, professional employees have a monthly salary, whereas nonprofessional employees are paid an hourly rate. Similarly, professional employees have a certain number of days of vacation, whereas nonprofessional employees receive vacation hours based on the number of hours they have worked. The amount contributed for health insurance is also different for each kind of employee. 
-	Use an abstract class Employee to store information common to all employees and to declare member functions for calculating weekly salary (number of hours worked * hourly rate) and computing health care contributions and vacation days earned that week (come up with some rules for these 2) . You need 3 functions (calculating weekly salary, health care contributions, and Vacation days). 
-	 Define derived classes Professional and Nonprofessional. Create instance for them. 
-	Test your classes.

![image](https://user-images.githubusercontent.com/83984148/194679302-7618854e-8629-4c34-a62a-c6a6a92d28a5.png)
![image](https://user-images.githubusercontent.com/83984148/194679419-0eec1c74-3add-4d95-aed0-74b9b7e11df4.png)

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
