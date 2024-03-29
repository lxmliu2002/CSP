/*
# [NOIP2012 普及组] 质因数分解

## 题目描述

已知正整数 $n$ 是两个不同的质数的乘积，试求出两者中较大的那个质数。

## 输入格式

输入一个正整数 $n$。

## 输出格式

输出一个正整数 $p$，即较大的那个质数。

## 样例 #1

### 样例输入 #1

```
21
```

### 样例输出 #1

```
7
```

## 提示

$1 \le n\le 2\times 10^9$

NOIP 2012 普及组 第一题
*/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 2;
    while (i <= sqrt(n))
    {
        if (n % i == 0)
        {
            break;
        }
        i++;
    }
    cout << n / i;
    return 0;
}