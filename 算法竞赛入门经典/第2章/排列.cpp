#include "stdio.h"
#include "vector"

void Permutation(std::vector<int> &num, bool sign[9], int x = 0)
{
    if (x == 6)
    {
        if (static_cast<double>(100 * num[0] + 10 * num[1] + num[2]) / (100 * num[3] + 10 * num[4] + num[5]) != static_cast<double>(1) / 2)
        {
            return;
        }
    }
    else if (x == 9)
    {
        if (static_cast<double>(100 * num[0] + 10 * num[1] + num[2]) / (100 * num[6] + 10 * num[7] + num[8]) == static_cast<double>(1) / 3)
        {
            printf("%d %d %d\n", 100 * num[0] + 10 * num[1] + num[2], 100 * num[3] + 10 * num[4] + num[5], 100 * num[6] + 10 * num[7] + num[8]);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (!sign[i])
        {
            sign[i] = 1;
            num.push_back(i + 1);
            Permutation(num, sign, x + 1);
            sign[i] = 0;
            num.pop_back();
        }
    }
}

int main()
{
    std::vector<int> num;
    bool sign[9]{};
    Permutation(num, sign);

    return 0;
}