/*
# 【深基5.习7】杨辉三角

## 题目描述

给出 $n(n\le20)$，输出杨辉三角的前 $n$ 行。

如果你不知道什么是杨辉三角，可以观察样例找找规律。

## 输入格式

## 输出格式

## 样例 #1

### 样例输入 #1

```
6
```

### 样例输出 #1

```
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
```
*/

#include <iostream>
using namespace std;
int n;
int a[25][25];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i][1] = 1;
        a[i][i] = 1;
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = 2; j < i; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}