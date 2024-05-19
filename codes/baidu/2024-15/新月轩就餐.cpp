#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10, M = 2005;
const int INF = 0X3f3f3f3f;
deque<int> q;
int ans = INF;
int n, m, cnt[M], a[N], l, r, type;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!cnt[a[i]])
        {
            type++;
        }
        cnt[a[i]]++;
        q.push_back(i);
        while (!q.empty() && cnt[a[q.front()]] > 1)
        {
            cnt[a[q.front()]]--;
            q.pop_front();
        }
        if (type == m)
        {
            if (q.size() < ans)
            {
                ans = q.size();
                l = q.front();
                r = q.back();
            }
        }
    }
    cout << l << " " << r << endl;
    return 0;
}