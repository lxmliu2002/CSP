/*
# 【深基4.例2】找最小值

## 题目描述

给出 $n$ 和 $n$ 个整数 $a_i$，求这 $n$ 个整数中最小值是什么。

## 输入格式

第一行输入一个正整数 $n$，表示数字个数。

第二行输入 $n$ 个非负整数，表示 $a_1,a_2 \dots a_n$，以空格隔开。

## 输出格式

输出一个非负整数，表示这 $n$ 个非负整数中的最小值。

## 样例 #1

### 样例输入 #1

```
8
1 9 2 6 0 8 1 7
```

### 样例输出 #1

```
0
```

## 提示

数据保证，$n\le100$ 且 $0\le a_i \le 1000$。
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    cout << min;
    return 0;
}