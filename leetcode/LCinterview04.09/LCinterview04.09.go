/*
 * @lc app=leetcode.cn id=面试题 04.09 lang=golang
 * @lcpr version=30204
 *
 * [面试题 04.09] 二叉搜索树序列
 *
 * https://leetcode.cn/problems/bst-sequences-lcci/description/
 *
 * LCCI
 * Hard (49.80%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 28.2K
 * Testcase Example:  '[2,1,3]'
 *
 * 从左向右遍历一个数组，通过不断将其中的元素插入树中可以逐步地生成一棵二叉搜索树。
 *
 * 给定一个由不同节点组成的二叉搜索树 root，输出所有可能生成此树的数组。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [2,1,3]
 * 输出：[[2,1,3],[2,3,1]]
 * 解释：数组 [2,1,3]、[2,3,1] 均可以通过从左向右遍历元素插入树中形成以下二叉搜索树
 * 2
 * / \
 * 1   3
 *
 *
 *
 *
 * 示例 2：
 *
 * 输入：root = [4,1,null,null,3,2]
 * 输出：[[4,1,3,2]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 二叉搜索树中的节点数在 [0, 1000] 的范围内
 * 1 <= 节点值 <= 10^6
 *
 * 用例保证符合要求的数组数量不超过 5000
 *
 *
 *
 */

// @lcpr-template-start
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

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
func BSTSequences(root *TreeNode) [][]int {

	if root == nil {
		return [][]int{{}}
	}

	res := make([][]int, 0, 5000)
	queue := make([]*TreeNode, 0, 1000)
	queue = append(queue, root)

	var calc func(path []int)
	calc = func(path []int) {
		if len(queue) == 0 {
			res = append(res, append([]int{}, path...))
			return
		}

		size := len(queue)
		for range size {
			node := queue[0]
			queue = queue[1:]
			path = append(path, node.Val)
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
			calc(path)
			path = path[:len(path)-1]
			queue = queue[:size-1]      // 这里额外注意有一个 node 的位置
			queue = append(queue, node) // 这里要把 node 重新加回来，以防止 size 失效
		}
	}

	calc(make([]int, 0, 1000))
	return res
}

// @lc code=end

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,1,null,null,3,2]\n
// @lcpr case=end

*/
