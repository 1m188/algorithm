/**
 * @file JZ73 翻转单词序列.cpp
 * @date 2022-05-11
 */

/*
描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“nowcoder. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a nowcoder.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

数据范围：1≤n≤100 
进阶：空间复杂度 O(n)  ，时间复杂度 O(n)  ，保证没有只包含空格的字符串
示例1
输入：
"nowcoder. a am I"

返回值：
"I am a nowcoder."

示例2
输入：
""

返回值：
""
*/

/* 对于每个空格分割的单词内部不需要翻转，只需要调转所有单词的顺序即可，
使用stringstream做空格的分割 */

#include <sstream>
#include <string>
using namespace std;

class Solution {
  public:
    string ReverseSentence(string str) {

        if (str.empty())
            return "";

        string ans;

        stringstream ss(str);
        string t;
        while (ss >> t) {
            ans = ' ' + t + ans;
        }
        ans.erase(ans.begin());

        return ans;
    }
};