/**
 * @file JZ61 扑克牌顺子.cpp
 * @date 2022-05-27
 */

/*
描述
现在有2副扑克牌，从扑克牌中随机五张扑克牌，我们需要来判断一下是不是顺子。
有如下规则：
1. A为1，J为11，Q为12，K为13，A不能视为14
2. 大、小王为 0，0可以看作任意牌
3. 如果给出的五张牌能组成顺子（即这五张牌是连续的）就输出true，否则就输出false。
4.数据保证每组5个数字，每组最多含有4个零，数组的数取值为 [0, 13]

要求：空间复杂度 O(1)O(1)，时间复杂度 O(nlogn)O(nlogn)，本题也有时间复杂度 O(n)O(n) 的解法
输入描述：
输入五张扑克牌的值
返回值描述：
五张扑克牌能否组成顺子。
示例1
输入：
[6,0,2,0,4]
复制
返回值：
true
复制
说明：
中间的两个0一个看作3，一个看作5 。即：[6,3,2,5,4]
这样这五张牌在[2,6]区间连续，输出true 
示例2
输入：
[0,3,2,6,4]
复制
返回值：
true
复制
示例3
输入：
[1,0,0,1,0]
复制
返回值：
false
复制
示例4
输入：
[13,12,11,0,1]
复制
返回值：
false
*/

/* 排序+模拟，注意牌相同时候的情况 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {

  public:
    bool IsContinuous(vector<int> numbers) {

        sort(numbers.begin(), numbers.end());

        int num = 0;
        while (!numbers[0]) {
            num++;
            numbers.erase(numbers.begin());
        }

        for (int i = 1; i < numbers.size(); i++) {
            int x = numbers[i] - numbers[i - 1] - 1;
            if (x < 0)
                return false;
            num -= x;
        }

        return num >= 0;
    }
};