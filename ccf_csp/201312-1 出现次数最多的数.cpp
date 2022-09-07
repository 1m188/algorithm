/**
 * @file 201312-1 出现次数最多的数.cpp
 * @date 2022-09-07
 */

/*
试题编号：	201312-1
试题名称：	出现次数最多的数
时间限制：	1.0s
内存限制：	256.0MB
问题描述：	
问题描述
　　给定n个正整数，找出它们中出现次数最多的数。如果这样的数有多个，请输出其中最小的一个。
输入格式
　　输入的第一行只有一个正整数n(1 ≤ n ≤ 1000)，表示数字的个数。
　　输入的第二行有n个整数s1, s2, …, sn (1 ≤ si ≤ 10000, 1 ≤ i ≤ n)。相邻的数用空格分隔。
输出格式
　　输出这n个次数中出现次数最多的数。如果这样的数有多个，输出其中最小的一个。
样例输入
6
10 1 10 20 30 20
样例输出
10
*/

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n = 0;
vector<int> vec;

int main() {

    scanf("%d", &n);
    vec.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);

    sort(vec.begin(), vec.end());

    int idx = 0;
    int res = 0;
    int cnt = 1;

    for (int i = 1; i < n; i++) {
        if (vec[i] == vec[i - 1])
            cnt++;
        else {
            if (cnt > res) {
                idx = i - 1;
                res = cnt;
            }
            cnt = 1;
        }
    }

    printf("%d", vec[idx]);

    return 0;
}