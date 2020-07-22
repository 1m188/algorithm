/*

选择类排序

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

// 直接选择排序
template <typename T>
void selectSort(std::vector<T> &vec)
{
    // 时间复杂度为O(n^2)
    // 空间复杂度为O(1)
    // 是一个不稳定的算法

    for (int i = 0; i < vec.size() - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < vec.size(); j++)
            if (vec[j] < vec[index])
                index = j;
        std::swap(vec[i], vec[index]);
    }
}

// 大顶堆调整节点
// 在[left,right]区间中调整根节点
template <typename T>
void heapAdjust(std::vector<T> &vec, int left, int right)
{
    T tmp = vec[left];
    int m = left * 2 + 1;
    while (m <= right)
    {
        if (m + 1 <= right && vec[m + 1] > vec[m])
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

// 堆排序 大顶堆
template <typename T>
void heapSort(std::vector<T> &vec)
{
    // 时间复杂度为O(nlog2n)
    // 空间复杂度为O(1)，是所有时间O(nlog2n)算法里最好的
    // 是一个不稳定的算法
    // 适用于关键字多的场景

    for (int i = (vec.size() - 2) / 2; i >= 0; i--)
        heapAdjust(vec, i, vec.size() - 1);
    for (int i = vec.size() - 1; i >= 1; i--)
    {
        std::swap(vec[0], vec[i]);
        heapAdjust(vec, 0, i - 1);
    }
}

/******************************************************************************************************************/

int main(int argc, char *argv[])
{
    const int len = 10;
    std::vector<int> &&randvec = genrandvec(len, 0, 100);
    printvec(randvec, "original vec");
    std::vector<int> vec;

    vec = randvec;
    selectSort(vec);
    printvec(vec, "after select sort");

    vec = randvec;
    heapSort(vec);
    printvec(vec, "after heap sort");

    return 0;
}