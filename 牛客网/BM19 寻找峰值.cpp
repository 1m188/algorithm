/*

描述
给定一个长度为n的数组nums，请你找到峰值并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个所在位置即可。
1.峰值元素是指其值严格大于左右相邻值的元素。严格大于即不能有等于
2.假设 nums[-1] = nums[n] =
−
∞
−∞
3.对于所有有效的 i 都有 nums[i] != nums[i + 1]
4.你可以使用O(logN)的时间复杂度实现此问题吗？

数据范围：
1
≤
�
�
�
�
.
�
�
�
�
�
ℎ
≤
2
×
1
0
5

1≤nums.length≤2×10
5

−
2
31
<
=
�
�
�
�
[
�
]
<
=
2
31
−
1
−2
31
 <=nums[i]<=2
31
 −1

如输入[2,4,1,2,7,8,4]时，会形成两个山峰，一个是索引为1，峰值为4的山峰，另一个是索引为5，峰值为8的山峰，如下图所示：

示例1
输入：
[2,4,1,2,7,8,4]
复制
返回值：
1
复制
说明：
4和8都是峰值元素，返回4的索引1或者8的索引5都可以
示例2
输入：
[1,2,3,1]
复制
返回值：
2
复制
说明：
3 是峰值元素，返回其索引 2

*/

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int findPeakElement(vector<int> &nums) {
        // write code here

        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

        int idx = -1;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                idx = i;
                break;
            }
        }
        return idx;
    }
};