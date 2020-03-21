/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] 将每个元素替换为右侧最大元素
 *
 * https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side/description/
 *
 * algorithms
 * Easy (74.60%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    5.9K
 * Total Submissions: 7.9K
 * Testcase Example:  '[17,18,5,4,6,1]'
 *
 * 给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。
 * 
 * 完成所有替换操作后，请你返回这个数组。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：arr = [17,18,5,4,6,1]
 * 输出：[18,6,6,6,1,-1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i] <= 10^5
 * 
 * 
 */

#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        // AC 暴力
        // for (int i = 0; i < arr.size() - 1; i++)
        // {
        //     arr[i] = *max_element(arr.begin() + i + 1, arr.end());
        // }
        // arr.back() = -1;
        // return arr;

        // AC 逆序遍历，用额外空间保存结果，空间换时间
        vector<int> res(arr.size(), 0);
        res.back() = -1;
        int maxNum = arr.back();
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            res[i] = maxNum;
            maxNum = max(maxNum, arr[i]);
        }
        return res;
    }
};
// @lc code=end
