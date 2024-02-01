/*
# 最长连号

## 题目描述

输入长度为 $n$ 的一个正整数序列，要求输出序列中最长连号的长度。

连号指在序列中，从小到大的连续自然数。

## 输入格式

第一行，一个整数 $n$。

第二行，$n$ 个整数 $a_i$，之间用空格隔开。

## 输出格式

一个数，最长连号的个数。

## 样例 #1

### 样例输入 #1

```
10
1 5 6 2 3 4 5 6 8 9
```

### 样例输出 #1

```
5
```

## 提示

#### 数据规模与约定

对于 $100\%$ 的数据，保证 $1 \leq n \leq 10^4$，$1 \leq a_i \leq 10^9$。
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int max = 0, cnt = 1;
    int a, b;
    cin >> a;
    for (int i = 1; i < n; i++)
    {
        cin >> b;
        if (b - a == 1)
        {
            cnt++;
        }
        else
        {
            if (cnt > max)
            {
                max = cnt;
            }
            cnt = 1;
        }
        a = b;
    }
    if (cnt > max)
    {
        max = cnt;
    }
    cout << max;
    return 0;
}