/*
 * @lc app=leetcode.cn id=LCR 059 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 059] 数据流中的第 K 大元素
 *
 * https://leetcode.cn/problems/jBjn9C/description/
 *
 * algorithms
 * Easy (62.41%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    28.8K
 * Total Submissions: 46.1K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n' +
  '[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * 设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
 *
 * 请实现 KthLargest 类：
 *
 *
 * KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
 * int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
 *
 *
 *
 *
 * 示例：
 *
 * 输入：
 * ["KthLargest", "add", "add", "add", "add", "add"]
 * [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
 * 输出：
 * [null, 4, 5, 5, 8, 8]
 *
 * 解释：
 * KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
 * kthLargest.add(3);   // return 4
 * kthLargest.add(5);   // return 5
 * kthLargest.add(10);  // return 5
 * kthLargest.add(9);   // return 8
 * kthLargest.add(4);   // return 8
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= 10^4
 * 0 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * -10^4 <= val <= 10^4
 * 最多调用 add 方法 10^4 次
 * 题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素
 *
 *
 *
 *
 * 注意：本题与主站 703 题相同：
 * https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/
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
class KthLargest {
private:
    vector<int> heap;
    void adjust(vector<int> &heap, int index) {
        int n = heap.size();
        while (true) {
            int idx = index * 2 + 1;
            if (idx >= n) break;
            if (idx + 1 < n && heap[idx + 1] < heap[idx]) idx++;
            if (heap[idx] >= heap[index]) break;
            swap(heap[idx], heap[index]);
            index = idx;
        }
    }
    void build_heap(vector<int> &heap) {
        for (int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
            adjust(heap, i);
    }
    int k = 0;

public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        int i = 0;
        for (; i < nums.size(); i++) {
            heap.push_back(nums[i]);
            if (heap.size() >= k) {
                build_heap(heap);
                i++;
                break;
            }
        }
        for (; i < nums.size(); i++) {
            if (nums[i] > heap[0]) {
                heap[0] = nums[i];
                adjust(heap, 0);
            }
        }
    }

    int add(int val) {
        if (heap.empty()) {
            heap.push_back(val);
            return val;
        }
        if (heap.size() < k) {
            heap.push_back(val);
            build_heap(heap);
            return heap[0];
        }
        if (val > heap[0]) {
            heap[0] = val;
            adjust(heap, 0);
        }
        return heap[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

/*
// @lcpr case=start
// ["KthLargest", "add", "add", "add", "add", "add"][[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]\n
// @lcpr case=end

 */
