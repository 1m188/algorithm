/*
 * @lc app=leetcode.cn id=95 lang=typescript
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode.cn/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (72.12%)
 * Likes:    1221
 * Dislikes: 0
 * Total Accepted:    133.1K
 * Total Submissions: 184.6K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 * 
 * 
 */

/**
 * 递归/迭代
 * 
 * 对于1..n中所有数按序排好，之后迭代，选择某个数作为根，其
 * 左边的数应该是其左子树的内容，右边就是右子树，如此迭代
 * 下去，直到最后得到null的节点，之后依次返还，每次得到一个根，
 * 直到最顶层函数返回一个树根组成的数组
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

function generateTrees(n: number): Array<TreeNode | null> {

    function generateTrees(start: number, end: number): (TreeNode | null)[] {
        if (start > end) return [null];

        let allTrees: (TreeNode | null)[] = [];

        for (let i = start; i <= end; i++) {
            let leftTrees: (TreeNode | null)[] = generateTrees(start, i - 1);
            let rightTrees: (TreeNode | null)[] = generateTrees(i + 1, end);

            for (let left of leftTrees) {
                for (let right of rightTrees) {
                    let node: TreeNode = new TreeNode(i, left, right);
                    allTrees.push(node);
                }
            }
        }

        return allTrees;
    }

    return generateTrees(1, n);

};
// @lc code=end

