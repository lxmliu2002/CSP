#include <iostream>
#include <stack>
#include <cmath>

using namespace std;
#define ll long long
const int MOD = 99887765;
const int N = 5e6 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    int a[N], b[N];
    stack<int> st;
    for (int i = 1; i <= n + 1; i++)
    {
        cin >> a[i];
        while (!st.empty() && a[i] < a[st.top()])
        {
            b[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    ll re;
    for (int i = i; i <= n + 1; i++)
    {
        re = re * x + b[i];
        re = (re % MOD + MOD) % MOD;
    }
    cout << re;

    return 0;
}