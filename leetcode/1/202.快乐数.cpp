/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (52.49%)
 * Likes:    231
 * Dislikes: 0
 * Total Accepted:    44.7K
 * Total Submissions: 78.3K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数是不是“快乐数”。
 * 
 * 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到
 * 1。如果可以变为 1，那么这个数就是快乐数。
 * 
 * 示例: 
 * 
 * 输入: 19
 * 输出: true
 * 解释: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 */

#include "vector"
#include "algorithm"

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        // 用数组记录用过的数字，因为循环可能从中间的某一个数重新开始，不一定从头开始
        std::vector<int> vec;
        while (std::find(vec.begin(), vec.end(), n) == vec.end()) // 如果能从数组中找到，说明开始循环，不是快乐数
        {
            // 否则加入数组，并且计算每位数平方和，并且判断是否是快乐数，重复过程
            vec.push_back(n);
            int temp = 0;
            while (n)
            {
                int t = n % 10;
                temp += t * t;
                n /= 10;
            }
            n = temp;
            if (n == 1)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
