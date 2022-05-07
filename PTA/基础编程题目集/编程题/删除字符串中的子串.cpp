/*
7-29 删除字符串中的子串 （20 分）
输入2个字符串S1和S2，要求删除字符串S1中出现的所有子串S2，即结果字符串中不能包含S2。

输入格式：

输入在2行中分别给出不超过80个字符长度的、以回车结束的2个非空字符串，对应S1和S2。

输出格式：

在一行中输出删除字符串S1中出现的所有子串S2后的结果字符串。

输入样例：

Tomcat is a male ccatat
cat
输出样例：

Tom is a male 
*/

#include "iostream"
#include "string"

int main()
{
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    bool isOk = false;
    while (!isOk)
    {
        isOk = true;
        //从每一个字符位置往后开始匹配
        for (auto it = s1.begin(); it < s1.end(); it++)
        {
            auto tit = it;
            for (const char &c : s2)
            {
                //字符串末尾不完整
                if (tit == s1.end())
                {
                    goto next;
                }
                if (c == *tit)
                {
                    tit++;
                }
                else
                {
                    goto next;
                }
            }
            //当全部匹配了才开始删除
            tit = s1.erase(it, tit);
            it = tit - 1;
            //只要删了一次，就要再检查一遍，直到最后没有删除过为止
            isOk = false;
        next:;
        }
    }

    std::cout << s1;

    return 0;
}