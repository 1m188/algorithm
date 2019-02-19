/*
自测-4 Have Fun with Numbers （20 分）
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:

Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:

1234567899
Sample Output:

Yes
2469135798
*/

//大概意思就是说，有一个大数，将他乘以2，组成结果的各位数字和组成输入的各位数字中，有没有互相不存在的

#include "iostream"
#include "string"
#include "algorithm"

int main()
{
    std::string integer;
    std::cin >> integer;

    //获取乘以2的结果
    std::string result;
    int carry = 0;
    int num = 0;
    for (auto cit = integer.crbegin(); cit != integer.crend(); cit++)
    {
        num = (*cit - '0') * 2 + carry;
        result.push_back(num % 10 + '0');
        num /= 10;
        carry = num;
    }
    if (num != 0)
    {
        result.push_back(num + '0');
    }
    std::reverse(result.begin(), result.end());

    //判定数字在两个大数中是否存在，从1到9任意一位数字，要么都不在，要么都在
    for (int i = 0; i <= 9; i++)
    {
        auto integerIt = std::find(integer.begin(), integer.end(), i + '0');
        auto resultIt = std::find(result.begin(), result.end(), i + '0');
        if ((integerIt == integer.end() && resultIt != result.end()) || (integerIt != integer.end() && resultIt == result.end()))
        {
            std::cout << "No\n"
                      << result;
            return 0;
        }
    }

    std::cout << "Yes\n"
              << result;

    return 0;
}