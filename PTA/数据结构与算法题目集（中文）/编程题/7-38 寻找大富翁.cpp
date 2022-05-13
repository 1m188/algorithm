/**
 * @file 7-38 寻找大富翁.cpp
 * @date 2022-05-13
 */

/*
胡润研究院的调查显示，截至2017年底，中国个人资产超过1亿元的高净值人群达15万人。
假设给出N个人的个人资产值，请快速找出资产排前M位的大富翁。

输入格式:
输入首先给出两个正整数N（≤10^6）和M（≤10），其中N为总人数，M为需要找出的大富翁数；
接下来一行给出N个人的个人资产值，以百万元为单位，为不超过长整型范围的整数。数字间以空格分隔。

输出格式:
在一行内按非递增顺序输出资产排前M位的大富翁的个人资产值。数字间以空格分隔，但结尾不得有多余空格。

输入样例:
8 3
8 12 7 3 20 9 5 18

输出样例:
20 18 12

代码长度限制
16 KB

时间限制
500 ms

内存限制
64 MB
*/

/* 堆排序，利用一个大小为M的小顶堆，先输入M个数据，构建一个堆，之后将剩下的数据一一读入，
当其比堆顶的数据大的时候，替换，并且调整堆，否则跳过，这样的过程能够一一将较小的值剔除，
取而代之以更大的值，直到最后就是整个数据集中前M大的数据了，之后再排序输出即可。

注意考虑N<=M的情况

对于本题中的堆，假设一个数组中的索引为i，则其父节点索引应该为int((i-1)/2)（如果
存在的话），其左右子节点分别为i*2+1,i*2+2 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N = 0,        // 多少个数据
    M = 0;        // 前多少个最大的
vector<int> heap; // 小顶堆

/**
 * @brief 从n索引代表的节点处向下调整堆
 * @param n n索引
 */
void adjust(int n) {
    int tmp = heap[n]; // 缓存待调整节点的值

    int k = n * 2 + 1;
    while (k < heap.size()) {                   // 当其左节点存在时（当左节点不存在则左右子节点都不存在，因为堆是完全树）
        if (k + 1 < M && heap[k + 1] < heap[k]) // 找到两个子节点中值最小的那个
            k++;

        /* 这里要注意是和之前要调整节点的值进行比较，因为如果换了的话
        则tmp本应该放在换了之后的那个子节点的位置的，如果要继续往下
        换的话则要和tmp比较，如果没有换的话则直接跳出去，无非就是将
        原来的值赋给原来的地方罢了 */
        if (heap[k] >= tmp) // 如果最小的子节点都比父节点大，则不能够交换，跳出
            break;

        heap[n] = heap[k]; // 向下调整

        // 往下走
        n = k;
        k = n * 2 + 1;
    }

    heap[n] = tmp;
}

/**
 * @brief 调整整个数组使其成为一个小顶堆
 */
void adjust_heap() {
    // 从每个非叶子节点向下调整一遍
    for (int i = (M - 1 - 1) / 2; i >= 0; i--) {
        adjust(i);
    }
}

/**
 * @brief 处理初始化输入
 */
void input() {
    // io加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    // 这里要注意分两种情况
    if (N >= M) {
        heap.resize(M);

        for (int i = 0; i < M; i++)
            cin >> heap[i];
        adjust_heap();

        for (int i = 0; i < N - M; i++) {
            int a = 0;
            cin >> a;
            if (a > heap[0]) {
                heap[0] = a;
                adjust(0);
            }
        }
    } else { // N<M则直接排序输出
        heap.resize(N);
        for (int i = 0; i < N; i++)
            cin >> heap[i];
    }
}

/**
 * @brief 排序并从数组后面输出
 */
void print() {
    sort(heap.begin(), heap.end());
    cout << heap.back();
    for (int i = heap.size() - 2; i >= 0; i--)
        cout << ' ' << heap[i];
}

int main() {
    input();
    print();
    return 0;
}