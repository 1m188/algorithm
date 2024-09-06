/*
 * @lc app=leetcode.cn id=面试题 03.02 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 03.02] 栈的最小值
 *
 * https://leetcode.cn/problems/min-stack-lcci/description/
 *
 * LCCI
 * Easy (62.50%)
 * Likes:    99
 * Dislikes: 0
 * Total Accepted:    44.8K
 * Total Submissions: 71.5K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 *
 * 请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。示例：MinStack
 * minStack = new
 * MinStack();minStack.push(-2);minStack.push(0);minStack.push(-3);minStack.getMin();
 * --> 返回 -3.minStack.pop();minStack.top();      --> 返回 0.minStack.getMin();
 * --> 返回 -2.
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class MinStack {
private:
    stack<pair<int, int>> stm;
    stack<int> st;

public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if (st.empty()) {
            st.push(x);
            stm.push({x, x});
        } else {
            st.push(x);
            if (x < stm.top().second)
                stm.push({x, x});
            else
                stm.push({x, stm.top().second});
        }
    }

    void pop() {
        st.pop();
        stm.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return stm.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
