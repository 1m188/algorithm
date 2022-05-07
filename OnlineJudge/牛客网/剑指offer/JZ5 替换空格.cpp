/*
描述
请实现一个函数，将一个字符串s中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

数据范围:0≤len(s)≤1000 。保证字符串中的字符为大写英文字母、小写英文字母和空格中的一种。

示例1
输入：
"We Are Happy"

返回值：
"We%20Are%20Happy"

示例2
输入：
" "

返回值：
"%20"
*/

/* 注意特殊的纯空格输入形式等，此外在手动分割空格的时候要注意循环遍历的边界情况 */

#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code here

        vector<string> vec;
        string tmp;

        for (const char &c : s) {
            if (c != ' ')
                tmp += c;
            else {
                if (!tmp.empty()) {
                    vec.push_back(tmp);
                    tmp.clear();
                }
                vec.push_back("%20");
            }
        }
        if (!tmp.empty()) {
            vec.push_back(tmp);
            tmp.clear();
        }

        for (const auto &s : vec)
            tmp += s;

        return tmp;
    }
};