#include "iostream"
#include "string"
int main()
{
    std::string str;
    std::cin >> str;

    std::string temp;
    std::string compare;
    for (int i = 0; i < str.size() / 2; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            temp += str[j];
        }
        while (compare.size() <= str.size())
        {
            if (compare == str)
            {
                printf("%d\n", temp.size());
                return 0;
            }
            compare += temp;
        }
        compare.clear();
        temp.clear();
    }

    return 0;
}