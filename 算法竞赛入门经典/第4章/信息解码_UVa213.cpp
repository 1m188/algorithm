#include "iostream"
#include "string"
#include "cmath"
#include "map"
int main()
{
    std::string codeHead = "";
    std::cin >> codeHead;

    std::map<std::pair<int, int>, char> code{};
    int bit = 1, num = 0;
    for (std::string::iterator it = codeHead.begin(); it != codeHead.end(); it++)
    {
        if (num < pow(2, bit) - 1)
        {
            code[std::pair<int, int>(bit, num)] = *it;
        }
        else
        {
            bit++;
            num = 0;
            code[std::pair<int, int>(bit, num)] = *it;
        }
        num++;
    }

    std::string codeText = "";
    std::string temp = "";
    while (std::cin >> temp && !std::cin.eof())
    {
        codeText += temp;
    }
    std::string text = "";
    while (true)
    {
        std::string length = codeText.substr(0, 3);
        codeText.erase(codeText.begin(), codeText.begin() + 3);
        int len = 4 * (length[0] - '0') + 2 * (length[1] - '0') + length[2] - '0';
        if (len == 0)
        {
            break;
        }
        while (true)
        {
            int textNum = 0;
            for (int i = 0; i < len; i++)
            {
                textNum += pow(2, len - i - 1) * (codeText[0] - '0');
                codeText.erase(codeText.begin());
            }
            if (textNum == pow(2, len) - 1)
            {
                break;
            }
            text += code[std::pair<int, int>(len, textNum)];
        }
    }
    std::cout << text << std::endl;

    return 0;
}