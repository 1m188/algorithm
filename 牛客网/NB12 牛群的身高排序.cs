/*
描述
农场主人记录了一群牛的身高，并将它们按照链表的形式存储。链表的头结点为 head，请你将这些身高数据按升序排列，并返回排序后的链表。


示例1
输入：
{4,2,1,3}
复制
返回值：
{1,2,3,4}
复制
示例2
输入：
{5, 0, 3, 4}
复制
返回值：
{0,3,4,5}
复制
备注：
链表中节点的数目在范围 [0, 5000] 内
0 <= Node.val <= 10000
*/

using System;
using System.Collections.Generic;

public class ListNode
{
    public int val;
    public ListNode next;

    public ListNode(int x)
    {
        val = x;
    }
}

class Solution
{
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    public ListNode sortList(ListNode head)
    {
        var li = new List<int>();
        ListNode cur = head;
        while (cur != null)
        {
            li.Add(cur.val);
            cur = cur.next;
        }

        li.Sort();

        int idx = 0;
        cur = head;
        while (cur != null)
        {
            cur.val = li[idx++];
            cur = cur.next;
        }

        return head;
    }
}