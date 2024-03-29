/*
# 【深基2.习6】Apples Prologue / 苹果和虫子

## 题目描述

八尾勇喜欢吃苹果。她现在有 $m$（$1 \le m \le 100$）个苹果，吃完一个苹果需要花费 $t$（$0 \le t \le 100$）分钟，吃完一个后立刻开始吃下一个。现在时间过去了 $s$（$1 \le s \le 10000$）分钟，请问她还有几个完整的苹果？

## 输入格式

输入三个**非负整数**表示 $m, t, s$。

## 输出格式

输出一个整数表示答案。

## 样例 #1

### 样例输入 #1

```
50 10 200
```

### 样例输出 #1

```
30
```

## 提示

如果你出现了 RE，不如检查一下被零除？
*/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int m;
    double t, s;
    cin >> m >> t >> s;
    if (t == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << max(0, m - int(ceil(s / t))) << endl;
    return 0;
}