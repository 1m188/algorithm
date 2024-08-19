/*
 * @lc app=leetcode.cn id=LCR 042 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 042] 最近的请求次数
 *
 * https://leetcode.cn/problems/H8086Q/description/
 *
 * algorithms
 * Easy (81.70%)
 * Likes:    46
 * Dislikes: 0
 * Total Accepted:    32.4K
 * Total Submissions: 39.7K
 * Testcase Example:  '["RecentCounter","ping","ping","ping","ping"]\n[[],[1],[100],[3001],[3002]]'
 *
 * 写一个 RecentCounter 类来计算特定时间范围内最近的请求。
 *
 * 请实现 RecentCounter 类：
 *
 *
 * RecentCounter() 初始化计数器，请求数为 0 。
 * int ping(int t) 在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的某个时间，并返回过去 3000
 * 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 [t-3000, t] 内发生的请求数。
 *
 *
 * 保证 每次对 ping 的调用都使用比之前更大的 t 值。
 *
 *
 *
 * 示例：
 *
 * 输入：
 * inputs = ["RecentCounter", "ping", "ping", "ping", "ping"]
 * inputs = [[], [1], [100], [3001], [3002]]
 * 输出：
 * [null, 1, 2, 3, 3]
 *
 * 解释：
 * RecentCounter recentCounter = new RecentCounter();
 * recentCounter.ping(1);     // requests = [1]，范围是 [-2999,1]，返回 1
 * recentCounter.ping(100);   // requests = [1, 100]，范围是 [-2900,100]，返回 2
 * recentCounter.ping(3001);  // requests = [1, 100, 3001]，范围是 [1,3001]，返回 3
 * recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002]，范围是
 * [2,3002]，返回 3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= t <= 10^9
 * 保证每次对 ping 调用所使用的 t 值都 严格递增
 * 至多调用 ping 方法 10^4 次
 *
 *
 *
 *
 * 注意：本题与主站 933 题相同： https://leetcode-cn.com/problems/number-of-recent-calls/
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
class RecentCounter {
private:
    vector<int> vec;

public:
    RecentCounter() {
    }

    int ping(int t) {
        while (!vec.empty() && vec.back() < t - 3000)
            vec.pop_back();
        vec.insert(vec.begin(), t);
        return vec.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

/*
// @lcpr case=start
// ["RecentCounter", "ping", "ping", "ping"\n[[], [1], [100], [3001], [3002]]\n
// @lcpr case=end

 */
