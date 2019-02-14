#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

int main() //好麻烦...，总体思想是将每个有空格隔开的东西单独放置，之后选取最长的那一个作为基准，将其他短的补空格至最长
{
    int n = 0;
    std::cin >> n;
    std::cin.get(); //吃掉上面的输入回车
    std::vector<std::vector<std::string>> code(n, std::vector<std::string>{});
    for (int i = 0; i < n; i++)
    {
        std::string temp = "";
        std::getline(std::cin, temp);

        for (std::string::iterator it = temp.begin(); it != temp.end();) //删除首位空格
        {
            if (*it == ' ')
            {
                temp.erase(it);
            }
            else
            {
                break;
            }
        }
        std::reverse(temp.begin(), temp.end());
        for (std::string::iterator it = temp.begin(); it != temp.end();)
        {
            if (*it == ' ')
            {
                temp.erase(it);
            }
            else
            {
                break;
            }
        }
        std::reverse(temp.begin(), temp.end());

        for (std::string::iterator it = temp.begin() + 1; it != temp.end();) //删除多余的空格
        {
            if (*it == ' ' && *(it - 1) == ' ')
            {
                temp.erase(it);
            }
            else
            {
                it++;
            }
        }
        temp += ' ';
        while (!temp.empty()) //将每一个由空格隔开的东西单独放置
        {
            code[i].push_back(temp.substr(0, temp.find(' ')));
            temp.erase(temp.begin(), temp.begin() + temp.find(' ') + 1);
        }
    }

    int maxSize = code[0].size(); //这里是将每一行的“东西”的数量对齐，对齐方式是补空
    for (std::vector<std::vector<std::string>>::iterator it = code.begin(); it != code.end(); it++)
    {
        if (it->size() > maxSize)
        {
            maxSize = it->size();
        }
    }
    for (std::vector<std::vector<std::string>>::iterator it = code.begin(); it != code.end(); it++)
    {
        int size = it->size();
        for (int i = 0; i < maxSize - size; i++)
        {
            it->push_back("");
        }
    }

    for (int i = 0; i < code[0].size(); i++) //关键一点，对齐每行的“东西”的长度
    {
        int colMs = code[0][i].size();
        for (int j = 0; j < code.size(); j++)
        {
            if (code[j][i].size() > colMs)
            {
                colMs = code[j][i].size();
            }
        }
        for (int j = 0; j < code.size(); j++)
        {
            int s = code[j][i].size();
            for (int k = 0; k < colMs - s; k++)
            {
                code[j][i].push_back(' ');
            }
        }
    }

    for (std::vector<std::vector<std::string>>::iterator it = code.begin(); it != code.end(); it++) //输出
    {
        for (std::vector<std::string>::iterator i = it->begin(); i != it->end(); i++)
        {
            std::cout << *i;
            if (std::distance(it->begin(), i) != it->size() - 1)
            {
                std::cout << ' ';
            }
            else
            {
                std::cout << std::endl;
            }
        }
    }

    return 0;
}