#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

struct Property //每笔订单的信息
{
    int p, q; //数量和价格
    int num;  //第num条指令

    Property() : p(-1), q(-1), num(-1) {}
};
void BUY(std::vector<Property> &buyList, std::vector<Property> &sellList, Property &buy, std::pair<int, int> &supply);   //买订单
void SELL(std::vector<Property> &buyList, std::vector<Property> &sellList, Property &sell, std::pair<int, int> &supply); //卖订单
void CANCEL(std::vector<Property> &buyList, std::vector<Property> &sellList, int i);                                     //取消订单

int main() //虽说是强行模拟，但感觉题目的意思没有领会清楚...
{
    std::vector<Property> buyList{}, sellList{};
    std::pair<int, int> supply{0, 0}; //供需
    std::string oper = "";
    for (int i = 0;; i++)
    {
        std::cin >> oper;
        if (oper == "END")
        {
            break;
        }
        else if (oper == "BUY")
        {
            Property buy = Property();
            std::cin >> buy.p >> buy.q;
            buy.num = i + 1;
            BUY(buyList, sellList, buy, supply);
        }
        else if (oper == "SELL")
        {
            Property sell = Property();
            std::cin >> sell.p >> sell.q;
            sell.num = i + 1;
            SELL(buyList, sellList, sell, supply);
        }
        else if (oper == "CANCEL")
        {
            int i = 0;
            std::cin >> i;
            CANCEL(buyList, sellList, i);
        }
    }

    return 0;
}

void BUY(std::vector<Property> &buyList, std::vector<Property> &sellList, Property &buy, std::pair<int, int> &supply)
{
    buyList.push_back(buy);
    supply.second += buy.p;
    std::sort(buyList.begin(), buyList.end(), [&](Property &a, Property &b) { return a.num < b.num; });
    std::sort(sellList.begin(), sellList.end(), [&](Property &a, Property &b) {if (a.q!=b.q){return a.q<b.q;}else {return a.num<b.num;} });
    for (std::vector<Property>::iterator it = buyList.begin(); it != buyList.end();)
    {
        if (it->q > sellList.begin()->q)
        {
            int minP = it->p < sellList.begin()->p ? it->p : sellList.begin()->p;
            supply.first -= minP;
            supply.second -= minP;
            buyList.erase(it);
            sellList.erase(sellList.begin());
        }
        else
        {
            it++;
        }
    }
}

void SELL(std::vector<Property> &buyList, std::vector<Property> &sellList, Property &sell, std::pair<int, int> &supply)
{
    sellList.push_back(sell);
    supply.first += sell.p;
    std::sort(sellList.begin(), sellList.end(), [&](Property &a, Property &b) { return a.num < b.num; });
    std::sort(buyList.begin(), buyList.end(), [&](Property &a, Property &b) {if (a.q!=b.q){return a.q>b.q;}else {return a.num<b.num;} });
    for (std::vector<Property>::iterator it = sellList.begin(); it != sellList.end();)
    {
        if (buyList.begin()->q > it->q)
        {
            int minP = it->p < buyList.begin()->p ? it->p : buyList.begin()->p;
            supply.first -= minP;
            supply.second -= minP;
            sellList.erase(it);
            buyList.erase(buyList.begin());
        }
        else
        {
            it++;
        }
    }
}

void CANCEL(std::vector<Property> &buyList, std::vector<Property> &sellList, int i)
{
    for (std::vector<Property>::iterator it = buyList.begin(); it != buyList.end();)
    {
        if (it->num == i)
        {
            buyList.erase(it);
        }
        else
        {
            it++;
        }
    }
    for (std::vector<Property>::iterator it = sellList.begin(); it != sellList.end();)
    {
        if (it->num == i)
        {
            sellList.erase(it);
        }
        else
        {
            it++;
        }
    }
}