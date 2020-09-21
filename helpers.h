#include <vector>
#include <iostream>
using namespace std;

#ifndef HELPERS_H
#define HELPERS_H

ifstream setFile(char const* fileName);

void readSet(ifstream &infile, vector<int> &vec);

void printValue (vector<int> set);

#endif //HELPERS_H
