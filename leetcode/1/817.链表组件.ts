/*
 * @lc app=leetcode.cn id=817 lang=typescript
 *
 * [817] 链表组件
 *
 * https://leetcode-cn.com/problems/linked-list-components/description/
 *
 * algorithms
 * Medium (59.38%)
 * Likes:    93
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 25.7K
 * Testcase Example:  '[0,1,2,3]\n[0,1,3]'
 *
 * 给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值 。同时给定列表 nums，该列表是上述链表中整型值的一个子集。
 * 
 * 返回列表 nums 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 nums 中）构成的集合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: head = [0,1,2,3], nums = [0,1,3]
 * 输出: 2
 * 解释: 链表中,0 和 1 是相连接的，且 nums 中不包含 2，所以 [0, 1] 是 nums 的一个组件，同理 [3] 也是一个组件，故返回
 * 2。
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入: head = [0,1,2,3,4], nums = [0,3,1,4]
 * 输出: 2
 * 解释: 链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数为n
 * 1 <= n <= 10^4
 * 0 <= Node.val < n
 * Node.val 中所有值 不同
 * 1 <= nums.length <= n
 * 0 <= nums[i] < n
 * nums 中所有值 不同
 * 
 * 
 */

/**
 * 逐个判断连续子序列是否在链表之中，使用set
 */

class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
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

function numComponents(head: ListNode | null, nums: number[]): number {

    if (!head) return 0;

    let nset = new Set(nums);
    let f = false;
    let res = 0;
    for (let cur: ListNode | null = head; cur; cur = cur.next) {
        if (nset.has(cur.val)) {
            if (!f) {
                f = true;
                res++;
            }
        } else {
            f = false;
        }
    }

    return res;

};
// @lc code=end

