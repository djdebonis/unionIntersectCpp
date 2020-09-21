#include <vector>
#include <iostream>
using namespace std;

//
// Created by David J DeBonis on 9/21/20.
//

#ifndef SET_H
#define SET_H

class Set {
private:
    vector<int> set1, set2;
    vector<int> setUnion, setIntersect;
public:
    Set();
    Set(vector<int> _set1, vector<int> _set2);
    vector<int> getUnion();
    vector<int> getIntersect();

    vector<int> returnUnion(){return setUnion;}
    vector<int> returnIntersect(){return setIntersect;}

    void printValue (vector<int> set);

    void output();

};



#endif //SET_H
