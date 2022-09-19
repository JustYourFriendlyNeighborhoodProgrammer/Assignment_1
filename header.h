#ifndef header_H
#define header_H

#include <iostream>
#include <fstream>

using namespace std;

int array_size = 0;

class header
{
public:
    // Reads data form file and stores data into an array
    // @param file
    void getData(ifstream &indata);

    // Checks if a certain integer exists in the array
    // @param the integer to look for
    // @return wether or not the integer was found and the index of the integer
    void checkInt(int num);

    // modifies the value of an integer in the array when called with the index of said integer in the array
    // @param a index of the array
    // @returns the old integer in the array and the new integer in the array
    void modifyInt(int index); 

    // adds a new integer to the end of the array
    // @param the integer to add at the end of the array
    void newInt(int num);

    // intakes an index of the array and removes the integer corresponding to said index.
    // @param a index of the array
    void removeInt(int index); 

private:
    // Data Fields
    // an array to store all integers in the file and given by the user
    int *my_array = new int[array_size];

    // it adds integers to the array and increase its own size or removes and decrease its own size
    // @param the integer to be added to the array or removed from the array
    // @param the old size of the array before its increased 
    // @param will determine whether or not to add or subtract form the array
    void resizeArray(int num, int &old_array_size, int holder);
    
    // its a display (of the array)
    void display();
};

#endif