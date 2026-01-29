/*
基于 C# 的八皇后问题解决方案
*/

bool[][] board = new bool[8][];
for (int i = 0; i < 8; i++)
{
    board[i] = new bool[8];
}
int ans = 0;

bool isOk(int row, int col)
{
    for (int i = 0; i < 8; i++)
        if (board[row][i] || board[i][col]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row, j = col; i < 8 && j < 8; i++, j++)
        if (board[i][j]) return false;
    for (int i = row, j = col; i >= 0 && j < 8; i--, j++)
        if (board[i][j]) return false;
    for (int i = row, j = col; i < 8 && j >= 0; i++, j--)
        if (board[i][j]) return false;
    return true;
}

void calc(int row = 0)
{
    if (row == 8) { ans++; return; }
    for (int col = 0; col < 8; col++)
    {
        if (isOk(row, col))
        {
            board[row][col] = true;
            calc(row + 1);
            board[row][col] = false;
        }
    }
}

calc();
Console.WriteLine(ans); // 92
