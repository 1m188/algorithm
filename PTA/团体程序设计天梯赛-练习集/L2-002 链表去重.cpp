/**
 * @file L2-002 链表去重.cpp
 * @date 2022-05-21
 */

/*
给定一个带整数键值的链表 L，你需要把其中绝对值重复的键值结点删掉。即对每个键值 K，只有第一个绝对值等于 K 的结点被保留。同时，所有被删除的结点须被保存在另一个链表上。例如给定 L 为 21→-15→-15→-7→15，你需要输出去重后的链表 21→-15→-7，还有被删除的链表 -15→15。

输入格式：
输入在第一行给出 L 的第一个结点的地址和一个正整数 N（≤10 
5
 ，为结点总数）。一个结点的地址是非负的 5 位整数，空地址 NULL 用 −1 来表示。

随后 N 行，每行按以下格式描述一个结点：

地址 键值 下一个结点
其中地址是该结点的地址，键值是绝对值不超过10 
4
 的整数，下一个结点是下个结点的地址。

输出格式：
首先输出去重后的链表，然后输出被删除的链表。每个结点占一行，按输入的格式输出。

输入样例：
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
输出样例：
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 数组下标模拟链表地址，注意输出格式 */

#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int head_addr = 0;                     // 第一个节点的地址
vector<pair<int, int>> vec(99999 + 1); // 索引是地址，first是值，second是下一个节点的地址
vector<bool> flags(1e4 + 1);           // 值是否已经有了，数组模拟set

/**
 * @brief 输入
 */
void input() {
    int n = 0;
    scanf("%d %d", &head_addr, &n);

    while (n--) {
        int a = 0, b = 0, c = 0;
        scanf("%d %d %d", &a, &b, &c);
        vec[a].first = b;
        vec[a].second = c;
    }
}

/**
 * @brief 计算并输出
 */
void calc() {

    // 无节点
    if (head_addr == -1)
        return;

    int del_head_addr = -1,                  // 要删除的链表头节点
        del_cur = -1;                        // 要删除的链表上的游标
    int pre = head_addr;                     // 剩余链表遍历时候的上一个节点地址
    flags[abs(vec[head_addr].first)] = true; // 初始化第一个节点

    for (int i = vec[head_addr].second; i != -1; i = vec[i].second) {

        int aval = abs(vec[i].first);

        if (flags[aval]) {             // 如果已经有这个结点的话
            if (del_head_addr == -1) { // 要删除的链表是否已有？
                del_head_addr = i;
                del_cur = i;
            } else { // 注意游标的运动
                vec[del_cur].second = i;
                del_cur = i;
            }
        } else { // 没有那就是剩下链表的一部分了
            flags[aval] = true;
            vec[pre].second = i;
            pre = i;
        }
    }
    vec[pre].second = -1;
    if (del_cur != -1) // 万一绝对值都没重复呢？
        vec[del_cur].second = -1;

    for (int i = head_addr; i != -1; i = vec[i].second) {
        printf("%05d %d ", i, vec[i].first);
        if (vec[i].second != -1) // 这里尤其要注意，输出下一个地址的时候如果有地址的话要按照一般地址格式输出，如果是-1则直接输出
            printf("%05d\n", vec[i].second);
        else
            printf("-1\n");
    }
    for (int i = del_head_addr; i != -1; i = vec[i].second) {
        printf("%05d %d ", i, vec[i].first);
        if (vec[i].second != -1)
            printf("%05d\n", vec[i].second);
        else
            printf("-1\n");
    }
}

int main() {
    input();
    calc();
    return 0;
}