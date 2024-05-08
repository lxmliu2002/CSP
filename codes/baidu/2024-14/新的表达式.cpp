#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int priority(char op)
{
    if (op == '&' || op == '|')
    {
        return 1;
    }
    return -1;
}

bool is_op(char op)
{
    return (op == '&' || op == '|');
}

void process(stack<int> &s, char op)
{
    int r = s.top();
    s.pop();
    int l = s.top();
    s.pop();
    switch (op)
    {
    case '&':
        s.push(min(l, r));
        break;
    case '|':
        s.push(max(l, r));
        break;
    }
}

int calculate(string str)
{
    stack<int> s;
    stack<char> sop;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            sop.push(str[i]);
        }
        else if (str[i] == ')')
        {
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

int main()
{
    string str;
    cin >> str;
    cout << calculate(str);
    return 0;
}