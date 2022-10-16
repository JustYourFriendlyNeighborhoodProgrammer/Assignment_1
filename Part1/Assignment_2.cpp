/*
A way to indicate an error, especially if there are several possible errors in code,
 is through the use of exceptions. Exceptions are used to signal that an error has occurred.
 You can insert code in your program that throws an exception when a particular kind of error occurs.
 An exception handler allows the user to catch or handle the exception.
 To avoid uncaught exceptions, you write a try block that can throw an exception and follow it with
 a catch block that catches the exception and handles it.
 Using the array code from assignment 1 perform the following:

Add a try and catch blocks (refer to the slide 53 of chapter 2)
 to the user inputs for the following functions from assignment 1:
 
1) A function that can modify the value of an integer when called with the index of the
 integer in the array and return the new value and old value back to the user.

2) A function that adds a new integer to the end of the array

*/
#include <iostream>
#include <exception>
#include <string>
#include <cctype>
#include <fstream>
#include "header.h"

using namespace std;

class invalidIndex // exception class for the invalid index
{
private:
    string msgIndex;
public:
    invalidIndex() { // the message the is throw if an error happens
        msgIndex = "Invalid index given, the input must be in range and be of type int \n";
    }
    invalidIndex(string str) {
        msgIndex = str;
    }
    string what() {
        return msgIndex; // returns the message
    }
};

class invalidInput // exception class for the invalid input
{
private:
    string msgInput;
public:
    invalidInput() { // the message the is throw if an error happens
        msgInput = "Invalid input given, the input must be of type int \n";
    }
    invalidInput(string str) {
        msgInput = str;
    }
    string what() {
        return msgInput; // returns the message
    }
};

int main(){
    int temp, temp2;
    header doc;

    ifstream infile;
    doc.getData(infile);
    cout << "\n";

    cout << "Enter a integer to see whether or not it is in the array." << endl;
    cin >> temp;
    cout << "\n";
    doc.checkInt(temp);



    try //try block
    {
        string index, num; // temp holders used to check inputs

        cout << "Replace a cell form the array, " 
        << "Enter a index (0~"<< array_size << ")." << endl;
        cin >> index; // index
        cout << "\n";
        for (int i = 0; i < index.size(); i++) // checks the index to see if it is a valid input
        {
            if (!isdigit(index[i]))
            {
                throw invalidIndex(); // if given index is not valid throw exception for said error
            }
            
        }
        temp = stoi(index); // if all goes well makes the string into an integer 
        if ((temp >= 0) && !(temp <= array_size)) // test to see if the integer is in range of array
        {
            throw invalidIndex(); // if integer is not in the range of the array throws exceptions
        }
        
        cout << "Enter the integer you wish to replace the selected cell with." << endl;
        cin >> num; // num
        cout << "\n";
        for (int i = 0; i < num.size(); i++) // checks the number to see if it is a valid input
        {
            if (!isdigit(num[i])) 
            {
                throw invalidInput(); // if given index is not valid throw exception for said error
            }
            
        }
        temp2 = stoi(num); // if all goes well makes the string into an integer
        doc.modifyInt(temp, temp2); // calls modify int
        cout << "\n";
        


        cout << "Add a integer to the array." << endl;
        cin >> index; // index
        cout << "\n";
        for (int i = 0; i < index.size(); i++) // checks the input to see if it is a valid input
        {
            if (!isdigit(index[i]))
            {
                throw invalidInput(); // if given input is not valid throw exception for said error
            }
            
        }
        temp = stoi(index); // turns string index into integer 
        doc.newInt(temp); 
        cout << "\n";
    } // catch block
    catch(invalidIndex indexObj) // catches if invalid index
    {
        cerr << indexObj.what();
        abort(); // leaves program
    }
    catch(invalidInput inputObj) // catches if invalid input 
    {
        cerr << inputObj.what();
        abort(); // leaves program
    }
    catch(...) // catches if unknow error happens
    {
        cerr << "Undefined exception occurred \n";
        abort(); // leaves program
    }

    cout << "Remove a cell form the array." << endl;
    cout << "Enter a index (0~"<< array_size << ")." << endl;
    cin >> temp;
    cout << "\n";
    doc.removeInt(temp);

    return 0;
}

