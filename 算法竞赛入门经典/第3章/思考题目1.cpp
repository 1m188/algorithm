#include "stdio.h"
#include "vector"
#include "math.h"

const int Num1() //输入一些数，统计个数
{
    int x = 0, num = 0;
    while (scanf("%d", &x))
    {
        num++;
    }
    return num;
}

const int *const Num2() //输入一些数，求最大值、最小值和平均数
{
    int x = 0, num = 0, numNum = 0, max = 0, min = 0, *a = new int[3]{};
    scanf("%d", &x);
    max = min = x;
    num += x;
    numNum++;
    while (scanf("%d", &x))
    {
        num += x;
        numNum++;
        if (x > max)
        {
            max = x;
        }
        if (x < min)
        {
            min = x;
        }
    }
    num /= numNum;
    a[0] = max;
    a[1] = min;
    a[2] = num;
    return a;
}

void Num3() //输入一些数，哪两个数最接近
{
    int x = 0;
    std::vector<int> num;
    while (scanf("%d", &x) && x)
    {
        num.push_back(x);
    }
    int dist = abs(num[0] - num[1]);
    int dist1 = 0, dist2 = 1;
    for (int i = 0; i < num.size() - 1; i++)
    {
        for (int j = i + 1; j < num.size(); j++)
        {
            if (abs(num[i] - num[j]) < dist)
            {
                dist = num[i] - num[j];
                dist1 = i, dist2 = j;
            }
        }
    }
    printf("%d %d\n", num[dist1], num[dist2]);
}

void Num4() //输入一些数，求第二大的值
{
    int x = 0, max = 0, secMax = 0;
    scanf("%d%d", &max, &secMax);
    if (max < secMax)
    {
        int temp = max;
        max = secMax;
        secMax = temp;
    }
    while (scanf("%d", &x) && x)
    {
        if (x > max)
        {
            max = x;
        }
        else if (x < max && x > secMax)
        {
            secMax = x;
        }
    }
    printf("%d\n", secMax);
}

void Num5() //输入一些数，求他们的方差
{
    int x = 0;
    double average = 0.0;
    std::vector<int> num;
    while (scanf("%d", &x) && x)
    {
        num.push_back(x);
        average += x;
    }
    average /= num.size();
    double temp = 0.0;
    for (int i = 0; i < num.size(); i++)
    {
        temp += pow(num[i] - average, 2);
    }
    temp /= num.size();
    printf("%lf\n", temp);
}

void Num6() //输入一些数，统计不超过平均数的个数
{
    int x = 0;
    double average = 0.0;
    std::vector<int> num;
    while (scanf("%d", &x) && x)
    {
        num.push_back(x);
        average += x;
    }
    average /= num.size();
    x = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] < average)
        {
            x++;
        }
    }
    printf("%d\n", x);
}