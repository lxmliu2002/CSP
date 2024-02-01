/*
# 【深基4.习5】求极差 / 最大跨度值

## 题目描述

给出 $n$ 和 $n$ 个整数 $a_i$，求这 $n$ 个整数中的极差是什么。极差的意思是一组数中的最大值减去最小值的差。

## 输入格式

第一行输入一个正整数 $n$，表示整数个数。

第二行输入 $n$ 个整数 $a_1,a_2 \dots a_n$，以空格隔开。

## 输出格式

输出一个整数，表示这 $n$ 个整数的极差。

## 样例 #1

### 样例输入 #1

```
6
4 1 5 1 4 1
```

### 样例输出 #1

```
4
```

## 提示

数据保证，$1 \leq n\leq 100$，$0\le a_i \le 1000$。
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int max = 0, min = 1000;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a > max)
        {
            max = a;
        }
        if (a < min)
        {
            min = a;
        }
    }
    cout << max - min;
    return 0;
}