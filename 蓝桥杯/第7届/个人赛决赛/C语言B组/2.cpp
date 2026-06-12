/*
 * 凑平方数
 *
 * 把0~9这10个数字，分成多个组，每个组恰好是一个平方数，这是能够办到的。
 * 比如：0, 36, 5948721
 *
 * 再比如：
 * 1098524736
 * 1, 25, 6390784
 * 0, 4, 289, 15376
 * 等等...
 *
 * 注意，0可以作为独立的数字，但不能作为多位数字的开始。
 * 分组时，必须用完所有的数字，不能重复，不能遗漏。
 *
 * 如果不计较小组内数据的先后顺序，请问有多少种不同的分组方案？
 *
 * 注意：需要提交的是一个整数，不要填写多余内容。
 *
 * 【求解思路】
 *   生成所有不超过 10 位的"全位不重复"平方数（约 611 个），
 *   每个用 10 位掩码表示使用了哪些数字。DFS 枚举子集，
 *   选择掩码互不重叠且并集为全 1（即用完 0~9）的方案。
 *   用 set 按排序后的选号列表去重，最终得 300 种。
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 将所有合法候选平方数编码为位掩码（第 d 位代表数字 d 是否出现）
vector<int> masks;
vector<string> names;                // 仅用于调试，可不存
const int FULL_MASK = (1 << 10) - 1; // 低 10 位全 1

// 生成所有候选：i^2 中各位数字无重复，且不多于 10 位
void init() {
    for (long long i = 0; i <= 99380; i++) { // sqrt(9876543210) ≈ 99380
        long long sq = i * i;
        string s = to_string(sq);

        // 含前导零的多位数非法
        if (s.length() > 1 && s[0] == '0') continue;

        int mask = 0;
        bool ok = true;
        for (char c : s) {
            int d = c - '0';
            if (mask & (1 << d)) {
                ok = false;
                break;
            }
            mask |= (1 << d);
        }
        if (ok) {
            masks.push_back(mask);
            names.push_back(s);
        }
    }
}

// DFS 搜所有合法分组，用 set 对排序后的索引列表去重
set<vector<int>> solutions;

void dfs(int idx, int curMask, vector<int> &chosen) {
    if (curMask == FULL_MASK) {
        vector<int> sorted = chosen;
        sort(sorted.begin(), sorted.end());
        solutions.insert(sorted);
        return;
    }
    for (int i = idx; i < (int)masks.size(); i++) {
        int m = masks[i];
        if (curMask & m) continue; // 数字重叠，跳过
        chosen.push_back(i);
        dfs(i + 1, curMask | m, chosen);
        chosen.pop_back();
    }
}

int main() {
    init();
    vector<int> chosen;
    dfs(0, 0, chosen);
    cout << solutions.size() << endl;
    return 0;
}
