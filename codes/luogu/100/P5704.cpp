/*
# 【深基2.例6】字母转换

## 题目描述

输入一个小写字母，输出其对应的大写字母。例如输入 q[回车] 时，会输出 Q。

## 输入格式

## 输出格式

## 样例 #1

### 样例输入 #1

```
q
```

### 样例输出 #1

```
Q
```
*/

#include <iostream>
using namespace std;
int main()
{
    char a;
    cin >> a;
    cout << char(a - 32);
    return 0;
}