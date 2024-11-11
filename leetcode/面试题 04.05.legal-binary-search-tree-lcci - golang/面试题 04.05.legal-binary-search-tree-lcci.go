/*
 * @lc app=leetcode.cn id=面试题 04.05 lang=golang
 * @lcpr version=30204
 *
 * [面试题 04.05] 合法二叉搜索树
 *
 * https://leetcode.cn/problems/legal-binary-search-tree-lcci/description/
 *
 * LCCI
 * Medium (35.99%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    43.8K
 * Total Submissions: 121.6K
 * Testcase Example:  '[2,1,3]'
 *
 * 实现一个函数，检查一棵二叉树是否为二叉搜索树。示例 1:输入:    2   / \  1   3输出: true示例 2:输入:    5   /
 * \  1   4     / \    3   6输出: false解释: 输入为: [5,1,4,null,null,3,6]。     根节点的值为
 * 5 ，但是其右子节点值为 4 。
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
func isValidBST(root *TreeNode) bool {

	pre := (*TreeNode)(nil)

	var find func(*TreeNode) bool
	find = func(root *TreeNode) bool {
		if root == nil {
			return true
		}

		f := find(root.Left)
		if !f {
			return false
		}

		if pre == nil {
			pre = root
			// return true
		} else {
			if pre.Val >= root.Val {
				pre = root
				return false
			} else {
				pre = root
				// return true
			}
		}

		f = find(root.Right)
		if !f {
			return false
		}

		return true
	}

	return find(root)

}

// @lc code=end
