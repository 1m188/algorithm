/*
 * @lc app=leetcode.cn id=LCR 158 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 158] 库存管理 II
 *
 * https://leetcode.cn/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/description/
 *
 * algorithms
 * Easy (69.86%)
 * Likes:    413
 * Dislikes: 0
 * Total Accepted:    323.5K
 * Total Submissions: 463.1K
 * Testcase Example:  '[6,1,3,1,1,1]'
 *
 * 仓库管理员以数组 stock 形式记录商品库存表。stock[i] 表示商品 id，可能存在重复。请返回库存表中数量大于 stock.length /
 * 2 的商品 id。
 *
 *
 *
 * 示例 1:
 *
 * 输入: stock = [6, 1, 3, 1, 1, 1]
 * 输出: 1
 *
 *
 *
 * 限制：
 *
 *
 * 1 <= stock.length <= 50000
 * 给定数组为非空数组，且存在结果数字
 *
 *
 *
 *
 * 注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int inventoryManagement(vector<int> &stock) {
        unordered_map<int, int> umap;
        for (const int &id : stock)
            umap[id]++;

        int n = stock.size();
        int res = 0;
        for (auto it = umap.cbegin(); it != umap.end(); it++) {
            if (it->second > n / 2) {
                res = it->first;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [6, 1, 3, 1, 1, 1]\n
// @lcpr case=end

 */