// Reads data form file and stores data into an array.
void header::getData(ifstream &indata) {
    int temp; // temporary holder variable 
    indata.open("file.txt"); // opens input file were the data is located 
    
    if (indata.is_open()) { // check whether or not the input file is open
        while (!indata.eof()) {    
            indata >> temp; // using the holder variable to hold the integer
            resizeArray(temp,array_size, 0); // adding integers to the array
        }
        indata.close(); // input file no longer needs to be open so close it   
    } else { // if input file is not open throws out appropriate error message  
        cout << "The input file does not exist. "
             << "Program terminates." << endl;
    }

}

// it adds integers to the array and increase its own size or removes and decrease its own size
void header::resizeArray(int num, int &old_array_size, int holder) {
    
    if (holder == 0) {
    
        int new_array_size = old_array_size + 1; // using the index of my_array to make another index fot temporary array
        int *temporary_array = new int[new_array_size]; // temporary array with a index that is one unit bigger than my_array

        for(int i = 0; i < old_array_size; i++) {
            temporary_array[i] = my_array[i]; // coping the contents of my_array into temporary array
        }
        temporary_array[new_array_size - 1] = num; // adds the integer to end of the array 
        delete[] my_array; // do I really need to explain this part (deletes my_array)
        my_array = temporary_array; // reassigns my_array with its contents and the new added integer
        old_array_size++; // increments my_array size
    
    } else if (holder == 1) {
    
        for (int i = num; i < old_array_size; ++i){
        my_array[i] = my_array[i + 1]; // removes the integer from the array and moves all the contents of the array down by one
        }

        int new_array_size = array_size - 1; // lowering the size of the array because now it has one less integer in it
        int *temporary_array = new int[new_array_size]; 

        for(int i = 0; i < new_array_size; i++) {
            temporary_array[i] = my_array[i]; // coping the contents of my_array into temporary array
        }

        delete[] my_array; // do I really need to explain this part (deletes my_array)
        my_array = temporary_array; // reassigns my_array with its contents and the new added integer
        old_array_size--; // decrements my_array size 

    }
}

// check if a certain integer exists in the array.
void header::checkInt(int num) {
    for (int i = 0; i < array_size; i++) { // incrementing through the array
        if (my_array[i] == num) { // incrementing through the array to find a match
            cout << num << " is present in the array it's index is " 
            <<"(" << i << ")." << "\n" << endl; 
            display();
            cout << "\n";
            return; // if integer is present returns the index of the location were said integer is stored 
        }
    }
    cout << num << " was not in the array." << "\n" << endl; // if integer is not present return error message

}

void header:: display(){
        for (int i = 0; i < array_size; i++) {
        cout << my_array[i] << " ";
        if ((i+1) % 10 == 0)
        {
            cout << "\n";
        } 
    }  
}

// modifies the value of an integer in the array when called with the index of the integer in the array.
void header:: modifyInt(int index, int num) {
    cout << "The old integer in the cell " << my_array[index] << endl; // shows old integer in the array at that specified index
    my_array[index]= num; // replaces the old integer in the array with the desired new integer
    cout << "The new integer in the cell " << my_array[index] << "\n" << endl; // shows new integer in the array at that specified index

    display();

}

// adds a new integer to the end of the array.
void header:: newInt(int num) {
    resizeArray(num,array_size, 0); // adds a integer to the end of the array and increase the array own size

    display();
    cout << "\n";
}

// intakes an index of an array and removes the integer corresponding to said index.
void header:: removeInt (int index) {
    resizeArray(index,array_size, 1);
    
    display();
    cout << "\n";
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