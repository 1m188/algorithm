/*
* @lc app=leetcode.cn id=LCR 055 lang=golang
* @lcpr version=30204
*
* [LCR 055] 二叉搜索树迭代器
*
* https://leetcode.cn/problems/kTOapQ/description/
*
  - algorithms
  - Medium (85.13%)
  - Likes:    56
  - Dislikes: 0
  - Total Accepted:    25K
  - Total Submissions: 29.3K
  - Testcase Example:  '["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]\n' +
    '[[[7,3,15,null,null,9,20]],[],[],[],[],[],[],[],[],[]]'

*
* 实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
*
*
*
*
* BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root
* 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
* boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
* int next()将指针向右移动，然后返回指针处的数字。
*
*
* 注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。
*
*
*
* 可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。
*
*
*
* 示例：
*
*
*
* 输入
* inputs = ["BSTIterator", "next", "next", "hasNext", "next", "hasNext",
* "next", "hasNext", "next", "hasNext"]
* inputs = [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [],
* []]
* 输出
* [null, 3, 7, true, 9, true, 15, true, 20, false]
*
* 解释
* BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
* bSTIterator.next();    // 返回 3
* bSTIterator.next();    // 返回 7
* bSTIterator.hasNext(); // 返回 True
* bSTIterator.next();    // 返回 9
* bSTIterator.hasNext(); // 返回 True
* bSTIterator.next();    // 返回 15
* bSTIterator.hasNext(); // 返回 True
* bSTIterator.next();    // 返回 20
* bSTIterator.hasNext(); // 返回 False
*
*
*
*
* 提示：
*
*
* 树中节点的数目在范围 [1, 10^5] 内
* 0 <= Node.val <= 10^6
* 最多调用 10^5 次 hasNext 和 next 操作
*
*
*
*
* 进阶：
*
*
* 你可以设计一个满足下述条件的解决方案吗？next() 和 hasNext() 操作均摊时间复杂度为 O(1) ，并使用 O(h) 内存。其中 h
* 是树的高度。
*
*
*
*
* 注意：本题与主站 173 题相同：
* https://leetcode-cn.com/problems/binary-search-tree-iterator/
*
*/
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type BSTIterator struct {
	current *TreeNode
	start   bool
}

func Constructor(root *TreeNode) BSTIterator {
	pre := (*TreeNode)(nil)
	next := (*TreeNode)(nil)

	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}

		dfs(root.Left)
		if next == nil {
			next = root
		} else if pre == nil {
			pre = next
			next = root
		} else {
			pre.Right = next
			next.Left = pre
			pre = next
			next = root
		}
		dfs(root.Right)
	}
	dfs(root)
	if pre != nil {
		pre.Right = next
	}
	if next != nil {
		next.Left = pre
		next.Right = nil
	}

	res := BSTIterator{}

	var find_left func(*TreeNode)
	find_left = func(root *TreeNode) {
		if root == nil {
			return
		}

		find_left(root.Left)
		if res.current == nil {
			res.current = root
		} else {
			return
		}
		find_left(root.Right)
	}
	find_left(root)

	return res
}

func (this *BSTIterator) Next() int {
	if !this.start {
		this.start = true
	} else {
		this.current = this.current.Right
	}
	return this.current.Val
}

func (this *BSTIterator) HasNext() bool {
	if !this.start {
		return this.current != nil
	} else {
		return this.current.Right != nil
	}
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
// @lc code=end
