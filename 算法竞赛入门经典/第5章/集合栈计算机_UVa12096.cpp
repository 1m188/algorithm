#include "iostream"
#include "stack"
#include "set"
#include "map"
#include "string"
#include "vector"
#include "algorithm"

int GetIdOfSet(std::map<std::set<int>, int> &idCache, int setId);
void PUSH(std::map<std::set<int>, int> &idCache, std::stack<int> &s);
void DUP(std::map<std::set<int>, int> &idCache, std::stack<int> &s);
void UNION(std::map<std::set<int>, int> &idCache, std::stack<int> &s);
void INTERSECT(std::map<std::set<int>, int> &idCache, std::stack<int> &s);
void ADD(std::map<std::set<int>, int> &idCache, std::stack<int> &s);

int main() //没有测试。想法是把每一种不同的集合做成不同的id，这样就很方便，唯一美中不足的是没有根据id找集合的函数，因为要求并集交集之类的，不过懒得加了，就这样吧.
{
    std::map<std::set<int>, int> idCache{};
    std::stack<int> s{};
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string oper = "";
        std::cin >> oper;
        if (oper == "PUSH")
        {
            PUSH(idCache, s);
        }
        else if (oper == "DUP")
        {
            DUP(idCache, s);
        }
        else if (oper == "UNION")
        {
            UNION(idCache, s);
        }
        else if (oper == "INTERSECT")
        {
            INTERSECT(idCache, s);
        }
        else if (oper == "ADD")
        {
            ADD(idCache, s);
        }
    }

    return 0;
}

int GetIdOfSet(std::map<std::set<int>, int> &idCache, std::set<int> x)
{
    if (idCache.count(x))
    {
        return idCache[x];
    }
    else
    {
        idCache[x] = idCache.size();
        return idCache[x];
    }
}

void PUSH(std::map<std::set<int>, int> &idCache, std::stack<int> &s)
{
    s.push(GetIdOfSet(idCache, std::set<int>{}));
}

void DUP(std::map<std::set<int>, int> &idCache, std::stack<int> &s)
{
    int top = s.top();
    s.push(top);
}

void UNION(std::map<std::set<int>, int> &idCache, std::stack<int> &s)
{
    std::set<int> andSet{};
    int top1 = s.top();
    s.pop();
    std::set<int> temp{};
    for (std::map<std::set<int>, int>::const_iterator it = idCache.begin(); it != idCache.end(); it++)
    {
        if (it->second == top1)
        {
            temp = it->first;
            break;
        }
    }
    for (std::set<int>::const_iterator it = temp.begin(); it != temp.end(); it++)
    {
        andSet.insert(*it);
    }
    int top2 = s.top();
    s.pop();
    temp.clear();
    for (std::map<std::set<int>, int>::const_iterator it = idCache.begin(); it != idCache.end(); it++)
    {
        if (it->second == top2)
        {
            temp = it->first;
            break;
        }
    }
    for (std::set<int>::const_iterator it = temp.begin(); it != temp.end(); it++)
    {
        andSet.insert(*it);
    }
    s.push(GetIdOfSet(idCache, andSet));
}

void INTERSECT(std::map<std::set<int>, int> &idCache, std::stack<int> &s)
{
    std::set<int> temp{};
    std::vector<int> forIntersection{};
    int top = s.top();
    s.pop();
    for (std::map<std::set<int>, int>::const_iterator it = idCache.begin(); it != idCache.end(); it++)
    {
        if (it->second == top)
        {
            temp = it->first;
            break;
        }
    }
    for (std::set<int>::const_iterator it = temp.begin(); it != temp.end(); it++)
    {
        forIntersection.push_back(*it);
    }
    top = s.top();
    s.pop();
    for (std::map<std::set<int>, int>::const_iterator it = idCache.begin(); it != idCache.end(); it++)
    {
        if (it->second == top)
        {
            temp = it->first;
            break;
        }
    }
    for (std::set<int>::const_iterator it = temp.begin(); it != temp.end(); it++)
    {
        forIntersection.push_back(*it);
    }
    std::sort(forIntersection.begin(), forIntersection.end());
    std::set<int> intersection{};
    for (std::vector<int>::iterator it = std::unique(forIntersection.begin(), forIntersection.end()); it != forIntersection.end(); it++)
    {
        intersection.insert(*it);
    }
    s.push(GetIdOfSet(idCache, intersection));
}

void ADD(std::map<std::set<int>, int> &idCache, std::stack<int> &s)
{
    int ftop = s.top();
    s.pop();
    int stop = s.top();
    s.pop();
    std::set<int> fTop{};
    std::set<int> sTop{};
    for (std::map<std::set<int>, int>::const_iterator it = idCache.begin(); it != idCache.end(); it++)
    {
        if (it->second == ftop)
        {
            fTop = it->first;
        }
        else if (it->second == stop)
        {
            sTop = it->first;
        }
    }
    for (std::set<int>::const_iterator it = fTop.begin(); it != fTop.end(); it++)
    {
        sTop.insert(*it);
    }
    s.push(GetIdOfSet(idCache, sTop));
}