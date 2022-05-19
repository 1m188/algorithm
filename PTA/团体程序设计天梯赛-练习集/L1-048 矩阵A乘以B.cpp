/**
 * @file L1-048 矩阵A乘以B.cpp
 * @date 2022-05-19
 */

/*
给定两个矩阵A和B，要求你计算它们的乘积矩阵AB。需要注意的是，只有规模匹配的矩阵才可以相乘。即若A有R 
a
​
 行、C 
a
​
 列，B有R 
b
​
 行、C 
b
​
 列，则只有C 
a
​
 与R 
b
​
 相等时，两个矩阵才能相乘。

输入格式：
输入先后给出两个矩阵A和B。对于每个矩阵，首先在一行中给出其行数R和列数C，随后R行，每行给出C个整数，以1个空格分隔，且行首尾没有多余的空格。输入保证两个矩阵的R和C都是正数，并且所有整数的绝对值不超过100。

输出格式：
若输入的两个矩阵的规模是匹配的，则按照输入的格式输出乘积矩阵AB，否则输出Error: Ca != Rb，其中Ca是A的列数，Rb是B的行数。

输入样例1：
2 3
1 2 3
4 5 6
3 4
7 8 9 0
-1 -2 -3 -4
5 6 7 8
输出样例1：
2 4
20 22 24 16
53 58 63 28
输入样例2：
3 2
38 26
43 -5
0 17
3 2
-11 57
99 68
81 72
输出样例2：
Error: 2 != 3
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 矩阵相乘计算，注意行和列 */

#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> ma, // a矩阵
    mb,                 // b矩阵
    ans;                // 结果矩阵

/**
 * @brief 输入两个矩阵
 */
void input() {
    int r = 0, c = 0;

    scanf("%d %d", &r, &c);
    ma.resize(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &ma[i][j]);

    scanf("%d %d", &r, &c);
    mb.resize(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mb[i][j]);
}

/**
 * @brief 计算
 */
void calc() {
    ans.resize(ma.size(), vector<int>(mb[0].size()));

    for (int i = 0; i < ans.size(); i++) {        // 对每一列
        for (int j = 0; j < ans[i].size(); j++) { // 对每一行

            int sum = 0;

            for (int k = 0; k < mb.size(); k++) // 求当前位置上的这个元素
                sum += ma[i][k] * mb[k][j];

            ans[i][j] = sum;
        }
    }
}

int main() {

    input();

    if (ma[0].size() != mb.size()) { // 不能相乘
        printf("Error: %zu != %zu", ma[0].size(), mb.size());
        return 0;
    }

    calc();

    printf("%zu %zu\n", ans.size(), ans[0].size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i][0]);
        for (int j = 1; j < ans[i].size(); j++) {
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}