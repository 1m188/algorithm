/*
Description
This problem is also a A + B  problem,but it has a little difference,you should determine does (a+b) could be divided with 86.For example ,if (A+B)=98,you should output no for result.

Input
Each line will contain two integers A and B. Process to end of file.

Output
For each case, if(A+B)%86=0,output yes in one line,else output no in one line.

Sample Input
1 1
8600 8600

Sample Output
no
yes
*/

#include "iostream"
#include "vector"
int main()
{
    std::vector<std::pair<int, int>> input{};
    int a = 0, b = 0;
    std::cin >> a >> b;
    while (!std::cin.eof())
    {
        input.push_back(std::pair<int, int>(a, b));
        std::cin >> a >> b;
    }

    for (std::vector<std::pair<int, int>>::iterator it = input.begin(); it != input.end(); it++)
    {
        int result = (*it).first + (*it).second;
        if (result % 86)
        {
            std::cout << "no\n";
        }
        else
        {
            std::cout << "yes\n";
        }
    }

    return 0;
}