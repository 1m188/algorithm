/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

#include "stack"

class Solution
{
  private:
    std::stack<int> stack;
    int minValue = 0;

  public:
    void push(int value)
    {
        if (stack.empty())
        {
            minValue = value;
        }
        else if (value < minValue)
        {
            minValue = value;
        }
        stack.push(value);
    }

    //注意pop出去了之后要获取剩下的栈中元素的最小值
    void pop()
    {
        stack.pop();
        if (stack.empty())
        {
            minValue = 0;
        }
        else
        {
            minValue = stack.top();
            std::stack<int> s;
            while (!stack.empty())
            {
                if (stack.top() < minValue)
                {
                    minValue = stack.top();
                }
                s.push(stack.top());
                stack.pop();
            }
            while (!s.empty())
            {
                stack.push(s.top());
                s.pop();
            }
        }
    }

    int top()
    {
        return stack.top();
    }

    int min()
    {
        return minValue;
    }
};