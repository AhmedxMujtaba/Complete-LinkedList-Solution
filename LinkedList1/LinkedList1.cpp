#include <iostream>
#include "StackActivities.h"
using namespace std;


int main()
{
    Stack stack;
    string expression = "10 + 23 - (23-3)";
    string prefixExpression = stack.infixToPrefix(expression);
    cout << prefixExpression << endl;

}