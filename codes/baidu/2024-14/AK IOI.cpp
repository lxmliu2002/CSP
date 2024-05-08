#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct NODE
{
    uint64_t x;
    uint64_t t;
};

bool cmp(NODE a, NODE b)
{
    return a.x < b.x;
}

int main()
{
    uint64_t n, m;
    cin >> n >> m;
    uint64_t sum = 0;
    uint64_t result = 0;
    priority_queue<uint64_t> q;

    NODE *nodes = new NODE[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i].x >> nodes[i].t;
    }
    // sort(nodes + 1, nodes + n + 1, cmp);
    sort(nodes, nodes + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (sum + nodes[i].x + nodes[i].t <= m)
        {
            sum += nodes[i].t;
            q.push(nodes[i].t);
        }
        else if (!q.empty() && sum - q.top() + nodes[i].x + nodes[i].t <= m)
        {
            sum = sum - q.top() + nodes[i].t;
            q.pop();
            q.push(nodes[i].t);
        }
    }
    cout << q.size();

    return 0;
}