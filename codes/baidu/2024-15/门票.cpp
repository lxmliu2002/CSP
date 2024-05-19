#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 100;
const long long mod = 1e9 + 7;

long long a[N], b[N], c[N];
long long tree[N];

long long lowbit(long long x)
{
    return x & -x;
}
long long sum(long long x)
{
    long long sum = 0;
    while (x)
    {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}
void add(long long x)
{
    while (x < N)
    {
        tree[x]++;
        x += lowbit(x);
    }
}
int main()
{
    long long n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i] - i * t;
        c[i] = b[i];
    }
    sort(c, c + 1 + n);
    long long result = 0;
    for (int i = 0; i <= n; i++)
    {
        long long pos = lower_bound(c, c + n + 1, b[i]) - c + 1;
        result += sum(pos);
        add(pos);
        result %= mod;
    }
    cout << result;
    return 0;
}