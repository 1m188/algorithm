/*
基于 C# 的查找算法实现
*/

using System.Diagnostics;

internal class Program
{
    private static void Main(string[] args)
    {
        // 测试查找
        var arr = new int[] { 1, 2, 3, 4, 5 };
        for (int i = 0; i < arr.Length; i++) Trace.Assert(Search.LinearSearch(arr, i + 1) == i);
        Trace.Assert(Search.LinearSearch(arr, 0) == -1);
        Trace.Assert(Search.LinearSearch(arr, 6) == -1);
        for (int i = 0; i < arr.Length; i++) Trace.Assert(Search.BinarySearch(arr, i + 1) == i);
        Trace.Assert(Search.BinarySearch(arr, 0) == -1);
        Trace.Assert(Search.BinarySearch(arr, 6) == -1);

        arr = [.. arr.Reverse()];
        for (int i = 0; i < arr.Length; i++) Trace.Assert(Search.LinearSearch(arr, arr.Length - i) == i);
        Trace.Assert(Search.LinearSearch(arr, 0) == -1);
        Trace.Assert(Search.LinearSearch(arr, 6) == -1);

        arr = [1, 5, 2, 4, 3];
        Trace.Assert(Search.LinearSearch(arr, 1) == 0);
        Trace.Assert(Search.LinearSearch(arr, 5) == 1);
        Trace.Assert(Search.LinearSearch(arr, 2) == 2);
        Trace.Assert(Search.LinearSearch(arr, 4) == 3);
        Trace.Assert(Search.LinearSearch(arr, 3) == 4);
        Trace.Assert(Search.LinearSearch(arr, 0) == -1);
        Trace.Assert(Search.LinearSearch(arr, 6) == -1);

        arr = [1, 5, 9, 12, 15, 66, 78, 80, 90, 100];
        Trace.Assert(Search.BinarySearch(arr, 1) == 0);
        Trace.Assert(Search.BinarySearch(arr, 5) == 1);
        Trace.Assert(Search.BinarySearch(arr, 9) == 2);
        Trace.Assert(Search.BinarySearch(arr, 12) == 3);
        Trace.Assert(Search.BinarySearch(arr, 15) == 4);
        Trace.Assert(Search.BinarySearch(arr, 66) == 5);
        Trace.Assert(Search.BinarySearch(arr, 78) == 6);
        Trace.Assert(Search.BinarySearch(arr, 80) == 7);
        Trace.Assert(Search.BinarySearch(arr, 90) == 8);
        Trace.Assert(Search.BinarySearch(arr, 100) == 9);

        Console.WriteLine("All tests passed.");
    }
}

// 查找算法
internal class Search
{
    // 线性查找
    public static int LinearSearch<T>(IEnumerable<T> arr, T target) where T : IEquatable<T>
    {
        int index = -1;
        foreach (var item in arr)
        {
            index++;
            if (item.Equals(target)) return index;
        }
        return -1;
    }

    // 二分查找
    // 要求有序序列
    public static int BinarySearch<T>(IList<T> arr, T target) where T : IComparable<T>
    {
        int left = 0, right = arr.Count - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid].Equals(target)) return mid;
            if (arr[mid].CompareTo(target) < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
}
