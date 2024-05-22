#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7;
int n, m, a[N], b[N], top;

struct NODE
{
    int k, x;
} st[N];

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    while (m--)
    {
        int k, x;
        cin >> k >> x;
        while (top && st[top].x <= x)
        {
            top--;
        }
        st[++top] = {k, x};
    }
    int nn = st[1].x;
    sort(b + 1, b + 1 + nn);
    int l = 1, r = nn;
    st[top + 1].x = 0;
    for (int i = 1; i <= top; i++)
    {
        int t = st[i].x - st[i + 1].x;
        if (st[i].k == 1)
        {
            while (t--)
            {
                a[nn--] = b[r--];
            }
        }
        else
        {
            while (t--)
            {
                a[nn--] = b[l++];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}