/*
    基于 C# 的队列实现
*/

using System.Diagnostics;

internal class Program
{
    private static void Main(string[] args)
    {
        Test<QueueLinkList<int>, int>([1, 5, 2, 4, 3]);
        Test<QueueList<int>, int>([1, 5, 2, 4, 3]);
        Test<QueueCircle<int>, int>([1, 5, 2, 4, 3]);
        Console.WriteLine("All test passed.");
    }

    private static void Test<T, E>(IEnumerable<E> datas)
    where T : IQueue<E>, new()
    where E : IEquatable<E>
    {
        var queue = new T();
        datas.ToList().ForEach(queue.Enqueue);
        Trace.Assert(queue.Count == datas.Count());
        Trace.Assert(queue.Peek().Equals(datas.First()));
        Trace.Assert(queue.Dequeue().Equals(datas.First()));
        Trace.Assert(queue.Count == datas.Count() - 1);
        Trace.Assert(queue.Peek().Equals(datas.Skip(1).First()));
        queue.Clear();
        Trace.Assert(queue.Count == 0);
        try
        {
            queue.Dequeue();
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }
        try
        {
            queue.Peek();
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }
    }
}

// 队列接口
internal interface IQueue<T>
{
    public int Count { get; }
    public void Enqueue(T item);
    public T Dequeue();
    public T Peek();
    public void Clear();
}

// 基于链表的队列实现
internal class QueueLinkList<T> : IQueue<T>
{
    private class Node // 链表节点
    {
        public required T Value { get; set; }
        public Node? Next { get; set; }
    }

    private Node? head; // 队列头
    private Node? tail; // 队列尾
    private int count; // 队列元素个数

    public int Count { get { return count; } }
    public void Enqueue(T item)
    {
        var node = new Node
        {
            Value = item,
            Next = null
        };
        if (head == tail && head == null)
        {
            head = tail = node;
        }
        else
        {
            tail!.Next = node;
            tail = node;
        }
        count++;
    }
    public T Dequeue()
    {
        if (head == null)
        {
            throw new Exception("Queue is empty");
        }
        var value = head.Value;
        head = head.Next;
        if (head == null) tail = null;
        count--;
        return value;
    }
    public T Peek()
    {
        if (head == null)
        {
            throw new Exception("Queue is empty");
        }
        return head.Value;
    }
    public void Clear()
    {
        head = tail = null;
        count = 0;
    }
}

// 基于动态数组的队列实现
internal class QueueList<T> : IQueue<T>
{
    private readonly List<T> queue = []; // 队列

    public int Count { get { return queue.Count; } }
    public void Enqueue(T item)
    {
        queue.Add(item);
    }
    public T Dequeue()
    {
        if (queue.Count == 0)
        {
            throw new Exception("Queue is empty");
        }
        var value = queue[0];
        queue.RemoveAt(0);
        return value;
    }
    public T Peek()
    {
        if (queue.Count == 0)
        {
            throw new Exception("Queue is empty");
        }
        return queue[0];
    }
    public void Clear()
    {
        queue.Clear();
    }
}

// 基于静态数组，有存储上限的循环队列实现
internal class QueueCircle<T> : IQueue<T>
{
    private const int MAX_SIZE = 100;
    private readonly T[] queue = new T[MAX_SIZE]; // 队列
    private int head = 0; // 队头
    private int tail = 0; // 队尾

    public int Count { get { return (tail - head + queue.Length) % queue.Length; } }
    public void Enqueue(T item)
    {
        if (Count == queue.Length - 1)
        {
            throw new Exception("Queue is full");
        }
        queue[tail] = item;
        tail = (tail + 1) % queue.Length;
    }
    public T Dequeue()
    {
        if (Count == 0)
        {
            throw new Exception("Queue is empty");
        }
        var value = queue[head];
        head = (head + 1) % queue.Length;
        return value;
    }
    public T Peek()
    {
        if (Count == 0)
        {
            throw new Exception("Queue is empty");
        }
        return queue[head];
    }
    public void Clear()
    {
        head = 0;
        tail = 0;
    }
}
