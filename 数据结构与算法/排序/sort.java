/*

排序算法

*/

import java.util.ArrayList;
import java.util.Random;
import java.util.function.UnaryOperator;

public class sort {
    /**
     * 生成一个随机整数数组
     * 
     * @param len   数组长度
     * @param left  生成的数字的下界
     * @param right 生成的数字的上界
     * @return 返回生成的随机整数组
     */
    private static Integer[] genRandVec(final int len, final int left, final int right) {
        Integer[] vec = new Integer[len];
        Random random = new Random();
        for (int i = 0; i < vec.length; i++)
            vec[i] = random.nextInt(right - left + 1) + left;
        return vec;
    }

    /**
     * 打印数组
     * 
     * @param vec    待打印数组
     * @param prefix 打印前缀
     */
    private static <T> void printVec(final T[] vec, final String prefix) {
        System.out.printf("%s:", prefix);
        for (T e : vec) {
            System.out.print(' ');
            System.out.print(e);
        }
        System.out.println();
    }

    // 插入类算法

    /**
     * 直接插入排序
     * 
     * @param vec 待排序数组
     */
    // 时间复杂度最好O(n)，最坏O(n^2)，平均O(n^2)
    // 空间复杂度O(1)
    // 稳定
    private static <T extends Comparable<T>> void insertSort(T[] vec) {
        for (int i = 1; i < vec.length; i++) {
            T tmp = vec[i];
            int idx = i - 1;
            for (; idx >= 0 && vec[idx].compareTo(tmp) > 0; idx--)
                vec[idx + 1] = vec[idx];
            vec[idx + 1] = tmp;
        }
    }

    /**
     * 在数组中有序部分二分寻找待插入的索引
     * 
     * @param vec    待排序数组
     * @param left   待插入区间左边界索引
     * @param right  待插入区间右边界索引
     * @param target 待插入数据
     * @return 待插入索引
     */
    private static <T extends Comparable<T>> int bindex(final T[] vec, int left, int right, final T target) {
        int mid = (left + right) / 2;
        while (left < right) {
            if (vec[mid].compareTo(target) == 0)
                return mid + 1;
            else if (vec[mid].compareTo(target) < 0)
                left = mid + 1;
            else
                right = mid - 1;
            mid = (left + right) / 2;
        }
        return vec[mid].compareTo(target) <= 0 ? mid + 1 : mid;
    }

    /**
     * 折半插入排序
     * 
     * @param vec 待排序数组
     */
    // 时间复杂度最好O(nlog2n)，最坏O(n^2)，平均O(n^2)
    // 空间复杂度O(1)
    // 稳定
    private static <T extends Comparable<T>> void binsertSort(T[] vec) {
        for (int i = 1; i < vec.length; i++) {
            int index = bindex(vec, 0, i - 1, vec[i]);
            T tmp = vec[i];
            for (int idx = i - 1; idx >= index; idx--)
                vec[idx + 1] = vec[idx];
            vec[index] = tmp;
        }
    }

    /**
     * 希尔排序
     * 
     * @param vec  待排序数组
     * @param k    初始增量
     * @param kfun 增量选择函数
     */
    // 时间复杂度平均O(nlog2n)
    // 空间复杂度O(1)
    // 不稳定
    private static <T extends Comparable<T>> void shellSort(T[] vec, int k, final UnaryOperator<Integer> kfun) {
        while (k > 1) {
            for (int i = 0; i < k; i++)
                for (int j = i + k; j < vec.length; j += k) {
                    T tmp = vec[j];
                    int idx = j - k;
                    for (; idx >= i && vec[idx].compareTo(tmp) > 0; idx -= k)
                        vec[idx + k] = vec[idx];
                    vec[idx + k] = tmp;
                }
            k = kfun.apply(k);
        }
        for (int i = 1; i < vec.length; i++) {
            T tmp = vec[i];
            int idx = i - 1;
            for (; idx >= 0 && vec[idx].compareTo(tmp) > 0; idx--)
                vec[idx + 1] = vec[idx];
            vec[idx + 1] = tmp;
        }
    }

    // 交换类算法

