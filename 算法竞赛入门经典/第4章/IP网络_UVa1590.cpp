#include "iostream"
#include "string"
#include "vector"
#include "cmath"
#include "algorithm"

std::string IPTen2Two(std::string ipten); //将字符串十进制IP转换为字符串二进制IP
std::string IPTwo2Ten(std::string iptwo); //将字符串二进制IP转换为字符串十进制IP
std::string Ten2Two(std::string ten);     //将字符串十进制转换为字符串二进制
std::string Two2Ten(std::string two);     //将字符串二进制转换为字符串十进制

int main()
{
    int T = 0;
    std::cin >> T;
    std::vector<std::string> IP{};
    for (int i = 0; i < T; i++)
    {
        std::string temp = "";
        std::cin >> temp;
        IP.push_back(IPTen2Two(temp)); //处理输入，把每一个十进制转成二进制的以供之后方便判断
    }

    int n = 0;
    for (int i = 0; i < 32; i++) //计算所有IP前多少位相同以便选取最小范围的网络
    {
        for (std::vector<std::string>::iterator it = IP.begin(); it != IP.end() - 1; it++)
        {
            if ((*it)[i] != (*(it + 1))[i])
            {
                goto outside;
            }
        }
        n++;
    }
outside:
    std::string internetAdress = "";
    std::string subnet = "";
    for (int i = 0; i < n; i++)
    {
        internetAdress += IP[0][i]; //给出前n位相同的前n位网络地址
        subnet += '1';              //和子网掩码
    }
    while (internetAdress.size() < 32) //之后若有不足32位部分补0
    {
        internetAdress += '0';
        subnet += '0';
    }
    internetAdress = IPTwo2Ten(internetAdress); //都转换为人看得懂的十进制IP
    subnet = IPTwo2Ten(subnet);
    std::cout << internetAdress << std::endl
              << subnet << std::endl;

    return 0;
}

std::string Ten2Two(std::string ten)
{
    int num = 0;
    int size = ten.size();
    for (int i = 0; i < size; i++)
    {
        num += (ten[size - i - 1] - '0') * pow(10, i);
    }

    std::string two = "";
    while (num)
    {
        int a = num % 2;
        two += a + '0';
        num /= 2;
    }
    int zeroNum = 8 - two.size();
    for (int i = 0; i < zeroNum; i++)
    {
        two += '0';
    }
    std::reverse(two.begin(), two.end());
    return two;
}

std::string Two2Ten(std::string two)
{
    int num = 0;
    int size = two.size();
    for (int i = 0; i < size; i++)
    {
        num += (two[size - 1 - i] - '0') * pow(2, i);
    }

    std::string ten = "";
    while (num)
    {
        ten += num % 10 + '0';
        num /= 10;
    }
    std::reverse(ten.begin(), ten.end());
    return ten;
}

std::string IPTen2Two(std::string ipten)
{
    std::string iptwo = "";
    ipten += '.';
    while (!ipten.empty())
    {
        iptwo += Ten2Two(ipten.substr(0, ipten.find('.')));
        ipten.erase(ipten.begin(), ipten.begin() + ipten.find('.') + 1);
    }
    return iptwo;
}

std::string IPTwo2Ten(std::string iptwo)
{
    std::string ipten = "";
    while (!iptwo.empty())
    {
        ipten += Two2Ten(iptwo.substr(0, 8));
        ipten += '.';
        iptwo.erase(iptwo.begin(), iptwo.begin() + 8);
    }
    ipten.erase(ipten.end() - 1);
    return ipten;
}