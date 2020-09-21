#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "Set.h"
#include "helpers.h"
using namespace std;

/*****
The main function reads data for two vectors from an
input file, where each line of the input file represents
its own vector, and the space between the digits represents
the separation of values in the vector. Thus, an input
file that appears like such:
> 1 2 3 4
> 2 3 4 5
would create two vectors equivelant to:
```cpp
vector<int> firstLine = {1, 2, 4, 4}
vector<int> secondLine = {2, 3, 4, 5}
```
respectively. These vectors are passed to the `Set` class,
which calculates the union and the intersection between
these two vectors (which is stored in the `Set` class).
Finally all of the information is outputted.

Author: David J DeBonis
Version: 2020-09-21

*****/

int main() {
    ifstream setInput;
    setInput.open("setInput.txt");
    vector<int> set1, set2;

    if (setInput.is_open()){
        try {
            readSet(setInput, set1);
        }
        catch (char const* message){
            cerr << message << endl;
        }
        try {
            readSet(setInput, set2);
        }
        catch (char const* message){
            cerr << message << endl;
        }
        cout << "Original set #1: ";
        printValue(set1);
        cout << "Original set #2: ";
        printValue(set2);
        cout << endl;
    }
    else {
        cerr << "File cannot be opened" << endl;
    }

    Set testSet(set1, set2);
    cout << "Initializing Set object..." << endl;
    cout << "Calculating Set union and intersect..." << endl;
    cout << "Output for input set: " << endl;
    testSet.output();

    setInput.close();

    return 0;
}
