/*
Declare the map container stateDataMap to store pairs of the form (stateName,capitalName),
 where stateName and capitalName are variables of type string:
 
1.  write c++ statements that add the following pairs to stateDataMap:
 (Nebraska, Lincoln), (New York, Albany), (Ohio, Columbus), (California, Sacramento),
 (Massachusetts, Boston), and (Texas, Austin).

2.  write a C++ method that outputs the data stored in stateDateMap.
3.  write a C++ statement that changes the capital of California to Los Angeles.
4.  write a C++ method that outputs the capitalName using the stateName which will
    be entered by the user.

*/



#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string temp;
    // map container stateDataMap that stores pairs of the from (stateName, capitalName)
    map<string,string> stateDataMap;

    // statements that add the following pairs to stateDataMap
    stateDataMap["Nebraska"] = "Lincoln";
    stateDataMap["New York"] = "Albany";
    stateDataMap["Ohio"] = "Columbus";
    stateDataMap["California"] = "Sacramento";
    stateDataMap["Massachusetts"] = "Boston";
    stateDataMap["Texas"] = "Austin";

    // a method that outputs the data stored in stateDataMap
    for (auto& itr : stateDataMap) {
        cout << itr.first << " ";
        cout << itr.second << "\n";
    }
    
    // statement that changes the capital of California to Los Angeles
    stateDataMap["California"] = "Los Angeles";

    cout << "\n";
    
    // a method that outputs the capitalName using the stateName
    cout << "Enter a state name to find out its capital: ";
    cin >> temp;
    for (auto& itr : stateDataMap) {
        if (itr.first == temp)
        {
            cout << "It's capital is: " << itr.second << "\n";
        }
    }
    return 0;
}

