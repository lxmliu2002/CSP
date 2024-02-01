
/*
# 【深基4.例11】数列求和

## 题目描述

计算 $1+2+3+\cdots+(n-1)+n$ 的值，其中正整数 $n$ 不大于 100。由于你没有高斯聪明，所以你不被允许使用等差数列求和公式直接求出答案。

## 输入格式

输入一个正整数 $n$。

## 输出格式

输出一个正整数，表示最后求和的答案。

## 样例 #1

### 样例输入 #1

```
100
```

### 样例输出 #1

```
5050
```

## 提示

数据保证，$1 \leq n \leq 100$。
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << sum;
    return 0;
}