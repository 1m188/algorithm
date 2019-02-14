#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "algorithm"
#include "iomanip"

struct Player //每个选手的属性
{
    std::string name;
    int place;
    bool isAmateur;
    bool isFoul;
    std::vector<int> score;
    int total;
    double moneyWonRate;
    double moneyWon;

    Player() : name(""), place(0), isAmateur(false), isFoul(false), score(std::vector<int>(4, 0)), total(0), moneyWonRate(0), moneyWon(0) {}
    Player(std::string n, int p, bool i, bool iF, int rd1, int rd2, int rd3, int rd4, int t, double mwr, double m) : name(n), place(p), isAmateur(i), isFoul(iF), score(std::vector<int>{rd1, rd2, rd3, rd4}), total(t), moneyWonRate(mwr), moneyWon(m) {}
};
void Input(std::vector<Player> &players, std::vector<double> &moneyRate, int &totalMoney);   //处理输入
void Print(std::vector<Player> &players);                                                    //处理输出
void Promotion(std::vector<Player> &players, int rnd);                                       //处理晋级
void CalMoney(std::vector<Player> &players, std::vector<double> &moneyRate, int totalMoney); //计算奖金

int main() //没有测试，加之题目又长又复杂还没有给出太多的细节，有些地方无法理解的是按照自己的想法写的，所以有些地方可能与题目要求不符
{
    std::vector<Player> players{};
    std::vector<double> moneyRate{};
    int totalMoney = 0;
    Input(players, moneyRate, totalMoney);

    Promotion(players, 1);
    Promotion(players, 2);
    CalMoney(players, moneyRate, totalMoney);

    Print(players);

    return 0;
}

void Input(std::vector<Player> &players, std::vector<double> &moneyRate, int &totalMoney)
{
    int kcase = 0;
    std::cin >> kcase;
    std::cin >> totalMoney;
    moneyRate.resize(70, 0);
    for (int i = 0; i < 70; i++)
    {
        std::cin >> moneyRate[i];
    }
    int playerNum = 0;
    std::cin >> playerNum;
    players.resize(playerNum, Player());
    for (int i = 0; i < playerNum; i++)
    {
        std::cin >> players[i].name;
        if (players[i].name.back() == '*')
        {
            players[i].isAmateur = true;
            players[i].name.erase(players[i].name.end() - 1);
        }
        std::string score = "";
        std::stringstream ss(nullptr);
        for (int j = 0; j < 4; j++)
        {
            std::cin >> score;
            if (score != "DQ")
            {
                ss = std::stringstream(score);
                ss >> players[i].score[j];
            }
            else
            {
                players[i].isFoul = true;
                for (int k = j; k < 4; k++)
                {
                    players[i].score[k] = 1000;
                }
                break;
            }
        }
        for (int j = 0; j < 4; j++)
        {
            players[i].total += players[i].score[j];
        }
    }
}

void Print(std::vector<Player> &players)
{
    std::sort(players.begin(), players.end(), [&](Player a, Player b) { return a.total > b.total; });
    std::cout << "Player Name Place RD1 RD2 RD3 RD4 TOTAL Money Won\n";
    std::cout << "---------------------------------------------------\n";
    for (std::vector<Player>::iterator it = players.begin(); it != players.end(); it++)
    {
        std::cout << it->name << ' ';
        if (it->isFoul == false)
        {
            if ((it - 1)->place == it->place || (it + 1)->place == it->place)
            {
                std::cout << it->place << 'T';
            }
            else
            {
                std::cout << it->place;
            }
            std::cout << ' ';
        }
        else
        {
            std::cout << ' ' << ' ';
        }
        if (it->isFoul == false)
        {
            for (int i = 0; i < 4; i++)
            {
                std::cout << it->score[i] << ' ';
            }
            std::cout << it->total << ' ';
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                if (it->score[i] == 0)
                {
                    for (int j = i; j < 4; j++)
                    {
                        std::cout << ' ' << ' ';
                    }
                    break;
                }
            }
            std::cout << "DQ" << ' ';
        }
        if (it->place <= 70)
        {
            std::cout << '$';
            std::cout.setf(std::ios::fixed);
            std::setprecision(2);
            std::cout << it->moneyWon;
            std::cout.unsetf(std::ios::fixed);
            std::setprecision(6);
        }
        else
        {
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

void Promotion(std::vector<Player> &players, int rnd)
{
    if (rnd == 1)
    {
        std::sort(players.begin(), players.end(), [&](Player a, Player b) -> bool { return a.score[0] + a.score[1] < b.score[0] + b.score[1]; });

        players[0].place = 1;
        for (int i = 1; i < players.size(); i++)
        {
            if (players[i].total == players[i - 1].total)
            {
                players[i].place = players[i - 1].place;
            }
            else
            {
                players[i].place = players[i - 1].place + 1;
            }
        }

        for (std::vector<Player>::iterator it = players.begin(); it != players.end(); it++)
        {
            if (it->place > 70)
            {
                players.erase(it, players.end());
                break;
            }
        }
    }
    else if (rnd == 2)
    {
        std::sort(players.begin(), players.end(), [&](Player a, Player b) -> bool { return a.total < b.total; });

        players[0].place = 1;
        for (int i = 1; i < players.size(); i++)
        {
            if (players[i].total == players[i - 1].total)
            {
                players[i].place = players[i - 1].place;
            }
            else
            {
                players[i].place = players[i - 1].place + 1;
            }
        }
    }
}

void CalMoney(std::vector<Player> &players, std::vector<double> &moneyRate, int totalMoney)
{
    int i = 0, j = 0;
    for (int k = 1; players[i].place <= 70 && j < moneyRate.size(); k++)
    {
        int m = 0;
        double mwr = 0;
        while (players[i].place == k)
        {
            if (players[i].isAmateur == false)
            {
                mwr += moneyRate[j];
                m++, i++, j++;
            }
            else
            {
                i++;
            }
        }
        mwr /= m;
        for (int n = i - m; n < i; n++)
        {
            if (players[n].isAmateur == false)
            {
                players[n].moneyWonRate = mwr;
            }
        }
    }
    for (std::vector<Player>::iterator it = players.begin(); it != players.end(); it++)
    {
        it->moneyWon = it->moneyWonRate * totalMoney;
    }
}