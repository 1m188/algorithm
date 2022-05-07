/*
 * @lc app=leetcode.cn id=56 lang=javascript
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (40.66%)
 * Likes:    542
 * Dislikes: 0
 * Total Accepted:    127.2K
 * Total Submissions: 297.6K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

// @lc code=start

/**
 * @param {number[][]} vec
 * @param {number} left
 * @param {number} right
 */
function sort(vec, left = 0, right = vec.length - 1) {
    if (left >= right) return;

    let low = left, high = right;
    let tmp = vec[low];
    while (low < high) {
        while (low < high && vec[high][0] >= tmp[0]) high--;
        if (low < high) vec[low++] = vec[high];
        while (low < high && vec[low][0] <= tmp[0]) low++;
        if (low < high) vec[high--] = vec[low];
    }
    vec[low] = tmp;
    sort(vec, left, low - 1);
    sort(vec, low + 1, right);
}

/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
    if (intervals.length === 0) return intervals;

    sort(intervals);
    let res = [intervals.shift()];
    for (let e of intervals) {
        let lst = res[res.length - 1];
        if (e[0] <= lst[1]) lst[1] = Math.max(e[1], lst[1]);
        else res.push(e);
    }
    return res;
};
// @lc code=end

