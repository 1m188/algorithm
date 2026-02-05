/*
    基于 C# 的线性表实现
*/

using System.Diagnostics;

internal class Program
{
    private static void Main(string[] args)
    {
        Test<LinearArray<int>, int>([1, 5, 2, 4, 3]);
        Test<LinearLinkList<int>, int>([1, 5, 2, 4, 3]);
        Test<LinearLinkListD<int>, int>([1, 5, 2, 4, 3]);
        Console.WriteLine("All test cases passed.");
    }

    private static void Test<T, E>(IEnumerable<E> datas)
    where T : ILinear<E>, new()
    where E : IEquatable<E>
    {
        Trace.Assert(datas.Count() >= 3); // 假设至少有三个元素

        // 创建线性表
        var linear = new T();
        datas.ToList().ForEach(linear.Add);
        Trace.Assert(linear.Count == datas.Count());

        // 增
        linear.Add(default!);
        Trace.Assert(linear.Count == datas.Count() + 1);
        Trace.Assert(linear.Get(linear.Count - 1).Equals(default));
        linear.Insert(0, default!);
        Trace.Assert(linear.Count == datas.Count() + 2);
        Trace.Assert(linear.Get(0).Equals(default));

        // 删
        Trace.Assert(linear.RemoveAt(0).Equals(default));
        Trace.Assert(linear.Count == datas.Count() + 1);
        Trace.Assert(linear.RemoveAt(linear.Count - 1).Equals(default));
        Trace.Assert(linear.Count == datas.Count());
        Trace.Assert(linear.Get(0).Equals(datas.First()));
        Trace.Assert(linear.Get(linear.Count - 1).Equals(datas.Last()));

        // 改
        linear.Set(0, default!);
        Trace.Assert(linear.Get(0).Equals(default));
        linear.Set(0, datas.First());
        Trace.Assert(linear.Get(0).Equals(datas.First()));
        linear.Set(linear.Count - 1, default!);
        Trace.Assert(linear.Get(linear.Count - 1).Equals(default));
        linear.Set(linear.Count - 1, datas.Last());
        Trace.Assert(linear.Get(linear.Count - 1).Equals(datas.Last()));

        // 查
        Trace.Assert(linear.Get(0).Equals(datas.First()));
        Trace.Assert(linear.Get(1).Equals(datas.Skip(1).First()));
        Trace.Assert(linear.Get(linear.Count - 1).Equals(datas.Last()));
        Trace.Assert(linear.IndexOf(datas.First()) == 0);
        if (!datas.First().Equals(datas.Skip(1).First()))
            Trace.Assert(linear.IndexOf(datas.Skip(1).First()) == 1,
                        $"{linear.GetType()}: {linear.IndexOf(datas.Skip(1).First())} != 1");
        Trace.Assert(linear.Contains(datas.First()));
        Trace.Assert(linear.Contains(datas.Last()));

        linear.Clear();
        Trace.Assert(linear.Count == 0);
    }
}

// 线性表接口
internal interface ILinear<T> where T : IEquatable<T>
{
    int Count { get; }
    void Add(T item);
    void Insert(int index, T item);
    T Get(int index);
    void Set(int index, T item);
    T RemoveAt(int index);
    void Clear();
    int IndexOf(T item);
    bool Contains(T item);
}

// 基于数组的线性表实现
internal class LinearArray<T> : ILinear<T> where T : IEquatable<T>
{
    private T[] arr = []; // 数组
    private int count = 0; // 当前元素个数
    private int cap = 0; // 数组容量

    public int Count { get { return count; } }
    public void Add(T item)
    {
        if (count == cap)
        {
            if (cap == 0)
            {
                cap = 1;
                arr = new T[cap];
            }
            else
            {
                cap <<= 1;
                T[] newArr = new T[cap];
                Array.Copy(arr, newArr, count);
                arr = newArr;
            }
        }
        arr[count++] = item;
    }
    public void Insert(int index, T item)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        Add(default!);
        for (int i = count - 2; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = item;
    }
    public T Get(int index)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        return arr[index];
    }
    public void Set(int index, T item)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        arr[index] = item;
    }
    public T RemoveAt(int index)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        T item = arr[index];
        for (int i = index; i < count - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        count--;
        return item;
    }
    public void Clear()
    {
        count = 0;
    }
    public int IndexOf(T item)
    {
        for (int i = 0; i < count; i++)
        {
            if (arr[i].Equals(item)) return i;
        }
        return -1;
    }
    public bool Contains(T item)
    {
        return IndexOf(item) != -1;
    }
}