    /**
     * 冒泡排序
     * 
     * @param vec 待排序数组
     */
    // 时间复杂度最好O(n)，最坏O(n^2)，平均O(n^2)
    // 空间复杂度O(1)
    // 稳定
    private static <T extends Comparable<T>> void bubbleSort(T[] vec) {
        for (int i = vec.length - 1; i >= 1; i--) {
            boolean flag = false;
            for (int j = 0; j < i; j++)
                if (vec[j].compareTo(vec[j + 1]) > 0) {
                    T tmp = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = tmp;
                    flag = true;
                }
            if (!flag)
                return;
        }
    }

    /**
     * 快速排序
     * 
     * @param vec   待排序数组
     * @param left  待排序部分左边界索引
     * @param right 待排序部分右边界索引
     */
    // 时间复杂度在最好O(nlog2n)，最坏O(n^2)，平均O(nlog2n)
    // 空间复杂度O(log2n)
    // 不稳定
    private static <T extends Comparable<T>> void quickSort(T[] vec, final int left, final int right) {
        if (left >= right)
            return;
        T tmp = vec[left];
        int low = left, high = right;
        while (low < high) {
            while (low < high && vec[high].compareTo(tmp) > 0)
                high--;
            if (low < high)
                vec[low++] = vec[high];
            while (low < high && vec[low].compareTo(tmp) < 0)
                low++;
            if (low < high)
                vec[high--] = vec[low];
        }
        vec[low] = tmp;
        quickSort(vec, left, low - 1);
        quickSort(vec, low + 1, right);
    }

    // 选择类算法

    /**
     * 直接选择排序
     * 
     * @param vec 待排序数组
     */
    // 时间复杂度O(n^2)
    // 空间复杂度O(1)
    // 不稳定
    private static <T extends Comparable<T>> void selectSort(T[] vec) {
        for (int i = 0; i < vec.length - 1; i++) {
            int idx = i;
            for (int j = i + 1; j < vec.length; j++)
                if (vec[j].compareTo(vec[idx]) < 0)
                    idx = j;
            T tmp = vec[idx];
            vec[idx] = vec[i];
            vec[i] = tmp;
        }
    }

    /**
     * 在一定范围中调整堆数组
     * 
     * @param vec   待调整堆数组
     * @param left  待调整范围左边界索引
     * @param right 待调整范围右边界索引
     */
    private static <T extends Comparable<T>> void heapAdjust(T[] vec, int left, int right) {
        T tmp = vec[left];
        int m = left * 2 + 1;
        while (m <= right) {
            if (m + 1 <= right && vec[m + 1].compareTo(vec[m]) > 0)
                m++;
            if (vec[m].compareTo(tmp) > 0) {
                vec[left] = vec[m];
                left = m;
                m = left * 2 + 1;
            } else
                break;
        }
        vec[left] = tmp;
    }

    /**
     * 堆排序
     * 
     * @param vec 待排序数组
     */
    // 时间复杂度O(nlog2n)
    // 空间复杂度O(1)
    // 不稳定
    private static <T extends Comparable<T>> void heapSort(T[] vec) {
        for (int i = (vec.length - 2) / 2; i >= 0; i--)
            heapAdjust(vec, i, vec.length - 1);
        for (int i = vec.length - 1; i >= 1; i--) {
            T tmp = vec[i];
            vec[i] = vec[0];
            vec[0] = tmp;
            heapAdjust(vec, 0, i - 1);
        }
    }

    // 其他排序算法

    /**
     * 将数组的两个部分归并到一起
     * 
     * @param vec   待归并数组
     * @param left  待归并部分左边界索引
     * @param mid   待归并部分中间分界索引
     * @param right 待归并部分右边界索引
     */
    private static <T extends Comparable<T>> void merge(T[] vec, int left, int mid, int right) {
        ArrayList<T> lvec = new ArrayList<T>();
        for (int i = left; i <= mid; i++)
            lvec.add(vec[i]);
        ArrayList<T> rvec = new ArrayList<T>();
        for (int i = mid + 1; i <= right; i++)
            rvec.add(vec[i]);
        int li = 0, ri = 0;
        while (li < lvec.size() && ri < rvec.size()) {
            if (lvec.get(li).compareTo(rvec.get(ri)) <= 0)
                vec[left++] = lvec.get(li++);
            else
                vec[left++] = rvec.get(ri++);
        }
        while (li < lvec.size())
            vec[left++] = lvec.get(li++);
        while (ri < rvec.size())
            vec[left++] = rvec.get(ri++);
    }

