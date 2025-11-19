/*
基于 C# 的排序算法实现
*/

using System.Diagnostics;

internal class Program
{
    private static void Main(string[] args)
    {
        Test(Sort.InsertSort, "InsertSort");
        Test(Sort.ShellSort, "ShellSort");
        Test(Sort.SelectSort, "SelectSort");
        Test(Sort.BubbleSort, "BubbleSort");
        Test(Sort.QuickSort, "QuickSort");
        Test(Sort.HeapSort, "HeapSort");
        Test(Sort.MergeSort, "MergeSort");
        Test(Sort.CountSort, "CountSort");
        Console.WriteLine("All tests passed.");
    }

    private static void Test(Action<IList<int>> sortFunc, string funcName)
    {
        static string str(IEnumerable<int> arr) => string.Join(",", arr);

        var arr = new int[] { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        sortFunc(arr);
        Trace.Assert(arr.SequenceEqual(Enumerable.Range(1, 10)), $"{funcName}. Expect: {str(Enumerable.Range(1, 10))}. Found: {str(arr)}");

        arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
        sortFunc(arr);
        Trace.Assert(arr.SequenceEqual(Enumerable.Range(1, 10)), $"{funcName}. Expect: {str(Enumerable.Range(1, 10))}. Found: {str(arr)}");

        arr = [1, 10, 2, 9, 3, 8, 4, 7, 5, 6];
        sortFunc(arr);
        Trace.Assert(arr.SequenceEqual(Enumerable.Range(1, 10)), $"{funcName}. Expect: {str(Enumerable.Range(1, 10))}. Found: {str(arr)}");

        arr = [];
        sortFunc(arr);
        Trace.Assert(arr.SequenceEqual(Enumerable.Range(1, 0)), $"{funcName}. Expect: {str(Enumerable.Range(1, 0))}. Found: {str(arr)}");

        arr = [1];
        sortFunc(arr);
        Trace.Assert(arr.SequenceEqual(Enumerable.Range(1, 1)), $"{funcName}. Expect: {str(Enumerable.Range(1, 1))}. Found: {str(arr)}");

        arr = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1];
        sortFunc(arr);
        Trace.Assert(arr.SequenceEqual([1, 1, 1, 1, 1, 1, 1, 1, 1, 1]), $"{funcName}. Expect: {str([1, 1, 1, 1, 1, 1, 1, 1, 1, 1])}. Found: {str(arr)}");

        arr = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5];
        sortFunc(arr);
        Trace.Assert(arr.SequenceEqual([1, 1, 2, 2, 3, 3, 4, 4, 5, 5]), $"{funcName}. Expect: {str([1, 1, 2, 2, 3, 3, 4, 4, 5, 5])}. Found: {str(arr)}");

        arr = [5, 5, 4, 4, 6, 7, 1, 2, 9, 0];
        sortFunc(arr);
        Trace.Assert(arr.SequenceEqual([0, 1, 2, 4, 4, 5, 5, 6, 7, 9]), $"{funcName}. Expect: {str([0, 1, 2, 4, 4, 5, 5, 6, 7, 9])}. Found: {str(arr)}");
    }
}