// 基于单向链表的线性表实现
internal class LinearLinkList<T> : ILinear<T> where T : IEquatable<T>
{
    private class Node // 链表节点
    {
        public required T Value { get; set; }
        public Node? Next { get; set; }
    }

    private Node? head; // 链表头节点
    private int count; // 链表节点数量

    public int Count { get { return count; } }
    public void Add(T item)
    {
        var node = new Node { Value = item };
        if (head == null)
        {
            head = node;
        }
        else
        {
            var cur = head;
            while (cur.Next != null) cur = cur.Next;
            cur.Next = node;
        }
        count++;
    }
    public void Insert(int index, T item)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        var node = new Node { Value = item };
        if (index == 0)
        {
            node.Next = head;
            head = node;
        }
        else
        {
            var cur = head;
            for (int i = 0; i < index - 1; i++) cur = cur!.Next;
            node.Next = cur!.Next;
            cur!.Next = node;
        }
        count++;
    }
    public T Get(int index)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        var cur = head;
        for (int i = 0; i < index; i++) cur = cur!.Next;
        return cur!.Value;
    }
    public void Set(int index, T item)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        var cur = head;
        for (int i = 0; i < index; i++) cur = cur!.Next;
        cur!.Value = item;
    }
    public T RemoveAt(int index)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        T val;
        if (index == 0)
        {
            val = head!.Value;
            head = head!.Next;
        }
        else
        {
            var cur = head;
            for (int i = 0; i < index - 1; i++) cur = cur!.Next;
            val = cur!.Next!.Value;
            cur!.Next = cur!.Next!.Next;
        }
        count--;
        return val;
    }
    public void Clear()
    {
        head = null;
        count = 0;
    }
    public int IndexOf(T item)
    {
        var cur = head;
        for (int i = 0; i < count; i++)
        {
            if (cur!.Value.Equals(item)) return i;
            cur = cur.Next;
        }
        return -1;
    }
    public bool Contains(T item)
    {
        return IndexOf(item) != -1;
    }
}

// 基于双向链表的线性表实现
internal class LinearLinkListD<T> : ILinear<T> where T : IEquatable<T>
{
    private class Node // 链表节点
    {
        public required T Value { get; set; }
        public Node? Next { get; set; }
        public Node? Prev { get; set; }
    }

    private Node? head; // 链表头节点
    private int count; // 链表节点数量

    public int Count { get { return count; } }
    public void Add(T item)
    {
        if (head == null)
        {
            head = new Node { Value = item };
        }
        else
        {
            var cur = head;
            while (cur.Next != null) cur = cur.Next;
            cur.Next = new Node { Value = item, Prev = cur };
        }
        count++;
    }
    public void Insert(int index, T item)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        var node = new Node { Value = item };
        if (index == 0)
        {
            node.Next = head;
            head!.Prev = node;
            head = node;
        }
        else
        {
            var cur = head;
            for (int i = 0; i < index; i++) cur = cur!.Next;
            var node1 = cur!.Prev!;
            var node2 = cur;
            node1.Next = node;
            node.Prev = node1;
            node.Next = node2;
            node2.Prev = node;
        }
        count++;
    }
    public T Get(int index)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        var cur = head;
        for (int i = 0; i < index; i++) cur = cur!.Next;
        return cur!.Value;
    }
    public void Set(int index, T item)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        var cur = head;
        for (int i = 0; i < index; i++) cur = cur!.Next;
        cur!.Value = item;
    }
    public T RemoveAt(int index)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        T val;
        if (index == 0)
        {
            val = head!.Value;
            head = head!.Next;
            head!.Prev = null;
        }
        else
        {
            var cur = head;
            for (int i = 0; i < index; i++) cur = cur!.Next;
            val = cur!.Value;
            var node1 = cur!.Prev!;
            var node2 = cur!.Next;
            node1.Next = node2;
            node2?.Prev = node1;
        }
        count--;
        return val;
    }
    public void Clear()
    {
        head = null;
        count = 0;
    }
    public int IndexOf(T item)
    {
        var cur = head;
        for (int i = 0; i < count; i++)
        {
            if (cur!.Value.Equals(item)) return i;
            cur = cur!.Next;
        }
        return -1;
    }
    public bool Contains(T item)
    {
        return IndexOf(item) != -1;
    }
}
