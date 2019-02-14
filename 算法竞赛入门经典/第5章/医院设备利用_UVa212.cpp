#include "iostream"
#include "queue"
#include "string"
#include "vector"
#include "algorithm"

struct OperatorRoom //手术室
{
    int num;
    int timeToMe;
    bool isPrepare;
    bool isOperator;

    OperatorRoom() : num(0), timeToMe(0), isPrepare(false), isOperator(false) {}
};
struct RestRoom //休息室
{
    int num;
    int timeToMe;
    bool isPrepare;
    bool isRest;

    RestRoom() : num(0), timeToMe(0), isPrepare(false), isRest(false) {}
};
struct Patient //病人
{
    std::string name;
    int timeToMe;
    int operatorNum;
    bool isOperator;
    bool isOperatorToRest;
    bool isRest;

    Patient() : name(""), timeToMe(0), operatorNum(0), isOperator(false), isOperatorToRest(false), isRest(false) {}
};

int main() //没有测试，可能有错
{
    int n = 0, m = 0, T = 0, t1 = 0, t2 = 0, t3 = 0, k = 0, operatorTime = 0, restTime = 0;
    std::cin >> n >> m >> T >> t1 >> t2 >> t3 >> k; //输入

    std::vector<OperatorRoom> operatorRoom(n, OperatorRoom());
    for (int i = 0; i < n; i++)
    {
        operatorRoom[i].num = i + 1;
    }

    std::vector<RestRoom> restRoom(m, RestRoom());
    for (int i = 0; i < m; i++)
    {
        restRoom[i].num = i + 1;
    }

    std::queue<Patient> patientQueue{};
    for (int i = 0; i < k; i++)
    {
        Patient p = Patient();
        std::cin >> p.name;
        patientQueue.push(p);
    }
    std::cin >> operatorTime >> restTime;

    std::vector<Patient> patient{};
    for (int t = 0; !patientQueue.empty(); t++)
    {
        for (std::vector<OperatorRoom>::iterator it = operatorRoom.begin(); it != operatorRoom.end(); it++) //清理手术室
        {
            if (it->isOperator == true && it->timeToMe == operatorTime)
            {
                it->isOperator = false;
                it->timeToMe = 0;
                it->isPrepare = true;
            }
            else if (it->isPrepare == true && it->timeToMe == t2)
            {
                it->isPrepare = false;
                it->timeToMe = 0;
            }
        }

        for (std::vector<RestRoom>::iterator it = restRoom.begin(); it != restRoom.end(); it++) //清理休息室
        {
            if (it->isRest == true && it->timeToMe == restTime)
            {
                it->isRest = false;
                it->timeToMe = 0;
                it->isPrepare = true;
            }
            else if (it->isPrepare == true && it->timeToMe == t3)
            {
                it->isPrepare = false;
                it->timeToMe = 0;
            }
        }

        std::sort(patient.begin(), patient.end(), [&](Patient &a, Patient &b) { return a.operatorNum < b.operatorNum; });
        for (std::vector<Patient>::iterator it = patient.begin(); it != patient.end(); it++) //对病人状态进行调整
        {
            if (it->isOperator == true && it->timeToMe == operatorTime)
            {
                it->isOperator = false;
                it->timeToMe = 0;
                it->isOperatorToRest = true;
            }
            else if (it->isOperatorToRest == true && it->timeToMe == t1)
            {
                it->isOperatorToRest = false;
                it->timeToMe = 0;
                it->isRest = true;
                std::find_if(restRoom.begin(), restRoom.end(), [&](RestRoom &a) { return a.isPrepare == false && a.isRest == false; })->isRest = true;
            }
            else if (it->isRest == true && it->timeToMe == restTime)
            {
                it->isRest = false;
                it->timeToMe = 0;
                patient.erase(it);
                it--;
            }
        }

        for (std::vector<OperatorRoom>::iterator it = std::find_if(operatorRoom.begin(), operatorRoom.end(), [&](OperatorRoom &a) { return a.isOperator == false && a.isPrepare == false; }); it != operatorRoom.end(); it = std::find_if(operatorRoom.begin(), operatorRoom.end(), [&](OperatorRoom &a) { return a.isOperator == false && a.isPrepare == false; })) //推一波人进手术室
        {
            patient.push_back(patientQueue.front());
            patient.back().isOperator = true;
            patient.back().operatorNum = it->num;
            patientQueue.pop();
            it->isOperator = true;
        }

        for (std::vector<OperatorRoom>::iterator it = operatorRoom.begin(); it != operatorRoom.end(); it++) //接下来都是时间流逝
        {
            if (it->isOperator == true || it->isPrepare == true)
            {
                it->timeToMe++;
            }
        }

        for (std::vector<RestRoom>::iterator it = restRoom.begin(); it != restRoom.end(); it++)
        {
            if (it->isPrepare == true || it->isRest == true)
            {
                it->timeToMe++;
            }
        }

        for (std::vector<Patient>::iterator it = patient.begin(); it != patient.end(); it++)
        {
            it->timeToMe++;
        }
    }

    return 0;
}