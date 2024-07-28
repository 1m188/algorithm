/*
描述
牛牛是一个非常聪明的牛，它想要实现一个队列，但是由于某些限制，它只能使用栈来模拟队列的操作。请你帮助牛牛实现一个能够支持队列的全部操作的栈。

请实现以下函数：

vector<int> queueFromStack(const vector<int>& input);
函数参数：

input：一个整数数组，表示输入的操作序列。其中，正数表示 push 操作，负数表示 pop 操作。
返回值：

返回一个整数数组，表示操作序列执行后的输出。
注意：

你只能使用栈的基本操作 —— 也就是 push、pop、top 和 empty 这些操作。
你所使用的语言也许不支持栈。你可以使用 vector 或者 list 来模拟一个栈，只要是标准的栈操作即可。
示例1
输入：
[1, 2, -1, 3, -1]
复制
返回值：
[1,2]
复制
备注：
1 <= input.length <= 2*10^5
- 2*10^5 <= input[i] <= 2*10^5
*/

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param input int整型vector
     * @return int整型vector
     */
    vector<int> queueFromStack(vector<int> &input) {
        // write code here

        stack<int> st1, st2;

        auto push = [&](int x) {
            st1.push(x);
        };
        auto pop = [&]() -> int {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            int x = st2.top();
            st2.pop();
            while (!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
            return x;
        };

        vector<int> res;
        for (int x : input) {
            if (x > 0)
                push(x);
            else
                res.push_back(pop());
        }
        return res;
    }
};