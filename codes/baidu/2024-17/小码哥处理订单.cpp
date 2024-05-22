#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int n, m, r[N], d[N], s[N], t[N];
bool check(int num)
{
    int sub[N], need[N];
    // 给sub数组的值全部初始化为0
    memset(sub, 0, sizeof(sub));
    for (int i = 1; i <= num; i++)
    {
        // 数组的差分求值，防止累加到重复值
        sub[s[i]] += d[i];
        sub[t[i] + 1] -= d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        // 前缀和求出每一天至少需要多少个房间
        need[i] = need[i - 1] + sub[i];
        // 每一天需要的房间和出租房间比较
        if (need[i] > r[i])
        { // 不满足出租要求
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> d[i] >> s[i] >> t[i];
    }
    int left = 1;
    int right = m;
    if (!check(m))
    { // 当全部订单均满足
        cout << 0;
        return 0;
    }
    int mid, ans;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        // 当订单未满足时，查找第一天未满足的订单
        if (check(mid))
        {
            right = mid - 1;
            ans = mid;
        }
        else
        { // 订单满足
            left = mid + 1;
        }
    }
    cout << "-1" << endl;
    cout << ans;
    return 0;
}