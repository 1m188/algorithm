/**
 * @file L2-012 关于堆的判断.cpp
 * @date 2022-05-24
 */

/*
将一系列给定数字顺序插入一个初始为空的小顶堆H[]。随后判断一系列相关命题是否为真。命题分下列几种：

x is the root：x是根结点；
x and y are siblings：x和y是兄弟结点；
x is the parent of y：x是y的父结点；
x is a child of y：x是y的一个子结点。
输入格式：
每组测试第1行包含2个正整数N（≤ 1000）和M（≤ 20），分别是插入元素的个数、以及需要判断的命题数。下一行给出区间[−10000,10000]内的N个要被插入一个初始为空的小顶堆的整数。之后M行，每行给出一个命题。题目保证命题中的结点键值都是存在的。

输出格式：
对输入的每个命题，如果其为真，则在一行中输出T，否则输出F。

输入样例：
5 4
46 23 26 24 10
24 is the root
26 and 23 are siblings
46 is the parent of 23
23 is a child of 10
输出样例：
F
T
F
T
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 堆的性质

注意细节，尤其是题目里说的是向一个空小顶堆逐一插入元素，而不是把一大把
元素建立成堆，建堆所需要的调整是从上至下，而插入所需要的调整是从下至上 */

#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief 向小顶堆里插入一个元素
 * @param heap 小顶堆
 * @param x 待插入元素
 */
void insert_heap(vector<int> &heap, int x) {
    heap.push_back(x);

    for (int i = heap.size() - 1; i >= 0; i = (i - 1) / 2) {
        if (heap[i] < heap[(i - 1) / 2]) // 不断和父亲比较，如果更小就交换
            swap(heap[i], heap[(i - 1) / 2]);
        else // 否则到头，直接跳出
            break;
    }
}

/**
 * @brief 判断小顶堆里两个元素是否是父子关系
 * @param heap 小顶堆
 * @param parent 待判断的父亲
 * @param child 待判断的孩子
 * @return true 是
 * @return false 否
 */
bool is_parent(const vector<int> &heap, int parent, int child) {
    int pi = -1;
    for (int i = 0; i < heap.size(); i++) { // 先找到父亲所在索引
        if (heap[i] == parent) {
            pi = i;
            break;
        }
    }

    if (pi == -1)
        return false;

    // 判断父亲是否有一个孩子是
    if ((pi * 2 + 1 < heap.size() && heap[pi * 2 + 1] == child) ||
        (pi * 2 + 2 < heap.size() && heap[pi * 2 + 2] == child))
        return true;

    return false;
}

/**
 * @brief 判断小顶堆里两个元素是否是兄弟
 * @param heap 小顶堆
 * @param x 待判断的兄弟之一
 * @param y 待判断的兄弟之二
 * @return true 是
 * @return false 否
 */
bool is_siblings(const vector<int> &heap, int x, int y) {
    int ix = -1, iy = -1;
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i] == x)
            ix = i;
        if (heap[i] == y)
            iy = i;
    }

    if (ix == -1 || iy == -1)
        return false;

    if ((ix - 1) / 2 == (iy - 1) / 2) // 找到两个兄弟判断他们的父亲是否一致
        return true;

    return false;
}

int main() {

    vector<int> H;

    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    while (n--) {
        int a = 0;
        scanf("%d", &a);
        insert_heap(H, a);
    }
    getchar(); // 注意吃掉最后一个回车，后面要加字符串

    while (m--) {
        string s;
        for (char c; (c = getchar()) != '\n';)
            s.push_back(c);

        if (s.find("root") != s.npos) {

            stringstream ss(s);
            int x = 0;
            ss >> x;
            printf(x == H[0] ? "T\n" : "F\n");

        } else if (s.find("siblings") != s.npos) {

            stringstream ss(s);
            int x = 0, y = 0;
            ss >> x;
            for (int i = 0; i < 5; i++)
                ss.get();
            ss >> y;

            printf(is_siblings(H, x, y) ? "T\n" : "F\n");

        } else if (s.find("parent") != s.npos) {

            stringstream ss(s);
            int son = 0, father = 0;
            ss >> father;
            for (int i = 0; i < 18; i++)
                ss.get();
            ss >> son;

            printf(is_parent(H, father, son) ? "T\n" : "F\n");

        } else {

            stringstream ss(s);
            int son = 0, father = 0;
            ss >> son;
            for (int i = 0; i < 15; i++)
                ss.get();
            ss >> father;

            printf(is_parent(H, father, son) ? "T\n" : "F\n");
        }
    }

    return 0;
}