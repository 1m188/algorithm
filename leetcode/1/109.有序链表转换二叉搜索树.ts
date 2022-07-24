/*
 * @lc app=leetcode.cn id=109 lang=typescript
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (76.23%)
 * Likes:    699
 * Dislikes: 0
 * Total Accepted:    115.7K
 * Total Submissions: 151.8K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: head = [-10,-3,0,5,9]
 * 输出: [0,-3,9,-10,null,5]
 * 解释: 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: head = []
 * 输出: []
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * head 中的节点数在[0, 2 * 10^4] 范围内
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 */

/**
 * 递归生成二叉树
 * 
 * 因为是平衡，而且数据又是从小到大排列好，则每次取最中间的一个作为
 * 根节点，左右分属左右两颗子树，可以做到二叉搜索且平衡
 */

class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}

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
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

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

function sortedListToBST(head: ListNode | null): TreeNode | null {

    let arr: number[] = [];
    for (let node = head; node; node = node.next)
        arr.push(node.val);

    function genTree(start: number, end: number): TreeNode | null {
        if (start > end) return null; // 注意递归出口
        let idx = Math.floor((start + end) / 2);
        let node = new TreeNode(arr[idx],
            genTree(start, idx - 1),
            genTree(idx + 1, end));
        return node;
    }

    return genTree(0, arr.length - 1);

};
// @lc code=end

