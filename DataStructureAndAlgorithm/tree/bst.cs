/*
基于 C# 的二叉查找树实现
*/

using System.Diagnostics;

internal class Program
{
    private static void Main(string[] args)
    {
        Test();
        Console.WriteLine("All tests passed.");
    }

    private static void Test()
    {
        var bst = BST<int>.New([1, 10, 9, 8, 2, 3, 4, 7, 5, 6]); // 生成二叉查找树
        Trace.Assert(bst.Count == 10);
        Trace.Assert(string.Join(',', bst.InOrder()) == "1,2,3,4,5,6,7,8,9,10"); // 中序遍历
        Trace.Assert(bst.Find(5));
        Trace.Assert(!bst.Find(11));

        bst.Insert(11);
        Trace.Assert(bst.Count == 11);
        Trace.Assert(string.Join(',', bst.InOrder()) == "1,2,3,4,5,6,7,8,9,10,11"); // 中序遍历
        Trace.Assert(bst.Find(11));
        Trace.Assert(!bst.Find(12));
        bst.Insert(11);
        Trace.Assert(bst.Count == 11);
        Trace.Assert(string.Join(',', bst.InOrder()) == "1,2,3,4,5,6,7,8,9,10,11"); // 中序遍历
        Trace.Assert(bst.Find(11));
        Trace.Assert(!bst.Find(12));

        bst.Delete(1); // 删除单子树节点
        Trace.Assert(bst.Count == 10);
        Trace.Assert(string.Join(',', bst.InOrder()) == "2,3,4,5,6,7,8,9,10,11"); // 中序遍历
        Trace.Assert(!bst.Find(1));
        Trace.Assert(bst.Find(11));

        bst.Delete(9); // 删除双子树节点
        Trace.Assert(bst.Count == 9);
        Trace.Assert(string.Join(',', bst.InOrder()) == "2,3,4,5,6,7,8,10,11"); // 中序遍历
        Trace.Assert(!bst.Find(9));
        Trace.Assert(bst.Find(11));

        bst.Delete(11); // 删除叶子节点
        Trace.Assert(bst.Count == 8);
        Trace.Assert(string.Join(',', bst.InOrder()) == "2,3,4,5,6,7,8,10"); // 中序遍历
        Trace.Assert(!bst.Find(11));
        Trace.Assert(bst.Find(10));

        bst.Delete(999); // 删除不存在的节点
        Trace.Assert(bst.Count == 8);
        Trace.Assert(string.Join(',', bst.InOrder()) == "2,3,4,5,6,7,8,10"); // 中序遍历
        Trace.Assert(!bst.Find(11));
        Trace.Assert(bst.Find(10));

        bst.Clear();
        Trace.Assert(bst.Count == 0);
    }
}

// 二叉查找树
internal class BST<T> where T : IComparable<T>
{
    private class Node
    {
        public required T Val;
        public Node? Left, Right;
    }

    private Node? root; // 根节点

    // 禁用构造函数，只能通过 New 方法创建
    private BST() { }

    public static BST<T> New(IEnumerable<T> arr)
    {
        var bst = new BST<T>();
        foreach (var val in arr) bst.Insert(val);
        bst.Count = arr.Count();
        return bst;
    }
    public int Count { get; private set; }
    // 增
    public void Insert(T val)
    {
        Node insert(Node? root, T val)
        {
            if (root == null) { Count++; return new Node { Val = val }; }
            if (root.Val.CompareTo(val) == 0) return root;
            if (root.Val.CompareTo(val) > 0) root.Left = insert(root.Left, val);
            else root.Right = insert(root.Right, val);
            return root;
        }
        root = insert(root, val);
    }
    // 删
    public void Delete(T val)
    {
        Node? delete(Node? root, T val)
        {
            if (root == null) return null;
            if (root.Val.CompareTo(val) > 0) root.Left = delete(root.Left, val);
            else if (root.Val.CompareTo(val) < 0) root.Right = delete(root.Right, val);
            else
            {
                if (root.Left == null && root.Right == null) { Count--; return null; }
                if (root.Left == null || root.Right == null) { Count--; return root.Left ?? root.Right; }
                var min = root.Right;
                while (min.Left != null) min = min.Left;
                root.Val = min.Val;
                root.Right = delete(root.Right, min.Val);
            }
            return root;
        }

        root = delete(root, val);
    }
    // 查
    public bool Find(T val)
    {
        var cur = root;
        while (cur != null)
        {
            if (cur.Val.CompareTo(val) == 0) return true;
            else if (cur.Val.CompareTo(val) > 0) cur = cur.Left;
            else cur = cur.Right;
        }
        return false;
    }
    // 中序遍历（升序遍历）
    public IEnumerable<T> InOrder()
    {
        if (Count == 0) return [];
        var list = new List<T>();

        void mid(Node? root)
        {
            if (root == null) return;
            mid(root.Left);
            list.Add(root.Val);
            mid(root.Right);
        }

        mid(root);
        return list;
    }
    public void Clear()
    {
        root = null;
        Count = 0;
    }
}
