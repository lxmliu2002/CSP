#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], sub[N], num1, num2;
int main()
{
    int ans = 0;
    int buf = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        sub[i] = a[i] - a[i - 1];
        if (sub[i] > 0)
        {
            num1 += sub[i];
        }
        else
        {
            num2 += sub[i];
        }
    }
    cout << max(num1, -num2);
    return 0;
}