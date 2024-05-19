#include <iostream>
#include <stack>
#include <cstring>
#include <string.h>

using namespace std;

int get_priority(char a)
{
    switch (a)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    }
    return -1;
}
bool is_op(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
    {
        return true;
    }
    return false;
}
string bf2md(string bf)
{
    stack<char> st;
    stack<char> st_op;
    for (int i = 0; i < bf.length(); i++)
    {
        if (isdigit(bf[i]))
        {
            st.push(bf[i]);
        }
        else if (bf[i] == '(')
        {
            st_op.push('(');
        }
        else if (bf[i] == ')')
        {
            while (st_op.top() != '(')
            {
                st.push(st_op.top());
                st_op.pop();
            }
            st_op.pop();
        }
        else if (is_op(bf[i]))
        {
            while (!st_op.empty() && get_priority(st_op.top()) >= get_priority(bf[i]))
            {
                st.push(st_op.top());
                st_op.pop();
            }
            st_op.push(bf[i]);
        }
    }
    while (!st_op.empty())
    {
        st.push(st_op.top());
        st_op.pop();
    }
    string ans;
    int len = st.size();
    stack<char> tmp;
    while (len--)
    {
        tmp.push(st.top());
        st.pop();
    }
    len = tmp.size();
    while (len--)
    {
        ans = ans + tmp.top();
        tmp.pop();
    }
    return ans;
}

int main()
{
    string str_before;
    cin >> str_before;
    stack<int> st;
    bool flag = false;
    string str = bf2md(str_before);
    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            st.push(str[i] - '0');
            flag = false;
        }
        if (is_op(str[i]))
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            switch (str[i])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            }
            flag = true;
        }
        if (flag)
        {
            stack<int> tmp, tmpp;
            tmp = st;
            while (!tmp.empty())
            {
                tmpp.push(tmp.top());
                tmp.pop();
            }
            while (!tmpp.empty())
            {
                cout << tmpp.top() << " ";
                tmpp.pop();
            }
            for (int j = i + 1; j < str.length(); j++)
            {
                cout << str[j] << " ";
            }
            // cout << str[str.length() - 1];
            cout << endl;
        }
    }
    return 0;
}