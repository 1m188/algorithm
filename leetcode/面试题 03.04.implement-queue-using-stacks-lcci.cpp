/*
 * @lc app=leetcode.cn id=面试题 03.04 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 03.04] 化栈为队
 *
 * https://leetcode.cn/problems/implement-queue-using-stacks-lcci/description/
 *
 * LCCI
 * Easy (71.70%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    38.6K
 * Total Submissions: 53.8K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 实现一个MyQueue类，该类用两个栈来实现一个队列。示例：MyQueue queue = new
 * MyQueue();queue.push(1);queue.push(2);queue.peek();  // 返回 1queue.pop();
 * // 返回 1queue.empty(); // 返回 false说明：你只能使用标准的栈操作 -- 也就是只有 push to top,
 * peek/pop from top, size 和 is empty 操作是合法的。你所使用的语言也许不支持栈。你可以使用 list 或者
 * deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
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
class MyQueue {
private:
    stack<int> s1, s2;

public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }

    /** Get the front element. */
    int peek() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
