/*

交换类排序

*/

#include "iostream"
#include "cstdlib"
#include "ctime"
#include "string"
#include "vector"
#include "algorithm"

// 生成一个随机整数组
// left和right指闭区间[left,right]上的数
std::vector<int> genrandvec(int len, int left, int right)
{
    if (left > right || left < 0 || right < 0 || len <= 0)
        return {};

    srand(static_cast<unsigned int>(time(nullptr)));
    std::vector<int> vec(len, 0);
    for (int i = 0; i < len; i++)
        vec[i] = rand() % (right - left + 1) + left;
    return vec;
}

// 输出一个数组
// prefix指输出时的字符串前缀
template <typename T>
void printvec(const std::vector<T> &vec, const std::string &prefix)
{
    std::cout << prefix << ':';
    std::for_each(
        vec.cbegin(), vec.cend(), [](const T &n) { std::cout << ' ' << n; });
    std::cout << '\n';
}

/******************************************************************************************************************/

// 冒泡排序
template <typename T>
void bubbleSort(std::vector<T> &vec)
{
    // 时间复杂度最好情况为O(n)，最坏情况为O(n^2)，平均为O(n^2)
    // 空间复杂度为O(1)
    // 是一个稳定的算法

    for (int i = vec.size() - 1; i >= 1; i--)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
                flag = true;
            }
        if (!flag)
            return;
    }
}

// 快速排序
// left right 为 [left,right]待排序区间
template <typename T>
void quickSort(std::vector<T> &vec, int left, int right)
{
    // 时间复杂度最好情况下为O(nlog2n)，最坏情况下O(n^2)，平均O(nlog2n)，在所有的O(nlog2n)算法里基本操作执行次数最少，同级别算法中最好
    // 空间复杂度为O(log2n)
    // 是一个不稳定的算法

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

/******************************************************************************************************************/

int main(int argc, char *argv[])
{
    const int len = 10;
    std::vector<int> &&randvec = genrandvec(len, 0, 100);
    printvec(randvec, "original vec");
    std::vector<int> vec;

    vec = randvec;
    bubbleSort(vec);
    printvec(vec, "after bubble sort");

    vec = randvec;
    quickSort(vec, 0, len - 1);
    printvec(vec, "after quick sort");

    return 0;
}