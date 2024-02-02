/*
# 【Mc生存】插火把

## 题目描述

话说有一天 linyorson 在“我的世界”开了一个 $n \times n$ 的方阵，现在他有 $m$ 个火把和 $k$ 个萤石，分别放在 $(x_1, y_1) \sim (x_m, y_m)$ 和 $(o_1, p_1) \sim (o_k, p_k)$ 的位置，没有光并且没放东西的地方会生成怪物。请问在这个方阵中有几个点会生成怪物？

P.S. 火把的照亮范围是：

```
    |暗|暗| 光 |暗|暗|
    |暗|光| 光 |光|暗|
    |光|光|火把|光|光|
    |暗|光| 光 |光|暗|
    |暗|暗| 光 |暗|暗|
```

萤石：

```
    |光|光| 光 |光|光|
    |光|光| 光 |光|光|
    |光|光|萤石|光|光|
    |光|光| 光 |光|光|
    |光|光| 光 |光|光|
```

## 输入格式

输入共 $m + k + 1$ 行。
第一行为 $n, m, k$。
第 $2$ 到第 $m + 1$ 行分别是火把的位置 $x_i, y_i$。
第 $m + 2$ 到第 $m + k + 1$ 行分别是萤石的位置 $o_i, p_i$。

注：可能没有萤石，但一定有火把。

## 输出格式

有几个点会生出怪物。

## 样例 #1

### 样例输入 #1

```
5 1 0
3 3
```

### 样例输出 #1

```
12
```

## 提示

数据保证，$1 \le n \le 100$，$1 \leq m+k \leq 25$，$1 \leq m \leq 25$，$0 \leq k \leq 5$。
*/

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int a[100 + 5][100 + 5]; // 定义一个坐标
int main()
{
    int n, m, k, x, y, ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y; // 输入火把的坐标
        for (int j = x - 1; j <= x + 1; j++)
        {
            for (int k = y - 1; k <= y + 1; k++)
            {
                a[j][k] = 1;
            }
        }
        a[x - 2][y] = 1, a[x + 2][y] = 1, a[x][y - 2] = 1, a[x][y + 2] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y; // 输入萤石的坐标
        for (int j = x - 2; j <= x + 2; j++)
        {
            for (int k = y - 2; k <= y + 2; k++)
            {
                a[j][k] = 1;
            }
        }
    }
    // 搜索如果有没亮的格子答案+1
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}