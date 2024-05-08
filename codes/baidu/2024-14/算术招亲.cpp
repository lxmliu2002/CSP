#include <iostream>
#include <stack>
#include <utility>
#include <cmath>
using namespace std;

#define N 40
bool tag[N];

bool is_op(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

int priority(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    if (op == '^')
    {
        return 3;
    }
    return -1;
}

void process(stack<int> &s, char op)
{
    int r = s.top();
    s.pop();
    int l = s.top();
    s.pop();
    switch (op)
    {
    case '+':
        s.push(l + r);
        break;
    case '-':
        s.push(l - r);
        break;
    case '*':
        s.push(l * r);
        break;
    case '/':
        s.push(l / r);
        break;
    case '^':
        s.push(pow(l, r));
        break;
    }
}

int calculate(string &str)
{
    stack<int> s;
    stack<char> sop;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            if (!tag[i])
            {
                continue;
            }
            sop.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (!tag[i])
            {
                continue;
            }
            while (sop.top() != '(')
            {
                process(s, sop.top());
                sop.pop();
            }
            sop.pop();
        }
        else if (is_op(str[i]))
        {
            while (!sop.empty() && priority(sop.top()) >= priority(str[i]))
            {
                process(s, sop.top());
                sop.pop();
            }
            sop.push(str[i]);
        }
        else
        {
            int num = 0;
            while (i < (int)str.size() && isdigit(str[i]))
            {
                num = num * 10 + str[i] - '0';
                i++;
            }
            i--;
            s.push(num);
        }
    }
    while (!sop.empty())
    {
        process(s, sop.top());
        sop.pop();
    }
    return s.top();
}

void pre_process(string &str)
{
    stack<pair<char, int>> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (!st.empty() && st.top().first == '(' && str[i] == ')')
        {
            tag[i] = tag[st.top().second] = true;
            st.pop();
        }
        else if (str[i] == '(')
        {
            st.push({'(', i});
        }
    }
}

int main()
{
    string str;
    cin >> str;
    pre_process(str);
    cout << calculate(str);
    return 0;
}