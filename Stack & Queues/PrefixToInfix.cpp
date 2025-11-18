#include <iostream>
#include <stack>
#include <cmath>  // for pow function
#include <cctype> // for isdigit()

using namespace std;

bool is_operand(char c)
{
    return isdigit(c);
}

double evaluate_prefix(string s)
{
    stack<double> Stack;

    for (int j = s.size() - 1; j >= 0; j--)
    {
        if (is_operand(s[j]))
        {
            Stack.push(s[j] - '0'); // Convert char to digit
        }
        else
        {
            // Operator encountered
            double o1 = Stack.top();
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();

            // Perform operation based on the operator
            switch (s[j])
            {
            case '+':
                Stack.push(o1 + o2);
                break;
            case '-':
                Stack.push(o1 - o2);
                break;
            case '*':
                Stack.push(o1 * o2);
                break;
            case '/':
                Stack.push(o1 / o2);
                break;
            case '^':
                Stack.push(pow(o1, o2));
                break;
            }
        }
    }

    return Stack.top();
}

int main()
{
    string s = "^ 3 3 * 2 - 3"; // Prefix expression
    cout << "Result: " << evaluate_prefix(s) << endl;
    return 0;
}
