/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

//两个栈倒来倒去，如果需要push的话直接向第一个栈push，如果要pop的话则将第一个栈的内容按顺序弹出并push到第二个栈中，之后pop掉第二个栈的栈顶元素，再把
//所有的元素放回栈1

#include "stack"

using namespace std;

class Solution
{
  public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int top = stack2.top();
        stack2.pop();
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return top;
    }

  private:
    stack<int> stack1;
    stack<int> stack2;
};