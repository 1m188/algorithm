/**
 * @file 7-37 模拟EXCEL排序.cpp
 * @date 2022-05-13
 */

/*
Excel可以对一组纪录按任意指定列排序。现请编写程序实现类似功能。

输入格式:
输入的第一行包含两个正整数N(≤10^5) 和C，其中N是纪录的条数，C是指定排序的列号。
之后有 N行，每行包含一条学生纪录。
每条学生纪录由学号（6位数字，保证没有重复的学号）、姓名（不超过8位且不包含空格的字符串）、
成绩（[0, 100]内的整数）组成，相邻属性用1个空格隔开。

输出格式:
在N行中输出按要求排序后的结果，即：当C=1时，按学号递增排序；
当C=2时，按姓名的非递减字典序排序；
当C=3时，按成绩的非递减排序。
当若干学生具有相同姓名或者相同成绩时，则按他们的学号递增排序。

输入样例:
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60

输出样例:
000001 Zoe 60
000007 James 85
000010 Amy 90

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 排序还是很简单的，如果会用C++里的sort方法的话，
我自己写了一个排序，死活过不去，超时，用标准库里的sort
连100ms都没要，网上看了一下大概说是sort里用了特殊的优化，
结合了多种排序方法，想来也是这道题时间和规模卡的比较紧 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief 存储学生信息的结构体
 */
struct Info {
    int id;      // 学号
    string name; // 名字
    int grade;   // 成绩
};

int N = 0,          // 多少个学生数据
    C = 0;          // 排序模式
vector<Info *> vec; // 待排序数组

/**
 * @brief 处理输入初始化
 */
void input() {
    // io加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C;
    vec.resize(N);
    for (int i = 0; i < N; i++) {
        vec[i] = new Info();
        cin >> vec[i]->id >> vec[i]->name >> vec[i]->grade;
    }
}

/**
 * @brief 自己写快排以及相关的比较函数，超时
 */
// int campare(int c, Info *e1, Info *e2) {
//     if (c == 1) {
//         if (e1->id == e2->id)
//             return 0;
//         else
//             return e1->id < e2->id ? -1 : 1;
//     } else if (c == 2) {
//         if (e1->name == e2->name)
//             return campare(1, e1, e2);
//         else
//             return e1->name < e2->name ? -1 : 1;
//     } else {
//         if (e1->grade == e2->grade)
//             return campare(1, e1, e2);
//         else
//             return e1->grade < e2->grade ? -1 : 1;
//     }
// }

// void qsort(int left = 0, int right = vec.size() - 1) {
//     if (right <= left)
//         return;

//     int start = left, end = right;
//     Info *tmp = vec[start];

//     while (left < right) {
//         while (left < right && campare(C, vec[right], tmp) > 0)
//             right--;
//         if (left < right)
//             vec[left++] = vec[right];
//         while (left < right && campare(C, vec[left], tmp) < 0)
//             left++;
//         if (left < right)
//             vec[right--] = vec[left];
//     }

//     vec[left] = tmp;

//     qsort(start, left - 1);
//     qsort(left + 1, end);
// }

/**
 * @brief 输出，注意相关格式的控制
 */
void print() {
    for (const auto &e : vec)
        cout << setw(6) << setfill('0') << e->id << ' ' << e->name << ' ' << e->grade << '\n';
}

int main() {
    input();
    // qsort();
    sort(vec.begin(), vec.end(), [](Info *p1, Info *p2) {
        if (C == 1)
            return p1->id < p2->id;
        else if (C == 2) {
            if (p1->name != p2->name)
                return p1->name < p2->name;
            else
                return p1->id < p2->id;
        } else {
            if (p1->grade != p2->grade)
                return p1->grade < p2->grade;
            else
                return p1->id < p2->id;
        }
    });
    print();
    return 0;
}