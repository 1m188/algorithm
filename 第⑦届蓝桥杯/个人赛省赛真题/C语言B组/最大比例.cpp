/*
最大比例

X星球的某个大奖赛设了M级奖励。每个级别的奖金是一个正整数。
并且，相邻的两个级别间的比例是个固定值。
也就是说：所有级别的奖金数构成了一个等比数列。比如：
16,24,36,54
其等比值为：3/2

现在，我们随机调查了一些获奖者的奖金数。
请你据此推算可能的最大的等比值。

输入格式：
第一行为数字 N (0<N<100)，表示接下的一行包含N个正整数
第二行N个正整数Xi(Xi<1 000 000 000 000)，用空格分开。每个整数表示调查到的某人的奖金数额

要求输出：
一个形如A/B的分数，要求A、B互质。表示可能的最大比例系数

测试数据保证了输入格式正确，并且最大比例是存在的。

例如，输入：
3
1250 200 32

程序应该输出：
25/4

再例如，输入：
4
3125 32 32 200

程序应该输出：
5/2

再例如，输入：
3
549755813888 524288 2

程序应该输出：
4/1

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 3000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。
*/

#include "iostream"
#include "vector"
#include "algorithm"

template <typename T>
T Gcd(T a, T b) //辗转相除法，算最大公约数，C++模板
{
    if (a == b)
    {
        return a;
    }
    else
    {
        T big = a > b ? a : b;
        T small = a < b ? a : b;
        T c = big % small;
        while (c)
        {
            big = small;
            small = c;
            c = big % small;
        }
        return small;
    }
}

void MaxRatio(std::vector<long long> &money)
{
    int size = money.size();
    for (int i = 0; i < size - 1; i++)
    {
        long long gcd = Gcd(money[i], money[i + 1]);
        money.push_back(money[i] / gcd);
        money.push_back(money[i + 1] / gcd);
    }
    money.erase(money.begin(), money.begin() + size);
    size = money.size();

    while (size > 2)
    {
        if (static_cast<double>(money[0]) / money[1] == static_cast<double>(money[2]) / money[3]) //恐怕是关键判断条件，我写了两遍都要用这个条件判断，其他的地方能用不同的方法实现的我都尽量用不同的更简单的方法
        {
            break;
        }
        for (int i = 0; i < size - 2; i++)
        {
            long long gcd = Gcd(money[i], money[i + 2]);
            money.push_back(money[i] / gcd);
            money.push_back(money[i + 2] / gcd);
        }
        money.erase(money.begin(), money.begin() + size);
        for (std::vector<long long>::iterator i = money.begin(); i < money.end() - 1; i++) //在保证顺序的前提下去除所有的重复元素
        {
            for (std::vector<long long>::iterator j = i + 1; j < money.end();)
            {
                if (*i == *j)
                {
                    money.erase(j);
                }
                else
                {
                    j++;
                }
            }
        }
        for (std::vector<long long>::iterator it = money.begin(); it != money.end();) //去除所有的1
        {
            if (*it == 1)
            {
                money.erase(it);
            }
            else
            {
                it++;
            }
        }
        size = money.size();
    }
}

int main()
{
    int N = 0;
    std::cin >> N;
    std::vector<long long> money{};
    for (int i = 0; i < N; i++)
    {
        long long n = 0;
        std::cin >> n;
        money.push_back(n);
    }

    std::sort(money.begin(), money.end());                             //algorithm中的方法，从小到大排列一个容器
    std::reverse(money.begin(), money.end());                          //反转容器元素
    money.erase(std::unique(money.begin(), money.end()), money.end()); //unique是一个方法将所有的相邻的重复元素移动到容器末尾并且返回第一个重复的元素的迭代器，由于只能够去除相邻元素的重复，因此使用之前一般都要排序，这样就打乱了顺序，在无关顺序的操作中很好用，之后使用erase擦去所有的重复元素
    MaxRatio(money);

    std::cout << money[0] << '/' << money[1] << std::endl;

    return 0;
}