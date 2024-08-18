/*
 * @lc app=leetcode.cn id=491 lang=typescript
 *
 * [491] 递增子序列
 *
 * https://leetcode.cn/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (52.87%)
 * Likes:    484
 * Dislikes: 0
 * Total Accepted:    90.1K
 * Total Submissions: 170.4K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
 * 
 * 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,6,7,7]
 * 输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,4,3,2,1]
 * 输出：[[4,4]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 15
 * -100 <= nums[i] <= 100
 * 
 * 
 */

/**
 * 哈希去重+dfs
 */

// @lc code=start
function findSubsequences(nums: number[]): number[][] {

    let res: number[][] = [];

    let vis: boolean[] = [];
    for (let i = 0; i < nums.length; i++) vis.push(false);

    function dfs(tmp: number[] = [], idx: number = 0): void {
        if (tmp.length >= 2)
            res.push([...tmp]);

        let set: Set<number> = new Set(); // 去重的关键手段
        for (let i = idx; i < nums.length; i++) {
            if (set.has(nums[i])) continue; // 如果这个数前面的序列选过了就不能再选了，为了避免有可能重复的数
            if (!vis[i] && (tmp.length == 0 || nums[i] >= tmp[tmp.length - 1])) {
                set.add(nums[i]);
                vis[i] = true;
                tmp.push(nums[i]);
                dfs(tmp, i + 1);
                tmp.pop();
                vis[i] = false;
            }
        }
    }

    dfs();

    return res;

};
// @lc code=end

