/*
 * @lc app=leetcode.cn id=48 lang=typescript
 *
 * [48] 旋转图像
 *
 * https://leetcode.cn/problems/rotate-image/description/
 *
 * algorithms
 * Medium (74.29%)
 * Likes:    1369
 * Dislikes: 0
 * Total Accepted:    352.8K
 * Total Submissions: 474.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 * 
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 * 
 * 
 * 
 * 
 */

/**
 * 旋转，从最外层开始，逐步向内层进行，
 * 每次对一个元素进行一周位置的调换，
 * 可以先写两层的调换过程，然后总结规律，
 * 写出一般的调换过程，注意边界条件的控制，
 * 以及调换数据坐标的表示
 */

// @lc code=start
/**
 Do not return anything, modify matrix in-place instead.
 */
function rotate(matrix: number[][]): void {

    let n = matrix.length;
    let start = 0, end = n - 2;

    while (start <= end) {
        for (let i = start; i <= end; i++) {
            let tmp = matrix[start][i];
            matrix[start][i] = matrix[n - i - 1][start];
            matrix[n - i - 1][start] = matrix[n - 1 - start][n - i - 1];
            matrix[n - 1 - start][n - i - 1] = matrix[i][n - 1 - start];
            matrix[i][n - 1 - start] = tmp;
        }

        start++, end--;
    }

};
// @lc code=end

