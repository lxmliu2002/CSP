#include <iostream>
#include <queue>

using namespace std;

const int N = 4e5 + 10;

struct Node
{
    int id, v;
    bool operator<(const Node &b) const { return v < b.v; }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int l[N], r[N], ans, a[N], tot;
    bool mark[N];
    priority_queue<Node> q;
    if (m > n / 2)
    {
        cout << "Error!";
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i < n; i++)
    {
        l[i] = i - 1;
        r[i] = i + 1;
        q.push({i, a[i]});
    }
    l[1] = n;
    r[1] = 2;
    l[n] = n - 1;
    r[n] = 1;
    q.push({1, a[1]});
    q.push({n, a[n]});
    tot = n;
    Node tmp;
    for (int i = 1; i <= m; i++)
    {
        tmp = q.top();
        q.pop();
        if (mark[tmp.id])
        {
            i--;
            continue;
        }
        ans += tmp.v;
        a[++tot] = a[l[tmp.id]] + a[r[tmp.id]] - a[tmp.id];
        q.push({tot, a[tot]});
        l[tot] = l[l[tmp.id]];
        r[l[l[tmp.id]]] = tot;
        r[tot] = r[r[tmp.id]];
        l[r[r[tmp.id]]] = tot;
        mark[tmp.id] = mark[l[tmp.id]] = mark[r[tmp.id]] = 1;
    }
    cout << ans;
    return 0;
}