/*
* @lc app=leetcode.cn id=LCR 147 lang=golang
* @lcpr version=30204
*
* [LCR 147] 最小栈
*
* https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/description/
*
  - algorithms
  - Easy (55.32%)
  - Likes:    541
  - Dislikes: 0
  - Total Accepted:    378K
  - Total Submissions: 683.1K
  - Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
    '[[],[-2],[2],[-3],[],[],[],[]]'

*
* 请你设计一个 最小栈 。它提供 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
*
*
*
* 实现 MinStack 类:
*
*
* MinStack() 初始化堆栈对象。
* void push(int val) 将元素val推入堆栈。
* void pop() 删除堆栈顶部的元素。
* int top() 获取堆栈顶部的元素。
* int getMin() 获取堆栈中的最小元素。
*
*
*
*
* 示例 1:
*
* 输入：
* ["MinStack","push","push","push","getMin","pop","top","getMin"]
* [[],[-2],[2],[-3],[],[],[],[]]
*
* 输出：
* [null,null,null,null,-3,null,2,-2]
*
* 解释：
* MinStack minStack = new MinStack();
* minStack.push(-2);
* minStack.push(2);
* minStack.push(-3);
* minStack.getMin();   --> 返回 -3.
* minStack.pop();
* minStack.top();      --> 返回 2.
* minStack.getMin();   --> 返回 -2.
*
*
*
*
*
* 提示：
*
*
* -2^31 <= val <= 2^31 - 1
* pop、top 和 getMin 操作总是在 非空栈 上调用
* push、pop、top 和 getMin 最多被调用 3 * 10^4 次
*
*
*
*
* 注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/
*
*
*
*/
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
type MinStack struct {
	stack     []int
	min_stack []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(x int) {
	if len(this.stack) == 0 {
		this.stack = append(this.stack, x)
		this.min_stack = append(this.min_stack, x)
	} else {
		this.stack = append(this.stack, x)
		if x < this.min_stack[len(this.min_stack)-1] {
			this.min_stack = append(this.min_stack, x)
		} else {
			this.min_stack = append(this.min_stack, this.min_stack[len(this.min_stack)-1])
		}
	}
}

func (this *MinStack) Pop() {
	this.stack = this.stack[:len(this.stack)-1]
	this.min_stack = this.min_stack[:len(this.min_stack)-1]
}

func (this *MinStack) Top() int {
	return this.stack[len(this.stack)-1]
}

func (this *MinStack) GetMin() int {
	return this.min_stack[len(this.min_stack)-1]
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[2],[-3],[],[],[],[]]\n
// @lcpr case=end

*/
