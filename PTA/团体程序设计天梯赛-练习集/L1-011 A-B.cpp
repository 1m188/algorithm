/**
 * @file L1-011 A-B.cpp
 * @date 2022-05-18
 */

/*
本题要求你计算A−B。不过麻烦的是，A和B都是字符串 —— 即从字符串A中把字符串B所包含的字符全删掉，
剩下的字符组成的就是字符串A−B。

输入格式：
输入在2行中先后给出字符串A和B。两字符串的长度都不超过10^4，
并且保证每个字符串都是由可见的ASCII码和空白字符组成，最后以换行符结束。

输出格式：
在一行中打印出A−B的结果字符串。

输入样例：
I love GPLT!  It's a fun game!
aeiou

输出样例：
I lv GPLT!  It's  fn gm!

代码长度限制
16 KB

时间限制
150 ms

内存限制
64 MB
*/

/* ascii码总共就128个，可以通过数组做集合快速查找 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string A, // 待更新字符串
    B;    // 待删除字符所在的字符串

vector<bool> vec(128); // 索引是ascii码，内容是这个字符要不要删掉

/**
 * @brief 输入并初始化集合
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getline(cin, A);
    getline(cin, B);

    for (const char &c : B)
        vec[c] = true;
}

/**
 * @brief 计算删除并输出
 */
void calc() {
    auto it = A.begin();

    while (it < A.end()) {
        if (vec[*it])
            it = A.erase(it);
        else
            it++;
    }

    cout << A;
}

int main() {
    input();
    calc();
    return 0;
}