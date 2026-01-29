/*
描述
农场里有一群牛，每头牛都有一个独特的编号。编号有正有负。请找出牛群中编号第 k 小的牛。你需要找的是数组排序后的第 k 个最小的元素，而不是第 k 个不同的元素。你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
示例1
输入：
[3, 2, 1, 5, 6, 4],2
复制
返回值：
2
复制
示例2
输入：
[3, 2, 3, 1, 2, 4, 5, 5, 6],4
复制
返回值：
3
复制
备注：
数组长度范围是 [1, 100000]，每个元素范围是 [-10000, 10000]
k的范围是 [1, nums.length]
*/

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @param k int整型
     * @return int整型
     */
    int findKthSmallest(vector<int> &nums, int k) {
        // write code here

        // 堆排序

        auto adjust = [](vector<int> &heap, int idx) {
            int length = heap.size();
            while (true) {
                int index = idx * 2 + 1;
                if (index >= length) break;
                if (index + 1 < length && heap[index + 1] > heap[index]) index++;
                if (heap[index] <= heap[idx]) break;
                swap(heap[index], heap[idx]);
                idx = index;
            }
        };
        auto build_heap = [&](vector<int> &heap) {
            for (int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
                adjust(heap, i);
        };

        vector<int> heap;
        for (int i = 0; i < nums.size(); i++) {
            heap.push_back(nums[i]);
            if (heap.size() >= k) {
                build_heap(heap);
                break;
            }
        }
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] < heap[0]) {
                heap[0] = nums[i];
                adjust(heap, 0);
            }
        }
        return heap[0];
    }
};