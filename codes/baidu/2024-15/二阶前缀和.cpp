#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    int n, R;
    cin >> n >> R;
    int x = 0, y = 0, v = 0;
    int **ary = new int *[1005];
    int **prefix = new int *[1005];
    for (int i = 0; i < 1005; i++)
    {
        ary[i] = new int[1005];
        prefix[i] = new int[1005];
        for (int j = 0; j < 1005; j++)
        {
            ary[i][j] = 0;
            prefix[i][j] = 0;
        }
    }

    while (n--)
    {
        cin >> x >> y >> v;
        ary[++x][++y] += v;
    }

    for (int i = 1; i < 1005; i++)
    {
        for (int j = 1; j < 1005; j++)
        {
            prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + ary[i][j];
        }
    }
    int result = 0;
    for (int i = R; i < 1005; i++)
    {
        for (int j = R; j < 1005; j++)
        {
            result = max(result, prefix[i][j] - prefix[i - R][j] - prefix[i][j - R] + prefix[i - R][j - R]);
        }
    }
    cout << result;

    return 0;
}