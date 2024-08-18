/*
 * @lc app=leetcode.cn id=373 lang=typescript
 *
 * [373] 查找和最小的 K 对数字
 *
 * https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (41.32%)
 * Likes:    421
 * Dislikes: 0
 * Total Accepted:    51.2K
 * Total Submissions: 123.9K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * 给定两个以 升序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
 * 
 * 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
 * 
 * 请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * 输出: [1,2],[1,4],[1,6]
 * 解释: 返回序列中的前 3 对数：
 * ⁠    [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * 输出: [1,1],[1,1]
 * 解释: 返回序列中的前 2 对数：
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: nums1 = [1,2], nums2 = [3], k = 3 
 * 输出: [1,3],[2,3]
 * 解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 10^5
 * -10^9 <= nums1[i], nums2[i] <= 10^9
 * nums1 和 nums2 均为升序排列
 * 1 <= k <= 1000
 * 
 * 
 */

/**
 * 堆排序的应用，取前k个数对，组成大根堆，
 * 之后的数对如果有和比根小的，则替代根，
 * 并调整堆，因为是升序，所以有比根还大的
 * 数对，后面也不用继续了，跳过一重循环，
 * 直到最后所有数对都被遍历完，得到的结果
 * 即为答案
 */

// @lc code=start
function kSmallestPairs(nums1: number[], nums2: number[], k: number): number[][] {

    let vec: number[][] = [];

    /**
     * 从某个节点开始向下调整堆
     * @param heap 大根堆
     * @param idx 节点在数组中的索引
     */
    function adjust(heap: number[][], idx: number): void {
        for (let i = idx * 2 + 1; i < heap.length; i = i * 2 + 1) {
            if (i + 1 < heap.length &&
                heap[i + 1][0] + heap[i + 1][1] > heap[i][0] + heap[i][1])
                i = i + 1;
            if (heap[i][0] + heap[i][1] > heap[idx][0] + heap[idx][1])
                [heap[i], heap[idx]] = [heap[idx], heap[i]];
            else
                break;
            idx = i;
        }
    }

    /**
     * 构建一个大根堆
     * @param heap 
     */
    function build_heap(heap: number[][]): void {
        for (let i = Math.floor((heap.length - 1 - 1) / 2); i >= 0; i--)
            adjust(heap, i);
    }

    for (let i = 0; i < nums1.length; i++) {
        for (let j = 0; j < nums2.length; j++) {
            if (vec.length < k) { // 数目不够加入
                vec.push([nums1[i], nums2[j]]);
                if (vec.length == k) build_heap(vec);
            }
            // 数目够了调整
            else if (nums1[i] + nums2[j] < vec[0][0] + vec[0][1]) {
                vec[0] = [nums1[i], nums2[j]];
                adjust(vec, 0);
            }
            else // 还大则跳出该重循环
                break;
        }
    }

    return vec;

};
// @lc code=end

