/*
# [AHOI2001] 彩票摇奖

## 题目描述

为了丰富人民群众的生活、支持某些社会公益事业，北塔市设置了一项彩票。该彩票的规则是：

1. 每张彩票上印有 $7$ 个各不相同的号码，且这些号码的取值范围为 $1\sim33$。
2. 每次在兑奖前都会公布一个由七个各不相同的号码构成的中奖号码。
3. 共设置 $7$ 个奖项，特等奖和一等奖至六等奖。

兑奖规则如下：
- 特等奖：要求彩票上 $7$ 个号码都出现在中奖号码中。
- 一等奖：要求彩票上有 $6$ 个号码出现在中奖号码中。
- 二等奖：要求彩票上有 $5$ 个号码出现在中奖号码中。
- 三等奖：要求彩票上有 $4$ 个号码出现在中奖号码中。
- 四等奖：要求彩票上有 $3$ 个号码出现在中奖号码中。
- 五等奖：要求彩票上有 $2$ 个号码出现在中奖号码中。
- 六等奖：要求彩票上有 $1$ 个号码出现在中奖号码中。

注：兑奖时并不考虑彩票上的号码和中奖号码中的各个号码出现的位置。例如，中奖号码为 $23\ 31\ 1\ 14\ 19\ 17\ 18$，则彩票 $12\ 8\ 9\ 23\ 1\ 16\ 7$ 由于其中有两个号码（$23$ 和 $1$）出现在中奖号码中，所以该彩票中了五等奖。

现已知中奖号码和小明买的若干张彩票的号码，请你写一个程序帮助小明判断他买的彩票的中奖情况。

## 输入格式

输入的第一行只有一个自然数 $n$，表示小明买的彩票张数；

第二行存放了 $7$ 个介于 $1$ 和 $33$ 之间的自然数，表示中奖号码；

在随后的 $n$ 行中每行都有 $7$ 个介于 $1$ 和 $33$ 之间的自然数，分别表示小明所买的 $n$ 张彩票。

## 输出格式

依次输出小明所买的彩票的中奖情况（中奖的张数），首先输出特等奖的中奖张数，然后依次输出一等奖至六等奖的中奖张数。

## 样例 #1

### 样例输入 #1

```
2
23 31 1 14 19 17 18
12 8 9 23 1 16 7
11 7 10 21 2 9 31
```

### 样例输出 #1

```
0 0 0 0 0 1 1
```

## 提示

#### 数据规模与约定

对于 $100\%$ 的数据，保证 $1 \leq n\lt1000$。
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[7];
    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }
    int cnt[7] = {0};
    int b[7];
    for (int i = 0; i < n; i++)
    {
        int cnt1 = 0;
        for (int j = 0; j < 7; j++)
        {
            cin >> b[j];
        }
        for (int j = 0; j < 7; j++)
        {
            for (int k = 0; k < 7; k++)
            {
                if (a[j] == b[k])
                {
                    cnt1++;
                }
            }
        }
        switch (cnt1)
        {
        case 7:
            cnt[0]++;
            break;
        case 6:
            cnt[1]++;
            break;
        case 5:
            cnt[2]++;
            break;
        case 4:
            cnt[3]++;
            break;
        case 3:
            cnt[4]++;
            break;
        case 2:
            cnt[5]++;
            break;
        case 1:
            cnt[6]++;
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}