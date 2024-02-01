/*
# [NOIP2013 普及组] 计数问题

## 题目背景

NOIP2013 普及组 T1

## 题目描述

试计算在区间 $1$ 到 $n$ 的所有整数中，数字 $x$（$0\le x\le9$）共出现了多少次？例如，在 $1$ 到 $11$ 中，即在 $1,2,3,4,5,6,7,8,9,10,11$ 中，数字 $1$ 出现了 $4$ 次。

## 输入格式

$2$ 个整数 $n,x$，之间用一个空格隔开。

## 输出格式

$1$ 个整数，表示 $x$ 出现的次数。

## 样例 #1

### 样例输入 #1

```
11 1
```

### 样例输出 #1

```
4
```

## 提示

对于 $100\%$ 的数据，$1\le n\le 10^6$，$0\le x \le 9$。
*/

#include <iostream>
using namespace std;
int count(int x, int num)
{
    int cnt = 0;
    while (num)
    {
        if (num % 10 == x)
        {
            cnt++;
        }
        num /= 10;
    }
    return cnt;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        cnt += count(x, i);
    }
    cout << cnt;
    return 0;
}