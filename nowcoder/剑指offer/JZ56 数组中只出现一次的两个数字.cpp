/**
 * @file JZ56 数组中只出现一次的两个数字.cpp
 * @date 2022-05-29
 */

/*
描述
一个整型数组里除了两个数字只出现一次，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

数据范围：数组长度 2\le n \le 10002≤n≤1000，数组中每个数的大小 0 < val \le 10000000<val≤1000000
要求：空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)

提示：输出时按非降序排列。
示例1
输入：
[1,4,1,6]
复制
返回值：
[4,6]
复制
说明：
返回的结果中较小的数排在前面     
示例2
输入：
[1,2,3,3,2,9]
复制
返回值：
[1,9]
*/

/* 两个相同的数异或后就消掉了，这里用异或，全部异或后，留下的是两个独一数
异或后的结果，找到最低位不为0的，说明这一位两个数不同，以这一位作为分组依据，
对原来的数据进行分组异或 */

#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int> &array) {
        // write code here

        int x = 0;
        for (const int &i : array) // 找出两个独一数的异或
            x ^= i;

        int t = 1;
        while ((x & t) == 0) // 找到该异或最低的一位不为0，用作分组
            t <<= 1;

        int a = 0, b = 0;
        for (const int &i : array) {
            if (i & t) // 分组异或
                a ^= i;
            else
                b ^= i;
        }

        if (a > b)
            return {b, a};
        else
            return {a, b};
    }
};