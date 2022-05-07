/*
Description
Recall the definition of the Fibonacci numbers: 

f1 := 1 
f2 := 2 
fn := fn-1 + fn-2     (n>=3) 
Given two numbers a and b, calculate how many Fibonacci numbers are in the range [a,b].

Input
The input contains several test cases. Each test case consists of two non-negative integer numbers a and b. Input is terminated by a=b=0. Otherwise, a<=b<=10^100. The numbers a and b are given with no superfluous leading zeros. 

Output
For each test case output on a single line the number of Fibonacci numbers fi with a<=fi<=b. 

Sample Input
10 100
1234567890 9876543210
0 0

Sample Output
5
4
*/

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

int StrCompare(std::string s1, std::string s2) //在用字符串比较数字的大小的时候要对齐所有的位，因此前面长度不够的字符串要在前面补0之后再比较
{
    while (s1.size() != s2.size())
    {
        if (s1.size() < s2.size())
        {
            s1.insert(0, "0");
        }
        else
        {
            s2.insert(0, "0");
        }
    }
    if (s1 == s2) //返回等于，大于，小于三种情况
    {
        return 0;
    }
    else if (s1 > s2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int FibNum(std::string a, std::string b)
{
    if (StrCompare(a, b) == 1)
    {
        return 0;
    }
    else
    {
        std::string m = "1", n = "2";
        int num = 0;
        for (;;)
        {
            if ((StrCompare(n, a) == 0 || StrCompare(n, a) == 1) && (StrCompare(n, b) == 0 || StrCompare(n, b) == 2)) //判断区间
            {
                num++;
            }
            else if (StrCompare(n, b) == 1) //判断循环结束的边界条件
            {
                break;
            }

            std::string newn = "";
            int nextBit = 0; //进位
            std::string::iterator itm = m.end() - 1;
            std::string::iterator itn = n.end() - 1;
            while (itm >= m.begin() && itn >= n.begin()) //字符串模拟每一位相加，且单位数字相加最高为18，注意这一点
            {
                if (*itm - '0' + *itn - '0' + nextBit >= 10)
                {
                    newn += (*itm - '0' + *itn - '0' + nextBit) % 10 + '0';
                    nextBit = 1;
                }
                else
                {
                    newn += *itm - '0' + *itn - '0' + nextBit + '0';
                    nextBit = 0;
                }
                itm--, itn--;
            }
            std::string mod = m.size() > n.size() ? m.substr(0, m.size() - n.size()) : n.substr(0, n.size() - m.size());
            std::string::iterator itmod = mod.end() - 1;
            while (itmod >= mod.begin()) //由于相加的数字字符串没有补0，因此要把多余的位再加一下
            {
                if (*itmod - '0' + nextBit >= 10)
                {
                    newn += (*itmod - '0' + nextBit) % 10 + '0';
                    nextBit = 1;
                }
                else
                {
                    newn += *itmod - '0' + nextBit + '0';
                    nextBit = 0;
                }
                itmod--;
            }
            if (nextBit) //判断最后一位是否要进位
            {
                newn += '1';
                nextBit = 0;
            }
            std::reverse(newn.begin(), newn.end()); //由于之前所有的相加都是每一位反过来加到新的字符串上的，因此要反转一下变成真正的加法结果
            m = n;                                  //m变成原来的n
            n = newn;                               //n变成新的加完了的结果字符串
        }
        return num;
    }
}

int main() //考虑到a<=b<=10^100，所以用字符串模拟手工竖式加法，但还是WA了，不知道为什么
{
    std::vector<std::pair<std::string, std::string>> ab{};
    std::string a = "", b = "";
    while (std::cin >> a >> b && a != "0" && b != "0")
    {
        ab.push_back(std::pair<std::string, std::string>(a, b));
    }

    for (std::vector<std::pair<std::string, std::string>>::iterator it = ab.begin(); it != ab.end(); it++)
    {
        std::cout << FibNum(it->first, it->second) << std::endl;
    }

    return 0;
}