    /**
     * 归并排序
     * 
     * @param vec   待排序数组
     * @param left  待归并部分左边界索引
     * @param right 待归并部分右边界索引
     */
    // 时间复杂度O(nlog2n)
    // 空间复杂度O(n)
    // 稳定
    private static <T extends Comparable<T>> void mergeSort(T[] vec, int left, int right) {
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }

    /**
     * 按照关键字某一位进行排序
     * 
     * @param vec 待排序数组
     * @param k   按照关键字哪一位进行排序
     */
    private static <T extends Number> void radix(T[] vec, int k) {
        ArrayList<ArrayList<T>> qvec = new ArrayList<ArrayList<T>>();
        for (int i = 0; i < 10; i++)
            qvec.add(new ArrayList<T>());
        int m = (int) Math.pow(10, k - 1);
        for (T e : vec)
            qvec.get(e.intValue() / m % 10).add(e);
        m = 0;
        for (ArrayList<T> q : qvec)
            while (!q.isEmpty())
                vec[m++] = q.remove(0);
    }

    /**
     * 基数排序
     * 
     * @param vec 待排序数组
     * @param k   关键字位数
     */
    // 时间复杂度O(d*(rd+n))，d为关键字位数，n为元素个数，rd为关键字基的个数
    // 时间复杂度O(rd)
    // 稳定
    private static <T extends Number> void radixSort(T[] vec, int k) {
        for (int i = 1; i <= k; i++)
            radix(vec, i); // 这里注意根据关键字的每一位进行排序
    }

    /**
     * 双向冒泡排序
     * 
     * @param vec 待排序数组
     */
    // 时间复杂度最好O(n)，最坏O(n^2)，平均O(n^2)
    // 空间复杂度O(1)
    // 稳定
    private static <T extends Comparable<T>> void dbubbleSort(T[] vec) {
        int left = 0, right = vec.length - 1;
        while (left < right) {
            boolean flag = false;
            for (int i = left; i < right; i++)
                if (vec[i].compareTo(vec[i + 1]) > 0) {
                    T tmp = vec[i];
                    vec[i] = vec[i + 1];
                    vec[i + 1] = tmp;
                    flag = true;
                }
            right--;
            for (int i = right; i > left; i--)
                if (vec[i].compareTo(vec[i - 1]) < 0) {
                    T tmp = vec[i];
                    vec[i] = vec[i - 1];
                    vec[i - 1] = tmp;
                    flag = true;
                }
            left++;
            if (!flag)
                return;
        }
    }

    /**
     * 计数排序
     * 
     * 要求待排序所有元素不相同
     * 
     * @param vec  待排序数组
     * @param rvec 结果放置数组
     */
    // 时间复杂度O(n^2)
    // 空间复杂度O(n)
    private static <T extends Comparable<T>> void calcSort(T[] vec, T[] rvec) {
        for (T e : vec) {
            int index = 0;
            for (T ee : vec)
                if (ee.compareTo(e) < 0)
                    index++;
            rvec[index] = e;
        }
    }

    public static void main(String[] args) {
        final int len = 10;
        Integer[] randvec = genRandVec(len, 0, 100);
        printVec(randvec, "original vec");
        Integer[] vec; // 泛型装不了基础数据类型

        vec = randvec.clone();
        insertSort(vec);
        printVec(vec, "after insert sort");

        vec = randvec.clone();
        binsertSort(vec);
        printVec(vec, "after bin insert sort");

        vec = randvec.clone();
        shellSort(vec, 3, k -> k / 2);
        printVec(vec, "after shell sort");

        vec = randvec.clone();
        bubbleSort(vec);
        printVec(vec, "after bubble sort");

        vec = randvec.clone();
        quickSort(vec, 0, len - 1);
        printVec(vec, "after quick sort");

        vec = randvec.clone();
        selectSort(vec);
        printVec(vec, "after select sort");

        vec = randvec.clone();
        heapSort(vec);
        printVec(vec, "after heap sort");

        vec = randvec.clone();
        mergeSort(vec, 0, len - 1);
        printVec(vec, "after merge sort");

        vec = randvec.clone();
        radixSort(vec, 3);
        printVec(vec, "after radix sort");

        vec = randvec.clone();
        dbubbleSort(vec);
        printVec(vec, "after dbubble sort");

        vec = new Integer[] { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        Integer[] rvec = new Integer[10];
        calcSort(vec, rvec);
        printVec(rvec, "after calc sort");
    }
}