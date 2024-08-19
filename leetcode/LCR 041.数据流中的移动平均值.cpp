/*
 * @lc app=leetcode.cn id=LCR 041 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 041] 数据流中的移动平均值
 *
 * https://leetcode.cn/problems/qIsx9U/description/
 *
 * algorithms
 * Easy (77.34%)
 * Likes:    109
 * Dislikes: 0
 * Total Accepted:    64.8K
 * Total Submissions: 83.8K
 * Testcase Example:  '["MovingAverage","next","next","next","next"]\n[[3],[1],[10],[3],[5]]'
 *
 * 给定一个窗口大小和一个整数数据流，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。
 *
 * 实现 MovingAverage 类：
 *
 *
 * MovingAverage(int size) 用窗口大小 size 初始化对象。
 * double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size
 * 个值的移动平均值，即滑动窗口里所有数字的平均值。
 *
 *
 *
 *
 * 示例：
 *
 * 输入：
 * inputs = ["MovingAverage", "next", "next", "next", "next"]
 * inputs = [[3], [1], [10], [3], [5]]
 * 输出：
 * [null, 1.0, 5.5, 4.66667, 6.0]
 *
 * 解释：
 * MovingAverage movingAverage = new MovingAverage(3);
 * movingAverage.next(1); // 返回 1.0 = 1 / 1
 * movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
 * movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
 * movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= size <= 1000
 * -10^5 <= val <= 10^5
 * 最多调用 next 方法 10^4 次
 *
 *
 *
 *
 * 注意：本题与主站 346 题相同：
 * https://leetcode-cn.com/problems/moving-average-from-data-stream/
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
class MovingAverage {
private:
    vector<int> vec;
    int sum = 0;
    int size = 0;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }

    double next(int val) {
        if (vec.size() < size) {
            vec.push_back(val);
            sum += val;
        } else {
            sum -= vec[0];
            vec.erase(vec.begin());
            vec.push_back(val);
            sum += val;
        }
        return sum * 1.0 / vec.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
// @lc code=end

/*
// @lcpr case=start
// ["MovingAverage", "next", "next", "next"\n[[3], [1], [10], [3], [5]]\n
// @lcpr case=end

 */
