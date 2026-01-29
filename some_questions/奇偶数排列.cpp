/*

输入一个数组，实现一个函数，让所有奇数都在偶数前面

*/

#include "iostream"
#include "vector"

void odd_even_numSort(std::vector<int> &vec) // 一趟快排
{
    int left = 0, right = vec.size() - 1;
    int tmp = vec[left];
    while (left < right)
    {
        while (left < right && vec[right] % 2 == 0)
            right--;
        if (left < right)
            vec[left++] = vec[right];
        while (left < right && vec[left] % 2 == 1)
            left++;
        if (left < right)
            vec[right--] = vec[left];
    }
    vec[left] = tmp;
}

int main(int argc, char *argv[])
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    odd_even_numSort(vec);
    for (const int &e : vec)
        std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}