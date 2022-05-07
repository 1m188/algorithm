/*
　　编程实现两个复数的运算。设有两个复数 和 ，则他们的运算公式为：

　　要求：（1）定义一个结构体类型来描述复数。
　　（2）复数之间的加法、减法、乘法和除法分别用不用的函数来实现。
　　（3）必须使用结构体指针的方法把函数的计算结果返回。
　　说明：用户输入：运算符号(+,-,*,/) a b c d.
　　输出：a+bi，输出时不管a,b是小于0或等于0都按该格式输出，输出时a,b都保留两位。

输入：
　　- 2.5 3.6 1.5 4.9
输出：
　　1.00+-1.30i
*/

#include "iostream"

//复数结构体
struct Plural
{
    float re;
    float im;

    Plural() : re(0), im(0) {}
};

//复数加
Plural *add(Plural &p1, Plural &p2)
{
    p1.re += p2.re;
    p1.im += p2.im;
    return &p1;
}

//复数减
Plural *minus(Plural &p1, Plural &p2)
{
    p1.re -= p2.re;
    p1.im -= p2.im;
    return &p1;
}

//复数乘
Plural *multiply(Plural &p1, Plural &p2)
{
    float re = p1.re * p2.re - p1.im * p2.im;
    float im = p1.re * p2.im + p1.im * p2.re;
    p1.re = re;
    p1.im = im;
    return &p1;
}

//复数除
Plural *divide(Plural &p1, Plural &p2)
{
    float re = (p1.re * p2.re + p1.im * p2.im) / (p2.re * p2.re + p2.im * p2.im);
    float im = (p1.im * p2.re - p1.re * p2.im) / (p2.re * p2.re + p2.im * p2.im);
    p1.re = re;
    p1.im = im;
    return &p1;
}

int main()
{
    //输入
    char op = '\0';
    std::cin >> op;
    Plural p1, p2;
    std::cin >> p1.re >> p1.im >> p2.re >> p2.im;

    //判定操作，获取结果
    Plural *result = NULL;
    switch (op)
    {
    case '+':
        result = add(p1, p2);
        break;
    case '-':
        result = minus(p1, p2);
        break;
    case '*':
        result = multiply(p1, p2);
        break;
    case '/':
        result = divide(p1, p2);
        break;
    }

    //输出
    printf("%.2f+%.2fi", result->re, result->im);

    return 0;
}