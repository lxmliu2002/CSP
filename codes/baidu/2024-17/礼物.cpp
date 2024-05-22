#include <bits/stdc++.h>
using namespace std;

int cnt1, cnt2, x, y;

bool check(int num)
{
    if (num - num / (x * y) < cnt1 + cnt2)
    {
        return false;
    }
    if (num - num / x < cnt1)
    {
        return false;
    }
    if (num - num / y < cnt2)
    {
        return false;
    }
    return true;
}

int main()
{
    cin >> cnt1 >> cnt2 >> x >> y;
    int l = 1, r = 2e9;
    int ans;
    int cnt = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}