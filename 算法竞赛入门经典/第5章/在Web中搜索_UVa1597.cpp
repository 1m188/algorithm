#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "algorithm"
#include "cctype"

struct Article //文章信息
{
    std::vector<std::string> article;                //文章，一行一个元素
    std::map<std::string, std::vector<int>> wordMap; //小写的单词对应的行数，0作为基准

    Article() : article(std::vector<std::string>{}), wordMap(std::map<std::string, std::vector<int>>{}) {}
};
void A(std::vector<Article> &articles, std::string A);                      //查找包含关键字A的文章
void A_AND_B(std::vector<Article> &articles, std::string A, std::string B); //查找同时包含关键字A和B的文章
void A_OR_B(std::vector<Article> &articles, std::string A, std::string B);  //查找包含A或B的文章
void NOT_A(std::vector<Article> &articles, std::string A);                  //查找不包含A的文章

int main() //没有测试
{
    int n = 0;
    std::cin >> n;
    std::cin.get();
    std::vector<Article> articles(n, Article());
    for (int i = 0; i < n; i++)
    {
        std::string row = "";
        while (std::getline(std::cin, row) && !std::cin.eof()) //输入
        {
            articles[i].article.push_back(row);                                 //文章的一行
            row += ' ';                                                         //便于后面的单词匹配
            for (std::string::iterator it = row.begin(); it != row.end(); it++) //转小写再存单词
            {
                if (isalpha(*it))
                {
                    *it = tolower(*it);
                }
            }

            while (!row.empty())
            {
                std::string word = row.substr(0, row.find(' '));                 //获得以空格隔开的单词
                if (articles[i].wordMap.find(word) == articles[i].wordMap.end()) //没有的单词加进去
                {
                    articles[i].wordMap[word] = std::vector<int>{};
                    articles[i].wordMap[word].push_back(i);
                }
                else //有了的单词看是否在同一行上，不在则加进去
                {
                    if (std::find(articles[i].wordMap[word].begin(), articles[i].wordMap[word].end(), i) == articles[i].wordMap[word].end())
                    {
                        articles[i].wordMap[word].push_back(i);
                    }
                }
                row.erase(row.begin(), row.begin() + row.find(' ') + 1);
            }
        }
    }

    int m = 0;
    std::cin >> m;
    std::cin.get();
    for (int i = 0; i < m; i++)
    {
        std::string oper = ""; //输入命令
        std::getline(std::cin, oper);
        if (oper.find(' ') != std::string::npos) //判断四种命令
        {
            if (oper.find("AND") != std::string::npos)
            {
                std::string A = oper.substr(0, oper.find(' '));
                std::string B = oper.substr(oper.find_last_of(' '));
                A_AND_B(articles, A, B);
            }
            else if (oper.find("OR") != std::string::npos)
            {
                std::string A = oper.substr(0, oper.find(' '));
                std::string B = oper.substr(oper.find_last_of(' '));
                A_OR_B(articles, A, B);
            }
            else if (oper.find("NOT") != std::string::npos)
            {
                std::string A = oper.substr(oper.find(' '));
                NOT_A(articles, A);
            }
        }
        else
        {
            A(articles, oper);
        }
    }

    return 0;
}

void A(std::vector<Article> &articles, std::string A)
{
    for (std::vector<Article>::iterator it = articles.begin(); it != articles.end(); it++)
    {
        if (it->wordMap.find(A) != it->wordMap.end())
        {
            for (std::vector<int>::iterator i = it->wordMap[A].begin(); i != it->wordMap[A].end(); i++)
            {
                std::cout << it->article[*i] << std::endl;
            }
        }
    }
}

void A_AND_B(std::vector<Article> &articles, std::string A, std::string B)
{
    for (std::vector<Article>::iterator it = articles.begin(); it != articles.end(); it++)
    {
        if ((it->wordMap.find(A) != it->wordMap.end()) && (it->wordMap.find(B) != it->wordMap.end()))
        {
            for (std::vector<int>::iterator i = it->wordMap[A].begin(); i != it->wordMap[A].end(); i++)
            {
                std::cout << it->article[*i] << std::endl;
            }
            for (std::vector<int>::iterator i = it->wordMap[B].begin(); i != it->wordMap[B].end(); i++)
            {
                if (it->article[*i].find(A) == std::string::npos)
                {
                    std::cout << it->article[*i] << std::endl;
                }
            }
        }
    }
}

void A_OR_B(std::vector<Article> &articles, std::string A, std::string B)
{
    for (std::vector<Article>::iterator it = articles.begin(); it != articles.end(); it++)
    {
        if (it->wordMap.find(A) != it->wordMap.end())
        {
            for (std::vector<int>::iterator i = it->wordMap[A].begin(); i != it->wordMap[A].end(); i++)
            {
                std::cout << it->article[*i] << std::endl;
            }
        }
        if (it->wordMap.find(B) != it->wordMap.end())
        {
            for (std::vector<int>::iterator i = it->wordMap[B].begin(); i != it->wordMap[B].end(); i++)
            {
                if (it->article[*i].find(A) == std::string::npos)
                {
                    std::cout << it->article[*i] << std::endl;
                }
            }
        }
    }
}

void NOT_A(std::vector<Article> &articles, std::string A)
{
    for (std::vector<Article>::iterator it = articles.begin(); it != articles.end(); it++)
    {
        if (it->wordMap.find(A) == it->wordMap.end())
        {
            for (std::vector<std::string>::iterator i = it->article.begin(); i != it->article.end(); i++)
            {
                std::cout << *i << std::endl;
            }
        }
    }
}