/*
问题描述
　　输入一个只包含加减乘除和括号的合法表达式，求表达式的值。其中除表示整除。
输入格式
　　输入一行，包含一个表达式。
输出格式
　　输出这个表达式的值。
样例输入
1-2+3*(4-5)
样例输出
-4
数据规模和约定
　　表达式长度不超过100，表达式运算合法且运算过程都在int内进行。
*/

//这一段代码将输入字符串转换为中缀表达式，之后将中缀表达式转换为后缀表达式，即逆波兰表达式，之后通过栈计算结果

#include "iostream"
#include "sstream"
#include "cstdlib"
#include "string"
#include "vector"
#include "stack"

//输入表达式字符串
std::string str;
//中缀表达式
std::vector<std::string> inFixExpression;
//后缀表达式
std::vector<std::string> postFixExpression;
//辅助求表达式和值的栈
std::stack<std::string> stack;

//字符串转换为中缀表达式
void str2In()
{
    std::string s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            s.push_back(str[i]);
        }
        else
        {
            if (!s.empty())
            {
                inFixExpression.push_back(s);
                s.clear();
            }
            s.push_back(str[i]);
            inFixExpression.push_back(s);
            s.clear();
        }
    }
    if (!s.empty())
    {
        inFixExpression.push_back(s);
    }
}

//中缀表达式转为后缀表达式
void in2Post()
{
    for (int i = 0; i < inFixExpression.size(); i++)
    {
        const std::string &s = inFixExpression[i];
        if (s == "(")
        {
            stack.push(s);
        }
        else if (s == ")")
        {
            while (stack.top() != "(")
            {
                postFixExpression.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
        }
        else if (s == "+" || s == "-")
        {
            while (!stack.empty())
            {
                if (stack.top() != "(")
                {
                    postFixExpression.push_back(stack.top());
                    stack.pop();
                }
                else
                {
                    break;
                }
            }
            stack.push(s);
        }
        else if (s == "*" || s == "/")
        {
            while (!stack.empty())
            {
                if (stack.top() != "(" && stack.top() != "+" && stack.top() != "-")
                {
                    postFixExpression.push_back(stack.top());
                    stack.pop();
                }
                else
                {
                    break;
                }
            }
            stack.push(s);
        }
        else
        {
            postFixExpression.push_back(s);
        }
    }
    while (!stack.empty())
    {
        postFixExpression.push_back(stack.top());
        stack.pop();
    }
}

//字符串转换为int
int str2Int(const std::string &s)
{
    return atoi(s.c_str());
}

//int转为字符串
std::string int2Str(int num)
{
    std::stringstream ss;
    ss << num;
    std::string s;
    ss >> s;
    return s;
}

//根据后缀表达式计算结果
int calc()
{
    for (int i = 0; i < postFixExpression.size(); i++)
    {
        const std::string &s = postFixExpression[i];
        if (s == "+" || s == "-" || s == "*" || s == "/")
        {
            int opr = str2Int(stack.top());
            stack.pop();
            int opl = str2Int(stack.top());
            stack.pop();

            if (s == "+")
            {
                stack.push(int2Str(opl + opr));
            }
            else if (s == "-")
            {
                stack.push(int2Str(opl - opr));
            }
            else if (s == "*")
            {
                stack.push(int2Str(opl * opr));
            }
            else
            {
                stack.push(int2Str(opl / opr));
            }
        }
        else
        {
            stack.push(s);
        }
    }
    return str2Int(stack.top());
}

int main()
{
    std::cin >> str;
    str2In();
    in2Post();
    std::cout << calc();

    return 0;
}