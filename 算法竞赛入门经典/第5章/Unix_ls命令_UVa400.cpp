#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<std::string> fileName(n, "");
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> fileName[i];
        m = std::max(m, static_cast<int>(fileName[i].size()));
    }
    std::sort(fileName.begin(), fileName.end());

    int cols = (60 - m) / (m + 2) + 1; //关键在于计算行列数，按书上来的...这一块我不知道为什么是这个公式...
    int rows = (n - 1) / cols + 1;
    for (int i = 0; i < cols * rows - fileName.size(); i++)
    {
        fileName.push_back("");
    }
    for (std::vector<std::string>::iterator it = fileName.begin(); it != fileName.end(); it++)
    {
        if (std::distance(fileName.begin(), it) < cols * rows - rows) //将不足相应位数的字符串补足
        {
            int size = it->size();
            for (int i = 0; i < m + 2 - size; i++)
            {
                it->push_back(' ');
            }
        }
        else
        {
            int size = it->size();
            for (int i = 0; i < m - size; i++)
            {
                it->push_back(' ');
            }
        }
    }
    for (int i = 0; i < rows; i++) //由于要打印的是一个二维的东西，但是我存储的数组是一维的，所以这里要仔细想一下
    {
        for (int j = i; j < cols * rows; j += rows)
        {
            std::cout << fileName[j];
        }
        std::cout << std::endl;
    }

    return 0;
}