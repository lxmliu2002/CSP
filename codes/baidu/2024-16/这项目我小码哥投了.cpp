#include <iostream>
#include <stack>

using namespace std;

const int N = 1e3 + 7;
int n,m,a[N][N],ans;
char ch;

int maxRec(int x)
{
    int ret = 0;
    stack<int> s;
    s.push(0);
    for(int i = 1;i<= m+1;i++)
    {
        while(a[x][i] < a[x][s.top()])
        {
            int h = a[x][s.top()];
            s.pop();
            int w = i -s.top() - 1;
            ret = max(ret ,w * h);
        }
        s.push(i);
    }
    return ret;
}
