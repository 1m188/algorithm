#include "iostream"
#include "string"
int main()
{
    std::string str;
    std::cin >> str;
    int num[10]{};
    int length = str.size();
    for (int i = 0; i < length; i++)
    {
        num[str[i] - '0']++;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << num[i] << std::endl;
    }

    return 0;
}