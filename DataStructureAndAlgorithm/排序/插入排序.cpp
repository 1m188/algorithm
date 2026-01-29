/*

插入类排序

*/

#include "iostream"
#include "cstdlib"
#include "ctime"
#include "string"
#include "vector"
#include "algorithm"
#include "functional"

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

/***********************************************************************************************************************/

// 直接插入排序
template <typename T>
void insertSort(std::vector<T> &vec)
{
    // 时间复杂度最坏情况下为O(n^2)，最好情况下为O(n)，平均为O(n^2)
    // 空间复杂度为O(1)
    // 是一个稳定的算法

    for (int i = 1; i < vec.size(); i++)
    {
        T tmp = vec[i];
        int in = i - 1;
        for (; in >= 0 && tmp < vec[in]; in--)
            vec[in + 1] = vec[in];
        vec[in + 1] = tmp;
    }
}

// 在有序数组里二分寻找待插入的位置
// left right 为[left,right]闭区间
// target为待插入的数
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
template <typename T>
void binsertSort(std::vector<T> &vec)
{
    // 时间复杂度最坏情况为O(n^2)，最好情况为O(nlog2n)，平均为O(n^2)
    // 空间复杂度为O(1)
    // 是一个稳定的算法

    for (int i = 1; i < vec.size(); i++)
    {
        T tmp = vec[i];
        int in = bindex(vec, 0, i - 1, tmp);
        for (int j = i - 1; j >= in; j--)
            vec[j + 1] = vec[j];
        vec[in] = tmp;
    }
}

// 希尔排序
// k为初始增量，kfun为增量选取策略
template <typename T>
void shellSort(std::vector<T> &vec, int k, const std::function<int(int)> &kfun)
{
    // 时间复杂度和增量选取有关，k/2的时间复杂度为O(n^2)
    // 空间复杂度为O(1)
    // 是一个不稳定的算法

    while (k > 1)
    {
        for (int i = 0; i < k; i++)
            for (int j = i + k; j < vec.size(); j += k)
            {
                T tmp = vec[j];
                int in = j - k;
                for (; in >= i && vec[in] > tmp; in -= k)
                    vec[in + k] = vec[in];
                vec[in + k] = tmp;
            }
        k = kfun(k);
    }

    for (int i = 1; i < vec.size(); i++)
    {
        T tmp = vec[i];
        int in = i - 1;
        for (; in >= 0 && vec[in] > tmp; in--)
            vec[in + 1] = vec[in];
        vec[in + 1] = tmp;
    }
}

/***********************************************************************************************************************/

int main(int argc, char *argv[])
{
    const std::vector<int> &&randvec = genrandvec(10, 0, 100);
    printvec(randvec, "original vec");
    std::vector<int> vec;

    vec = randvec;
    insertSort(vec);
    printvec(vec, "after insert sort");

    vec = randvec;
    binsertSort(vec);
    printvec(vec, "after binary insert sort");

    vec = randvec;
    shellSort(vec, 3, [](int k) { return k / 2; });
    printvec(vec, "after shell /2 sort");

    return 0;
}