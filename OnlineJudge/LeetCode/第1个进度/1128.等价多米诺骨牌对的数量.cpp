/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 *
 * https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/description/
 *
 * algorithms
 * Easy (42.62%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 10.6K
 * Testcase Example:  '[[1,2],[2,1],[3,4],[5,6]]'
 *
 * 给你一个由一些多米诺骨牌组成的列表 dominoes。
 * 
 * 如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。
 * 
 * 形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且
 * b==c。
 * 
 * 在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对
 * (i, j) 的数量。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= dominoes.length <= 40000
 * 1 <= dominoes[i][j] <= 9
 * 
 * 
 */

// 设计一种 list->int 映射方式，较小的数字作十位，较大的数字作个位。比如，(1, 2) 和 (2, 1) 都会映射为数字 12。这样一来，等价的骨牌都会有相同的映射。
// 通过一次遍历，用字典来记录{映射结果：出现次数}。
// 最后，遍历字典计算次数。代码给出了两种方法，一种是跟上面的一样，求 k*(k-1)/2；另一种是实时计算:当你遇到(1, 2)时，如果 12 之前出现了 m 次，那么新加入的 12 就能再多贡献 m 个匹配对数。
// 时间复杂度：O(n)
// 空间复杂度：O(n)

#include "vector"
#include "unordered_map"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int res = 0;
        unordered_map<int, int> um;
        for (const auto &vec : dominoes)
        {
            int x = vec[0], y = vec[1];
            um[max(x, y) * 10 + min(x, y)]++;
        }
        for (const auto &p : um)
        {
            res += p.second * (p.second - 1) / 2;
        }
        return res;
    }
};
// @lc code=end
