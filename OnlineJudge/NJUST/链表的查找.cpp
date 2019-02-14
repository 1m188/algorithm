/*
Description
在B原有的基础上，在链表里对一个id=x的值进行查找，如果链表里存在id=x的值，就输出YES，否则输出NO。

Input
第一行输入一个t，代表t组数据，然后输入一个n，代表n个数，接下来输入n个数，最后再输入一个m，代表m个查询，然后输入m个数（均小于1000）

Output
对于每一个查询输出查询结果

Sample Input
1
5
1 2 3 4 5
3
2 4 6

Sample Output
YES
YES
NO
*/

#include "iostream"
#include "list"
#include "vector"
#include "algorithm"
int main() //WA。怀疑是“在B原有的基础上”这里，我是直接写的，B是什么？
{
    int t = 0;
    std::cin >> t;
    int n = 0;
    std::cin >> n;
    std::vector<std::list<int>> num(t, std::list<int>{});
    for (int i = 0; i < t; i++) //处理输入
    {
        for (int j = 0; j < n; j++)
        {
            int temp = 0;
            std::cin >> temp;
            num[i].push_back(temp);
        }
    }
    int m = 0;
    std::cin >> m;
    std::vector<int> find(m, 0);
    for (int i = 0; i < m; i++)
    {
        std::cin >> find[i];
    }

    for (std::vector<std::list<int>>::iterator itNum = num.begin(); itNum != num.end(); itNum++)
    { //对数组中每一个链表，都查找要查找的所有元素
        for (std::vector<int>::iterator it = find.begin(); it != find.end(); it++)
        {
            if (std::find((*itNum).begin(), (*itNum).end(), *it) != (*itNum).end()) //algorithm里的一个函数find，能够在一个容器中查找相应的元素，如果存在则返回元素的迭代器，否则返回end（）迭代器
            {
                std::cout << "Yes";
            }
            else
            {
                std::cout << "No";
            }
            if (it != find.end() - 1) //格式控制
            {
                std::cout << std::endl;
            }
        }
        if (itNum != num.end() - 1) //格式控制
        {
            std::cout << std::endl;
        }
    }

    return 0;
}