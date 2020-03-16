/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 *
 * https://leetcode-cn.com/problems/last-stone-weight/description/
 *
 * algorithms
 * Easy (59.41%)
 * Likes:    39
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 19K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * 有一堆石头，每块石头的重量都是正整数。
 * 
 * 每一回合，从中选出两块最重的石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
 * 
 * 
 * 如果 x == y，那么两块石头都会被完全粉碎；
 * 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
 * 
 * 
 * 最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 1000
 * 
 * 
 */

#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
private:
    void binInsert(vector<int> &vec, int val)
    {
        if (vec.empty())
        {
            vec.push_back(val);
        }
        else
        {
            int start = 0, end = vec.size();
            while (end > start)
            {
                int mid = (start + end) / 2;
                if (vec[mid] < val)
                {
                    start = mid + 1;
                }
                else if (vec[mid] > val)
                {
                    end = mid;
                }
                else
                {
                    break;
                }
            }
            int mid = (start + end) / 2;
            vec.insert(vec.begin() + mid, val);
        }
    }

public:
    int lastStoneWeight(vector<int> &stones)
    {
        sort(stones.begin(), stones.end());
        while (stones.size() > 1)
        {
            int x = stones.back();
            stones.pop_back();
            int y = stones.back();
            stones.pop_back();
            if (x != y)
            {
                int res = max(x, y) - min(x, y);
                binInsert(stones, res);
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
};
// @lc code=end
