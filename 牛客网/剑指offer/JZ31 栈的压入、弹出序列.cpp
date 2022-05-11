/**
 * @file JZ31 栈的压入、弹出序列.cpp
 * @date 2022-05-11
 */

/*
描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
1. 0<=pushV.length == popV.length <=1000
2. -1000<=pushV[i]<=1000
3. pushV 的所有数字均不相同
示例1
输入：
[1,2,3,4,5],[4,5,3,2,1]

返回值：
true

说明：
可以通过push(1)=>push(2)=>push(3)=>push(4)=>pop()=>push(5)=>pop()=>pop()=>pop()=>pop()
这样的顺序得到[4,5,3,2,1]这个序列，返回true      
示例2
输入：
[1,2,3,4,5],[4,3,5,1,2]

返回值：
false

说明：
由于是[1,2,3,4,5]的压入顺序，[4,3,5,1,2]的弹出顺序，要求4，3，5必须在1，2前压入，
且1，2不能弹出，但是这样压入的顺序，1又不能在2之前弹出，所以无法形成的，返回false   
*/

/* 模拟入栈出栈过程，判断是否合法，总之就是如果要出一个元素，在
这个元素入栈之前的元素都要出出去 */

#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> st;

        int idx = 0;                // pushV里的当前准备入栈索引
        for (const int &i : popV) { // 对出栈序列中每一个元素

            // 要么栈为空，要么栈顶元素不等于要出栈的元素，这两种情况都只能往后入栈的部分去找
            while (st.empty() || st.top() != i) {
                if (idx >= pushV.size()) // 能入的栈以及入完了，但是还达不到要求，false
                    return false;
                st.push(pushV[idx++]);
            }

            // 出栈
            if (!st.empty() && st.top() == i)
                st.pop();
        }

        return true;
    }
};