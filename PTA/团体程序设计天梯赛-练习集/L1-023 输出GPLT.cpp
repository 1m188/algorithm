/**
 * @file L1-023 输出GPLT.cpp
 * @date 2022-05-18
 */

/*
给定一个长度不超过10000的、仅由英文字母构成的字符串。
请将字符重新调整顺序，按GPLTGPLT....这样的顺序输出，并忽略其它字符。
当然，四种字符（不区分大小写）的个数不一定是一样多的，若某种字符已经输出完，
则余下的字符仍按GPLT的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
pcTclnGloRgLrtLhgljkLhGFauPewSKgt

输出样例：
GPLTGPLTGLTGLGLL

代码长度限制
16 KB

时间限制
150 ms

内存限制
64 MB
*/

/* 注意映射 */

#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> chnum(4);
unordered_map<char, int> ump1 = {{'G', 0}, {'P', 1}, {'L', 2}, {'T', 3}};
unordered_map<int, char> ump2 = {{0, 'G'}, {1, 'P'}, {2, 'L'}, {3, 'T'}};

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for (const char &c : s) {
        auto it = ump1.find(toupper(c));
        if (it != ump1.end())
            chnum[it->second]++;
    }
}

void print() {
    int sum = chnum[0] + chnum[1] + chnum[2] + chnum[3];

    for (int i = 0; sum; i = (i + 1) % 4) {
        if (chnum[i]) {
            cout << ump2[i];
            chnum[i]--;
            sum--;
        }
    }
}

int main() {
    input();
    print();
    return 0;
}