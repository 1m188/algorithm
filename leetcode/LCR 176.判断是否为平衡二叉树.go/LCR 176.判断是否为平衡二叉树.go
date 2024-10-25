/*
 * @lc app=leetcode.cn id=LCR 176 lang=golang
 * @lcpr version=30204
 *
 * [LCR 176] 判断是否为平衡二叉树
 *
 * https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/description/
 *
 * algorithms
 * Easy (59.46%)
 * Likes:    394
 * Dislikes: 0
 * Total Accepted:    277.2K
 * Total Submissions: 466.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 *
 *
 *
 * 示例 1:
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 * 解释：如下图
 *
 *
 *
 *
 * 示例 2:
 *
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 * 解释：如下图
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= 树的结点个数 <= 10000
 *
 *
 * 注意：本题与主站 110 题相同：https://leetcode-cn.com/problems/balanced-binary-tree/
 *
 */
package main

import "math"

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
func isBalanced(root *TreeNode) bool {

	var judge func(*TreeNode) (int, bool)
	judge = func(root *TreeNode) (int, bool) {
		if root == nil {
			return 0, true
		}

		deep_left, f_left := judge(root.Left)
		if !f_left {
			return 0, false
		}

		deep_right, f_right := judge(root.Right)
		if !f_right {
			return 0, false
		}

		if math.Abs(float64(deep_left)-float64(deep_right)) > 1 {
			return 0, false
		}

		return max(deep_left, deep_right) + 1, true
	}

	_, res := judge(root)
	return res

}

// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

*/
