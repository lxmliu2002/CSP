#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    char **a = new char *[m + 1];
    int **b = new int *[m + 1];
    int **sum = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        a[i] = new char[n];
        b[i] = new int[n];
        sum[i] = new int[n];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '1')
            {
                b[i][j] = 1;
            }
            else
            {
                b[i][j] = 0;
            }
            sum[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + b[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}