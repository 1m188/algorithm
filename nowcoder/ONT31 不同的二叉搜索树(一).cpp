/*
描述
给定一个由节点值从 1 到 n 的 n 个节点。请问由多少种不同的方法用这 n 个节点构成互不相同的二叉搜索树。
请你输出有多少种方法。

例如：当n=2时有


数据范围：
1
≤
�
≤
19

1≤n≤19
示例1
输入：
2
复制
返回值：
2
复制
示例2
输入：
3
复制
返回值：
5

*/

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int BSTCount(int n) {
        // write code here

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int left = 0; left < i; left++) {
                dp[i] += dp[left] * dp[i - 1 - left];
            }
        }

        return dp[n];
    }
};