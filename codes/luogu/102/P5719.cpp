/*
# 【深基4.例3】分类平均

## 题目描述

给定 $n$ 和 $k$，将从 1 到 $n$ 之间的所有正整数可以分为两类：A 类数可以被 $k$ 整除（也就是说是 $k$ 的倍数），而 B 类数不能。请输出这两类数的平均数，精确到小数点后 $1$ 位，用空格隔开。

数据保证两类数的个数都不会是 $0$。

## 输入格式

输入两个正整数 $n$ 与 $k$。

## 输出格式

输出一行，两个实数，分别表示 A 类数与 B 类数的平均数。精确到小数点后一位。

## 样例 #1

### 样例输入 #1

```
100 16
```

### 样例输出 #1

```
56.0 50.1
```

## 提示

数据保证，$1 \leq n\leq 10000$，$1 \leq k \leq 100$。
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int nn = n / k;
    double suma = 0;
    double sumb = 0;
    for (int i = 0; i < nn; i++)
    {
        suma += (i + 1) * k;
    }
    for (int i = 0; i < n; i++)
    {
        sumb += (i + 1);
    }
    sumb -= suma;
    double ra = suma / nn;
    double rb = sumb / (n - nn);
    cout << fixed << setprecision(1) << ra << " " << rb;
    return 0;
}