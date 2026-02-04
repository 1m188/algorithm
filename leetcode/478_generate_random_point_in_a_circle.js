/*
 * @lc app=leetcode.cn id=478 lang=javascript
 * @lcpr version=30204
 *
 * [478] 在圆内随机生成点
 *
 * https://leetcode.cn/problems/generate-random-point-in-a-circle/description/
 *
 * algorithms
 * Medium (48.65%)
 * Likes:    178
 * Dislikes: 0
 * Total Accepted:    33.8K
 * Total Submissions: 69.4K
 * Testcase Example:  '["Solution","randPoint","randPoint","randPoint"]\n[[1.0,0.0,0.0],[],[],[]]'
 *
 * 给定圆的半径和圆心的位置，实现函数 randPoint ，在圆中产生均匀随机点。
 * 
 * 实现 Solution 类:
 * 
 * 
 * Solution(double radius, double x_center, double y_center) 用圆的半径 radius
 * 和圆心的位置 (x_center, y_center) 初始化对象
 * randPoint() 返回圆内的一个随机点。圆周上的一点被认为在圆内。答案作为数组返回 [x, y] 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: 
 * ["Solution","randPoint","randPoint","randPoint"]
 * [[1.0, 0.0, 0.0], [], [], []]
 * 输出: [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
 * 解释:
 * Solution solution = new Solution(1.0, 0.0, 0.0);
 * solution.randPoint ();//返回[-0.02493，-0.38077]
 * solution.randPoint ();//返回[0.82314,0.38945]
 * solution.randPoint ();//返回[0.36572,0.17248]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 < radius <= 10^8
 * -10^7 <= x_center, y_center <= 10^7
 * randPoint 最多被调用 3 * 10^4 次
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * @param {number} radius
 * @param {number} x_center
 * @param {number} y_center
 */
var Solution = function (radius, x_center, y_center) {
    this.radius = radius;
    this.x_center = x_center;
    this.y_center = y_center;
};

/**
 * @return {number[]}
 */
Solution.prototype.randPoint = function () {
    while (true) {
        const x = Math.random() * 2 * this.radius - this.radius + this.x_center;
        const y = Math.random() * 2 * this.radius - this.radius + this.y_center;
        if (Math.pow(x - this.x_center, 2) + Math.pow(y - this.y_center, 2) <= Math.pow(this.radius, 2)) {
            return [x, y];
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(radius, x_center, y_center)
 * var param_1 = obj.randPoint()
 */
// @lc code=end



/*
// @lcpr case=start
// ["Solution","randPoint","randPoint","randPoint"][[1.0, 0.0, 0.0], [], [], []]\n
// @lcpr case=end

 */

