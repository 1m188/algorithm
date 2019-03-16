/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (47.86%)
 * Total Accepted:    18.6K
 * Total Submissions: 38.8K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */
class MinStack
{
  private:
    vector<int> v;
    int min = 0;

  public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (v.empty() || x < min)
        {
            min = x;
        }
        v.push_back(x);
    }

    void pop()
    {
        v.pop_back();
        min = *min_element(v.begin(), v.end());
    }

    int top()
    {
        return v.back();
    }

    int getMin()
    {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

// #include "vector"
// #include "algorithm"
// using namespace std;
