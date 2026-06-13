/*

反幻方

我国古籍很早就记载着

2 9 4
7 5 3
6 1 8

这是一个三阶幻方。每行每列以及对角线上的数字相加都相等。

下面考虑一个相反的问题。
可不可以用 1~9 的数字填入九宫格。
使得：每行每列每个对角线上的数字和都互不相等呢？


这应该能做到。
比如：
9 1 2
8 4 3
7 5 6

你的任务是搜索所有的三阶反幻方。并统计出一共有多少种。
旋转或镜像算同一种。

比如：
9 1 2
8 4 3
7 5 6

7 8 9
5 4 1
6 3 2

2 1 9
3 4 8
6 5 7

等都算作同一种情况。

请提交三阶反幻方一共多少种。这是一个整数，不要填写任何多余内容。

*/

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

// 正方形的8种对称变换（D4群），每个变换给出9个新位置索引
// 3x3网格索引布局：0 1 2 / 3 4 5 / 6 7 8
const int D4[8][9] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8}, // 0: 恒等变换
    {6, 3, 0, 7, 4, 1, 8, 5, 2}, // 1: 顺时针旋转90°
    {8, 7, 6, 5, 4, 3, 2, 1, 0}, // 2: 旋转180°
    {2, 5, 8, 1, 4, 7, 0, 3, 6}, // 3: 顺时针旋转270°（逆时针90°）
    {6, 7, 8, 3, 4, 5, 0, 1, 2}, // 4: 上下翻转
    {2, 1, 0, 5, 4, 3, 8, 7, 6}, // 5: 左右翻转
    {0, 3, 6, 1, 4, 7, 2, 5, 8}, // 6: 主对角线翻转（转置）
    {8, 5, 2, 7, 4, 1, 6, 3, 0}  // 7: 副对角线翻转
};

int main() {
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    set<string> ans; // 存放规范形式（对称等价类的最小表示）

    do {
        // 计算8个和：3行 + 3列 + 2条对角线
        int s[8];
        for (int r = 0; r < 3; ++r)
            s[r] = a[r * 3] + a[r * 3 + 1] + a[r * 3 + 2]; // 三行
        for (int c = 0; c < 3; ++c)
            s[3 + c] = a[c] + a[3 + c] + a[6 + c]; // 三列
        s[6] = a[0] + a[4] + a[8];                 // 主对角线
        s[7] = a[2] + a[4] + a[6];                 // 副对角线

        // 检查是否8个和两两不同
        sort(s, s + 8);
        bool ok = true;
        for (int i = 1; i < 8; ++i)
            if (s[i] == s[i - 1]) {
                ok = false;
                break;
            }

        if (ok) {
            // 求该排列在所有对称变换下的最小字典序作为规范形式
            string canonical;
            canonical.reserve(9);
            for (int i = 0; i < 9; ++i)
                canonical.push_back('0' + a[i]);

            for (int t = 1; t < 8; ++t) {
                string cur;
                cur.reserve(9);
                for (int i = 0; i < 9; ++i)
                    cur.push_back('0' + a[D4[t][i]]);
                if (cur < canonical)
                    canonical = cur;
            }
            ans.insert(canonical);
        }
    } while (next_permutation(a, a + 9));

    cout << ans.size() << endl;
    return 0;
}
