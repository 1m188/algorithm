#include "iostream"
#include "vector"
#include "string"

std::vector<std::pair<int, int>> L(std::vector<std::vector<int>> &board, int player);                             //打印所有当前可以执行的合法操作
int Mrc(std::vector<std::vector<int>> &board, std::pair<int, int> rc, int player);                                //在r，c处下棋，如果没有合法操作则换一方下，保证合法输入
void Q(std::vector<std::vector<int>> &board);                                                                     //退出游戏并且打印棋盘
std::vector<std::pair<int, int>> Judge(std::vector<std::vector<int>> &board, std::pair<int, int> rc, int player); //判断当一个player方的棋下在rc处的时候，有哪些子可以被翻过来

int main() //代码庞杂，懒得测试了...
{
    std::vector<std::vector<int>> board(8, std::vector<int>(8, -1));
    for (std::vector<std::vector<int>>::iterator it = board.begin(); it != board.end(); it++)
    {
        for (std::vector<int>::iterator i = (*it).begin(); i != (*it).end(); i++)
        {
            std::cin >> *i;
        }
    }
    int player = -1;
    std::cin >> player;
    std::string oper = "";
    std::cin >> oper;
    while (oper != "Q")
    {
        if (oper == "L")
        {
            std::vector<std::pair<int, int>> temp(L(board, player));
            if (!temp.empty())
            {
                for (std::vector<std::pair<int, int>>::iterator it = temp.begin(); it != temp.end(); it++)
                {
                    std::cout << '(' << it->first << ',' << it->second << ')' << std::endl;
                }
            }
            else
            {
                std::cout << "No legal move\n";
            }
        }
        else if (oper[0] == 'M')
        {
            player = Mrc(board, std::pair<int, int>{oper[1] - '0', oper[2] - '0'}, player);
        }
        std::cin >> oper;
    }
    Q(board);

    return 0;
}

std::vector<std::pair<int, int>> L(std::vector<std::vector<int>> &board, int player)
{
    std::vector<std::pair<int, int>> xy{};
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == -1)
            {
                if (!Judge(board, std::pair<int, int>{i, j}, player).empty())
                {
                    xy.push_back(std::pair<int, int>{i, j});
                }
            }
        }
    }
    return xy;
}

int Mrc(std::vector<std::vector<int>> &board, std::pair<int, int> rc, int player)
{
    std::vector<std::pair<int, int>> temp(L(board, player));
    if (temp.empty())
    {
        player = !player;
    }
    board[rc.first][rc.second] = player;

    temp = Judge(board, rc, player);
    for (std::vector<std::pair<int, int>>::iterator it = temp.begin(); it != temp.end(); it++)
    {
        board[it->first][it->second] = player;
    }

    return !player;
}

void Q(std::vector<std::vector<int>> &board)
{
    for (std::vector<std::vector<int>>::iterator it = board.begin(); it != board.end(); it++)
    {
        for (std::vector<int>::iterator i = (*it).begin(); i != (*it).end(); i++)
        {
            if (*i == -1)
            {
                std::cout << ' '; //-1代表此处没有下棋
            }
            else if (*i == 0)
            {
                std::cout << 'b'; //0代表黑棋
            }
            else
            {
                std::cout << 'w'; //1代表白棋
            }
        }
        std::cout << std::endl;
    }
}

std::vector<std::pair<int, int>> Judge(std::vector<std::vector<int>> &board, std::pair<int, int> rc, int player)
{
    std::vector<std::pair<int, int>> turnXy{};

    int size = board.size();
    int r = rc.first, c = rc.second;

    int i = r - 1;
    while (i >= 0 && board[i][c] == !player) //向上翻棋
    {
        i--;
    }
    if (i >= 0 && board[i][c] == player)
    {
        for (int k = r - 1; k > i; k--)
        {
            turnXy.push_back(std::pair<int, int>{k, c});
        }
    }

    i = r + 1;
    while (i < size && board[i][c] == !player) //向下翻棋
    {
        i++;
    }
    if (i < size && board[i][c] == player)
    {
        for (int k = r + 1; k < i; k++)
        {
            turnXy.push_back(std::pair<int, int>{k, c});
        }
    }

    i = c - 1;
    while (i >= 0 && board[r][i] == !player) //向左翻棋
    {
        i--;
    }
    if (i >= 0 && board[r][i] == player)
    {
        for (int k = c - 1; k > i; k--)
        {
            turnXy.push_back(std::pair<int, int>{r, k});
        }
    }

    i = c + 1;
    while (i < size && board[r][i] == !player) //向右翻棋
    {
        i++;
    }
    if (i < size && board[r][i] == player)
    {
        for (int k = c + 1; k < i; k++)
        {
            turnXy.push_back(std::pair<int, int>{r, k});
        }
    }

    i = r - 1;
    int j = c - 1;
    while (i >= 0 && j >= 0 && board[i][j] == !player) //向左上翻棋
    {
        i--, j--;
    }
    if (i >= 0 && j >= 0 && board[i][j] == player)
    {
        int m = r - 1, n = c - 1;
        while (m > i && n > j)
        {
            turnXy.push_back(std::pair<int, int>{m, n});
            m--, n--;
        }
    }

    i = r - 1, j = c + 1;
    while (i >= 0 && j < size && board[i][j] == !player) //向右上翻棋
    {
        i--, j++;
    }
    if (i >= 0 && j < size && board[i][j] == player)
    {
        int m = r - 1, n = c + 1;
        while (m > i && n < j)
        {
            turnXy.push_back(std::pair<int, int>{m, n});
            m--, n++;
        }
    }

    i = r + 1, j = c - 1;
    while (i < size && j >= 0 && board[i][j] == !player) //向左下翻棋
    {
        i++, j--;
    }
    if (i < size && j >= 0 && board[i][j] == player)
    {
        int m = r + 1, n = c - 1;
        while (m < i && n > j)
        {
            turnXy.push_back(std::pair<int, int>{m, n});
            m++, n--;
        }
    }

    i = r + 1, j = c + 1;
    while (i < size && j < size && board[i][j] == !player) //向右下翻棋
    {
        i++, j++;
    }
    if (i < size && j < size && board[i][j] == player)
    {
        int m = r + 1, n = c + 1;
        while (m < i && n < j)
        {
            turnXy.push_back(std::pair<int, int>{m, n});
            m++, n++;
        }
    }

    return turnXy;
}