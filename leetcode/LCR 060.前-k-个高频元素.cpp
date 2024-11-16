/*
 * @lc app=leetcode.cn id=LCR 060 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 060] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/g5c51o/description/
 *
 * algorithms
 * Medium (67.83%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    34.3K
 * Total Submissions: 50.5K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个整数数组 nums 和一个整数 k ，请返回其中出现频率前 k 高的元素。可以按 任意顺序 返回答案。
 *
 *
 *
 * 示例 1:
 *
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 *
 * 示例 2:
 *
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 *
 *
 *
 *
 * 进阶：所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 *
 *
 *
 * 注意：本题与主站 347 题相同：https://leetcode-cn.com/problems/top-k-frequent-elements/
 *
 */
#include <unordered_map>
#include <vector>

using namespace std;

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> umap;
        for (const int &n : nums)
            umap[n]++;

        auto adjust = [&](vector<pair<int, int>> &heap, int index) {
            int n = heap.size();
            while (true) {
                int idx = index;
                int left = idx * 2 + 1;
                int right = idx * 2 + 2;
                if (left < n && heap[left].second < heap[idx].second) idx = left;
                if (right < n && heap[right].second < heap[idx].second) idx = right;
                if (idx == index) break;
                swap(heap[idx], heap[index]);
                index = idx;
            }
        };
        auto build_heap = [&](vector<pair<int, int>> &heap) {
            for (int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
                adjust(heap, i);
        };

        vector<pair<int, int>> heap(k), vec;
        for (auto it = umap.begin(); it != umap.end(); it++) {
            vec.push_back(*it);
        }
        for (int i = 0; i < k; i++) {
            heap[i] = vec[i];
        }
        build_heap(heap);
        for (int i = k; i < vec.size(); i++) {
            if (vec[i].second > heap[0].second) {
                heap[0] = vec[i];
                adjust(heap, 0);
            }
        }

        vector<int> res(k);
        for (int i = 0; i < k; i++)
            res[i] = heap[i].first;
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
