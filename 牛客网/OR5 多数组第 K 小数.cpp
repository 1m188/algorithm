/**
 * @file OR5 多数组第 K 小数.cpp
 * @date 2024-11-15
 */

/*
描述
给定两个升序的数列 arr1 和 arr2 ，和一个整数 target ，请你找出两个数列中第 K 小的值。

数据范围：两个数列的长度都满足
1
≤
n
≤
1
0
6

1≤n≤10
6
   ，数列中的值都满足
1
≤
v
a
l
≤
1
0
9

1≤val≤10
9
   ，给定整数大小满足
1
≤
t
a
r
g
e
t
≤
l
e
n
(
a
r
r
1
)
+
l
e
n
(
a
r
r
2
)

1≤target≤len(arr1)+len(arr2)
示例1
输入：
[1,2,3,4],[1,3,4],2
复制
返回值：
1
复制
说明：
两个数列中数升序排列是 1 1 2 3 3 4，故第二小的是 1
示例2
输入：
[1,2,3,4],[1,3,4],7
复制
返回值：
4
*/

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param arr1 int整型vector
     * @param arr2 int整型vector
     * @param target int整型
     * @return int整型
     */
    int findKthNum(vector<int> &arr1, vector<int> &arr2, int target) {
        // write code here

        if (target == 1) return min(arr1[0], arr2[0]);

        target--;

        int idx1 = 0, idx2 = 0;
        while (idx1 < arr1.size() && idx2 < arr2.size() && target) {
            if (arr1[idx1] == arr2[idx2]) {
                idx1++;
            } else if (arr1[idx1] > arr2[idx2]) {
                idx2++;
            } else {
                idx1++;
            }
            target--;
        }

        while (idx1 < arr1.size() && target) {
            idx1++;
            target--;
        }
        while (idx2 < arr2.size() && target) {
            idx2++;
            target--;
        }

        if (idx1 >= arr1.size()) return arr2[idx2];
        if (idx2 >= arr2.size()) return arr1[idx1];
        return min(arr1[idx1], arr2[idx2]);
    }
};