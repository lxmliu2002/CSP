/*
# 小鱼的航程（改进版）

## 题目背景

## 题目描述

有一只小鱼，它平日每天游泳 $250$ 公里，周末休息（实行双休日)，假设从周 $x$ 开始算起，过了 $n$ 天以后，小鱼一共累计游泳了多少公里呢？

## 输入格式

输入两个正整数 $x,n$，表示从周 $x$ 算起，经过 $n$ 天。

## 输出格式

输出一个整数，表示小鱼累计游泳了多少公里。

## 样例 #1

### 样例输入 #1

```
3 10
```

### 样例输出 #1

```
2000
```

## 提示

数据保证，$1\le x \le 7$，$1 \le n\le 10^6$。
*/

#include <iostream>
using namespace std;
int main()
{
    unsigned long long x, n;
    cin >> x >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i + x) % 7 == 0 || (i + x) % 7 == 6)
        {
            continue;
        }
        else
        {
            sum += 250;
        }
    }
    cout << sum << endl;
    return 0;
}