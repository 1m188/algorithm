/**
 * @file JZ59 滑动窗口的最大值.cpp
 * @date 2022-05-11
 */

/*
描述
给定一个长度为 n 的数组 nums 和滑动窗口的大小 size ，找出所有滑动窗口里数值的最大值。

例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， 
{2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

数据范围： 1≤size≤n≤10000，数组中每个元素的值满足 ∣val∣≤10000
要求：空间复杂度 O(n)，时间复杂度 O(n)


示例1
输入：
[2,3,4,2,6,2,5,1],3

返回值：
[4,4,6,6,6,5]

示例2
输入：
[9,10,9,-7,-3,8,2,-6],5

返回值：
[10,10,9,8]

示例3
输入：
[1,2,3,4],3

返回值：
[3,4]
*/

/* 单调队列，对于这一题要保存很多大值和次大值，以及次次大值，除非碰到更大的，
但在这之前这些值都要保存下来，所以得要用一个单调队列 */

#include <deque>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> maxInWindows(const vector<int> &nums, int size) {
        vector<int> ans;
        deque<int> dque;

        for (int i = 0; i < nums.size(); i++) { // 对每个元素

            // 新的值是否大于单调队列尾部的值
            // 如果大于，则原来这些值就没必要保留了
            while (!dque.empty() && nums[dque.back()] < nums[i])
                dque.pop_back();
            dque.push_back(i);

            // 判定队头元素是否超出窗口范围
            if (dque.front() <= i - size)
                dque.pop_front();

            // 判定是否形成窗口
            if (i >= size - 1)
                ans.push_back(nums[dque.front()]);
        }

        return ans;
    }
};