#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& str) 
{
    stack<char> charStack;
    for (char c : str) 
    {
        if (c == '(' || c == '[' || c == '{') 
        {
            charStack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') 
        {
            if (charStack.empty()) 
            {
                return false;
            }

            char open = charStack.top();
            charStack.pop();
            if ((c == ')' && open != '(') || (c == ']' && open != '[') || (c == '}' && open != '{')) 
            {
                return false;
            }
        }
    }
    return charStack.empty();
}

int main() 
{
    string input1 = "{[()]}()";
    string input2 = "[{]}";

    if (isBalanced(input1)) 
    {
        cout << "First line is balanced" << endl;
    }
    else 
    {
        cout << "First line is didnt balanced" << endl;
    }

    if (isBalanced(input2)) 
    {
        cout << "Second line is balanced" << endl;
    }
    else 
    {
        cout << "Second line is didnt balanced" << endl;
    }

    return 0;
}