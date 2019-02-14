/*
Description
给出三个点，求所能确定的外接圆的圆心和半径

Input
第一行输入测试个数n
接下来n行每行输入三个点p1,p2,p3 ,分别表示为坐标p1.x,p1.y,p2.x,p2.y,p3.x,p3.y

Output
如果三点共线，输出“no such a circle”；反之，输出圆心坐标和半径（保留两位小数）（数与数之间用一个空格分开，如下的测试用例）

控制两位小数输出的方法：
(c++)
#include < iomanip >（注意去掉空格！）
double d;
cout << setiosflags(ios::fixed) << setprecision(2) << d << endl;
或 printf("%.2lf\n",d);

Sample Input
2
0 0 1 0 0 1
0 0 1 1 2 2

Sample Output
0.50 0.50 0.71
no such a circle

Hint
控制两位小数输出的方法：
(c++)
double d;
cout<
*/

#include "cstdio"
#include "vector"
#include "cmath"
int main()
{
    int n = 0;
    scanf("%d", &n);
    std::vector<std::pair<int, int>> point{};
    for (int num = 0; num < n; num++)
    {
        int x = 0, y = 0;
        for (int i = 0; i < 3; i++)
        {
            scanf("%d%d", &x, &y);
            point.push_back(std::pair<int, int>(x, y));
        }
    }

    while (!point.empty())
    {
        if ((point[0].first - point[1].first == 0 && point[2].first == point[1].first) || (static_cast<double>(point[0].second - point[1].second) / (point[0].first - point[1].first) * (point[2].first - point[0].first) == point[2].second - point[0].second))
        {
            printf("no such a circle\n");
        }
        else
        {
            double a = pow(pow(point[0].first - point[1].first, 2) + pow(point[0].second - point[0].second, 2), 0.5);
            double b = pow(pow(point[1].first - point[2].first, 2) + pow(point[1].second - point[2].second, 2), 0.5);
            double c = pow(pow(point[0].first - point[2].first, 2) + pow(point[0].second - point[2].second, 2), 0.5);
            double p = (a + b + c) / 2;
            double S = pow(p * (p - a) * (p - b) * (p - c), 0.5);
            double R = a * b * c / (4 * S);
            double s0_2 = pow(point[0].first, 2) + pow(point[0].second, 2);
            double s1_2 = pow(point[1].first, 2) + pow(point[1].second, 2);
            double s2_2 = pow(point[2].first, 2) + pow(point[2].second, 2);
            double x0 = ((s0_2 - s1_2) * (point[0].second - point[2].second) - (s0_2 - s2_2) * (point[0].second - point[1].second)) / (2 * (point[0].second - point[2].second) * (point[0].first - point[1].first) - 2 * (point[0].second - point[1].second) * (point[0].first - point[2].first));
            double y0 = ((s0_2 - s1_2) * (point[0].first - point[2].first) - (s0_2 - s2_2) * (point[0].first - point[1].first)) / (2 * (point[0].second - point[1].second) * (point[0].first - point[2].first) - 2 * (point[0].second - point[2].second) * (point[0].first - point[1].first));
            printf("%.2f %.2f %.2f\n", x0, y0, R);
        }
        point.erase(point.begin(), point.begin() + 3);
    }

    return 0;
}