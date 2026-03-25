/*
描述
给定一个初始为空的整数集合，每次执行以下两种操作之一：
∙

∙ 插入操作 `1 x`：若
x
x 不在集合中，则插入
x
x；否则输出 `Already Exist` 并忽略操作。
∙

∙ 提取操作 `2 x`：若集合不为空，删除并输出集合中与
x
x 绝对差最小的元素；若存在多个候选，则删除并输出其中较小者；若集合为空，则输出 `Empty`。
输入描述：
第一行包含整数
Q

(
1
≦
Q
≦
1
0
5
)
Q (1≦Q≦10
5
 )，表示操作次数。
接下来
Q
Q 行，每行包含操作类型
o
p
op 和参数
x
x，格式为 op x，其中
o
p
∈
{
1
,
2
}
op∈{1,2}，
0
≦
x
≦
1
0
9
0≦x≦10
9
 。
输出描述：
对于每次输出类操作（插入重复元素或提取操作），在单独一行输出结果。如插入重复元素则输出 `Already Exist`；提取操作输出删除的元素值或 `Empty`。
示例1
输入：
5
1 10
1 20
1 15
2 17
2 17
复制
输出：
15
20
复制
说明：
第一次提取删除集合中与
17
17 距离最小的
15
15；第二次提取删除剩余元素中与
17
17 距离最小的
20
20。
*/

// 这题目居然还不能用Python来做，没有平衡搜索树的结构，只能用C++的set

#include <cmath>
#include <iostream>
#include <set>
using namespace std;

int main() {

    int Q = 0;
    cin >> Q;
    auto se = set<int>();
    while (Q--) {
        int op = 0, x = 0;
        cin >> op >> x;

        if (op == 1) {
            if (se.find(x) == se.end()) {
                se.insert(x);
            } else {
                cout << "Already Exist" << endl;
            }
        } else if (op == 2) {
            if (se.empty()) {
                cout << "Empty" << endl;
            } else {
                auto it = se.lower_bound(x);
                if (it == se.begin()) {
                    cout << *it << endl;
                    se.erase(it);
                } else if (it == se.end()) {
                    it--;
                    cout << *it << endl;
                    se.erase(it);
                } else {
                    auto it2 = it;
                    it2--;
                    // 注意相等的时候取更小的那个值
                    auto target_it = abs(*it2 - x) <= abs(*it - x) ? it2 : it;
                    cout << *target_it << endl;
                    se.erase(target_it);
                }
            }
        }
    }

    return 0;
}
