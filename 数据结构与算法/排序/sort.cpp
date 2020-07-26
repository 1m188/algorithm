/*

排序算法

*/

#include "iostream"
#include "vector"
#include "string"
#include "cstdlib"
#include "ctime"
#include "algorithm"
#include "functional"
#include "queue"
#include "cmath"

// 生成一个随机整数组
std::vector<int> genRandVec(int len, int left, int right)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    std::vector<int> vec(len);
    for (auto it = vec.begin(); it < vec.end(); it++)
        *it = rand() % (right - left + 1) + left;
    return vec;
}

// 输出一个数组
template <typename T>
void printVec(const std::vector<T> &vec, const std::string &prefix)
{
    std::cout << prefix << ':';
    std::for_each(vec.cbegin(), vec.cend(), [](const auto &e) { std::cout << ' ' << e; });
    std::cout << '\n';
}

/*******************************************************************************************************************************/

// 插入类算法

// 直接插入排序
// 时间复杂度最好O(n)，最坏O(n^2)，平均O(n^2)
// 空间复杂度O(1)
// 稳定
template <typename T>
void insertSort(std::vector<T> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        T tmp = vec[i];
        int idx = i - 1;
        for (; idx >= 0 && vec[idx] > tmp; idx--)
            vec[idx + 1] = vec[idx];
        vec[idx + 1] = tmp;
    }
}

// 从数组的有序部分中寻找待插入位置索引
template <typename T>
int bindex(const std::vector<T> &vec, int left, int right, const T &target)
{
    int mid = (left + right) / 2;
    while (left < right)
    {
        if (vec[mid] == target)
            return mid + 1;
        else if (vec[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
        mid = (left + right) / 2;
    }
    return vec[mid] <= target ? mid + 1 : mid;
}

// 折半插入排序
// 时间复杂度最好O(nlog2n)，最坏O(n^2)，平均O(n^2)
// 空间复杂度O(1)
// 稳定
template <typename T>
void binsertSort(std::vector<T> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        int index = bindex(vec, 0, i - 1, vec[i]);
        T tmp = vec[i];
        for (int idx = i - 1; idx >= index; idx--)
            vec[idx + 1] = vec[idx];
        vec[index] = tmp;
    }
}

// 希尔排序
// 时间复杂度平均O(nlog2n)
// 空间复杂度O(1)
// 不稳定
template <typename T>
void shellSort(std::vector<T> &vec, int k, const std::function<int(int)> &kfun)
{
    while (k > 1)
    {
        for (int i = 0; i < k; i++)
            for (int j = i + k; j < vec.size(); j += k)
            {
                T tmp = vec[j];
                int idx = j - k;
                for (; idx >= i && vec[idx] > tmp; idx -= k)
                    vec[idx + k] = vec[idx];
                vec[idx + k] = tmp;
            }
        k = kfun(k);
    }
    for (int i = 1; i < vec.size(); i++)
    {
        T tmp = vec[i];
        int idx = i - 1;
        for (; idx >= 0 && vec[idx] > tmp; idx--)
            vec[idx + 1] = vec[idx];
        vec[idx + 1] = tmp;
    }
}

// 交换类算法

// 冒泡排序
// 时间复杂度最好O(n)，最坏O(n^2)，平均O(n^2)
// 空间复杂度O(1)
// 稳定
template <typename T>
void bubbleSort(std::vector<T> &vec)
{
    for (int i = vec.size(); i >= 1; i--)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
            if (vec[j] > vec[j + 1])
                std::swap(vec[j], vec[j + 1]), flag = true;
        if (!flag)
            return;
    }
}

// 快速排序
// 时间复杂度最好O(nlog2n)，最坏O(n^2)，平均O(nlog2n)
// 空间复杂度O(log2n)
// 不稳定
template <typename T>
void quickSort(std::vector<T> &vec, int left, int right)
{
    if (left >= right)
        return;
    T tmp = vec[left];
    int low = left, high = right;
    while (low < high)
    {
        while (low < high && vec[high] > tmp)
            high--;
        if (low < high)
            vec[low++] = vec[high];
        while (low < high && vec[low] < tmp)
            low++;
        if (low < high)
            vec[high--] = vec[low];
    }
    vec[low] = tmp;
    quickSort(vec, left, low - 1);
    quickSort(vec, low + 1, right);
}

// 选择类算法

// 直接选择排序
// 时间复杂度O(n^2)
// 空间复杂度O(1)
// 不稳定
template <typename T>
void selectSort(std::vector<T> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < vec.size(); j++)
            if (vec[j] < vec[idx])
                idx = j;
        std::swap(vec[idx], vec[i]);
    }
}

