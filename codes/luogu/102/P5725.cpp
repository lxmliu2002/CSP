/*
# 【深基4.习8】求三角形

## 题目描述

模仿例题，打印出不同方向的正方形，然后打印三角形矩阵。中间有个空行。

## 输入格式

输入矩阵的规模，不超过 $9$。

## 输出格式

输出矩形和正方形

## 样例 #1

### 样例输入 #1

```
4
```

### 样例输出 #1

```
01020304
05060708
09101112
13141516

      01
    0203
  040506
07080910
```
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cnt = 1;

    for (int i = 1; i <= n * n; i++)
    {
        if (i < 10)
        {
            cout << setw(2) << setfill('0') << i;
        }
        else
        {
            cout << setw(2) << i;
        }
        if (i % n == 0)
        {
            cout << endl;
        }
    }
    cout << endl;

    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum +=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<=n-i)
            {
                cout << "  ";
            }
            else
            {
                if(cnt<10)
                {
                    cout << "0";
                }
                cout << cnt;
                cnt++;
            }
        }
        cout << endl;
    }
    return 0;
}