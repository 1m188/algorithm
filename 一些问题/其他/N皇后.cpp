//N皇后，八皇后的推广形式，扩展版本，在NxN格的国际象棋上摆放N个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法

const int NQueen(int N, bool *chess[N], int row = 0) //传入一个长宽均为N的正方形布尔二维数组用来模拟棋盘
{
    if (N <= 0)
    {
        return -1;
    }

    static int caseNum = 0;

    if (row >= N)
    {
        caseNum++;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        if (!chess[row][i])
        {
            if (row > 0)
            {
                for (int r = row - 1; r >= 0; r--)
                {
                    for (int c = 0; c < N; c++)
                    {
                        if (chess[r][c])
                        {
                            if (c == i || (row - r >= 0 ? row - r : r - row) == (i - c >= 0 ? i - c : c - i))
                            {
                                goto next;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
            chess[row][i] = 1;
            NQueen(N, chess, row + 1);
            chess[row][i] = 0;
        }
    next:;
    }

    return caseNum;
}