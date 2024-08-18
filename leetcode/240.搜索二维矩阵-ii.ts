/*
 * @lc app=leetcode.cn id=240 lang=typescript
 *
 * [240] 搜索二维矩阵 II
 *
 * https://leetcode.cn/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (51.72%)
 * Likes:    1081
 * Dislikes: 0
 * Total Accepted:    296.1K
 * Total Submissions: 572.3K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
 * 
 * 
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 5
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 20
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * 每行的所有元素从左到右升序排列
 * 每列的所有元素从上到下升序排列
 * -10^9 <= target <= 10^9
 * 
 * 
 */

/**
 * 逐行二分查找
 */

// @lc code=start
function searchMatrix(matrix: number[][], target: number): boolean {

    function bin_search(vec: number[], target: number): boolean {
        let start = 0, end = vec.length - 1, mid = 0;
        while (start <= end) {
            mid = Math.floor((start + end) / 2);
            if (vec[mid] == target) return true;
            else if (vec[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }

    for (let i = 0; i < matrix.length; i++)
        if (bin_search(matrix[i], target)) return true;
    return false;

};
// @lc code=end

