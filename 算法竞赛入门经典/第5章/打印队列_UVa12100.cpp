#include "iostream"
#include "vector"

struct Task
{
    int orginalPlace;
    int priorityClass;

    Task() : orginalPlace(0), priorityClass(0) {}
    Task(int o, int p) : orginalPlace(o), priorityClass(p) {}
};

int main() //直接模拟，要细心
{
    int n = 0;
    std::cin >> n;
    std::vector<Task> tasks(n, Task());
    for (int i = 0; i < n; i++)
    {
        tasks[i].orginalPlace = i;
        std::cin >> tasks[i].priorityClass;
    }
    int attentionPlace = 0;
    std::cin >> attentionPlace;

    int minutes = 0;
    while (true)
    {
        for (std::vector<Task>::iterator it = tasks.begin() + 1; it != tasks.end(); it++)
        {
            if (it->priorityClass > tasks[0].priorityClass)
            {
                tasks.push_back(tasks[0]);
                tasks.erase(tasks.begin());
                it = tasks.begin();
            }
        }
        minutes++;
        if (tasks[0].orginalPlace == attentionPlace)
        {
            break;
        }
        else
        {
            tasks.erase(tasks.begin());
        }
    }
    std::cout << minutes << std::endl;

    return 0;
}