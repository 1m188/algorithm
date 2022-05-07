/*
Description
Ignatius was born in a leap year, so he want to know when he could hold his birthday party. Can you tell him?

Given a positive integers Y which indicate the start year, and a positive integer N, your task is to tell the Nth leap year from year Y.

Note: if year Y is a leap year, then the 1st leap year is year Y.

Input
The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
Each test case contains two positive integers Y and N(1<=N<=10000).

Output
For each test case, you should output the Nth leap year from year Y.

Sample Input
3
2005 25
1855 12
2004 10000

Sample Output
2108
1904
43236
*/

#include "iostream"
#include "vector"
int main() //AC.水题
{
    int T = 0;
    std::cin >> T;
    std::vector<std::pair<int, int>> test(T, std::pair<int, int>{0, 0});
    for (int i = 0; i < T; i++)
    {
        std::cin >> test[i].first >> test[i].second;
    }

    for (std::vector<std::pair<int, int>>::iterator it = test.begin(); it != test.end(); it++)
    {
        int Y = (*it).first, N = (*it).second;
        while (N)
        {
            if ((!(Y % 4) && Y % 100) || !(Y % 400))
            {
                N--;
            }
            Y++;
        }
        std::cout << Y - 1 << std::endl;
    }

    return 0;
}