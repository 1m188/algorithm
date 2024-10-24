/*
 * @lc app=leetcode.cn id=LCR 045 lang=golang
 * @lcpr version=30204
 *
 * [LCR 045] 找树左下角的值
 *
 * https://leetcode.cn/problems/LwUNpT/description/
 *
 * algorithms
 * Medium (78.59%)
 * Likes:    53
 * Dislikes: 0
 * Total Accepted:    37.3K
 * Total Submissions: 47.5K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 *
 * 假设二叉树中至少有一个节点。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入: root = [2,1,3]
 * 输出: 1
 *
 *
 * 示例 2:
 *
 * ⁠
 *
 * 输入: [1,2,3,4,null,5,6,null,null,7]
 * 输出: 7
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [1,10^4]
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 *
 *
 * 注意：本题与主站 513 题相同：
 * https://leetcode-cn.com/problems/find-bottom-left-tree-value/
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
func findBottomLeftValue(root *TreeNode) int {

	res := root.Val
	que := []*TreeNode{root}

	for len(que) > 0 {
		res = que[0].Val
		que2 := []*TreeNode{}
		for _, value := range que {
			if value.Left != nil {
				que2 = append(que2, value.Left)
			}
			if value.Right != nil {
				que2 = append(que2, value.Right)
			}
		}
		que = que2
	}

	return res

}

// @lc code=end

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,5,6,null,null,7]\n
// @lcpr case=end

*/
