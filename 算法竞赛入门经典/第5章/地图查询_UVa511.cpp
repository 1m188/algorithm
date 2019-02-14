#include "iostream"
#include "vector"
#include "string"
#include "cmath"
#include "algorithm"

struct Map //地图信息
{
    std::string name;             //名字
    double rate;                  //比例
    double s;                     //面积
    std::pair<double, double> p1; //两个输入的点之一
    std::pair<double, double> p2; //...之二
    int postalClass;              //详细程度
    double centerToQueryPlace;    //地图中心到查询地点的距离
    double queryPlaceToRightDown; //地图右下角到查询地点的距离

    Map() : name(""), rate(0), s(0), p1(std::pair<double, double>{}), p2(std::pair<double, double>{}), postalClass(0), centerToQueryPlace(0), queryPlaceToRightDown(0) {}
};
struct Place //查询地点信息
{
    std::string name; //名字
    double x, y;      //坐标

    Place() : name(""), x(0), y(0) {}
};
void Query(const std::vector<Map> &map, const std::vector<Place> &place, const std::pair<std::string, int> &queryPlace); //查询函数

int main() //没有测试，假设左下角为（0，0）点，强行模拟
{
    int n = 0;
    std::cin >> n;
    std::vector<Map> map(n, Map());
    for (int i = 0; i < n; i++) //地图输入
    {
        std::cin >> map[i].name >> map[i].p1.first >> map[i].p1.second >> map[i].p2.first >> map[i].p2.second;
        map[i].rate = fabs(map[i].p1.second - map[i].p2.second) / fabs(map[i].p1.first - map[i].p2.first);
        map[i].s = fabs(map[i].p1.second - map[i].p2.second) * fabs(map[i].p1.first - map[i].p2.first);
    }

    int m = 0;
    std::cin >> m;
    std::vector<Place> place(m, Place());
    for (int i = 0; i < m; i++) //地点输入
    {
        std::cin >> place[i].name >> place[i].x >> place[i].y;
    }

    int q = 0;
    std::cin >> q;
    for (int i = 0; i < q; i++) //查询地点输入
    {
        std::pair<std::string, int> queryPlace{};
        std::cin >> queryPlace.first >> queryPlace.second;
        Query(map, place, queryPlace); //查询
    }

    return 0;
}

void Query(const std::vector<Map> &map, const std::vector<Place> &place, const std::pair<std::string, int> &queryPlace)
{ //这个地方其实是直接按照题目的意思来的，强行的模拟每一种情况，有很多次排序和删除，应该有更加高效的算法
    std::vector<Place>::const_iterator placeInfo = std::find_if(place.begin(), place.end(), [&](Place a) { return a.name == queryPlace.first; });

    if (placeInfo == place.end())
    {
        std::cout << "query illegal.\n";
    }
    else
    {
        std::vector<Map> queryMap{};

        for (std::vector<Map>::const_iterator it = map.begin(); it != map.end(); it++)
        {
            if (it->p1.first < it->p2.first ? it->p1.first : it->p2.first <= placeInfo->x && it->p1.first > it->p2.first ? it->p1.first : it->p2.first >= placeInfo->x && it->p1.second < it->p2.second ? it->p1.second : it->p2.second >= placeInfo->y && it->p1.second > it->p2.second ? it->p1.second : it->p2.second <= placeInfo->y)
            {
                queryMap.push_back(*it);
            }
        }

        if (queryMap.empty() || queryMap.size() > queryPlace.second)
        {
            std::cout << "query illegal.\n";
        }
        else
        {
            std::sort(queryMap.begin(), queryMap.end(), [&](Map a, Map b) { return a.s > b.s; });
            queryMap.begin()->postalClass = 1;
            for (std::vector<Map>::iterator it = queryMap.begin() + 1; it != queryMap.end(); it++)
            {
                if (it->s == (it - 1)->s)
                {
                    it->postalClass = (it - 1)->postalClass;
                }
                else
                {
                    it->postalClass = (it - 1)->postalClass + 1;
                }
            }
            while (queryMap.back().postalClass != queryMap.begin()->postalClass)
            {
                queryMap.erase(queryMap.end() - 1);
            }

            if (queryMap.size() == 1)
            {
                std::cout << queryMap[0].name << std::endl;
            }
            else if (queryMap.size() > 1)
            {
                for (std::vector<Map>::iterator it = queryMap.begin(); it != queryMap.end(); it++)
                {
                    it->centerToQueryPlace = pow(pow(fabs(it->p1.first + it->p2.first) / 2 - placeInfo->x, 2) + pow(fabs(it->p1.second + it->p2.second) / 2 - placeInfo->y, 2), 0.5);
                }
                std::sort(queryMap.begin(), queryMap.end(), [&](Map a, Map b) { return a.centerToQueryPlace < b.centerToQueryPlace; });
                while (queryMap.back().centerToQueryPlace != queryMap.begin()->centerToQueryPlace)
                {
                    queryMap.erase(queryMap.end() - 1);
                }

                if (queryMap.size() == 1)
                {
                    std::cout << queryMap[0].name << std::endl;
                }
                else if (queryMap.size() > 1)
                {
                    std::sort(queryMap.begin(), queryMap.end(), [&](Map a, Map b) { return fabs(1 / a.rate - 0.75) < fabs(1 / b.rate - 0.75); });
                    while (fabs(1 / queryMap.back().rate - 0.75) != fabs(1 / queryMap.begin()->rate - 0.75))
                    {
                        queryMap.erase(queryMap.end() - 1);
                    }

                    if (queryMap.size() == 1)
                    {
                        std::cout << queryMap[0].name << std::endl;
                    }
                    else if (queryMap.size() > 1)
                    {
                        for (std::vector<Map>::iterator it = queryMap.begin(); it != queryMap.end(); it++)
                        {
                            double rightDownX = it->p1.first > it->p2.first ? it->p1.first : it->p2.first;
                            double rightDownY = it->p1.second < it->p2.second ? it->p1.second : it->p2.second;
                            it->queryPlaceToRightDown = pow(pow(placeInfo->x - rightDownX, 2) + pow(placeInfo->y - rightDownY, 2), 0.5);
                        }
                        std::sort(queryMap.begin(), queryMap.end(), [&](Map a, Map b) { return a.queryPlaceToRightDown > b.queryPlaceToRightDown; });
                        while (queryMap.back().queryPlaceToRightDown != queryMap.begin()->queryPlaceToRightDown)
                        {
                            queryMap.erase(queryMap.end() - 1);
                        }

                        if (queryMap.size() == 1)
                        {
                            std::cout << queryMap[0].name << std::endl;
                        }
                        else if (queryMap.size() > 1)
                        {
                            std::sort(queryMap.begin(), queryMap.end(), [&](Map a, Map b) { return (a.p1.first < a.p2.first ? a.p1.first : a.p2.first) < (b.p1.first < b.p2.first ? b.p1.first : b.p2.first); });
                            std::cout << queryMap[0].name << std::endl;
                        }
                    }
                }
            }
        }
    }
}