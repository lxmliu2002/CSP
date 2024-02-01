/*
# [NOIP2004 提高组] 津津的储蓄计划

## 题目描述

津津的零花钱一直都是自己管理。每个月的月初妈妈给津津 $300$ 元钱，津津会预算这个月的花销，并且总能做到实际花销和预算的相同。

为了让津津学习如何储蓄，妈妈提出，津津可以随时把整百的钱存在她那里，到了年末她会加上 $20\%$ 还给津津。因此津津制定了一个储蓄计划：每个月的月初，在得到妈妈给的零花钱后，如果她预计到这个月的月末手中还会有多于 $100$ 元或恰好 $100$ 元，她就会把整百的钱存在妈妈那里，剩余的钱留在自己手中。


例如 $11$月初津津手中还有 $83$ 元，妈妈给了津津 $300$ 元。津津预计$11$月的花销是 $180$ 元，那么她就会在妈妈那里存 $200$ 元，自己留下 $183$ 元。到了 $11$ 月月末，津津手中会剩下 $3$ 元钱。


津津发现这个储蓄计划的主要风险是，存在妈妈那里的钱在年末之前不能取出。有可能在某个月的月初，津津手中的钱加上这个月妈妈给的钱，不够这个月的原定预算。如果出现这种情况，津津将不得不在这个月省吃俭用，压缩预算。


现在请你根据 $2004$ 年 $1$ 月到 $12$ 月每个月津津的预算，判断会不会出现这种情况。如果不会，计算到 $2004$ 年年末，妈妈将津津平常存的钱加上 $20\%$ 还给津津之后，津津手中会有多少钱。

## 输入格式

$12$ 行数据，每行包含一个小于 $350$ 的非负整数，分别表示 $1$ 月到 $12$ 月津津的预算。

## 输出格式

一个整数。如果储蓄计划实施过程中出现某个月钱不够用的情况，输出 $-X$，$X$ 表示出现这种情况的第一个月；否则输出到 $2004$ 年年末津津手中会有多少钱。

注意，洛谷不需要进行文件输入输出，而是标准输入输出。

## 样例 #1

### 样例输入 #1

```
290
230
280
200
300
170
340
50
90
80
200
60
```

### 样例输出 #1

```
-7
```

## 样例 #2

### 样例输入 #2

```
290
230
280
200
300
170
330
50
90
80
200
60
```

### 样例输出 #2

```
1580
```
*/

#include <iostream>
using namespace std;

int main()
{
    int expenditure, savings = 0, redEnvelopes = 0;

    for (int month = 1; month <= 12; month++)
    {
        cin >> expenditure;
        savings -= expenditure - 300;
        if (savings < 0)
        {
            cout << "-" << month;
            return 0;
        }
        else
        {
            redEnvelopes += savings / 100, savings %= 100;
        }
    }
    cout << 120 * redEnvelopes + savings;
    return 0;
}
