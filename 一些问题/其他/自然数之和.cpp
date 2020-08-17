/*

一个无序自然数数列，给定一个数M，选取自然数数列中两个数，其中他们的和是M，打印所有这样的自然数对

*/

#include "iostream"
#include "vector"

template <typename T>
void quickSort(std::vector<T> &vec, const int left, const int right)
{
    if (left >= right)
        return;

    int low = left, high = right;
    T tmp = vec[low];
    while (low < high)
    {
        while (low < high && vec[high] >= tmp)
            high--;
        if (low < high)
            vec[low++] = vec[high];
        while (low < high && vec[low] <= tmp)
            low++;
        if (low < high)
            vec[high--] = vec[low];
    }
    vec[low] = tmp;
    quickSort(vec, left, low - 1);
    quickSort(vec, low + 1, right);
}

void printAnd(const std::vector<int> &v, const int M)
{
    std::vector<int> vec(v);
    quickSort(vec, 0, vec.size() - 1);

    int left = 0, right = vec.size() - 1;
    int sum = vec[left] + vec[right];
    while (left < right && sum != M)
    {
        if (sum > M)
            right--;
        else
            left++;
        sum = vec[left] + vec[right];
    }

    while (left < right)
    {
        std::cout << vec[left] << ' ' << vec[right] << '\n';
        left++, right--;
    }
}

int main(int argc, char *argv[])
{
    std::vector<int> vec{1, 3, 2, 4, 5, 10, 9, 8, 6, 7};
    printAnd(vec, 10);

    return 0;
}