#include "stdio.h"
#include "vector"
int main()
{
    int a = 0, b = 0, c = 0;
    std::vector<double> numList;
    std::vector<int> precision;
    while (scanf("%d%d%d", &a, &b, &c) && (a || b || c))
    {
        if (b)
        {
            numList.push_back(static_cast<double>(a) / b);
            precision.push_back(c);
        }
        else
        {
            numList.push_back(-1);
        }
    }
    for (int i = 0; i < numList.size(); i++)
    {
        printf("Case %d: %.*f\n", i + 1, precision[i], numList[i]);
    }

    return 0;
}