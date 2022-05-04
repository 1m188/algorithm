/*
Description
I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.

Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation. Output a blank line between two test cases.

Sample Input
2
1 2
112233445566778899 998877665544332211

Sample Output
Case 1:
1 + 2 = 3

Case 2:
112233445566778899 + 998877665544332211 = 1111111111111111110
*/

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
int main() //WA.用字符串来做加减法难道有错吗?
{
    int T = 0;
    std::cin >> T;
    std::vector<std::pair<std::string, std::string>> test(T, std::pair<std::string, std::string>{});
    for (int i = 0; i < T; i++)
    {
        std::cin >> test[i].first >> test[i].second;
    }

    for (int i = 0; i < test.size(); i++)
    {
        std::string temp = "";
        int nextBit = 0;
        std::string::iterator it1 = test[i].first.end() - 1;
        std::string::iterator it2 = test[i].second.end() - 1;
        while (it1 >= test[i].first.begin() || it2 >= test[i].second.begin())
        {
            int num = (*it1) - '0' + (*it2) - '0' + nextBit;
            temp += num % 10 + '0';
            nextBit = num / 10 % 10;
            if (it1 != test[i].first.end())
            {
                it1--;
            }
            if (it2 != test[i].second.end())
            {
                it2--;
            }
        }
        if (nextBit)
        {
            temp += '1';
        }
        std::reverse(temp.begin(), temp.end());
        std::cout << "Case " << i + 1 << ":" << std::endl;
        std::cout << test[i].first << " + " << test[i].second << " = " << temp << std::endl;
        std::cout << std::endl;
    }

    return 0;
}