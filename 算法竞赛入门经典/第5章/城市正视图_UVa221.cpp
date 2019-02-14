#include "iostream"
#include "vector"
#include "algorithm"

struct Building //建筑物属性
{
    int num;
    double x, y, width, deepth;
    double height;

    Building() : num(0), x(0), y(0), width(0), deepth(0), height(0) {}
    Building(int n, double X, double Y, double w, double d, double h) : num(n), x(X), y(Y), width(w), deepth(d), height(h) {}
};

int main() //没有测试。离散化，遍历所有的x，但由于x是无限的，所以将x的取值变为x的区间取值，之后判断该坐标南边有没有其他比他高的建筑物，没有则输出并跳到下一个建筑物的判断中，若遍历了建筑物所有的x取值区间还没有一个地方可以露出来的话则该建筑物没有看得见的部分
{
    int n = 0;
    std::cin >> n;
    std::vector<Building> building(n, Building());
    for (int i = 0; i < n; i++)
    {
        std::cin >> building[i].num >> building[i].x >> building[i].y >> building[i].width >> building[i].deepth >> building[i].height;
    }
    std::sort(building.begin(), building.end(), [&](Building a, Building b) -> bool { if (a.x != b.x){return a.x < b.x;}else{return a.y < b.y;} });

    for (std::vector<Building>::iterator it = building.begin(); it != building.end(); it++)
    {
        for (double i = it->x; i <= it->x + it->width; i += 0.1)
        {
            for (std::vector<Building>::iterator j = building.begin(); j != building.end(); j++)
            {
                if (j != it && j->y < it->y && (i >= j->x && i <= j->x + j->width) && j->height > it->height)
                {
                    break;
                }
                else
                {
                    std::cout << it->num << std::endl;
                    goto nextBuilding;
                }
            }
        }
    nextBuilding:;
    }

    return 0;
}