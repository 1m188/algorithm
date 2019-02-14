#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

void IR(std::vector<std::vector<std::string>> &ex, std::vector<int> R);
void DR(std::vector<std::vector<std::string>> &ex, std::vector<int> R);
void IC(std::vector<std::vector<std::string>> &ex, std::vector<int> C);
void DC(std::vector<std::vector<std::string>> &ex, std::vector<int> C);
void EX(std::vector<std::vector<std::string>> &ex, const std::pair<int, int> f, const std::pair<int, int> s);

int main() //这个程序好麻烦。。。就不运行调试了。。。所以应该是有某些地方和题目要求不符的。。。懒得改了。。
{
    int r = 0, c = 0;
    std::cin >> r >> c;
    std::vector<std::vector<std::string>> ex(r, std::vector<std::string>(c, ""));
    for (std::vector<std::vector<std::string>>::iterator it = ex.begin(); it != ex.end(); it++)
    {
        for (std::vector<std::string>::iterator i = (*it).begin(); i != (*it).end(); i++)
        {
            std::cin >> (*i);
        }
    }
    std::vector<std::vector<std::string>> orginEx(ex);

    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string command = "";
        std::getline(std::cin, command);
        if (command.substr(0, 2) == "EX")
        {
            std::pair<int, int> f{}, s{};
            f.first = command[command.find(' ') + 1] - '0';
            f.second = command[command.find(' ') + 3] - '0';
            s.first = command[command.find(' ') + 5] - '0';
            s.second = command[command.find(' ') + 7] - '0';
            EX(ex, f, s);
        }
        else
        {
            std::string cmd = command.substr(command.find('<') + 1, 2);
            command.erase(command.begin(), command.begin() + command.find('>') + 2);
            int A = command[0] - '0';
            command.erase(command.begin(), command.begin() + 1);
            std::vector<int> rc{};
            for (int i = 0; i < A; i++)
            {
                rc.push_back(command[2 * (i + 1) - 1] - '0');
            }
            if (cmd == "DC")
            {
                DC(ex, rc);
            }
            else if (cmd == "DR")
            {
                DR(ex, rc);
            }
            else if (cmd == "IC")
            {
                IC(ex, rc);
            }
            else if (cmd == "IR")
            {
                IR(ex, rc);
            }
            else
            {
                std::cout << "Wrong Command!\n";
            }
        }
    }

    int q = 0;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        int qr = 0, qc = 0;
        std::cin >> qr >> qc;
        for (std::vector<std::vector<std::string>>::iterator it = ex.begin(); it != ex.end(); it++)
        {
            for (std::vector<std::string>::iterator i = (*it).begin(); i != (*it).end(); i++)
            {
                if (*i == orginEx[qr][qc])
                {
                    std::cout << std::distance(ex.begin(), it) + 1 << std::distance((*it).begin(), i) + 1 << std::endl;
                    goto nextOne;
                }
            }
        }
    nextOne:;
    }

    return 0;
}

void IR(std::vector<std::vector<std::string>> &ex, std::vector<int> R)
{
    int c = ex.size();
    std::sort(R.begin(), R.end());
    while (R.size())
    {
        ex.insert(ex.begin() + R[0] - 1, std::vector<std::string>(c, ""));
        R.erase(R.begin());
        for (std::vector<int>::iterator it = R.begin(); it != R.end(); it++)
        {
            (*it)++;
        }
    }
}

void DR(std::vector<std::vector<std::string>> &ex, std::vector<int> R)
{
    std::sort(R.begin(), R.end());
    while (R.size())
    {
        ex.erase(ex.begin() + R[0] - 1);
        R.erase(R.begin());
        for (std::vector<int>::iterator it = R.begin(); it != R.end(); it++)
        {
            (*it)--;
        }
    }
}

void IC(std::vector<std::vector<std::string>> &ex, std::vector<int> C)
{
    int r = ex.size();
    std::sort(C.begin(), C.end());
    while (C.size())
    {
        for (int i = 0; i < r; i++)
        {
            ex[i].insert(ex[i].begin() + C[0] - 1, std::string(""));
        }
        C.erase(C.begin());
        for (std::vector<int>::iterator it = C.begin(); it != C.end(); it++)
        {
            (*it)++;
        }
    }
}

void DC(std::vector<std::vector<std::string>> &ex, std::vector<int> C)
{
    int r = ex.size();
    std::sort(C.begin(), C.end());
    while (C.size())
    {
        for (int i = 0; i < r; i++)
        {
            ex[i].erase(ex[i].begin() + C[0] - 1);
        }
        C.erase(C.begin());
        for (std::vector<int>::iterator it = C.begin(); it != C.end(); it++)
        {
            (*it)--;
        }
    }
}

void EX(std::vector<std::vector<std::string>> &ex, const std::pair<int, int> f, const std::pair<int, int> s)
{
    std::swap(ex[f.first][f.second], ex[s.first][s.second]);
}