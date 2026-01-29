/**
 * @file JZ21 调整数组顺序使奇数位于偶数前面(一).cpp
 * @date 2022-05-27
 */

/*
描述
输入一个长度为 n 整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前面部分，所有的偶数位于数组的后面部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

数据范围：0 \le n \le 50000≤n≤5000，数组中每个数的值 0 \le val \le 100000≤val≤10000
要求：时间复杂度 O(n)O(n)，空间复杂度 O(n)O(n)
进阶：时间复杂度 O(n^2)O(n 
2
 )，空间复杂度 O(1)O(1)
示例1
输入：
[1,2,3,4]
复制
返回值：
[1,3,2,4]
复制
示例2
输入：
[2,4,6,5,7]
复制
返回值：
[5,7,2,4,6]
复制
示例3
输入：
[1,3,5,6,7]
复制
返回值：
[1,3,5,7,6]
*/

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
    vector<int> reOrderArray(vector<int> &array) {
        // write code here

        vector<int> odd, even;

        for (const int &i : array)
            if (i % 2)
                odd.push_back(i);
            else
                even.push_back(i);

        odd.insert(odd.end(), even.begin(), even.end());

        return odd;
    }
};