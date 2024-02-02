/*
# 梦中的统计

## 题目背景

Bessie 处于半梦半醒的状态。过了一会儿，她意识到她在数数，不能入睡。

## 题目描述

Bessie 的大脑反应灵敏，仿佛真实地看到了她数过的一个又一个数。她开始注意每一个数码（$0 \ldots 9$）：每一个数码在计数的过程中出现过多少次？

给出两个整数 $M$ 和 $N$，求在序列 $[M, M + 1, M + 2, \ldots, N - 1, N]$ 中每一个数码出现了多少次。

## 输入格式

第 $1$ 行: 两个用空格分开的整数 $M$ 和 $N$。

## 输出格式

第 $1$ 行: 十个用空格分开的整数，分别表示数码 $0 \ldots 9$ 在序列中出现的次数。

## 样例 #1

### 样例输入 #1

```
129 137
```

### 样例输出 #1

```
1 10 2 9 1 1 1 1 0 1
```

## 提示

数据保证，$1 \leq M \leq N \leq 2 \times 10^9$，$N-M \leq 5 \times 10^5$。
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int ans[10] = {0};
    for (int i = m; i <= n; i++)
    {
        int t = i;
        while (t)
        {
            ans[t % 10]++;
            t /= 10;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}