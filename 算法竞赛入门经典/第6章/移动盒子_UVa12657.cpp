#include "iostream"
#include "list"
#include "algorithm"
int main() //链表
{
    int n = 0, m = 0;
    int kase = 0; //case数

    while (std::cin >> n >> m)
    {
        std::list<int> box{};
        for (int i = 0; i < n; i++)
        {
            box.push_back(i + 1); //初始化，这样可以在数据很大的时候快一些，不必遍历两次
        }

        bool isReverse = false; //用来判断是否反序
        for (int i = 0; i < m; i++)
        {
            int oper = 0;
            std::cin >> oper;
            if (oper == 1)
            {
                int x = 0, y = 0;
                std::cin >> x >> y;
                std::list<int>::iterator X = box.begin(), Y = box.begin();
                for (std::list<int>::iterator it = box.begin(); it != box.end(); it++) //找出x，y的迭代器
                {
                    if (*it == x)
                    {
                        X = it;
                    }
                    else if (*it == y)
                    {
                        Y = it;
                    }
                }

                if (!isReverse) //反序前后的左右是不一样的
                {
                    if (--Y != X)
                    {
                        Y++;
                        box.insert(Y, *X);
                        box.erase(X);
                    }
                }
                else
                {
                    if (++Y != X)
                    {
                        Y--;
                        box.insert(Y, *X);
                        box.erase(X);
                    }
                }
            }
            else if (oper == 2)
            {
                int x = 0, y = 0;
                std::cin >> x >> y;
                std::list<int>::iterator X = box.begin(), Y = box.begin();
                for (std::list<int>::iterator it = box.begin(); it != box.end(); it++)
                {
                    if (*it == x)
                    {
                        X = it;
                    }
                    else if (*it == y)
                    {
                        Y = it;
                    }
                }

                if (!isReverse)
                {
                    Y++;
                }
                else
                {
                    Y--;
                }
                if (Y != X)
                {
                    box.insert(Y, *X);
                    box.erase(X);
                }
            }
            else if (oper == 3)
            {
                int x = 0, y = 0;
                std::cin >> x >> y;
                std::list<int>::iterator X = box.begin(), Y = box.begin();
                for (std::list<int>::iterator it = box.begin(); it != box.end(); it++)
                {
                    if (*it == x)
                    {
                        X = it;
                    }
                    else if (*it == y)
                    {
                        Y = it;
                    }
                }
                std::swap(*X, *Y);
            }
            else if (oper == 4)
            {
                isReverse = !isReverse; //当有某种很耗时的操作的时候可以加个标记而不实际操作，这样可以快一些，但是所有操作都要考虑到标记
            }
        }

        long long prity = 0; //这里注意一下，100000这个大小的话int会溢出，要用long long才行
        if (!isReverse)      //是否反序影响应从前还是从后开始遍历
        {
            for (std::list<int>::iterator it = box.begin(); it != box.end();)
            {
                prity += *it;
                for (int i = 0; i < 2; i++)
                {
                    it++;
                }
            }
        }
        else
        {
            for (std::list<int>::reverse_iterator rit = box.rbegin(); rit != box.rend();)
            {
                prity += *rit;
                for (int i = 0; i < 2; i++)
                {
                    rit++;
                }
            }
        }
        std::cout << "Case " << ++kase << ": " << prity << std::endl;
    }

    return 0;
}