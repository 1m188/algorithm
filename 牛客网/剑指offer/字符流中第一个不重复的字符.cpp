/*
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/

//用数组按先后顺序保存每个字符和其出现的次数，这样可以直接从前往后查找字符并且通过其相应的出现次数判定

#include "vector"
#include "algorithm"

class Solution
{
  private:
    std::vector<std::pair<char, int>> vec;

  public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        auto &&it = std::find_if(vec.begin(), vec.end(), [&](const std::pair<char, int> &p) { return p.first == ch; });
        if (it != vec.end())
        {
            it->second++;
        }
        else
        {
            vec.push_back({ch, 1});
        }
    }

    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        auto &&it = std::find_if(vec.begin(), vec.end(), [](const std::pair<char, int> &p) { return p.second == 1; });
        return it != vec.end() ? it->first : '#';
    }
};