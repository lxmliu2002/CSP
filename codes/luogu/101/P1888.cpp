/*
# 三角函数

## 题目描述

输入一组勾股数 $a,b,c（a\neq b\neq c）$，用分数格式输出其较小锐角的正弦值。（要求约分。）

## 输入格式

一行，包含三个正整数，即勾股数 $a,b,c$（无大小顺序）。

## 输出格式

一行，包含一个分数，即较小锐角的正弦值

## 样例 #1

### 样例输入 #1

```
3 5 4
```

### 样例输出 #1

```
3/5
```

## 提示

数据保证：$a,b,c$ 为正整数且 $\in [1,10^9]$。
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b)
    {
        swap(a, b);
    }
    if (a > c)
    {
        swap(a, c);
    }
    if (b > c)
    {
        swap(b, c);
    }
    cout << a / __gcd(a, c) << "/" << c / __gcd(a, c) << endl;
}
