/**
 * @file 7-29 修理牧场.cpp
 * @date 2022-05-09
 */

/*
农夫要修理牧场的一段栅栏，他测量了栅栏，发现需要N块木头，每块木头长度为整数L_i
​个长度单位，于是他购买了一条很长的、能锯成N块的木头，即该木头的长度是L_i的总和。

但是农夫自己没有锯子，请人锯木的酬金跟这段木头的长度成正比。
为简单起见，不妨就设酬金等于所锯木头的长度。
例如，要将长度为20的木头锯成长度为8、7和5的三段，第一次锯木头花费20，
将木头锯成12和8；第二次锯木头花费12，将长度为12的木头锯成7和5，总花费为32。
如果第一次将木头锯成15和5，则第二次锯木头花费15，总花费为35（大于32）。

请编写程序帮助农夫计算将木头锯成N块的最少花费。

输入格式:
输入首先给出正整数N（≤10^4），表示要将木头锯成N块。
第二行给出N个正整数（≤50），表示每段木块的长度。

输出格式:
输出一个整数，即将木头锯成N块的最少花费。

输入样例:
8
4 5 1 2 1 3 1 1

输出样例:
49

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 哈夫曼树 */

#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 优先队列，数字小的优先度高，便于取出
priority_queue<int, vector<int>, greater<int>> pque;

/**
 * @brief 输入初始化
 */
void input() {
    int N = 0;
    cin >> N;
    while (N--) {
        int t = 0;
        cin >> t;
        pque.push(t);
    }
}

/**
 * @brief 计算最少花费
 * @return int 最终结果
 */
int calc() {
    // 最终结果，对于每一次的加和，需要锯一次木头，
    // 即花一次钱，哈夫曼树能让短的木头在尽可能远的
    // 地方被锯，长的木头尽可能早的锯，而木头越长，
    // 花费越多，所以长木头尽可能早锯
    int ans = 0;
    while (pque.size() > 1) {
        int x = pque.top();
        pque.pop();
        int y = pque.top();
        pque.pop();
        ans += x + y;
        pque.push(x + y);
    }
    return ans;
}

int main() {
    input();
    cout << calc();
    return 0;
}