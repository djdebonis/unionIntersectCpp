#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

class Stack{
    // very basic implementation of stack ADT using vector class
public:
    Stack(){};

    void push(double amount){
        theArray.push_back(amount);
        topOfStack++;
    }

    void pop(){
        theArray.pop_back();
        topOfStack--;
    }

    double top(){
        return theArray.back();
    }

    int getSize(){
        return theArray.size();
    }


private:
    vector<double> theArray;
    int topOfStack = -1;
};

bool isOperator(string input);
double operate(double leftOperand, double rightOperand, string symbol);
double evaluatePostfix(Stack & theStack, istream & infile);


int main() {
    string filename = "postfix.txt";
    ofstream outfile(filename);
    //outfile.open(filename);

    string tempValue;
    cout << "Please enter a postfix expression (operand/operators separated by spaces): ";
    getline(cin, tempValue);

    if (outfile.is_open()) {
        outfile << tempValue;
    }
    else {
        cerr << "File could not be opened." << endl;
    }
    outfile.close();

    Stack postfix;
    double answer;

    ifstream infile(filename);

    if (infile.is_open()) {
        try {
            answer = evaluatePostfix(postfix, infile);
            cout << "The answer is " << answer << endl;
        } catch (const char *message) {
            cerr << message << endl;
        }


    }
    else {
        cerr << "File '" << filename << "' not found" << endl;
    }

    infile.close();

    return 0;
}

bool isOperator(string input){
    bool result = false;
    vector<string> operators {"+", "-", "*", "/"};
    for(int i = 0; i < operators.size(); i++){
        if (input == operators[i]){
            result = true;
        }
    }
    return result;
}

double operate(double leftOperand, double rightOperand, string symbol){
    double rvalue;
    if (symbol == "+"){
        rvalue = leftOperand + rightOperand;
    }
    else if (symbol == "-"){
        rvalue = leftOperand + rightOperand;
    }
    else if (symbol == "*"){
        rvalue = leftOperand * rightOperand;
    }
    else if (symbol == "/"){
        rvalue = leftOperand / rightOperand;
    }
    return rvalue;
}

double evaluatePostfix(Stack & theStack, istream & infile){
    string docString;
    string element;
    while(infile >> element){
        // cout << element << endl;
        if (isOperator(element)){ // if it's an operator
            if (theStack.getSize() >= 2){ // given that there are the right amount of operators
                double left = theStack.top();
                theStack.pop();
                double right = theStack.top();
                theStack.pop();

                double newTotal = operate(left, right, element);
                theStack.push(newTotal);
                // cout << "New total: " << newTotal << endl;
            }
            else {
                throw "Incorrect syntax with postfix expression; not enough values to be operated upon.";
            }
        }
        else {
            double number = atof(element.c_str());
            theStack.push(number);

        }

    }
    if (theStack.getSize() > 1) {
        throw "Incorrect syntax with postfix expression; too many operands/not enough operators.";
    }
    double total = theStack.top();
    return total;
}
