#include "iostream"

bool solve(int &W);//递归

int main()
{
    int T = 0, W = 0;
    std::cin >> T;
    while (T--)
    {
        if (solve(W))
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
        if (T)
        {
            std::cout << '\n';
        }
    }

    return 0;
}

bool solve(int &W)
{
    int W1 = 0, W2 = 0, D1 = 0, D2 = 0;
    bool b1 = true, b2 = true;
    std::cin >> W1 >> D1 >> W2 >> D2;
    if(!W1)//如果左边是子天平的话
    {
        b1 = solve(W1);//递归下一层
    }
    if(!W2)//...右边...
    {
        b2 = solve(W2);
    }
    W = W1 + W2;//上一层的W等于这一层的所有重量，即将子天平的总重计算出来
    return b1 && b2 && (W1 * D1 == W2 * D2);//返回左边平衡？&&右边平衡？&&本层天平平衡？只要有一个不成立就会返回false，则上面的b1胡总和b2就会变成false，最终层层传递，一开始得到的返回值就是false，除非每层都平衡
}