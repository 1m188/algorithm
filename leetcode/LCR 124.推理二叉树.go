/*
 * @lc app=leetcode.cn id=LCR 124 lang=golang
 * @lcpr version=30204
 *
 * [LCR 124] 推理二叉树
 *
 * https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/description/
 *
 * algorithms
 * Medium (70.09%)
 * Likes:    1143
 * Dislikes: 0
 * Total Accepted:    356.5K
 * Total Submissions: 508.6K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 某二叉树的先序遍历结果记录于整数数组 preorder，它的中序遍历结果记录于整数数组 inorder。请根据 preorder 和 inorder
 * 的提示构造出这棵二叉树并返回其根节点。
 *
 *
 *
 * 注意：preorder 和 inorder 中均不含重复数字。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 *
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 *
 *
 * 示例 2:
 *
 * 输入: preorder = [-1], inorder = [-1]
 *
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
 *
 *
 *
 *
 * 注意：本题与主站 105
 * 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *
 *
 *
 */
package leetcode

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
func deduceTree(preorder []int, inorder []int) *TreeNode {

	if len(preorder) == 0 || len(inorder) == 0 {
		return nil
	}
	if len(preorder) == 1 || len(inorder) == 1 {
		return &TreeNode{Val: preorder[0]}
	}

	node := &TreeNode{Val: preorder[0]}

	idx := 0
	for index := range inorder {
		if inorder[index] == preorder[0] {
			idx = index
			break
		}
	}

	inorder_left := inorder[:idx]
	inorder_right := inorder[idx+1:]
	preorder_left := preorder[1 : 1+len(inorder_left)]
	preorder_right := preorder[1+len(inorder_left):]

	node.Left = deduceTree(preorder_left, inorder_left)
	node.Right = deduceTree(preorder_right, inorder_right)

	return node

}

// @lc code=end

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

*/
