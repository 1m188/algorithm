/*
 * @lc app=leetcode.cn id=面试题 04.06 lang=golang
 * @lcpr version=30204
 *
 * [面试题 04.06] 后继者
 *
 * https://leetcode.cn/problems/successor-lcci/description/
 *
 * LCCI
 * Medium (62.49%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    70K
 * Total Submissions: 112K
 * Testcase Example:  '[2,1,3]\n1'
 *
 * 设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
 *
 * 如果指定节点没有对应的“下一个”节点，则返回null。
 *
 * 示例 1:
 *
 * 输入: root = [2,1,3], p = 1
 *
 * ⁠ 2
 * ⁠/ \
 * 1   3
 *
 * 输出: 2
 *
 * 示例 2:
 *
 * 输入: root = [5,3,6,2,4,null,null,1], p = 6
 *
 * ⁠     5
 * ⁠    / \
 * ⁠   3   6
 * ⁠  / \
 * ⁠ 2   4
 * ⁠/
 * 1
 *
 * 输出: null
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
func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {

	if p == nil {
		return nil
	}

	pre := (*TreeNode)(nil)
	next := (*TreeNode)(nil)
	res := (*TreeNode)(nil)

	var mid func(*TreeNode)
	mid = func(root *TreeNode) {
		if res != nil {
			return
		}

		if root == nil {
			return
		}

		mid(root.Left)
		if next == nil {
			next = root
		} else {
			pre = next
			next = root
		}
		if pre != nil && pre.Val == p.Val {
			res = next
		}
		mid(root.Right)
	}
	mid(root)

	return res

}

// @lc code=end

/*
// @lcpr case=start
// [2,1,3]\n12/ \1   3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n65/ \3   6/ \2   4/   1\n
// @lcpr case=end

*/
