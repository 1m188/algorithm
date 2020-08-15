/*

八皇后问题。在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法

*/

#include "cmath"
#include "iostream"
#include "vector"

/**************************************************************************************************************/

// N皇后
class NQueue
{
private:
    // 已存在皇后的坐标
    std::vector<std::pair<int, int>> qp;

    // 总的方案数
    int num = 0;

    // 判定皇后位置是否被允许
    bool isqpok(const std::pair<int, int> &p) const
    {
        for (const auto &e : qp)
            //                   行列检测                                          对角检测
            if (e.first == p.first || e.second == p.second || abs(e.first - p.first) == abs(e.second - p.second))
                return false;

        return true;
    }

    //N皇后
    void nq(const int N, int r = 0)
    {
        if (r >= N)
            num++;

        for (int i = 0; i < N; i++)
        {
            std::pair<int, int> p{i, r};
            if (isqpok(p))
            {
                qp.push_back(p);
                nq(N, r + 1);
                qp.pop_back();
            }
        }
    }

public:
    NQueue() = default;
    ~NQueue() = default;
    NQueue(const NQueue &) = delete;
    NQueue(const NQueue &&) = delete;
    NQueue &operator=(const NQueue &) = delete;
    NQueue &operator=(const NQueue &&) = delete;

    int nQueue(int n)
    {
        if (n <= 0)
            return 0;
        qp.clear();
        num = 0;
        nq(n);
        return num;
    }
};

/**************************************************************************************************************/

int main(int argc, char *argv[])
{
    NQueue nq;

    std::cout << "8 queue: " << nq.nQueue(8) << '\n'
              << "10 queue: " << nq.nQueue(10) << '\n';

    return 0;
}