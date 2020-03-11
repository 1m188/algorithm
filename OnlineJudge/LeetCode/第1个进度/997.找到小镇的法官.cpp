/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 *
 * https://leetcode-cn.com/problems/find-the-town-judge/description/
 *
 * algorithms
 * Easy (50.40%)
 * Likes:    48
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 25.1K
 * Testcase Example:  '2\n[[1,2]]'
 *
 * 在一个小镇里，按从 1 到 N 标记了 N 个人。传言称，这些人中有一个是小镇上的秘密法官。
 * 
 * 如果小镇的法官真的存在，那么：
 * 
 * 
 * 小镇的法官不相信任何人。
 * 每个人（除了小镇法官外）都信任小镇的法官。
 * 只有一个人同时满足属性 1 和属性 2 。
 * 
 * 
 * 给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示标记为 a 的人信任标记为 b 的人。
 * 
 * 如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的标记。否则，返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：N = 2, trust = [[1,2]]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 输入：N = 3, trust = [[1,3],[2,3]]
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 输入：N = 3, trust = [[1,3],[2,3],[3,1]]
 * 输出：-1
 * 
 * 
 * 示例 4：
 * 
 * 输入：N = 3, trust = [[1,2],[2,3]]
 * 输出：-1
 * 
 * 
 * 示例 5：
 * 
 * 输入：N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
 * 输出：3
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 1000
 * trust.length <= 10000
 * trust[i] 是完全不同的
 * trust[i][0] != trust[i][1]
 * 1 <= trust[i][0], trust[i][1] <= N
 * 
 * 
 */

#include "vector"
#include "unordered_map"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        unordered_map<int, vector<int>> um;
        for (int i = 1; i <= N; i++)
        {
            um[i] = vector<int>();
        }

        for (const vector<int> &t : trust)
        {
            um[t[0]].push_back(t[1]);
        }

        vector<int> res;
        for (auto it = um.begin(); it != um.end(); it++)
        {
            if (it->second.empty())
            {
                res.push_back(it->first);
            }
        }

        for (const int &n : res)
        {
            for (const pair<int, vector<int>> &p : um)
            {
                if (p.first != n)
                {
                    if (find(p.second.begin(), p.second.end(), n) == p.second.end())
                    {
                        goto next;
                    }
                }
            }
            return n;
        next:;
        }
        return -1;
    }
};
// @lc code=end
