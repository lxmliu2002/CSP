/*
# 【深基4.例6】数字直角三角形

## 题目描述

给出 $n$，请输出一个直角边长度是 $n$ 的数字直角三角形。所有数字都是 $2$ 位组成的，如果没有 $2$ 位则加上前导 $0$。

## 输入格式

输入一个正整数 $n$。

## 输出格式

输出如题目要求的数字直角三角形。

## 样例 #1

### 样例输入 #1

```
5
```

### 样例输出 #1

```
0102030405
06070809
101112
1314
15
```

## 提示

数据保证，$1\le n\le13$。
*/

#include <iostream>
using namespace std;
void outputn(int n)
{
    if (n < 10)
    {
        cout << "0";
    }
    cout << n;
}
int main()
{
    int n;
    cin >> n;
    int sum = 1;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            outputn(sum);
            sum++;
        }
        cout << endl;
    }
    return 0;
}