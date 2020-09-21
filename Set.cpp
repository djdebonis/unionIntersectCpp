#include "Set.h"
#include <algorithm>

Set::Set(){
    set1 = {0,1,2,3};
    set2 = {3,4,5,6};

    setUnion = getUnion();
    setIntersect = getIntersect();
}

Set::Set(vector<int> _set1, vector<int> _set2) : set1(_set1), set2(_set2){
    setUnion = getUnion();
    setIntersect = getIntersect();
}

vector<int> Set::getUnion() {
    vector<int> tempUnion;
    for(int i = 0; i < set1.size(); i++){
        int tempInt = set1[i];
        // if the object is not already in the union vector:
        if (!(std::find(tempUnion.begin(), tempUnion.end(), tempInt) != tempUnion.end())){
            tempUnion.push_back(tempInt); // add it to the union vector
        }
    }
    for(int i = 0; i < set2.size(); i++) {
        int tempInt = set2[i];
        if (!(std::find(tempUnion.begin(), tempUnion.end(), tempInt) != tempUnion.end())) {
            tempUnion.push_back(tempInt); // add it to the union vector
        }
    }

    return tempUnion;
}

vector<int> Set::getIntersect() {
    vector<int> tempIntersect;
    for(int i = 0; i < set1.size(); i++){
        int tempInt = set1[i];
        // if this int isn't already in the `tempIntersect` vector
        if (!(std::find(tempIntersect.begin(), tempIntersect.end(), tempInt) != tempIntersect.end())){
            // if this int is *also* in the other set
            if (std::find(set2.begin(), set2.end(), tempInt) != set2.end()){
                tempIntersect.push_back(tempInt);
            }
        }
    }
    return tempIntersect;
}

void Set::printValue(vector<int> set){
    for (int i = 0; i < set.size(); i++){
        cout << set[i] << " ";
    }
    cout << endl;
}

void Set::output(){
    cout << "Set #1: ";
    printValue(set1);
    cout << "Set #2: ";
    printValue(set2);
    cout << "Union: ";
    printValue(setUnion);
    cout << "Intersection: ";
    printValue(setIntersect);
}
