#include "iostream"
#include "vector"
int main() //直接模拟就好了
{
    int T = 0;
    std::cin >> T;
    std::vector<int> cardsNum(T, 0);
    for (int i = 0; i < T; i++)
    {
        std::cin >> cardsNum[i];
    }

    for (std::vector<int>::iterator it = cardsNum.begin(); it != cardsNum.end(); it++)
    {
        std::vector<int> cards{};
        for (int i = 0; i < *it; i++)
        {
            cards.push_back(i + 1);
        }
        while (cards.size() >= 2)
        {
            std::cout << cards[0];
            cards.erase(cards.begin());
            int newCard = cards[0];
            cards.erase(cards.begin());
            cards.push_back(newCard);
            if (cards.size() >= 2)
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}