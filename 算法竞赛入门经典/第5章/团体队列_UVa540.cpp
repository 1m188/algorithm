#include "iostream"
#include "queue"
#include "vector"
#include "string"
#include "algorithm"

void ENQUEUE(const std::vector<std::vector<int>> &teamNumber, std::queue<int> &nowQueue, int x);
void DEQUEUE(std::queue<int> &nowQueue);

int main() //没有测试
{
    int t = 0;
    std::cin >> t;
    std::vector<std::vector<int>> teamNumber(t, std::vector<int>{});
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        while (std::cin >> n && n)
        {
            teamNumber[i].push_back(n);
        }
    }
    std::queue<int> nowQueue{};
    int n = 0;
    while (std::cin >> n && n)
    {
        nowQueue.push(n);
    }

    std::string oper = "";
    while (std::cin >> oper && oper != "STOP")
    {
        if (oper == "ENQUEUE")
        {
            int x = 0;
            std::cin >> x;
            ENQUEUE(teamNumber, nowQueue, x);
        }
        else if (oper == "DEQUEUE")
        {
            DEQUEUE(nowQueue);
        }
    }

    return 0;
}

void ENQUEUE(const std::vector<std::vector<int>> &teamNumber, std::queue<int> &nowQueue, int x)
{
    std::vector<int> temp{};
    std::vector<int> team{};
    for (std::vector<std::vector<int>>::const_iterator it = teamNumber.begin(); it != teamNumber.end(); it++)
    {
        if (std::find(it->begin(), it->end(), x) != it->end())
        {
            team = *it;
            break;
        }
    }
    while (!nowQueue.empty())
    {
        temp.push_back(nowQueue.front());
        nowQueue.pop();
    }
    for (std::vector<int>::const_iterator it = temp.end() - 1; it >= temp.begin(); it--)
    {
        if (std::find(team.begin(), team.end(), *it) != team.end())
        {
            temp.insert(it + 1, x);
            goto end;
        }
    }
    temp.push_back(x);
end:
    for (std::vector<int>::const_iterator it = temp.begin(); it != temp.end(); it++)
    {
        nowQueue.push(*it);
    }
}

void DEQUEUE(std::queue<int> &nowQueue)
{
    int num = nowQueue.front();
    nowQueue.pop();
    std::cout << num << std::endl;
}