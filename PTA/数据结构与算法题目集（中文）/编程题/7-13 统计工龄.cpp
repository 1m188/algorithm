/*
给定公司N名员工的工龄，要求按工龄增序输出每个工龄段有多少员工。

输入格式:
输入首先给出正整数N（≤10^5），即员工总人数；随后给出N个整数，即每个员工的工龄，范围在[0, 50]。

输出格式:
按工龄的递增顺序输出每个工龄的员工个数，格式为：“工龄:人数”。每项占一行。如果人数为0则不输出该项。

输入样例:
8
10 2 0 5 7 2 5 2

输出样例:
0:1
2:3
5:2
7:1
10:1

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

#include <iostream>
#include <vector>

using namespace std;

int N = 0;
vector<int> vec;

void input() {
    cin >> N;
    vec.resize(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
}

// 快速排序  选择数组头元素作为枢轴
void quicksort(int start = 0, int end = N - 1) {
    if (start >= end)
        return;

    int left = start, right = end, tmp = vec[start];

    while (left < right) {
        while (left < right && vec[right] > tmp)
            right--;
        if (left < right)
            vec[left++] = vec[right];
        while (left < right && vec[left] < tmp)
            left++;
        if (left < right)
            vec[right--] = vec[left];
    }

    vec[left] = tmp;

    quicksort(start, left - 1);
    quicksort(left + 1, end);
}

// 计数输出
void print() {
    int age = vec[0], count = 1;
    for (int i = 1; i < N; i++) {
        if (vec[i] == age)
            count++;
        else {
            cout << age << ':' << count << '\n';
            age = vec[i];
            count = 1;
        }
    }
    cout << age << ':' << count;
}

int main() {
    input();
    quicksort();
    print();
    return 0;
}