/*
# 【深基2.例8】再分肥宅水

## 题目描述

现在有 $t$ 毫升肥宅快乐水，要均分给 $n$ 名同学。每名同学需要 $2$ 个杯子。现在想知道每名同学可以获得多少毫升饮料（严格精确到小数点后 $3$ 位），以及一共需要多少个杯子。

## 输入格式

输入一个实数 $t$ 和一个正整数 $n$，使用空格隔开。

## 输出格式

输出两行。

第一行输出一个三位小数，表示可以获得多少毫升饮料。第二行输出一个正整数，表示一共需要多少个杯子。

## 样例 #1

### 样例输入 #1

```
500.0 3
```

### 样例输出 #1

```
166.667
6
```

## 提示

对于所有数据，$0\leq t\leq 10000$ 且小数点后不超过 $3$ 位，$1\leq n\leq 1000$。
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double t;
    int n;
    cin >> t >> n;
    cout << fixed << setprecision(3) << t / n << endl
         << n * 2;
    return 0;
}