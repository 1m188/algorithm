/*
 * @lc app=leetcode.cn id=LCR 135 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 135] 报数
 *
 * https://leetcode.cn/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/description/
 *
 * algorithms
 * Easy (77.61%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    276.9K
 * Total Submissions: 356.8K
 * Testcase Example:  '2'
 *
 * 实现一个十进制数字报数程序，请按照数字从小到大的顺序返回一个整数数列，该数列从数字 1 开始，到最大的正整数 cnt 位数字结束。
 *
 *
 *
 * 示例 1:
 *
 * 输入：cnt = 2
 *
 * 输出：[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99]
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
    vector<int> countNumbers(int cnt) {

        int max = pow(10, cnt) - 1;
        vector<int> res(max);
        for (int i = 1; i <= max; i++)
            res[i - 1] = i;
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

 */
