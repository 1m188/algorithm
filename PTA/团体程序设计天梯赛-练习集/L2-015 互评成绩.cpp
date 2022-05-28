/**
 * @file L2-015 互评成绩.cpp
 * @date 2022-05-28
 */

/*
学生互评作业的简单规则是这样定的：每个人的作业会被k个同学评审，得到k个成绩。系统需要去掉一个最高分和一个最低分，将剩下的分数取平均，就得到这个学生的最后成绩。本题就要求你编写这个互评系统的算分模块。

输入格式：
输入第一行给出3个正整数N（3 < N ≤10 
4
 ，学生总数）、k（3 ≤ k ≤ 10，每份作业的评审数）、M（≤ 20，需要输出的学生数）。随后N行，每行给出一份作业得到的k个评审成绩（在区间[0, 100]内），其间以空格分隔。

输出格式：
按非递减顺序输出最后得分最高的M个成绩，保留小数点后3位。分数间有1个空格，行首尾不得有多余空格。

输入样例：
6 5 3
88 90 85 99 60
67 60 80 76 70
90 93 96 99 99
78 65 77 70 72
88 88 88 88 88
55 55 55 55 55
输出样例：
87.667 88.000 96.000
代码长度限制
16 KB
时间限制
300 ms
内存限制
64 MB
*/

/* 小顶堆求前m大数据（当然或许不用堆直接存储排序或许也可以） */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

/**
 * @brief 小顶堆调整
 * @tparam T 堆内数据类型
 * @param vec 小顶堆
 * @param x 从x索引处所代表的节点向下调整
 */
template <typename T>
void adjust(vector<T> &vec, int x) {
    T tmp = vec[x];

    int k = x * 2 + 1;
    while (k < vec.size()) {
        if (k + 1 < vec.size() && vec[k + 1] < vec[k])
            k = k + 1;

        if (vec[k] < tmp) {
            vec[x] = vec[k];
        } else
            break;

        x = k;
        k = x * 2 + 1;
    }

    vec[x] = tmp;
}

/**
 * @brief 建堆
 * @tparam T 堆内数据类型
 * @param vec 待建小顶堆的数组
 */
template <typename T>
void build_heap(vector<T> &vec) {
    for (int i = (vec.size() - 1 - 1) / 2; i >= 0; i--)
        adjust(vec, i);
}

int main() {

    int n = 0, k = 0, m = 0;
    scanf("%d %d %d", &n, &k, &m);

    vector<double> grade;

    while (n--) {

        // 挨个读入成绩，求和，求最大最小值，以及之后求最终成绩
        int sum = 0, maxg = -1, ming = 101;
        for (int i = 0; i < k; i++) {
            int x = 0;
            scanf("%d", &x);
            sum += x;
            if (x > maxg)
                maxg = x;
            if (x < ming)
                ming = x;
        }

        sum -= maxg + ming;
        double g = double(sum) / (k - 2);

        // 取前m个数建小顶堆，之后的数如果比堆顶（小顶堆里最小的）要大，
        // 则取代之，并从根向下调整，直到最后，此时堆里有的是前m大的元素
        if (grade.size() < m) {
            grade.push_back(g);
            if (grade.size() == m)
                build_heap(grade);
        } else if (g > grade[0]) {
            grade[0] = g;
            adjust(grade, 0);
        }
    }

    sort(grade.begin(), grade.end()); // 不要忘记排序，前m大不代表之中有序

    // 按要求输出
    printf("%.3lf", grade[0]);
    for (int i = 1; i < grade.size(); i++)
        printf(" %.3lf", grade[i]);

    return 0;
}