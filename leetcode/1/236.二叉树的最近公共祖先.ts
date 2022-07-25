/*
 * @lc app=leetcode.cn id=236 lang=typescript
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (69.19%)
 * Likes:    1863
 * Dislikes: 0
 * Total Accepted:    417.7K
 * Total Submissions: 603.6K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出：3
 * 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出：5
 * 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2], p = 1, q = 2
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [2, 10^5] 内。
 * -10^9 <= Node.val <= 10^9
 * 所有 Node.val 互不相同 。
 * p != q
 * p 和 q 均存在于给定的二叉树中。
 * 
 * 
 */

/**
 * 递归求两树节点的最近公共祖先，不知道怎么稀里糊涂就过了...
 */

class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {

    if (!root || !p || !q) return null;

    /**
     * 关键函数，递归找两节点最近公共祖先
     * 
     * 如果当前节点为空，则直接返回空
     * 
     * 如果当前节点为p、q中的一个，则返回当前节点
     * 
     * 否则，递归查找左右子树，当左右子树返回值都为null的时候，
     * 说明左右子树都没有p、q中任何一个，则也返回null，并从其他地方查找
     * 
     * 当都有返回的时候，说明左右两边底下恰好是p、q两个节点，
     * 则该节点就是最近公共祖先，且返回上一层的时候，上一层必然只有
     * 一边有非null返回
     * 
     * @param root 当前判定树根
     * @returns 最近公共祖先
     */
    function find(root: TreeNode | null): TreeNode | null {
        if (!root) return null;
        if (root === p || root === q) return root;
        let left = find(root.left);
        let right = find(root.right);
        if (!left && !right) return null;
        if (left && right) return root;
        return left ? left : right;
    }

    return find(root);

};
// @lc code=end

