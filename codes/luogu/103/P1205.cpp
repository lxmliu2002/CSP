/*
# [USACO1.2] 方块转换 Transformations

## 题目描述

一块 $n \times n$ 正方形的黑白瓦片的图案要被转换成新的正方形图案。写一个程序来找出将原始图案按照以下列转换方法转换成新图案的最小方式：

- 转 $90\degree$：图案按顺时针转 $90\degree$。

- 转 $180\degree$：图案按顺时针转 $180\degree$。

- 转 $270\degree$：图案按顺时针转 $270\degree$。

- 反射：图案在水平方向翻转（以中央铅垂线为中心形成原图案的镜像）。

- 组合：图案在水平方向翻转，然后再按照 $1 \sim 3$ 之间的一种再次转换。

- 不改变：原图案不改变。

- 无效转换：无法用以上方法得到新图案。

如果有多种可用的转换方法，请选择序号最小的那个。

只使用上述 $7$ 个中的一个步骤来完成这次转换。

## 输入格式

第一行一个正整数 $n$。

然后 $n$ 行，每行 $n$ 个字符，全部为 `@` 或 `-`，表示初始的正方形。

接下来 $n$ 行，每行 $n$ 个字符，全部为 `@` 或 `-`，表示最终的正方形。

## 输出格式

单独的一行包括 $1 \sim 7$ 之间的一个数字（在上文已描述）表明需要将转换前的正方形变为转换后的正方形的转换方法。

## 样例 #1

### 样例输入 #1

```
3
@-@
---
@@-
@-@
@--
--@
```

### 样例输出 #1

```
1
```

## 提示

【数据范围】
对于 $100\%$ 的数据，$1\le n \le 10$。

题目翻译来自 NOCOW。

USACO Training Section 1.2
*/

#include <iostream>
#include <string>
using namespace std;

struct matrix
{                   // 开始OOP行为
    int n;          // 数组大小
    char a[15][15]; // 数组本身
    matrix w1(void)
    {
        matrix ans;
        ans.n = this->n;
        for (int i = 0; i < n; i = ++i)
        {
            for (int j = 0; j < n; j = ++j)
            {
                ans.a[j][n - 1 - i] = this->a[i][j];
            }
        }
    }
    // 操作2
    matrix w2(void)
    {
        matrix ans;
        ans.n = this->n;
        for (int i = 0; i < n; i = ++i)
        {
            for (int j = 0; j < n; j = ++j)
            {
                ans.a[n - 1 - i][n - 1 - j] = this->a[i][j];
            } // 手推公式}
            return ans;
        }
    }
    // 操作3
    matrix w3(void)
    {
        matrix ans;
        ans.n = this->n;
        for (int i = 0; i < n; i = ++i)
        {
            for (int j = 0; j < n; j = ++j)
            {
                ans.a[n - 1 - j][i] = this->a[i][j]; // 手推公式
            }
        }
        return ans;
    }
    // 操作4
    matrix w4(void)
    {
        matrix ans;
        ans.n = this->n;
        for (int i = 0; i < n; i = ++i)
        {
            for (int j = 0; j < n; j = ++j)
            {
                ans.a[i][n - j - 1] = this->a[i][j]; // 手推公式
            }
        }
        return ans;
    }
    // 操作4+操作1组成的操作5
    matrix w51(void)
    {
        matrix temp = this->w4();
        matrix ans = temp.w1();
        return ans;
    }
    // 操作4+操作2组成的操作5
    matrix w52(void)
    {
        matrix temp = this->w4();
        matrix ans = temp.w2();
        return ans;
    }
    // 操作4+操作3组成的操作5
    matrix w53(void)
    {
        matrix temp = this->w4();
        matrix ans = temp.w3();
        return ans;
    }
    // 相等函数，Java的老毛病，重载运算符我是真的不会写。。。
    bool equals(matrix a)
    {
        if (a.n != this->n)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < a.n; i = ++i)
            {
                for (int j = 0; j < a.n; j = ++j)
                {
                    if (this->a[i][j] != a.a[i][j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
} orig, latt; // 只用两个类就好了，一个存开始，一个存结束。

int main()
{
    // 输入n，不解释
    int n;
    cin >> n;
    orig.n = n;
    latt.n = n;
    // 开始读入元素
    for (int i = 0; i < n; i = ++i)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            orig.a[i][j] = temp[j];
        }
    }
    for (int i = 0; i < n; i = ++i)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            latt.a[i][j] = temp[j];
        }
    }
    // 现在是判断时间，return 0 是为了结束程序从而输出最小。
    if (orig.w1().equals(latt))
    {
        cout << "1" << endl;
        return 0;
    }

    if (orig.w2().equals(latt))
    {
        cout << "2" << endl;
        return 0;
    }

    if (orig.w3().equals(latt))
    {
        cout << "3" << endl;
        return 0;
    }

    if (orig.w4().equals(latt))
    {
        cout << "4" << endl;
        return 0;
    }
    // 注意每个都满足操作5
    if (orig.w51().equals(latt) || orig.w52().equals(latt) || orig.w53().equals(latt))
    {
        cout << "5" << endl;
        return 0;
    }
    // 操作6就是相等
    if (orig.equals(latt))
    {
        cout << "6" << endl;
        return 0;
    }
    // 操作7放在最后
    cout << "7" << endl;
    return 0;
}