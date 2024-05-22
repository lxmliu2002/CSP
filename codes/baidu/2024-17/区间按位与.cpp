#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 7;
int m, n, a[N], mn[N][50], Lg[N], ans;
void pre()
{
    Lg[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        Lg[i] = Lg[i >> 1] + 1;
    }
}
void ST_create()
{
    for (int i = 1; i <= n; i++)
    {
        mn[i][0] = a[i];
    }
    for (int j = 1; j <= Lg[n]; j++)
    {
        for (int i = 1; i <= n - (1 << j) + 1; i++)
        {
            mn[i][j] = mn[i][j - 1] & mn[i + (1 << (j - 1))][j - 1];
        }
    }
}

int ST_query(int l, int r)
{
    int k = Lg[r - l + 1];
    return mn[l][k] & mn[r - (1 << k) + 1][k];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    pre();
    ST_create();
    while (m--)
    {
        int a1, a2;
        cin >> a1 >> a2;
        cout << ST_query(a1, a2) << endl;
    }
    return 0;
}