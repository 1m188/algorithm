#include "iostream"
#include "set"
#include "vector"
#include "map"
#include "string"
#include "algorithm"
int main() //没有测试，且一定会有错误，话说题目中好多地方都没有给出细节...结果我都是自己脑补的...
{
    std::map<std::string, std::vector<std::string>> mta{};
    int n = 0;
    std::string mtaAddress = "";
    while (std::cin >> mtaAddress && !std::cin.eof())
    {
        if (mta.find(mtaAddress) == mta.end())
        {
            std::cin >> n;
            mta[mtaAddress] = std::vector<std::string>(n, "");
            for (int i = 0; i < n; i++)
            {
                std::cin >> mta[mtaAddress][i];
            }
        }
    }
    std::set<std::string> connected{};
    std::string sender = "";
    std::cin >> sender;
    std::cin >> n;
    std::vector<std::string> recvList(n, "");
    for (int i = 0; i < n; i++)
    {
        std::cin >> recvList[i];
    }

    for (std::vector<std::string>::iterator it = recvList.begin(); it != recvList.end(); it++)
    {
        if (std::find(connected.begin(), connected.end(), it->substr(it->find('@') + 1)) == connected.end())
        {
            connected.insert(it->substr(it->find('@') + 1));
            std::cout << it->substr(it->find('@') + 1) << std::endl;
        }
    }

    return 0;
}