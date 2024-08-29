/*
 * @lc app=leetcode.cn id=LCR 075 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 075] 数组的相对排序
 *
 * https://leetcode.cn/problems/0H97ZC/description/
 *
 * algorithms
 * Easy (69.37%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    32.7K
 * Total Submissions: 47.1K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * 给定两个数组，arr1 和 arr2，
 *
 *
 * arr2 中的元素各不相同
 * arr2 中的每个元素都出现在 arr1 中
 *
 *
 * 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1
 * 的末尾。
 *
 *
 *
 * 示例：
 *
 * 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * 输出：[2,2,2,1,4,3,3,9,6,7,19]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * arr2 中的元素 arr2[i] 各不相同
 * arr2 中的每个元素 arr2[i] 都出现在 arr1 中
 *
 *
 *
 *
 * 注意：本题与主站 1122 题相同：https://leetcode-cn.com/problems/relative-sort-array/ 
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
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        vector<int> cnt(arr2.size(), 0);
        vector<int> vec;
        for (const int &e : arr1) {
            int idx = -1;
            for (int i = 0; i < arr2.size(); i++) {
                if (arr2[i] == e) {
                    idx = i;
                    break;
                }
            }
            if (idx == -1)
                vec.push_back(e);
            else {
                cnt[idx]++;
            }
        }

        sort(vec.begin(), vec.end());

        vector<int> res;
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < cnt[i]; j++)
                res.push_back(arr2[i]);
        }
        for (const int &e : vec)
            res.push_back(e);
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]\n
// @lcpr case=end

 */
