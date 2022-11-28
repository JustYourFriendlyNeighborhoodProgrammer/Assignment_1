/*
As discussed in chapter 5, a palindrome is a word that reads the same left to right as 
 right to left. Write a recursive function that determines whether its argument string is a 
 palindrome.

test for palindrome:
kayak
i saw i was i
able was i ere i saw elba
level madam level
noon
anna

*/



#include <iostream>
#include <stdio.h>

using namespace std;

bool palindrome(string word, int i, int j);

int main() {
    char str[100];
    string temp;
    printf("Enter a string to see whether or not it is a palindrome. \n");
    scanf("%[^\n]s", str);
    temp = str;
    // using the bool palindrome function to determine if the strings is a palindrome or not and print the corresponding output
    if (palindrome(temp, 0, temp.length() - 1)) {
        printf("The string is a palindrome!");
    } else {
        printf("the string is not a palindrome.");
    }
    // pause before ending program 
    printf("\n");
    system("pause");
    return 0;
}

// recursive function that determines whether its argument string is a palindrome 
bool palindrome(string word, int i, int j)
{
    if (word.at(i++) == word.at(j--)) {
        if (j > i) {
            return palindrome(word, i, j);
        }
        return true;
    } else {
        return false;
    }   
}