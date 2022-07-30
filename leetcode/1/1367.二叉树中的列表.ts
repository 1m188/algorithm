/*
 * @lc app=leetcode.cn id=1367 lang=typescript
 *
 * [1367] 二叉树中的列表
 *
 * https://leetcode.cn/problems/linked-list-in-binary-tree/description/
 *
 * algorithms
 * Medium (42.95%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    19.9K
 * Total Submissions: 46.3K
 * Testcase Example:  '[4,2,8]\n[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]'
 *
 * 给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。
 * 
 * 如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 head 为首的链表中每个节点的值，那么请你返回 True ，否则返回 False
 * 。
 * 
 * 一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：head = [4,2,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：true
 * 解释：树中蓝色的节点构成了与链表对应的子路径。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：head = [1,4,2,6], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1,4,2,6,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：false
 * 解释：二叉树中不存在一一对应链表的路径。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 二叉树和链表中的每个节点的值都满足 1 <= node.val <= 100 。
 * 链表包含的节点数目在 1 到 100 之间。
 * 二叉树包含的节点数目在 1 到 2500 之间。
 * 
 * 
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

function isSubPath(head: ListNode | null, root: TreeNode | null): boolean {

    /**
     * 从当前树节点开始，判定是否存在一条连续的路径是链表
     * @param head 
     * @param root 
     * @returns 
     */
    function judge(head: ListNode | null, root: TreeNode | null): boolean {
        if (!head) return true;
        if (!root) return false;
        if (head.val != root.val)
            return false;
        return judge(head.next, root.left) || judge(head.next, root.right);
    }

    /**
     * 找到和链头节点一致的树节点，从此开始判定链表
     * 
     * 因为是递归，最后返回的是总结果
     * @param root 
     * @returns 
     */
    function find(root: TreeNode | null): boolean {
        if (root) {
            if (root.val == head!.val && judge(head, root))
                return true;
            return find(root.left) || find(root.right);
        }
        return false;
    }

    return find(root);

};
// @lc code=end

