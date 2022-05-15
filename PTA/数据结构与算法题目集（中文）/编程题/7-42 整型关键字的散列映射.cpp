/**
 * @file 7-42 整型关键字的散列映射.cpp
 * @date 2022-05-15
 */

/*
给定一系列整型关键字和素数P，用除留余数法定义的散列函数H(Key)=Key将关键字映射到长度为P的散列表中。
用线性探测法解决冲突。

输入格式:
输入第一行首先给出两个正整数N（≤1000）和P（≥N的最小素数），分别为待插入的关键字总数、以及散列表的长度。
第二行给出N个整型关键字。数字间以空格分隔。

输出格式:
在一行内输出每个整型关键字在散列表中的位置。数字间以空格分隔，但行末尾不得有多余空格。

输入样例:
4 5
24 15 61 88

输出样例:
4 0 1 3

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 散列表，除留余数法做映射+线性探测法解决冲突，需要注意的是：

1. 用线性探测法解决冲突的时候，探测到了表的末尾应该要回来探测头部，直到再次
探测到本元素最开始映射到的那个索引为止。

2. 重复元素只需要给出最开始映射到的那个索引即可 */

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int N = 0,                     // 元素数目
    P = 0;                     // 散列表长
vector<int> nums;              // 总的元素
vector<pair<bool, int>> hasht; // 散列表，用pair是为了标记某个位置上是否有元素，因为题目中没给出整形的范围

/**
 * @brief 输入
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> P;
    hasht.resize(P);
    nums.resize(N);

    for (int i = 0; i < N; i++)
        cin >> nums[i];
}

/**
 * @brief 给出从key到索引的映射，需要注意的是，这里并没有做
          插入不进去的情况，按照题目给出来的要求，最终所有
          的元素要么会冲突（能够解决），要么重复（给出第一次
          元素插入的地方）
 * @param key 待插入的key
 * @return int 应该插入在散列表中的索引位置
 */
int hkey(int key) {
    int idx = key % P;                                   // 给出最开始的位置
    while (hasht[idx].first && hasht[idx].second != key) // 如果被占了且不是自己（重复元素）
        idx = (idx + 1) % P;                             // 这里mod很重要，表示到了散列表尾部能够从头继续探测
    return idx;
}

/**
 * @brief 计算并输出最终结果
 */
void calc() {
    for (int &n : nums) {

        int idx = hkey(n);

        hasht[idx].first = true;
        hasht[idx].second = n;
        n = idx; // 将每个元素的索引就地保存在数组中，后面直接输出
    }

    cout << nums[0];
    for (int i = 1; i < N; i++)
        cout << ' ' << nums[i];
}

int main() {
    input();
    calc();
    return 0;
}