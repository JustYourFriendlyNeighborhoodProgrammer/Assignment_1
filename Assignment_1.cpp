/*
    Author: Kevin Membreno
    Date:   9/26/2022
*/
#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

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

    cout << "Replace a cell form the array, " 
    << "Enter a index (0~"<< array_size << ")." << endl;
    cin >> temp;
    cout << "\n";
    doc.modifyInt(temp);
    cout << "\n";
    cout << "Add a integer to the array." << endl;
    cin >> temp;
    cout << "\n";
    doc.newInt(temp);
    cout << "\n";
    cout << "Remove a cell form the array." << endl;
    cout << "Enter a index (0~"<< array_size << ")." << endl;
    cin >> temp;
    cout << "\n";
    doc.removeInt(temp);
    cout << "\n";

    return 0;
}

// Reads data form file and stores data into an array.
void header::getData(ifstream &indata) {
    int temp; // temporary holder variable 
    indata.open("file.txt"); // opens input file were the data is located 
    
    if (indata.is_open()) { // check whether or not the input file is open
        while (!indata.eof()) {    
            indata >> temp; // using the holder variable to hold the integer
            resizeArray(temp,array_size); // adding integers to the array
        }
        indata.close(); // input file no longer needs to be open so close it   
    } else { // if input file is not open throws out appropriate error message  
        cout << "The input file does not exist. "
             << "Program terminates." << endl;
    }

}

// it adds integers to the array and increase its own size 
void header::resizeArray(int num, int &old_array_size) {
    int new_array_size = old_array_size + 1; // using the index of my_array to make another index fot temporary array
	int *temporary_array = new int[new_array_size]; // temporary array with a index that is one unit bigger than my_array

	for(int i = 0; i < old_array_size; i++) {
		temporary_array[i] = my_array[i]; // coping the contents of my_array into temporary array
	}
	temporary_array[new_array_size - 1] = num; // adds the integer to end of the array 
	delete[] my_array; // do I really need to explain this part (deletes my_array)
	my_array = temporary_array; // reassigns my_array with its contents and the new added integer

	old_array_size++; // increments my_array size
}

// check if a certain integer exists in the array.
void header::checkInt(int num) {
    for (int i = 0; i < array_size; i++) { // incrementing through the array
        if (my_array[i] == num) { // incrementing through the array to find a match
            cout << num << " is present in the array it's index is " 
            <<"(" << i << ")." << "\n" << endl; 
            return; // if integer is present returns the index of the location were said integer is stored 
        }
    }
    cout << num << " was not in the array." << "\n" << endl; // if integer is not present return error message

}

// modifies the value of an integer in the array when called with the index of the integer in the array.
void header:: modifyInt (int index) {
    int num; // temporary holder variable 
    cout << "Enter the integer you wish to replace the selected cell with." << endl;
    cin >> num;
    cout << "\n";
    cout << "The old integer in the cell " << my_array[index] << endl; // shows old integer in the array at that specified index
    my_array[index]= num; // replaces the old integer in the array with the desired new integer
    cout << "The new integer in the cell " << my_array[index] << "\n" << endl; // shows new integer in the array at that specified index

    for (int i = 0; i < array_size; i++) {
        cout << my_array[i] << " ";
        if ((i+1) % 10 == 0)
        {
            cout << "\n";
        } 
    }    

}

// adds a new integer to the end of the array.
void header:: newInt(int num) {
    resizeArray(num,array_size); // adds a integer to the end of the array and increase the array own size

    for (int i = 0; i < array_size; i++) {
        cout << my_array[i] << " ";
        if ((i+1) % 10 == 0)
        {
            cout << "\n";
        } 
    }    
    cout << "\n";
}

// intakes an index of an array and removes the integer corresponding to said index.
void header:: removeInt (int index) {
    for (int i = index; i < array_size; ++i){
    my_array[i] = my_array[i + 1]; // removes the integer from the array and moves all the contents of the array down by one
    }
    int new_array_size = array_size - 1; // lowering the size of the array because now it has one less integer in it
	int *temporary_array = new int[new_array_size]; 

	for(int i = 0; i < new_array_size; i++) {
		temporary_array[i] = my_array[i]; // coping the contents of my_array into temporary array
	}

	delete[] my_array; // do I really need to explain this part (deletes my_array)
	my_array = temporary_array; // reassigns my_array with its contents and the new added integer
    array_size--; // decrements my_array size 


    for (int i = 0; i < array_size; i++) {
        cout << my_array[i] << " ";
        if ((i+1) % 10 == 0)
        {
            cout << "\n";
        } 
    }    
}
