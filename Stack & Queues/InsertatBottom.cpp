#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st;
    for (int i = 1; i <= 10; i++)
        st.push(i);
    int el;
    cin >> el;
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(el);
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}