#include "iostream"
#include "queue"
#include "set"
int main() //做一个优先队列每次取最小值，乘以2、3、5均为丑数，用set看是否和之前的数字重复
{
    const std::vector<int> coeff{2, 3, 5};
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> uglyNum{}; //越大的数优先级越低
    std::set<long long> s{};
    uglyNum.push(1);
    s.insert(1);
    for (int i = 1;; i++)
    {
        long long x = uglyNum.top();
        uglyNum.pop();
        if (i == 1500)
        {
            std::cout << x << std::endl;
            break;
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                long long y = x * coeff[j];
                if (!s.count(y))
                {
                    s.insert(y);
                    uglyNum.push(y);
                }
            }
        }
    }

    return 0;
}