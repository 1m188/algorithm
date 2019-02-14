/*
Description
Ignatius is poor at math,he falls across a puzzle problem,so he has no choice but to appeal to Eddy. 
this problem describes that:f(x)=5*x^13+13*x^5+k*a*x,input a nonegative integer k(k<10000),
to find the minimal nonegative integer a,make the arbitrary integer x ,65|f(x)if
no exists that a,then print "no".

Input
The input contains several test cases. Each test case consists of a nonegative integer k, 
More details in the Sample Input.

Output
The output contains a string "no",if you can't find a,or you should output a line contains the a.
More details in the Sample Output.

Sample Input
11
100
9999

Sample Output
22
no
43
*/

#include "iostream"
#include "vector"
int main() //AC.数论，关键在于要使f(x)能够整除65只需要让18+ka(即f(1))整除65即可，之后a的取值在1到65之间，如果没有一个a能够满足条件就不存在
{
    std::vector<int> test{};
    int k = 0;
    while (std::cin >> k && !std::cin.eof())
    {
        test.push_back(k);
    }

    for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
    {
        for (int i = 1; i <= 65; i++)
        {
            if (!((18 + (*it) * i) % 65))
            {
                std::cout << i << std::endl;
                goto end;
            }
        }
        std::cout << "no\n";
    end:;
    }

    return 0;
}