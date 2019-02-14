#include "iostream"
#include "vector"
#include "string"

bool IsGuessOver(std::vector<int> &alph)
{
    for (std::vector<int>::iterator it = alph.begin(); it != alph.end(); it++)
    {
        if (*it)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::vector<std::pair<std::string, std::string>> input{};
    int n = 0;
    while (std::cin >> n && n != -1)
    {
        std::string words = "";
        std::cin >> words;
        std::string guess = "";
        std::cin >> guess;
        input.push_back(std::pair<std::string, std::string>(words, guess));
    }

    for (int i = 0; i < input.size(); i++)
    {
        std::vector<int> alph(26, 0);
        int chance = 6;
        for (std::string::iterator its = input[i].first.begin(); its != input[i].first.end(); its++)
        {
            alph[*its - 97]++;
        }
        for (std::string::iterator its = input[i].second.begin(); its != input[i].second.end(); its++)
        {
            if (alph[*its - 97])
            {
                alph[*its - 97] = 0;
            }
            else
            {
                chance--;
            }
            if (!chance)
            {
                std::cout << "Round " << i + 1 << std::endl
                          << "You lose.\n";
                break;
            }
            else if (IsGuessOver(alph))
            {
                std::cout << "Round " << i + 1 << std::endl
                          << "You win.\n";
                break;
            }
            else if (its == input[i].second.end() - 1)
            {
                std::cout << "Round " << i + 1 << std::endl
                          << "You chickened out.\n";
                break;
            }
        }
    }

    return 0;
}