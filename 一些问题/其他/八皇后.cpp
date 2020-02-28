//八皇后问题。在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法

const int eightQueen(bool chess[8][8], int row = 0)
{
    static int caseNum = 0;

    if (row >= 8)
    {
        return 0;
    }

    for (int i = 0; i < 8; i++)
    {
        if (!chess[row][i])
        {
            if (row > 0)
            {
                for (int j = row - 1; j >= 0; j--)
                {
                    for (int k = 0; k < 8; k++)
                    {
                        if (chess[j][k])
                        {
                            if (k == i || (j - row > 0 ? j - row : row - j) == (k - i > 0 ? k - i : i - k))
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
            eightQueen(chess, row + 1);
            chess[row][i] = 0;
            if (row == 7)
            {
                caseNum++;
            }
        }
    next:;
    }

    return caseNum;
}