/*
# 【深基5.例10】显示屏

## 题目描述

液晶屏上，每个阿拉伯数字都是可以显示成 $3\times5$ 的点阵的（其中 `X` 表示亮点，`.` 表示暗点）。现在给出数字位数（不超过 $100$）和一串数字，要求输出这些数字在显示屏上的效果。数字的显示方式如同样例输出，注意每个数字之间都有一列间隔。

## 输入格式

第一行输入一个正整数 $n$，表示数字的位数。

第二行输入一个长度为 $n$ 的自然数。

## 输出格式

输出五行，表示显示屏上的数字。

## 样例 #1

### 样例输入 #1

```
10
0123456789
```

### 样例输出 #1

```
XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
X.X...X...X...X.X.X.X...X.....X.X.X.X.X
X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
X.X...X.X.....X...X...X.X.X...X.X.X...X
XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
```

## 提示

数据保证，$1 \leq n \leq 100$。
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s, ans[5];
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            ans[0] += "XXX";
            ans[4] += "XXX";
            ans[1] += "X.X";
            ans[2] += "X.X";
            ans[3] += "X.X";
        }
        if (s[i] == '1')
        {
            ans[0] += "..X";
            ans[4] += "..X";
            ans[1] += "..X";
            ans[2] += "..X";
            ans[3] += "..X";
        }
        if (s[i] == '2')
        {
            ans[0] += "XXX";
            ans[4] += "XXX";
            ans[1] += "..X";
            ans[2] += "XXX";
            ans[3] += "X..";
        }
        if (s[i] == '3')
        {
            ans[0] += "XXX";
            ans[4] += "XXX";
            ans[1] += "..X";
            ans[2] += "XXX";
            ans[3] += "..X";
        }
        if (s[i] == '4')
        {
            ans[0] += "X.X";
            ans[4] += "..X";
            ans[1] += "X.X";
            ans[2] += "XXX";
            ans[3] += "..X";
        }
        if (s[i] == '5')
        {
            ans[0] += "XXX";
            ans[4] += "XXX";
            ans[1] += "X..";
            ans[2] += "XXX";
            ans[3] += "..X";
        }
        if (s[i] == '6')
        {
            ans[0] += "XXX";
            ans[4] += "XXX";
            ans[1] += "X..";
            ans[2] += "XXX";
            ans[3] += "X.X";
        }
        if (s[i] == '7')
        {
            ans[0] += "XXX";
            ans[4] += "..X";
            ans[1] += "..X";
            ans[2] += "..X";
            ans[3] += "..X";
        }
        if (s[i] == '8')
        {
            ans[0] += "XXX";
            ans[4] += "XXX";
            ans[1] += "X.X";
            ans[2] += "XXX";
            ans[3] += "X.X";
        }
        if (s[i] == '9')
        {
            ans[0] += "XXX";
            ans[4] += "XXX";
            ans[1] += "X.X";
            ans[2] += "XXX";
            ans[3] += "..X";
        }
        if (i != s.size() - 1)
        {
            ans[0] += ".";
            ans[4] += ".";
            ans[1] += ".";
            ans[2] += ".";
            ans[3] += ".";
        }
    }
    cout << ans[0] << endl
         << ans[1] << endl
         << ans[2] << endl
         << ans[3] << endl
         << ans[4] << endl;
    return 0;
}