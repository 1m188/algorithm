/*
    基于 C# 的单链表实现
*/

using System.Diagnostics;
using T = int; // 泛型类型

/* 测试用例 */

// 创建
var head = Node<T>.New(1, 5, 2, 4, 3);
Trace.Assert(head!.ToString() == "1->5->2->4->3");

// 增
head = Node<T>.AddNode(head, 10);
Trace.Assert(head!.ToString() == "1->5->2->4->3->10");

// 删
head = Node<T>.DelNode(head, 1);
Trace.Assert(head!.ToString() == "5->2->4->3->10");
head = Node<T>.DelNode(head, 10);
Trace.Assert(head!.ToString() == "5->2->4->3");
head = Node<T>.DelNode(head, 2);
Trace.Assert(head!.ToString() == "5->4->3");

// 改
head = Node<T>.ChangeNode(head, 5, 9);
Trace.Assert(head!.ToString() == "9->4->3");
head = Node<T>.ChangeNode(head, 3, 6);
Trace.Assert(head!.ToString() == "9->4->6");
head = Node<T>.ChangeNode(head, 4, 8);
Trace.Assert(head!.ToString() == "9->8->6");

// 查
var node = Node<T>.FindNode(head, 9);
Trace.Assert(node!.data == 9);
node = Node<T>.FindNode(head, 8);
Trace.Assert(node!.data == 8);
node = Node<T>.FindNode(head, 6);
Trace.Assert(node!.data == 6);
node = Node<T>.FindNode(head, 10);
Trace.Assert(node == null);

Console.WriteLine("All test cases passed.");


// 链表节点
class Node<T> where T : IEquatable<T>
{
    public required T data;
    public Node<T>? next;

    public static Node<T>? New(params T[] datas)
    {
        if (datas.Length == 0) return null;
        var head = new Node<T> { data = datas[0], next = null };
        var cur = head;
        for (int i = 1; i < datas.Length; i++)
        {
            cur.next = new Node<T> { data = datas[i], next = null };
            cur = cur.next;
        }
        return head;
    }

    public override string ToString()
    {
        var li = new List<T>
        {
            data
        };

        var cur = next;
        while (cur != null)
        {
            li.Add(cur.data);
            cur = cur.next;
        }

        return string.Join("->", li);
    }

    // 追加节点
    public static Node<T> AddNode(Node<T>? head, T data)
    {
        if (head == null) return new Node<T> { data = data, next = null };
        var cur = head;
        while (cur.next != null)
        {
            cur = cur.next;
        }
        cur.next = new Node<T> { data = data, next = null };
        return head;
    }

    // 删除节点
    public static Node<T>? DelNode(Node<T>? head, T data)
    {
        if (head == null) return null;
        if (head.data.Equals(data)) return head.next;
        var cur = head;
        while (cur.next != null)
        {
            if (cur.next.data.Equals(data))
            {
                cur.next = cur.next.next;
                break;
            }
            cur = cur.next;
        }
        return head;
    }

    // 修改节点
    public static Node<T>? ChangeNode(Node<T>? head, T data, T new_data)
    {
        if (head == null) return null;
        var cur = head;
        while (cur != null)
        {
            if (cur.data.Equals(data))
            {
                cur.data = new_data;
                break;
            }
            cur = cur.next;
        }
        return head;
    }

    // 查找节点
    public static Node<T>? FindNode(Node<T>? head, T data)
    {
        if (head == null) return null;
        var cur = head;
        while (cur != null)
        {
            if (cur.data.Equals(data))
            {
                return cur;
            }
            cur = cur.next;
        }
        return null;
    }
}
