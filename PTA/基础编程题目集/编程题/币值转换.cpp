/*
7-23 币值转换 （20 分）
输入一个整数（位数不超过9位）代表一个人民币值（单位为元），请转换成财务要求的大写中文格式。如23108元，转换后变成“贰万叁仟壹百零捌”元。为了简化输出，用小写英文字母a-j顺序代表大写数字0-9，用S、B、Q、W、Y分别代表拾、百、仟、万、亿。于是23108元应被转换输出为“cWdQbBai”元。

输入格式：

输入在一行中给出一个不超过9位的非负整数。

输出格式：

在一行中输出转换后的结果。注意“零”的用法必须符合中文习惯。

输入样例1：

813227345
输出样例1：

iYbQdBcScWhQdBeSf
输入样例2：

6900
输出样例2：

gQjB
*/

//虽然AC了，但是感觉这代码的优化程度好低啊......

#include "iostream"
#include "string"
#include "algorithm"

int main()
{
    std::string str;
    std::cin >> str;

    //数字，单位和目标字符串
    std::string nums = "abcdefghij", units = "SBQ", s;
    //获取大小和设定一个开始和单位等级
    int size = str.size(), start = 0, level = 0;
    //把字符串倒过来从个位开始处理
    std::reverse(str.begin(), str.end());

    //每4位一处理
    while (start < size)
    {
        std::string subStr = str.substr(start, 4);
        //变成数字
        for (char &c : subStr)
        {
            c = nums[c - '0'];
        }

        //如果位数大于1，则要加单位
        if (subStr.size() > 1)
        {
            //每隔一个加一个单位
            int index = 0;
            for (auto it = subStr.begin() + 1; it < subStr.end(); it += 2)
            {
                subStr.insert(it, units[index]);
                index++;
            }

            //删除从个位开始的连续的0及其单位
            if (subStr[0] == nums[0])
            {
                subStr.erase(subStr.begin());
                for (auto it = subStr.begin() + 1; *it == nums[0]; it++)
                {
                    it = subStr.erase(it - 1, it + 1);
                }
            }

            //删除数字之中0的单位
            for (auto it = subStr.begin(); it < subStr.end(); it++)
            {
                if (*it == nums[0])
                {
                    it = subStr.erase(it - 1);
                }
            }

            //删除数字中连续的多余的0
            for (auto it = subStr.begin(); it < subStr.end(); it++)
            {
                if (*it == nums[0])
                {
                    for (auto it1 = it + 1; *it1 == *it;)
                    {
                        it1 = subStr.erase(it1);
                    }
                }
            }
        }

        //反过来，使得高位在前低位在后
        std::reverse(subStr.begin(), subStr.end());

        //确定单位等级
        switch (level)
        {
        case 1:
            subStr.push_back('W');
            break;
        case 2:
            subStr.push_back('Y');
            break;
        }

        //把新的更高位的4位数字加到总的字符串前面，启示索引自加4，单位等级提升
        s = subStr + s;
        start += 4;
        level++;
    }

    std::cout << s;

    return 0;
}