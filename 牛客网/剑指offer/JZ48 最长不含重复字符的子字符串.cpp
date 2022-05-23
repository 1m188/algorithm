/**
 * @file JZ48 最长不含重复字符的子字符串.cpp
 * @date 2022-05-23
 */

/*
描述
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
数据范围:
\ \text{s.length}\le 40000 s.length≤40000
示例1
输入：
"abcabcbb"
复制
返回值：
3
复制
说明：
因为无重复字符的最长子串是"abc"，所以其长度为 3。    
示例2
输入：
"bbbbb"
复制
返回值：
1
复制
说明：
因为无重复字符的最长子串是"b"，所以其长度为 1。    
示例3
输入：
"pwwkew"
复制
返回值：
3
复制
说明：
因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是子串的长度，"pwke" 是一个子序列，不是子串。
*/

/* 双指针+动态更新长度，注意字符串里的字符不一定只是小写英文字符，对于所有字符都应该考虑，
所以这里使用unordered_set，遍历的时候不断考虑新的字符是否在set里面，如果在，则需要更新最长
长度，然后左指针右移，删除左指针所指，如果不在，把他加进去，右指针右移 */

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        // write code here

        unordered_set<char> uset({s[0]});

        int max_len = 1;

        int i = 0, j = 1;
        while (j < s.size()) {
            if (uset.find(s[j]) == uset.end()) {
                uset.insert(s[j]);
                j++;
            } else {
                max_len = max(max_len, j - i);
                uset.erase(s[i]);
                i++;
            }
        }
        max_len = max(max_len, j - i);

        return max_len;
    }
};