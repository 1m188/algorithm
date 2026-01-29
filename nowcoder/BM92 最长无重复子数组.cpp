/**
 * @file BM92 最长无重复子数组.cpp
 * @date 2024-11-27
 */

/*
描述
给定一个长度为n的数组arr，返回arr的最长无重复元素子数组的长度，无重复指的是所有数字都不相同。
子数组是连续的，比如[1,3,5,7,9]的子数组有[1,3]，[3,5,7]等等，但是[1,3,7]不是子数组

数据范围：
0
≤
a
r
r
.
l
e
n
g
t
h
≤
1
0
5
0≤arr.length≤10
5
 ，
0
<
a
r
r
[
i
]
≤
1
0
5
0<arr[i]≤10
5

示例1
输入：
[2,3,4,5]
复制
返回值：
4
复制
说明：
[2,3,4,5]是最长子数组
示例2
输入：
[2,2,3,4,3]
复制
返回值：
3
复制
说明：
[2,3,4]是最长子数组
示例3
输入：
[9]
复制
返回值：
1
复制
示例4
输入：
[1,2,3,1,2,3,2,2]
复制
返回值：
3
复制
说明：
最长子数组为[1,2,3]
示例5
输入：
[2,2,3,4,8,99,3]
复制
返回值：
5
复制
说明：
最长子数组为[2,3,4,8,99]
*/
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int> &arr) {
        // write code here

        vector<int> idxes(1e5 + 1, -1);
        int left = 0, right = 0;
        idxes[arr[0]] = 0;
        int maxLen = 1;

        while (right + 1 < arr.size()) {
            int newVal = arr[right + 1];
            if (idxes[newVal] == -1) {
                idxes[newVal] = ++right;
                maxLen = max(maxLen, right - left + 1);
            } else {
                idxes[arr[left++]] = -1;
            }
        }

        return maxLen;
    }
};