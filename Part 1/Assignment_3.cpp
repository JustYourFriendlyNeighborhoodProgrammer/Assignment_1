/*
Write a new queue function called move_to_rear that moves the element currently
 at the front of the queue to the rear of the queue. The element that was second in line
 will be the new front element. Do these using functions push, front, and pop.

*/



#include <iostream>
#include <queue>
#include <string>

using namespace std;

void move_to_rear(queue<string> q); // moves the element currently at the front of the queue to the rear of the queue.
void print_queue(queue<string> q); // prints the elements of the queue for the display

int main() {
    queue<string> q1; // declaring a queue of type string 

    //filling the queue with elements
    q1.push("Jonathan");
    q1.push("Dustin");
    q1.push("Robin");
    q1.push("Debbie");
    q1.push("Rich");

    move_to_rear(q1);

    return 0;
}

// Moves the element currently at the front of the queue to the rear of the queue.
void move_to_rear(queue<string> q) {
    cout << "Old queue: " << endl;
    print_queue(q);
    string temp;
    temp = q.front();
    q.pop();
    q.push(temp);
    cout << "New queue: " << endl;
    print_queue(q);
    
}

// Print the queue
void print_queue(queue<string> q) {
    queue<string> temp = q;
    while (!temp.empty()) {
        cout << temp.front()<<"\n";
        temp.pop();
    }
    cout << '\n';
}