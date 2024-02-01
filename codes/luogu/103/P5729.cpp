/*
# 【深基5.例7】工艺品制作

## 题目描述

现有一个长宽高分别为 $w,x,h$ 组成的实心玻璃立方体，可以认为是由 $1\times1\times1$ 的数个小方块组成的，每个小方块都有一个坐标 $ ( i,j,k ) $。现在需要进行 $q$ 次切割。每次切割给出 $(x_1,y_1,z_1),(x_2,y_2,z_2)$ 这 6 个参数，保证 $x_1\le x_2$，$y_1\le y_2$，$z_1\le z_2$；每次切割时，使用激光工具切出一个立方体空洞，空洞的壁平行于立方体的面，空洞的对角点就是给出的切割参数的两个点。

换句话说，所有满足  $x_1\le i\le x_2$，$y_1\le j \le y_2 $，$z_1\le k\le z_2$ 的小方块 $(i,j,k)$ 的点都会被激光蒸发。例如有一个  $4\times4\times 4$ 的大方块，其体积为 $64$；给出参数 $(1,1,1),(2,2,2)$ 时，中间的 $8$ 块小方块就会被蒸发，剩下 $56$ 个小方块。现在想知道经过所有切割操作后，剩下的工艺品还剩下多少格小方块的体积？

## 输入格式

第一行三个正整数 $w,x,h$。

第二行一个正整数 $q$。

接下来 $q$ 行，每行六个整数 $(x_1,y_1,z_1),(x_2,y_2,z_2)$。

## 输出格式

输出一个整数表示答案。

## 样例 #1

### 样例输入 #1

```
4 4 4
1
1 1 1 2 2 2
```

### 样例输出 #1

```
56
```

## 提示

数据保证，$1\le w,x,h\le 20$，$1 \leq q\le 100$。$1 \leq x_1 \leq x_2 \leq w$，$1 \leq y_1\leq y_2 \leq x$，$1 \leq z_1 \leq z_2 \leq h$。
*/

#include <iostream>
using namespace std;
int main()
{
    int w, x, h;
    cin >> w >> x >> h;
    int a[20][20][20];
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < h; k++)
            {
                a[i][j][k] = 1;
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1 - 1; i < x2; i++)
        {
            for (int j = y1 - 1; j < y2; j++)
            {
                for (int k = z1 - 1; k < z2; k++)
                {
                    a[i][j][k] = 0;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < h; k++)
            {
                if (a[i][j][k] == 1)
                {
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}