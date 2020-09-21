#include "helpers.h"

ifstream setFile(char const* fileName){
    ifstream setInput;
    setInput.open("setInput.txt");
    return setInput;
}

void readSet(ifstream &infile, vector<int> &vec) {
    stringstream ss;
    int tempInt;
    string readString;

    getline(infile,readString);
    ss << readString;

    while (!ss.eof()){
        ss >> tempInt; // place value into tempInt var
        if (ss.fail()){
            ss.clear();
            throw "Input contains non-integer data";

        }
        vec.push_back(tempInt);
    }
}
void printValue (vector<int> set){
    for (int i = 0; i < set.size(); i++){
        cout << set[i] << " ";
    }
    cout << endl;
}
