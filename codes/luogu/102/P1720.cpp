/*
# 月落乌啼算钱（斐波那契数列）

## 题目背景

（本道题目木有隐藏歌曲……不用猜了……）

《爱与愁的故事第一弹·heartache》最终章。

吃完 pizza，月落乌啼知道超出自己的预算了。为了不在爱与愁大神面前献丑，只好还是硬着头皮去算钱……

## 题目描述

算完钱后，月落乌啼想着：“你坑我！”于是当爱与愁大神问多少钱时，月落乌啼说了一堆乱码。爱与愁大神说：“算了算了，我只问第 $n$ 样菜价格多少？”月落乌啼写出了：

$$F_n=\dfrac{\left(\frac{1+\sqrt{5}}{2}\right)^n-\left(\frac{1-\sqrt{5}}{2}\right)^n}{\sqrt{5}}$$

由于爱与愁大神学过编程，于是就用 $1$ 分钟的时间求出了 $F_n$ 的结果。月落乌啼为此大吃一惊。你能学学爱与愁大神求出 $F_n$ 的值吗？

## 输入格式

一行一个自然数 $n$。

## 输出格式

只有 $1$ 行一个实数 $F_n$，保留两位小数。

## 样例 #1

### 样例输入 #1

```
6
```

### 样例输出 #1

```
8.00
```

## 提示

对于所有数据：$0 \leq n\leq 48$。
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double a = (1 + sqrt(5)) / 2;
    double b = (1 - sqrt(5)) / 2;
    double ans = (pow(a, n) - pow(b, n)) / sqrt(5);
    cout << fixed << setprecision(2) << ans;
    return 0;
}