/*
 * @lc app=leetcode.cn id=430 lang=typescript
 *
 * [430] 扁平化多级双向链表
 *
 * https://leetcode.cn/problems/flatten-a-multilevel-doubly-linked-list/description/
 *
 * algorithms
 * Medium (59.21%)
 * Likes:    363
 * Dislikes: 0
 * Total Accepted:    53.9K
 * Total Submissions: 91K
 * Testcase Example:  '[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]'
 *
 * 你会得到一个双链表，其中包含的节点有一个下一个指针、一个前一个指针和一个额外的 子指针
 * 。这个子指针可能指向一个单独的双向链表，也包含这些特殊的节点。这些子列表可以有一个或多个自己的子列表，以此类推，以生成如下面的示例所示的 多层数据结构
 * 。
 * 
 * 给定链表的头节点 head ，将链表 扁平化 ，以便所有节点都出现在单层双链表中。让 curr
 * 是一个带有子列表的节点。子列表中的节点应该出现在扁平化列表中的 curr 之后 和 curr.next 之前 。
 * 
 * 返回 扁平列表的 head 。列表中的节点必须将其 所有 子指针设置为 null 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 * 输出：[1,2,3,7,8,11,12,9,10,4,5,6]
 * 解释：输入的多级列表如上图所示。
 * 扁平化后的链表如下图：
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,null,3]
 * 输出：[1,3,2]
 * 解释：输入的多级列表如上图所示。
 * 扁平化后的链表如下图：
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 说明：输入中可能存在空列表。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 节点数目不超过 1000
 * 1 <= Node.val <= 10^5
 * 
 * 
 * 
 * 
 * 如何表示测试用例中的多级链表？
 * 
 * 以 示例 1 为例：
 * 
 * 
 * ⁠1---2---3---4---5---6--NULL
 * ⁠        |
 * ⁠        7---8---9---10--NULL
 * ⁠            |
 * ⁠            11--12--NULL
 * 
 * 序列化其中的每一级之后：
 * 
 * 
 * [1,2,3,4,5,6,null]
 * [7,8,9,10,null]
 * [11,12,null]
 * 
 * 
 * 为了将每一级都序列化到一起，我们需要每一级中添加值为 null 的元素，以表示没有节点连接到上一级的上级节点。
 * 
 * 
 * [1,2,3,4,5,6,null]
 * [null,null,7,8,9,10,null]
 * [null,11,12,null]
 * 
 * 
 * 合并所有序列化结果，并去除末尾的 null 。
 * 
 * 
 * [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 * 
 * 
 * 
 * 
 * 
 */

/**
 * dfs递归求链表加入原链表即可，感觉ts的类型推导还是不够完善，
 * 明明逻辑上不为空，但实际写的时候还是会提示有可能出错
 */

export class Node {
    val: number
    prev: Node | null
    next: Node | null
    child: Node | null
    constructor(val?: number, prev?: Node, next?: Node, child?: Node) {
        this.val = (val === undefined ? 0 : val);
        this.prev = (prev === undefined ? null : prev);
        this.next = (next === undefined ? null : next);
        this.child = (child === undefined ? null : child);
    }
}

// @lc code=start
/**
 * Definition for node.
 * class Node {
 *     val: number
 *     prev: Node | null
 *     next: Node | null
 *     child: Node | null
 *     constructor(val?: number, prev? : Node, next? : Node, child? : Node) {
 *         this.val = (val===undefined ? 0 : val);
 *         this.prev = (prev===undefined ? null : prev);
 *         this.next = (next===undefined ? null : next);
 *         this.child = (child===undefined ? null : child);
 *     }
 * }
 */

function flatten(head: Node | null): Node | null {

    if (!head) return null;

    function dfs(node: Node): Node {
        let cur: Node | null = node;
        while (cur && !cur.child) cur = cur.next;
        if (!cur) return node;
        let curn = cur.next;
        let link = dfs(cur.child as Node);
        cur.child = null;
        cur.next = link;
        link.prev = cur;
        while (link.next) link = link.next;
        link.next = curn;
        if (curn) curn.prev = link;
        return node;
    }

    return dfs(head);

};
// @lc code=end