internal class Sort
{
    // 插入排序
    public static void InsertSort<T>(IList<T> arr) where T : IComparable<T>
    {
        for (int i = 1; i < arr.Count; i++)
            for (int j = i; j > 0; j--)
                if (arr[j].CompareTo(arr[j - 1]) < 0) (arr[j], arr[j - 1]) = (arr[j - 1], arr[j]);
                else break;
    }
    // 希尔排序
    public static void ShellSort<T>(IList<T> arr) where T : IComparable<T>
    {
        for (int gap = arr.Count / 2; gap > 0; gap /= 2)
            for (int i = gap; i < arr.Count; i += gap)
                for (int j = i; j > 0; j -= gap)
                    if (arr[j].CompareTo(arr[j - gap]) < 0) (arr[j], arr[j - gap]) = (arr[j - gap], arr[j]);
                    else break;
    }
    // 选择排序
    public static void SelectSort<T>(IList<T> arr) where T : IComparable<T>
    {
        for (int i = 0; i < arr.Count; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < arr.Count; j++)
                if (arr[j].CompareTo(arr[minIndex]) < 0) minIndex = j;
            if (minIndex != i) (arr[i], arr[minIndex]) = (arr[minIndex], arr[i]);
        }
    }
    // 冒泡排序
    public static void BubbleSort<T>(IList<T> arr) where T : IComparable<T>
    {
        for (int i = arr.Count - 1; i > 0; i--)
        {
            bool f = false;
            for (int j = 0; j < i; j++)
                if (arr[j].CompareTo(arr[j + 1]) > 0) { (arr[j], arr[j + 1]) = (arr[j + 1], arr[j]); f = true; }
            if (!f) break;
        }
    }
    // 快速排序
    public static void QuickSort<T>(IList<T> arr) where T : IComparable<T>
    {
        void quickSort(int start, int end)
        {
            if (start >= end) return;
            T pivot = arr[start];
            int l = start, r = end;
            while (l < r)
            {
                while (l < r && arr[r].CompareTo(pivot) >= 0) r--;
                if (l < r && arr[r].CompareTo(pivot) < 0) arr[l++] = arr[r];
                while (l < r && arr[l].CompareTo(pivot) <= 0) l++;
                if (l < r && arr[l].CompareTo(pivot) > 0) arr[r--] = arr[l];
            }
            arr[l] = pivot;
            quickSort(start, l - 1);
            quickSort(l + 1, end);
        }
        quickSort(0, arr.Count - 1);
    }
    // 堆排序
    public static void HeapSort<T>(IList<T> arr) where T : IComparable<T>
    {
        void adjust(int index, int end)
        {
            while (true)
            {
                int idx = index;
                if (index * 2 + 1 <= end && arr[index * 2 + 1].CompareTo(arr[idx]) > 0) idx = index * 2 + 1;
                if (index * 2 + 2 <= end && arr[index * 2 + 2].CompareTo(arr[idx]) > 0) idx = index * 2 + 2;
                if (idx == index) break;
                (arr[index], arr[idx]) = (arr[idx], arr[index]);
                index = idx;
            }
        }

        void buildHeap()
        {
            for (int i = (arr.Count - 1 - 1) / 2; i >= 0; i--) adjust(i, arr.Count - 1);
        }

        buildHeap();
        for (int i = arr.Count - 1; i > 0; i--)
        {
            (arr[0], arr[i]) = (arr[i], arr[0]); // 交换
            adjust(0, i - 1);
        }
    }
    // 归并排序
    public static void MergeSort<T>(IList<T> arr) where T : IComparable<T>
    {
        void merge(int l, int m, int r)
        {
            T[] left = new T[m - l];
            for (int idx = l; idx < m; idx++) left[idx - l] = arr[idx];
            T[] right = new T[r - m];
            for (int idx = m; idx < r; idx++) right[idx - m] = arr[idx];
            int i = 0, j = 0, k = l;
            while (i < left.Length && j < right.Length)
            {
                if (left[i].CompareTo(right[j]) <= 0) arr[k++] = left[i++];
                else arr[k++] = right[j++];
            }
            while (i < left.Length) arr[k++] = left[i++];
            while (j < right.Length) arr[k++] = right[j++];
        }

        void mergeSort(int l, int r)
        {
            if (l >= r - 1) return;
            int m = (l + r) / 2;
            mergeSort(l, m);
            mergeSort(m, r);
            merge(l, m, r);
        }

        mergeSort(0, arr.Count);
    }
    // 计数排序
    public static void CountSort(IList<int> arr) // 这个写泛型感觉实在是有点困难...
    {
        if (arr.Count == 0) return;
        int minVal = arr.Min(), maxVal = arr.Max();
        int offset = minVal;
        int[] count = new int[maxVal - minVal + 1];
        foreach (int num in arr) count[num - offset]++;
        int idx = 0;
        for (int i = 0; i < count.Length; i++)
        {
            while (count[idx] == 0) idx++;
            arr[i] = idx + offset;
            count[idx]--;
        }
    }
}
