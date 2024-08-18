/*
 * @lc app=leetcode.cn id=655 lang=typescript
 *
 * [655] 输出二叉树
 *
 * https://leetcode.cn/problems/print-binary-tree/description/
 *
 * algorithms
 * Medium (60.53%)
 * Likes:    133
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 20K
 * Testcase Example:  '[1,2]'
 *
 * 给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局
 * 。构造此格式化布局矩阵需要遵循以下规则：
 * 
 * 
 * 树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
 * 矩阵的列数 n 应该等于 2^height+1 - 1 。
 * 根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
 * 对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2^height-r-1] ，右子节点放置在
 * res[r+1][c+2^height-r-1] 。
 * 继续这一过程，直到树中的所有节点都妥善放置。
 * 任意空单元格都应该包含空字符串 "" 。
 * 
 * 
 * 返回构造得到的矩阵 res 。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2]
 * 输出：
 * [["","1",""],
 * ["2","",""]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3,null,4]
 * 输出：
 * [["","","","1","","",""],
 * ["","2","","","","3",""],
 * ["","","4","","","",""]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数在范围 [1, 2^10] 内
 * -99 <= Node.val <= 99
 * 树的深度在范围 [1, 10] 内
 * 
 * 
 */

/**
 * 按照题目要求逐步操作即可
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

function printTree(root: TreeNode | null): string[][] {

    if (!root) return []; // 特殊情况

    /**
     * 获取树的高度
     * @param root 
     * @returns 
     */
    function get_height(root: TreeNode | null): number {
        if (!root) return 0;
        return Math.max(get_height(root.left), get_height(root.right)) + 1;
    }

    /**
     * dfs递归设置节点的位置
     * @param node 
     * @param r 
     * @param c 
     * @returns 
     */
    function dfs(node: TreeNode | null = root,
        r: number = 0,
        c: number = Math.floor((n - 1) / 2)): void {
        if (!node) return;
        res[r][c] = node.val.toString();
        let x = Math.pow(2, m - 1 - r - 1);
        dfs(node.left, r + 1, c - x);
        dfs(node.right, r + 1, c + x);
    }

    let m = get_height(root);
    let n = Math.pow(2, m) - 1;

    let res: string[][] = [];
    for (let i = 0; i < m; i++) {
        res.push([]);
        for (let j = 0; j < n; j++) {
            res[i].push('');
        }
    }

    dfs();

    return res;

};
// @lc code=end

