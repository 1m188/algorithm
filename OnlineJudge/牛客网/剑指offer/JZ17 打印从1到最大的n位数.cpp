/*
描述
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
1. 用返回一个整数列表来代替打印
2. n 为正整数，0 < n <= 5

示例1
输入：
1

返回值：
[1,2,3,4,5,6,7,8,9]
*/

#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 最大位数
     * @return int整型vector
     */
    vector<int> printNumbers(int n) {
        // write code here

        int maxn = 0;
        for (int i = 0; i < n; i++)
            maxn = maxn * 10 + 9;

        vector<int> ans;
        for (int i = 1; i <= maxn; i++)
            ans.push_back(i);

        return ans;
    }
};