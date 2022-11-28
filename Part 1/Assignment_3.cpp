/*
Write a new queue function called move_to_rear that moves the element currently
 at the front of the queue to the rear of the queue. The element that was second in line
 will be the new front element. Do these using functions push, front, and pop.

*/



#include <iostream>
#include <queue>
#include <string>

using namespace std;

void move_to_rear();
void print_queue();
queue<string> q1;

int main() {

    //filling the queue with elements
    q1.push("Jonathan");
    q1.push("Dustin");
    q1.push("Robin");
    q1.push("Debbie");
    q1.push("Rich");

    move_to_rear();

    return 0;
}

// Moves the element currently at the front of the queue to the rear of the queue.
void move_to_rear()
{
    cout << "Old queue: " << endl;
    print_queue();
    queue<string> temp = q1;
    string temp1;
    temp1 = temp.front();
    temp.pop();
    temp.push(temp1);
    q1 = temp;
    cout << "New queue: " << endl;
    print_queue();
    
}

// Print the queue
void print_queue()
{
    queue<string> temp = q1;
    while (!temp.empty()) {
        cout << temp.front()<<"\n";
        temp.pop();
    }
    cout << '\n';
}