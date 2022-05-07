/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第K大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/description/
 *
 * algorithms
 * Easy (42.41%)
 * Likes:    107
 * Dislikes: 0
 * Total Accepted:    14.4K
 * Total Submissions: 34K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n' +
  '[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * 设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。
 * 
 * 你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用
 * KthLargest.add，返回当前数据流中第K大的元素。
 * 
 * 示例:
 * 
 * 
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 * 
 * 
 * 说明: 
 * 你可以假设 nums 的长度≥ k-1 且k ≥ 1。
 * 
 */

#include "vector"
#include "algorithm"
#include "limits"
using namespace std;

// @lc code=start
class KthLargest
{
private:
    int num = 0;
    vector<int> vec;
    void binaryInsert(int val)
    {
        // 二分搜索插入
        int start = 0, end = vec.size();
        while (end > start)
        {
            int mid = (start + end) / 2;
            if (vec[mid] < val)
            {
                end = mid;
            }
            else if (vec[mid] > val)
            {
                start = mid + 1;
            }
            else
            {
                break;
            }
        }
        vec.insert(vec.begin() + (start + end) / 2, val);
        if (vec.size() > num)
        {
            vec.pop_back();
        }
    }

public:
    KthLargest(int k, vector<int> &nums)
    {
        // 这个算法收集给定数组的排序前k项，然后不断二分插入并且返回最后一项
        // AC
        sort(nums.begin(), nums.end(), [](const int &i1, const int &i2) { return i1 > i2; });
        num = k;
        if (nums.size() > k)
        {
            vec.assign(nums.begin(), nums.begin() + k);
        }
        else
        {
            vec = nums;
        }
    }

    int add(int val)
    {
        binaryInsert(val);
        return vec.back();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
