/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 *
 * https://leetcode-cn.com/problems/goat-latin/description/
 *
 * algorithms
 * Easy (58.74%)
 * Likes:    33
 * Dislikes: 0
 * Total Accepted:    7.5K
 * Total Submissions: 12.7K
 * Testcase Example:  '"I speak Goat Latin"'
 *
 * 给定一个由空格分割单词的句子 S。每个单词只包含大写或小写字母。
 * 
 * 我们要将句子转换为 “Goat Latin”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。
 * 
 * 山羊拉丁文的规则如下：
 * 
 * 
 * 如果单词以元音开头（a, e, i, o, u），在单词后添加"ma"。
 * 例如，单词"apple"变为"applema"。
 * 
 * 如果单词以辅音字母开头（即非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
 * 例如，单词"goat"变为"oatgma"。
 * 
 * 根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从1开始。
 * 例如，在第一个单词后添加"a"，在第二个单词后添加"aa"，以此类推。
 * 
 * 
 * 返回将 S 转换为山羊拉丁文后的句子。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "I speak Goat Latin"
 * 输出: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "The quick brown fox jumped over the lazy dog"
 * 输出: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa
 * hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 * 
 * 
 * 说明:
 * 
 * 
 * S 中仅包含大小写字母和空格。单词间有且仅有一个空格。
 * 1 <= S.length <= 150。
 * 
 * 
 */

#include "string"
#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    string toGoatLatin(string S)
    {
        vector<string> vec;
        string str;
        for (const char &c : S)
        {
            if (c != ' ')
            {
                str.push_back(c);
            }
            else
            {
                vec.push_back(str);
                str.clear();
            }
        }
        vec.push_back(str);
        str.clear();

        for (int i = 0; i < vec.size(); i++)
        {
            string &s = vec[i];
            switch (s[0])
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                s.append("ma");
                break;
            default:
                s.push_back(s[0]);
                s.append("ma");
                s.erase(s.begin());
            }
            for (int j = 0; j < i + 1; j++)
            {
                s.push_back('a');
            }
        }

        for (const string &s : vec)
        {
            str.append(s);
            str.push_back(' ');
        }
        str.pop_back();
        return str;
    }
};
// @lc code=end
