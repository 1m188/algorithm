#include "iostream"
#include "vector"
#include "algorithm"

struct Theme //主题
{
    int tid, num, t0, t, dt;

    Theme() : tid(-1), num(-1), t0(-1), t(-1), dt(-1) {}
};
struct Service //客服
{
    int pid, k;
    std::vector<int> priority;
    Theme working;
    int timeToWorking; //处理主题的时间周期

    Service() : pid(-1), k(-1), priority(std::vector<int>{}), working(Theme()), timeToWorking(-1) {}
};

int main() //强行模拟，感觉题目的意思没怎么看明白，多半有错。我理解的是对每个服务加他的时间，看他的任务是否完成，完成了就把任务数置零，之后遍历所有的客服，如果有多个完成任务的客服就排序之后选新的任务，否则直接选任务，最后的时刻就是最早开始处理的任务和处理所有任务的时间之和
{
    int n = 0;
    std::cin >> n;
    std::vector<Theme> theme(n, Theme());
    for (int i = 0; i < n; i++)
    {
        std::cin >> theme[i].tid >> theme[i].num >> theme[i].t0 >> theme[i].t >> theme[i].dt;
    }

    int m = 0;
    std::cin >> m;
    std::vector<Service> service(m, Service());
    for (int i = 0; i < m; i++)
    {
        std::cin >> service[i].pid >> service[i].k;
        service[i].priority.resize(service[i].k, -1);
        for (int j = 0; j < service[i].k; j++)
        {
            std::cin >> service[i].priority[j];
        }
    }

    int firstT = theme.begin()->t0; //给出最早处理的任务时刻
    for (std::vector<Theme>::iterator it = theme.begin(); it != theme.end(); it++)
    {
        if (it->t0 < firstT)
        {
            firstT = it->t0;
        }
    }
    int t = 0; //处理所有任务的时间
    while (!theme.empty())
    {
        for (std::vector<Service>::iterator it = service.begin(); it != service.end(); it++) //这里对于时间的处理是num个任务要经过num个t时间处理任务以及num-1个dt时间等待任务间隔
        {
            if (it->working.num > 1)
            {
                if (it->timeToWorking == it->working.t + it->working.dt)
                {
                    it->working.num--;
                }
            }
            else
            {
                if (it->timeToWorking == it->working.t)
                {
                    it->working.num--;
                }
            }
            if (it->timeToWorking == it->working.t + it->working.dt || it->timeToWorking == it->working.t)
            {
                it->timeToWorking = 0;
            }
            else
            {
                it->timeToWorking++;
            }
        }

        std::vector<std::vector<Service>::iterator> fre{};
        for (std::vector<Service>::iterator it = service.begin(); it != service.end(); it++) //挑选新任务
        {
            if (it->working.num == 0)
            {
                fre.push_back(it);
            }
        }
        if (fre.size() > 1)
        {
            std::sort(fre.begin(), fre.end(), [&](std::vector<Service>::iterator a, std::vector<Service>::iterator b) {if (a->working.t0 != b->working.t0){return a->working.t0<b->working.t0;} else {return a->working.tid<b->working.tid;} });
            for (std::vector<Service>::iterator it : fre)
            {
                std::vector<Theme>::iterator tempIt = std::find_if(theme.begin(), theme.end(), [&](Theme a) { return a.tid == it->priority[0]; });
                for (int i = 1; tempIt == theme.end() && i < it->priority.size(); i++)
                {
                    tempIt = std::find_if(theme.begin(), theme.end(), [&](Theme a) { return a.tid == it->priority[i]; });
                }
                if (tempIt != theme.end())
                {
                    it->working = *tempIt;
                    theme.erase(tempIt);
                }
                else
                {
                    it->working.num = -1;
                }
            }
        }
        else if (fre.size() == 1)
        {
            std::vector<Theme>::iterator it = std::find_if(theme.begin(), theme.end(), [&](Theme a) { return a.tid == fre[0]->priority[0]; });
            for (int i = 1; it == theme.end() && i < fre[0]->priority.size(); i++)
            {
                it = std::find_if(theme.begin(), theme.end(), [&](Theme a) { return a.tid == fre[0]->priority[i]; });
            }
            if (it != theme.end())
            {
                fre[0]->working = *it;
                theme.erase(it);
            }
            else
            {
                fre[0]->working.num = -1;
            }
        }
        t++;
    }

    std::cout << t + firstT << std::endl;

    return 0;
}