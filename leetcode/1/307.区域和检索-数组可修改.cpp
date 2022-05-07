/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 *
 * https://leetcode-cn.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (56.36%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 22.9K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * 
 * update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。
 * 
 * 示例:
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * 说明:
 * 
 * 
 * 数组仅可以在 update 函数下进行修改。
 * 你可以假设 update 函数与 sumRange 函数的调用次数是均匀分布的。
 * 
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class NumArray
{
private:
    vector<int> &vec;

public:
    NumArray(vector<int> &nums) : vec(nums)
    {
    }

    void update(int i, int val)
    {
        vec[i] = val;
    }

    int sumRange(int i, int j)
    {
        int sum = 0;
        for (int k = i; k <= j; k++)
            sum += vec[k];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end
