#include "iostream"
#include "vector"
#include "algorithm"

bool Judge(std::vector<std::vector<char>> &board);                                                 //判断是否被将军
bool GgJudge(std::pair<int, int> G, std::pair<int, int> g, std::vector<std::vector<char>> &board); //判断将帅碰面
bool RgJudge(std::pair<int, int> R, std::pair<int, int> g, std::vector<std::vector<char>> &board); //判断车将军
bool HgJudge(std::pair<int, int> H, std::pair<int, int> g, std::vector<std::vector<char>> &board); //判断马将军
bool CgJudge(std::pair<int, int> C, std::pair<int, int> g, std::vector<std::vector<char>> &board); //判断炮将军

int main() //代码庞杂，恕不测试
{
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<char>> board(10, std::vector<char>(9, ' '));
    std::pair<int, int> g{};
    for (std::vector<std::vector<char>>::iterator it = board.begin(); it != board.end(); it++)
    {
        for (std::vector<char>::iterator i = (*it).begin(); i != (*it).end(); i++)
        {
            char c = ' ';
            std::cin >> c;
            if (c == 'G' || c == 'R' || c == 'H' || c == 'C' || c == 'g')
            {
                *i = c;
                if (*i == 'g')
                {
                    g.first = std::distance(board.begin(), it);
                    g.second = std::distance((*it).begin(), i);
                }
            }
        }
    }

    if (g.first - 1 >= 0)
    {
        std::vector<std::vector<char>> temp(board);
        std::swap(temp[g.first][g.second], board[g.first - 1][g.second]);
        if (!Judge(temp))
        {
            std::cout << "No\n";
            return 0;
        }
    }
    if (g.first + 1 <= 2)
    {
        std::vector<std::vector<char>> temp(board);
        std::swap(temp[g.first][g.second], board[g.first + 1][g.second]);
        if (!Judge(temp))
        {
            std::cout << "No\n";
            return 0;
        }
    }
    if (g.second - 1 >= 3)
    {
        std::vector<std::vector<char>> temp(board);
        std::swap(temp[g.first][g.second], board[g.first][g.second - 1]);
        if (!Judge(temp))
        {
            std::cout << "No\n";
            return 0;
        }
    }
    if (g.second + 1 <= 5)
    {
        std::vector<std::vector<char>> temp(board);
        std::swap(temp[g.first][g.second], board[g.first][g.second + 1]);
        {
            if (!Judge(temp))
            {
                std::cout << "No\n";
                return 0;
            }
        }
    }
    std::cout << "Yes\n";

    return 0;
}

bool Judge(std::vector<std::vector<char>> &board)
{
    std::pair<int, int> G{}, R{}, H{}, C{}, g{};
    for (std::vector<std::vector<char>>::iterator it = board.begin(); it != board.end(); it++)
    {
        for (std::vector<char>::iterator i = (*it).begin(); i != (*it).end(); i++)
        {
            if (*i == 'G')
            {
                G.first = std::distance(board.begin(), it);
                G.second = std::distance((*it).begin(), i);
            }
            else if (*i == 'R')
            {
                R.first = std::distance(board.begin(), it);
                R.second = std::distance((*it).begin(), i);
            }
            else if (*i == 'H')
            {
                H.first = std::distance(board.begin(), it);
                H.second = std::distance((*it).begin(), i);
            }
            else if (*i == 'C')
            {
                C.first = std::distance(board.begin(), it);
                C.second = std::distance((*it).begin(), i);
            }
            else if (*i == 'g')
            {
                g.first = std::distance(board.begin(), it);
                g.second = std::distance((*it).begin(), i);
            }
        }
    }

    return GgJudge(G, g, board) || RgJudge(R, g, board) || HgJudge(R, g, board) || CgJudge(C, g, board);
}

bool GgJudge(std::pair<int, int> G, std::pair<int, int> g, std::vector<std::vector<char>> &board)
{
    if (G.second != g.second)
    {
        return false;
    }
    else
    {
        for (int i = g.first + 1; i < G.first; i++)
        {
            if (board[i][G.second] != ' ')
            {
                return false;
            }
        }
        return true;
    }
}

bool RgJudge(std::pair<int, int> R, std::pair<int, int> g, std::vector<std::vector<char>> &board)
{
    if (R.first != g.first && R.second != g.second)
    {
        return false;
    }
    else if (R.first == g.first)
    {
        for (int i = std::min(R.second, g.second) + 1; i < std::max(R.second, g.second); i++)
        {
            if (board[R.first][i] != ' ')
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        for (int i = std::min(R.first, g.first) + 1; i < std::max(R.first, g.first); i++)
        {
            if (board[i][R.second] != ' ')
            {
                return false;
            }
        }
        return true;
    }
}

bool HgJudge(std::pair<int, int> H, std::pair<int, int> g, std::vector<std::vector<char>> &board)
{
    std::vector<std::pair<int, int>> hxy{};
    if (H.first - 1 >= 0 && board[H.first - 1][H.second] == ' ')
    {
        if (H.first - 2 >= 0)
        {
            if (H.second - 1 >= 0)
            {
                hxy.push_back(std::pair<int, int>(H.first - 2, H.second - 1));
            }
            if (H.second + 1 <= 8)
            {
                hxy.push_back(std::pair<int, int>(H.first - 2, H.second + 1));
            }
        }
    }
    if (H.second - 1 >= 0 && board[H.first][H.second - 1] == ' ')
    {
        if (H.second - 2 >= 0)
        {
            if (H.first - 1 >= 0)
            {
                hxy.push_back(std::pair<int, int>(H.first - 1, H.second - 2));
            }
            if (H.first + 1 <= 9)
            {
                hxy.push_back(std::pair<int, int>(H.first + 1, H.second - 2));
            }
        }
    }
    if (H.first + 1 <= 9 && board[H.first + 1][H.second] == ' ')
    {
        if (H.first + 2 <= 9)
        {
            if (H.second - 1 >= 0)
            {
                hxy.push_back(std::pair<int, int>(H.first + 2, H.second - 1));
            }
            if (H.second + 1 <= 8)
            {
                hxy.push_back(std::pair<int, int>(H.first + 2, H.second + 1));
            }
        }
    }
    if (H.second + 1 <= 8 && board[H.first][H.second + 1] == ' ')
    {
        if (H.second + 2 <= 8)
        {
            if (H.first - 1 >= 0)
            {
                hxy.push_back(std::pair<int, int>(H.first - 1, H.second + 2));
            }
            if (H.first + 1 <= 9)
            {
                hxy.push_back(std::pair<int, int>(H.first + 1, H.second + 2));
            }
        }
    }

    for (std::vector<std::pair<int, int>>::iterator it = hxy.begin(); it != hxy.end(); it++)
    {
        if (*it == g)
        {
            return true;
        }
    }
    return false;
}

bool CgJudge(std::pair<int, int> C, std::pair<int, int> g, std::vector<std::vector<char>> &board)
{
    if (C.first != g.first && C.second != g.second)
    {
        return false;
    }
    else if (C.first == g.first)
    {
        int num = 0;
        for (int i = std::min(C.second, g.second) + 1; i < std::max(C.second, g.second); i++)
        {
            if (board[C.first][i] != ' ')
            {
                num++;
            }
        }
        if (num == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int num = 0;
        for (int i = std::min(C.first, g.first) + 1; i < std::max(C.first, g.first); i++)
        {
            if (board[i][C.second] != ' ')
            {
                num++;
            }
        }
        if (num == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}