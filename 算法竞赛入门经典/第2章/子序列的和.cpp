#include "stdio.h"
#include "math.h"
#include "vector"
int main()
{
    int n = 0, m = 0;
    double num = 0.0;
    std::vector<double> numList = std::vector<double>();
    while (scanf("%d%d", &n, &m) && n && m)
    {
        for (int i = n; i <= m; i++)
        {
            num += 1.0 / pow(i, 2);
        }
        numList.push_back(num);
        num = 0.0;
    }
    for (int i = 0; i < numList.size(); i++)
    {
        printf("Case %d: %.5f\n", i + 1, numList[i]);
    }

    return 0;
}