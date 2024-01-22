/*
# 【深基2.习2】三角形面积

## 题目描述

一个三角形的三边长分别是 $a$、$b$、$c$，那么它的面积为 $\sqrt{p(p-a)(p-b)(p-c)}$，其中 $p=\frac{1}{2}(a+b+c)$。输入这三个数字，计算三角形的面积，四舍五入精确到 $1$ 位小数。

## 输入格式

第一行输入三个实数 $a,b,c$，以空格隔开。

## 输出格式

输出一个实数，表示三角形面积。精确到小数点后 $1$ 位。

## 样例 #1

### 样例输入 #1

```
3 4 5
```

### 样例输出 #1

```
6.0
```

## 提示

数据保证能构成三角形，$0\leq a,b,c\leq 1000$，每个边长输入时不超过 $2$ 位小数。
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double p = (a + b + c) / 2;
    cout << fixed << setprecision(1) << sqrt(p * (p - a) * (p - b) * (p - c));
    return 0;
}