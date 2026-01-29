/**
 * @file JZ45 把数组排成最小的数.cpp
 * @date 2022-05-27
 */

/*
描述
输入一个非负整数数组numbers，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组[3，32，321]，则打印出这三个数字能排成的最小数字为321323。
1.输出结果可能非常大，所以你需要返回一个字符串而不是整数
2.拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

数据范围:
0<=len(numbers)<=100
示例1
输入：
[11,3]
复制
返回值：
"113"
复制
示例2
输入：
[]
复制
返回值：
""
复制
示例3
输入：
[3,32,321]
复制
返回值：
"321323"
*/

/* 排序，如果a+b<b+a，那么a应该排在b的前面，对每个数字都如此进行排序，
最后直接用得到的序列拼起来即可 */

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    string PrintMinNumber(vector<int> numbers) {

        vector<string> vec;
        for (int n : numbers) {
            if (!n) {
                vec.push_back("0");
                continue;
            }
            string s;
            while (n) {
                s.push_back(n % 10 + '0');
                n /= 10;
            }
            reverse(s.begin(), s.end());
            vec.push_back(s);
        }

        sort(vec.begin(), vec.end(), [](const string &a, const string &b) {
            return a + b < b + a;
        });

        string ans;
        for (const string &str : vec)
            ans += str;

        return ans;
    }
};