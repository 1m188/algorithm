/*
 * @lc app=leetcode.cn id=90 lang=typescript
 *
 * [90] 子集 II
 *
 * https://leetcode.cn/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (63.60%)
 * Likes:    883
 * Dislikes: 0
 * Total Accepted:    223.7K
 * Total Submissions: 351.8K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * 
 * 
 * 
 * 
 */

/**
 * 类似于全排列那种题目，注意去重
 */

// @lc code=start
function subsetsWithDup(nums: number[]): number[][] {

    nums.sort(); // 开始注意排序，用来方便筛选重复元素

    let res: number[][] = [[]];

    let vis: boolean[] = [];
    for (let i = 0; i < nums.length; i++) vis.push(false);


    /**
     * 回溯求所有不同的集合
     * @param tmp 当前集合
     * @param size 当前集合大小
     * @param idx 从nums的什么位置开始选择元素
     * @returns 
     */
    function back(tmp: number[], size: number, idx: number): void {
        if (tmp.length == size) {
            res.push([...tmp]);
            return;
        }

        // 注意这里从idx开始，因为不是全排列，只是组合，前面选过的
        // 就没有必要再选了
        for (let i = idx; i < nums.length; i++) {
            // 注意！精华！去重
            if (i != 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;

            if (!vis[i]) {
                vis[i] = true;
                tmp.push(nums[i]);
                back(tmp, size, i + 1);
                tmp.pop();
                vis[i] = false;
            }
        }
    }


    // 对每个大小的集合都要遍历
    for (let i = 1; i <= nums.length; i++)
        back([], i, 0);

    return res;

};
// @lc code=end