// 调整堆
template <typename T>
void heapAdjust(std::vector<T> &vec, int left, int right)
{
    T tmp = vec[left];
    int m = left * 2 + 1;
    while (m <= right)
    {
        if (m + 1 <= right && vec[m + 1] > vec[m]) // 大顶堆选取两个子节点中最大的和父节点比较
            m++;
        if (vec[m] > tmp)
        {
            vec[left] = vec[m];
            left = m;
            m = left * 2 + 1;
        }
        else
            break;
    }
    vec[left] = tmp;
}

// 堆排序
// 时间复杂度O(nlog2n)
// 空间复杂度O(1)
// 不稳定
template <typename T>
void heapSort(std::vector<T> &vec)
{
    for (int i = (vec.size() - 2) / 2; i >= 0; i--)
        heapAdjust(vec, i, vec.size() - 1);
    for (int i = vec.size() - 1; i >= 1; i--)
    {
        std::swap(vec[0], vec[i]);
        heapAdjust(vec, 0, i - 1);
    }
}

// 其他排序算法

// 将数组中两个有序部分归并起来
template <typename T>
void merge(std::vector<T> &vec, int left, int mid, int right)
{
    std::vector<T> lvec(vec.begin() + left, vec.begin() + mid + 1), rvec(vec.begin() + mid + 1, vec.begin() + right + 1);
    int lidx = 0, ridx = 0;
    while (lidx < lvec.size() && ridx < rvec.size())
        if (lvec[lidx] <= rvec[ridx])
            vec[left++] = lvec[lidx++];
        else
            vec[left++] = rvec[ridx++];
    while (lidx < lvec.size())
        vec[left++] = lvec[lidx++];
    while (ridx < rvec.size())
        vec[left++] = rvec[ridx++];
}

// 归并排序
// 时间复杂度O(nlog2n)
// 空间复杂度O(n)
// 稳定
template <typename T>
void mergeSort(std::vector<T> &vec, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

// 按照关键字的每一位进行的排序
template <typename T>
void radix(std::vector<T> &vec, int nd)
{
    std::vector<std::queue<T>> qvec(10);
    int m = pow(10, nd - 1);
    for (const T &e : vec)
        qvec[e / m % 10].push(e);
    m = 0;
    for (std::queue<T> &q : qvec)
        while (!q.empty())
        {
            vec[m++] = q.front();
            q.pop();
        }
}

// 基数排序
// 时间复杂度O(d*(n+rd))，d为关键字位数，rd为关键字基的个数，n为元素个数
// 空间复杂度O(rd)
// 稳定
template <typename T>
void radixSort(std::vector<T> &vec, int d)
{
    for (int i = 1; i <= d; i++)
        radix(vec, i);
}

// 双向冒泡排序
// 时间复杂度最好O(n)，最坏O(n^2)
// 空间复杂度O(1)
// 稳定
template <typename T>
void dbubbleSort(std::vector<T> &vec)
{
    int left = 0, right = vec.size() - 1;
    while (left < right)
    {
        bool flag = false;
        for (int i = left; i < right; i++)
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i], vec[i + 1]);
                flag = true;
            }
        right--;
        for (int i = right; i > left; i--)
            if (vec[i] < vec[i - 1])
            {
                std::swap(vec[i], vec[i - 1]);
                flag = true;
            }
        left++;
        if (!flag)
            return;
    }
}

// 计数排序
// 时间复杂度O(n^2)
// 空间复杂度O(n)
template <typename T>
std::vector<T> calcSort(const std::vector<T> &vec)
{
    std::vector<T> rvec(vec.size());
    for (const T &e : vec)
    {
        int idx = 0;
        for (const T &ee : vec)
            if (ee < e)
                idx++;
        rvec[idx] = e;
    }
    return rvec;
}

/*******************************************************************************************************************************/

int main(int argc, char *argv[])
{
    const int len = 10;
    std::vector<int> &&randvec = genRandVec(len, 0, 100);
    printVec(randvec, "original vec");
    std::vector<int> vec;

    vec = randvec;
    insertSort(vec);
    printVec(vec, "insert sort");

    vec = randvec;
    binsertSort(vec);
    printVec(vec, "bin insert sort");

    vec = randvec;
    shellSort(vec, 3, [](const int &k) { return k / 2; });
    printVec(vec, "shell sort");

    vec = randvec;
    bubbleSort(vec);
    printVec(vec, "bubble sort");

    vec = randvec;
    quickSort(vec, 0, len - 1);
    printVec(vec, "quick sort");

    vec = randvec;
    selectSort(vec);
    printVec(vec, "select sort");

    vec = randvec;
    heapSort(vec);
    printVec(vec, "heap sort");

    vec = randvec;
    mergeSort(vec, 0, len - 1);
    printVec(vec, "merge sort");

    vec = randvec;
    radixSort(vec, 3);
    printVec(vec, "radix sort");

    vec = randvec;
    dbubbleSort(vec);
    printVec(vec, "dbubble sort");

    vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vec = calcSort(vec);
    printVec(vec, "calc sort");

    return 0;
}