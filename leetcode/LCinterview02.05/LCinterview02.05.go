/*
 * @lc app=leetcode.cn id=面试题 02.05 lang=golang
 * @lcpr version=30204
 *
 * [面试题 02.05] 链表求和
 *
 * https://leetcode.cn/problems/sum-lists-lcci/description/
 *
 * LCCI
 * Medium (47.05%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    80.4K
 * Total Submissions: 170.8K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给定两个用链表表示的整数，每个节点包含一个数位。
 *
 * 这些数位是反向存放的，也就是个位排在链表首部。
 *
 * 编写函数对这两个整数求和，并用链表形式返回结果。
 *
 *
 *
 * 示例：
 *
 * 输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
 * 输出：2 -> 1 -> 9，即912
 *
 *
 * 进阶：思考一下，假设这些数位是正向存放的，又该如何解决呢?
 *
 * 示例：
 *
 * 输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
 * 输出：9 -> 1 -> 2，即912
 *
 *
 */

// @lcpr-template-start
package main

type ListNode struct {
	Val  int
	Next *ListNode
}

// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	cur, cur1, cur2 := head, l1, l2
	x := 0

	for cur1 != nil && cur2 != nil {
		sum := cur1.Val + cur2.Val + x
		cur.Next = &ListNode{Val: sum % 10}
		x = sum / 10
		cur = cur.Next
		cur1 = cur1.Next
		cur2 = cur2.Next
	}

	for cur1 != nil {
		sum := cur1.Val + x
		cur.Next = &ListNode{Val: sum % 10}
		x = sum / 10
		cur = cur.Next
		cur1 = cur1.Next
	}

	for cur2 != nil {
		sum := cur2.Val + x
		cur.Next = &ListNode{Val: sum % 10}
		x = sum / 10
		cur = cur.Next
		cur2 = cur2.Next
	}

	if x > 0 {
		cur.Next = &ListNode{Val: x}
	}

	return head.Next
}

// @lc code=end

/*
// @lcpr case=start
// (7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295\n
// @lcpr case=end

// @lcpr case=start
// (6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295\n
// @lcpr case=end

*/
