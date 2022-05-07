/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 *
 * https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/description/
 *
 * algorithms
 * Easy (44.48%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    12.5K
 * Total Submissions: 28.1K
 * Testcase Example:  '["c","f","j"]\n"a"'
 *
 * 给定一个只包含小写字母的有序数组letters 和一个目标字母 target，寻找有序数组里面比目标字母大的最小字母。
 * 
 * 数组里字母的顺序是循环的。举个例子，如果目标字母target = 'z' 并且有序数组为 letters = ['a', 'b']，则答案返回
 * 'a'。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "a"
 * 输出: "c"
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "c"
 * 输出: "f"
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "d"
 * 输出: "f"
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "g"
 * 输出: "j"
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "j"
 * 输出: "c"
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "k"
 * 输出: "c"
 * 
 * 
 * 注:
 * 
 * 
 * letters长度范围在[2, 10000]区间内。
 * letters 仅由小写字母组成，最少包含两个不同的字母。
 * 目标字母target 是一个小写字母。
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
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        letters.erase(unique(letters.begin(), letters.end()), letters.end()); // 注意去重
        // 二分查找
        int start = 0, end = letters.size();
        while (end > start)
        {
            int mid = (start + end) / 2;
            if (letters[mid] > target)
            {
                end = mid;
            }
            else if (letters[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                // 刚好等于的时候需要使索引+1获取最小的更大值
                start = end = mid + 1;
                break;
            }
        }
        int mid = (start + end) / 2;
        // 超出索引部分按照循环判断
        if (mid < 0 || mid >= letters.size())
        {
            mid = 0;
        }
        return letters[mid];
    }
};
// @lc code=end
