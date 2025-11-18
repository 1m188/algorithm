/*
基于 C# 的栈实现
*/

using System.Diagnostics;

internal class Program
{
    private static void Main(string[] args)
    {
        // 做点测试
        Test<StackList<int>, int>([1, 5, 2, 4, 3]);
        Test<StackArray<int>, int>([1, 5, 2, 4, 3]);
        Console.WriteLine("All test passed.");
    }

    private static void Test<T, E>(IEnumerable<E> datas)
    where T : IStack<E>, new()
    where E : IEquatable<E>
    {
        Trace.Assert(datas.Count() >= 2);
        var stack = new T();
        stack.PushRange(datas);
        Trace.Assert(stack.Count() == datas.Count());
        Trace.Assert(stack.Top().Equals(datas.Last()));
        Trace.Assert(stack.Pop().Equals(datas.Last()));
        Trace.Assert(stack.Top().Equals(datas.ElementAt(datas.Count() - 2)));
        Trace.Assert(stack.Count() == datas.Count() - 1);
        stack.Clear();
        Trace.Assert(stack.Count() == 0);
        Trace.Assert(stack.IsEmpty());
        try
        {
            stack.Pop();
        }
        catch (Exception e)
        {
            Console.WriteLine($"Pop an empty stack and throw an exception: {e.Message}");
        }
        try
        {
            stack.Top();
        }
        catch (Exception e)
        {
            Console.WriteLine($"Get top element of an empty stack and throw an exception: {e.Message}");
        }
    }
}

// 栈接口
internal interface IStack<T>
{
    public void Push(T item);
    public T Pop();
    public T Top();
    public bool IsEmpty();
    public int Count();
    public void Clear();
    public void PushRange(IEnumerable<T> items);
}

// 基于链表的栈实现
internal class StackList<T> : IStack<T>
{
    private class Node
    {
        public required T data;
        public Node? next;
    }

    private Node? top; // 栈顶
    private int size; // 栈的大小

    public void Push(T item)
    {
        var node = new Node { data = item };
        if (top == null)
        {
            top = node;
        }
        else
        {
            node.next = top;
            top = node;
        }
        size++;
    }
    public T Pop()
    {
        if (top == null) throw new Exception("Stack is empty");
        T data = top.data;
        top = top.next;
        size--;
        return data;
    }
    public T Top()
    {
        if (top == null) throw new Exception("Stack is empty");
        return top.data;
    }
    public bool IsEmpty()
    {
        return size == 0;
    }
    public int Count()
    {
        return size;
    }
    public void Clear()
    {
        top = null;
        size = 0;
    }
    public void PushRange(IEnumerable<T> items)
    {
        items.ToList().ForEach(Push);
    }
}

// 基于数组的栈实现
internal class StackArray<T> : IStack<T>
{
    private readonly List<T> stack = []; // 栈

    public void Push(T item)
    {
        stack.Add(item);
    }
    public T Pop()
    {
        if (stack.Count == 0) throw new Exception("Stack is empty");
        T data = stack[^1];
        stack.RemoveAt(stack.Count - 1);
        return data;
    }
    public T Top()
    {
        if (stack.Count == 0) throw new Exception("Stack is empty");
        return stack[^1];
    }
    public bool IsEmpty()
    {
        return stack.Count == 0;
    }
    public int Count()
    {
        return stack.Count;
    }
    public void Clear()
    {
        stack.Clear();
    }
    public void PushRange(IEnumerable<T> items)
    {
        items.ToList().ForEach(Push);
    }
}
