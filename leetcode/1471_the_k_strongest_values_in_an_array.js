/*
 * @lc app=leetcode.cn id=1471 lang=javascript
 * @lcpr version=30204
 *
 * [1471] 数组中的 k 个最强值
 *
 * https://leetcode.cn/problems/the-k-strongest-values-in-an-array/description/
 *
 * algorithms
 * Medium (60.72%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    19K
 * Total Submissions: 31.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个整数数组 arr 和一个整数 k 。
 * 
 * 设 m 为数组的中位数，只要满足下述两个前提之一，就可以判定 arr[i] 的值比 arr[j] 的值更强：
 * 
 * 
 * |arr[i] - m| > |arr[j] - m|
 * |arr[i] - m| == |arr[j] - m|，且 arr[i] > arr[j]
 * 
 * 
 * 请返回由数组中最强的 k 个值组成的列表。答案可以以 任意顺序 返回。
 * 
 * 中位数 是一个有序整数列表中处于中间位置的值。形式上，如果列表的长度为 n ，那么中位数就是该有序列表（下标从 0 开始）中位于 ((n - 1) /
 * 2) 的元素。
 * 
 * 
 * 例如 arr = [6, -3, 7, 2, 11]，n = 5：数组排序后得到 arr = [-3, 2, 6, 7, 11] ，数组的中间位置为 m
 * = ((5 - 1) / 2) = 2 ，中位数 arr[m] 的值为 6 。
 * 例如 arr = [-7, 22, 17, 3]，n = 4：数组排序后得到 arr = [-7, 3, 17, 22] ，数组的中间位置为 m =
 * ((4 - 1) / 2) = 1 ，中位数 arr[m] 的值为 3 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [1,2,3,4,5], k = 2
 * 输出：[5,1]
 * 解释：中位数为 3，按从强到弱顺序排序后，数组变为 [5,1,4,2,3]。最强的两个元素是 [5, 1]。[1, 5] 也是正确答案。
 * 注意，尽管 |5 - 3| == |1 - 3| ，但是 5 比 1 更强，因为 5 > 1 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,1,3,5,5], k = 2
 * 输出：[5,5]
 * 解释：中位数为 3, 按从强到弱顺序排序后，数组变为 [5,5,1,1,3]。最强的两个元素是 [5, 5]。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [6,7,11,7,6,8], k = 5
 * 输出：[11,8,6,6,7]
 * 解释：中位数为 7, 按从强到弱顺序排序后，数组变为 [11,8,6,6,7,7]。
 * [11,8,6,6,7] 的任何排列都是正确答案。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^5
 * -10^5 <= arr[i] <= 10^5
 * 1 <= k <= arr.length
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getStrongest = function (arr, k) {
    arr.sort((a, b) => a - b);
    const m = arr[Math.floor((arr.length - 1) / 2)];

    /**
     * 判断是否更强壮
     * @param {number} a 第一个数
     * @param {number} b 第二个数
     * @return {boolean} a是否比b更强壮
     */
    function isStronger(a, b) {
        return (Math.abs(a - m) > Math.abs(b - m)) || (Math.abs(a - m) == Math.abs(b - m) && a > b);
    }

    /**
     * 调整小根堆
     * @param {number[]} heap 待调整的堆
     * @param {number} start 开始调整的起始索引
     * @param {number} end 结束调整的索引
     * @return {void} 无返回值
     */
    function adjust(heap, start, end) {
        while (true) {
            let index = start;
            if (start * 2 + 1 <= end && isStronger(heap[index], heap[start * 2 + 1])) {
                index = start * 2 + 1;
            }
            if (start * 2 + 2 <= end && isStronger(heap[index], heap[start * 2 + 2])) {
                index = start * 2 + 2;
            }
            if (index === start) break;
            [heap[index], heap[start]] = [heap[start], heap[index]];
            start = index;
        }
    }

    /**
     * 构建小根堆
     * @param {number[]} heap 待构建的堆
     * @return {void} 无返回值
     */
    function buildHeap(heap) {
        for (let i = Math.floor((heap.length - 1 - 1) / 2); i >= 0; i--) {
            adjust(heap, i, heap.length - 1);
        }
    }

    /**
     * @type {number[]}
     */
    let heap = new Array();

    for (let i = 0; i < k; i++) heap.push(arr[i]);
    buildHeap(heap);
    for (let i = k; i < arr.length; i++) {
        if (isStronger(arr[i], heap[0])) {
            heap[0] = arr[i];
            adjust(heap, 0, k - 1);
        }
    }

    return heap;
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,1,3,5,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [6,7,11,7,6,8]\n5\n
// @lcpr case=end

 */

