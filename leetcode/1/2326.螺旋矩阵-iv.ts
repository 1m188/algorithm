/*
 * @lc app=leetcode.cn id=2326 lang=typescript
 *
 * [2326] 螺旋矩阵 IV
 *
 * https://leetcode.cn/problems/spiral-matrix-iv/description/
 *
 * algorithms
 * Medium (66.98%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 11.9K
 * Testcase Example:  '3\n5\n[3,0,2,6,8,1,7,9,4,2,5,5,0]'
 *
 * 给你两个整数：m 和 n ，表示矩阵的维数。
 * 
 * 另给你一个整数链表的头节点 head 。
 * 
 * 请你生成一个大小为 m x n 的螺旋矩阵，矩阵包含链表中的所有整数。链表中的整数从矩阵 左上角 开始、顺时针 按 螺旋
 * 顺序填充。如果还存在剩余的空格，则用 -1 填充。
 * 
 * 返回生成的矩阵。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
 * 输出：[[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
 * 解释：上图展示了链表中的整数在矩阵中是如何排布的。
 * 注意，矩阵中剩下的空格用 -1 填充。
 * 
 * 
 * 示例 2：
 * 
 * 输入：m = 1, n = 4, head = [0,1,2]
 * 输出：[[0,1,2,-1]]
 * 解释：上图展示了链表中的整数在矩阵中是如何从左到右排布的。 
 * 注意，矩阵中剩下的空格用 -1 填充。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 10^5
 * 1 <= m * n <= 10^5
 * 链表中节点数目在范围 [1, m * n] 内
 * 0 <= Node.val <= 1000
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

function spiralMatrix(m: number, n: number, head: ListNode | null): number[][] {

    let res: number[][] = new Array(m);
    for (let i = 0; i < m; i++) res[i] = new Array(n);

    let left = 0, right = n - 1, up = 0, bottom = m - 1;
    while (left <= right && up <= bottom) {
        let f = false;
        for (let i = left; i <= right; i++) {
            if (head) { res[up][i] = head.val; head = head.next; }
            else res[up][i] = -1;
            f = true;
        }
        if (!f) break;
        f = false;
        for (let i = up + 1; i <= bottom; i++) {
            if (head) { res[i][right] = head.val; head = head.next; }
            else res[i][right] = -1;
            f = true;
        }
        if (!f) break;
        f = false;
        for (let i = right - 1; i >= left; i--) {
            if (head) { res[bottom][i] = head.val; head = head.next; }
            else res[bottom][i] = -1;
            f = true;
        }
        if (!f) break;
        f = false;
        for (let i = bottom - 1; i > up; i--) {
            if (head) { res[i][left] = head.val; head = head.next; }
            else res[i][left] = -1;
            f = true;
        }
        if (!f) break;
        f = false;
        left++, right--, up++, bottom--;
    }

    return res;

};
// @lc code=end

