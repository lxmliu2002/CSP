#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n + 1];
    int result = 0;
    int *sum = new int[n + 1];
    int *l = new int[2 * (n + 1)];
    int *r = new int[2 * (n + 1)];
    for (int i = 0; i <= n; i++)
    {
        a[i] = 0;
        sum[i] = 0;
        l[i] = 0;
        l[i + n + 1] = 0;
        r[i] = 0;
        r[i + n + 1] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            a[i] = -1;
        }
        sum[i] = sum[i - 1] + a[i];
        int tmp = sum[i] + n;
        if (!l[tmp])
        {
            l[tmp] = i;
        }
        else
        {
            r[tmp] = i;
        }
    }
    for (int i = 0; i < 2 * n; i++)
    {
        result = max(result, r[i] - l[i]);
    }
    cout << result;

    return 0;
}