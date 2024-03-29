/*
# 【深基3.习8】三角形分类

## 题目描述

给出三条线段 $a,b,c$ 的长度，均是不大于 $10000$ 的正整数。打算把这三条线段拼成一个三角形，它可以是什么三角形呢？

- 如果三条线段不能组成一个三角形，输出`Not triangle`；
- 如果是直角三角形，输出`Right triangle`；
- 如果是锐角三角形，输出`Acute triangle`；
- 如果是钝角三角形，输出`Obtuse triangle`；
- 如果是等腰三角形，输出`Isosceles triangle`；
- 如果是等边三角形，输出`Equilateral triangle`。

如果这个三角形符合以上多个条件，请按以上顺序分别输出，并用换行符隔开。

## 输入格式

输入 3 个整数 $a$、$b$ 和 $c$。

## 输出格式

输出若干行判定字符串。

## 样例 #1

### 样例输入 #1

```
3 3 3
```

### 样例输出 #1

```
Acute triangle
Isosceles triangle
Equilateral triangle
```

## 样例 #2

### 样例输入 #2

```
3 4 5
```

### 样例输出 #2

```
Right triangle
```

## 样例 #3

### 样例输入 #3

```
6 10 6
```

### 样例输出 #3

```
Obtuse triangle
Isosceles triangle
```

## 样例 #4

### 样例输入 #4

```
1 14 5
```

### 样例输出 #4

```
Not triangle
```

## 提示

当两短边的平方和大于一长边的平方，说明是锐角三角形。

当两短边的平方和等于一长边的平方，说明是直角三角形。

当两短边的平方和小于一长边的平方，说明是钝角三角形。
*/

#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b)
    {
        swap(a, b);
    }
    if (a > c)
    {
        swap(a, c);
    }
    if (b > c)
    {
        swap(b, c);
    }
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        cout << "Not triangle" << endl;
    }
    else
    {
        if (a * a + b * b == c * c)
        {
            cout << "Right triangle" << endl;
        }
        else if (a * a + b * b > c * c)
        {
            cout << "Acute triangle" << endl;
        }
        else
        {
            cout << "Obtuse triangle" << endl;
        }
        if (a == b || b == c || a == c)
        {
            cout << "Isosceles triangle" << endl;
        }
        if (a == b && b == c)
        {
            cout << "Equilateral triangle" << endl;
        }
    }
    return 0;
}