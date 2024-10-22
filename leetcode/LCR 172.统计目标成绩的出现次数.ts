/*
 * @lc app=leetcode.cn id=LCR 172 lang=typescript
 * @lcpr version=30204
 *
 * [LCR 172] 统计目标成绩的出现次数
 *
 * https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/description/
 *
 * algorithms
 * Easy (52.67%)
 * Likes:    460
 * Dislikes: 0
 * Total Accepted:    414.4K
 * Total Submissions: 786.8K
 * Testcase Example:  '[2,2,3,4,4,4,5,6,6,8]\n4'
 *
 * 某班级考试成绩按非严格递增顺序记录于整数数组 scores，请返回目标成绩 target 的出现次数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: scores = [2, 2, 3, 4, 4, 4, 5, 6, 6, 8], target = 4
 * 输出: 3
 * 
 * 示例 2：
 * 
 * 输入: scores = [1, 2, 3, 5, 7, 9], target = 6
 * 输出: 0
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= scores.length <= 10^5
 * -10^9 <= scores[i] <= 10^9
 * scores 是一个非递减数组
 * -10^9 <= target <= 10^9
 * 
 * 
 * 
 * 
 * 注意：本题与主站 34
 * 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * 
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
function countTarget(scores: number[], target: number): number {

    const bf = (vec: number[], target: number) => {
        let left = 0, right = vec.length - 1
        while (left <= right) {
            let mid = Math.floor((left + right) / 2)
            if (vec[mid] == target) return mid
            else if (vec[mid] > target) right = mid - 1
            else left = mid + 1
        }
        return -1
    }


    let index = bf(scores, target)
    if (index == -1) return 0
    else {
        let cnt = 1
        for (let i = index + 1; i < scores.length; i++) {
            if (scores[i] == target) cnt++
            else break
        }
        for (let i = index - 1; i >= 0; i--) {
            if (scores[i] == target) cnt++
            else break
        }
        return cnt
    }

};
// @lc code=end



/*
// @lcpr case=start
// [2, 2, 3, 4, 4, 4, 5, 6, 6, 8]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3, 5, 7, 9]\n6\n
// @lcpr case=end

 */

