/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 *
 * [1170] 比较字符串最小字母出现频次
 *
 * https://leetcode-cn.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/
 *
 * algorithms
 * Easy (60.14%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 8.9K
 * Testcase Example:  '["cbd"]\n["zaaaz"]'
 *
 * 我们来定义一个函数 f(s)，其中传入参数 s 是一个非空字符串；该函数的功能是统计 s  中（按字典序比较）最小字母的出现频次。
 * 
 * 例如，若 s = "dcce"，那么 f(s) = 2，因为最小的字母是 "c"，它出现了 2 次。
 * 
 * 现在，给你两个字符串数组待查表 queries 和词汇表 words，请你返回一个整数数组 answer 作为答案，其中每个 answer[i] 是满足
 * f(queries[i]) < f(W) 的词的数目，W 是词汇表 words 中的词。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：queries = ["cbd"], words = ["zaaaz"]
 * 输出：[1]
 * 解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。
 * 
 * 
 * 示例 2：
 * 
 * 输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
 * 输出：[1,2]
 * 解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 > f("cc")。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= queries.length <= 2000
 * 1 <= words.length <= 2000
 * 1 <= queries[i].length, words[i].length <= 10
 * queries[i][j], words[i][j] 都是小写英文字母
 * 
 * 
 */

#include "vector"
#include "string"
using namespace std;

// @lc code=start
class Solution
{
private:
    int getFreq(const string &str) const
    {
        int freq = 0;
        char cc = 'z' + 1;
        for (const char &c : str)
        {
            if (c == cc)
            {
                freq++;
            }
            else if (c < cc)
            {
                cc = c;
                freq = 1;
            }
        }
        return freq;
    }

    int binGetIndex(const vector<int> &vec, const int &num) const
    {
        if (vec.empty())
        {
            return 0;
        }

        int left = 0, right = vec.size(), mid = 0;
        while (right > left)
        {
            mid = (left + right) / 2;
            if (vec[mid] > num)
            {
                right = mid;
            }
            else if (vec[mid] < num)
            {
                left = mid + 1;
            }
            else
            {
                break;
            }
        }
        mid = (left + right) / 2;
        return mid;
    }

public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> wordsFreq;
        for (string &word : words)
        {
            int freq = getFreq(word);
            int index = binGetIndex(wordsFreq, freq);
            wordsFreq.insert(wordsFreq.begin() + index, freq);
        }

        vector<int> answer;
        for (string &query : queries)
        {
            int freq = getFreq(query);
            int index = binGetIndex(wordsFreq, freq);
            if (wordsFreq[index] == freq)
            {
                while (index < wordsFreq.size() && wordsFreq[index] <= freq)
                {
                    index++;
                }
            }
            int num = wordsFreq.size() - index;
            answer.push_back(num);
        }
        return answer;
    }
};
// @lc code=end
