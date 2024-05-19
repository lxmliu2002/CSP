#include <iostream>
#include <stack>
using namespace std;

const int N = 270;
string s[N];
int cnt, s2[N];

bool is_op(string s)
{
    return (s == "and" || s == "or" || s == "not");
}

int get_priority(string op)
{
    if (op == "not")
    {
        return 3;
    }
    if (op == "and")
    {
        return 2;
    }
    if (op == "or")
    {
        return 1;
    }
    return -1;
}

void process_op(stack<string> &st, string op)
{
    string l, r;
    r = st.top();
    st.pop();
    if (!st.empty())
    {
        l = st.top();
    }
    if (op == "not")
    {
        if (r == "true")
        {
            st.push("false");
        }
        else
        {
            st.push("true");
        }
    }
    if (op == "and")
    {
        st.pop();
        if (r == "true" && l == "true")
        {
            st.push("true");
        }
        else
        {
            st.push("false");
        }
    }
    if (op == "or")
    {
        st.pop();
        if (r == "false" && l == "false")
        {
            st.push("false");
        }
        else
        {
            st.push("true");
        }
    }
}

string calculate(string *s, int cnt)
{
    stack<string> st;
    stack<string> op;
    for (int i = 0; i < cnt; i++)
    {
        if (is_op(s[i]))
        {
            string cur_op = s[i];
            if (cur_op != "not")
            {
                while (!op.empty() && get_priority(op.top()) >= get_priority(cur_op))
                {
                    process_op(st, op.top());
                    op.pop();
                }
            }
            op.push(cur_op);
        }
        else
        {
            st.push(s[i]);
            while (!op.empty() && op.top() == "not")
            {
                process_op(st, op.top());
                op.pop();
            }
        }
    }
    while (!op.empty())
    {
        process_op(st, op.top());
        op.pop();
    }
    return st.top();
}

bool check(string *s, int cnt)
{
    if (s[0] == "or" || s[0] == "and" || s[cnt - 1] == "or" || s[cnt - 1] == "and" || s[cnt - 1] == "not")
    {
        return false;
    }
    for (int i = 0; i < cnt; i++)
    {
        if (s[i] == "not" && (s[i + 1] == "or" || s[i + 1] == "and"))
        {
            return false;
        }
    }
    int cnt2 = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (s[i] == "or" || s[i] == "and")
        {
            s2[cnt2++] = 1;
        }
        else if (s[i] == "true" || s[i] == "false")
        {
            s2[cnt2++] = 0;
        }
        if (cnt2 >= 2 && (s2[cnt2 - 2] ^ 1) != s2[cnt2 - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    while (cin >> s[cnt])
    {
        cnt++;
    }
    if (!check(s, cnt))
    {
        cout << "error";
        return 0;
    }
    cout << calculate(s, cnt);
    return 0;
}