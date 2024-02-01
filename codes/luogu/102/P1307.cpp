/*
# [NOIP2011 普及组] 数字反转

## 题目描述

给定一个整数 $N$，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例 2）。

## 输入格式

一个整数 $N$。

## 输出格式

一个整数，表示反转后的新数。

## 样例 #1

### 样例输入 #1

```
123
```

### 样例输出 #1

```
321
```

## 样例 #2

### 样例输入 #2

```
-380
```

### 样例输出 #2

```
-83
```

## 提示

**【数据范围】**

$-1,000,000,000\leq N\leq 1,000,000,000 $。

noip2011 普及组第一题
*/

#include <iostream>
using namespace std;
bool iszero(string n)
{
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] != '0')
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string N;
    cin >> N;
    bool flag = true;
    if (N[0] == '-')
    {
        cout << '-';
        for (int i = N.length() - 1; i >= 1; i--)
        {
            if (iszero(N.substr(1, N.length() - 1)))
            {
                cout << 0;
                return 0;
            }
            if (N[i] == '0' && flag && N.length() > 2)
            {
                continue;
            }
            if (N[i] != '0')
            {
                flag = false;
            }
            cout << N[i];
        }
    }
    else
    {
        for (int i = N.length() - 1; i >= 0; i--)
        {
            if (iszero(N))
            {
                cout << 0;
                return 0;
            }
            if (N[i] == '0' && flag && N.length() > 1)
            {
                continue;
            }
            if (N[i] != '0')
            {
                flag = false;
            }
            cout << N[i];
        }
    }
    return 0;
}