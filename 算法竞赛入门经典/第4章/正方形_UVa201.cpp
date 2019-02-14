#include "iostream"
#include "vector"

int Judge(std::vector<std::vector<bool>> H, std::vector<std::vector<bool>> V, int x); //判断每条边有x个点的时候有几个正方形

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<bool>> H(n, std::vector<bool>(n, false)), V(n, std::vector<bool>(n, false));
    int T = 0;                  //既然书上没有说怎么输入，那我就自己定规则输入了，反正关键在于如何判定正方形以及计数
    std::cin >> T;              //输入有几条水平连线
    for (int i = 0; i < T; i++) //定一个二维点阵，一个用作储存竖直的连线，一个储存水平的的连线，只要两个点都为true则其间有一条连线
    {
        int m = 0, n = 0;
        std::cin >> m >> n;
        H[m - 1][n - 1] = true;
        H[m - 1][n] = true;
    }
    std::cin >> T; //输入有几条竖直连线
    for (int i = 0; i < T; i++)
    {
        int m = 0, n = 0;
        std::cin >> m >> n;
        V[m - 1][n - 1] = true;
        V[m][n - 1] = true;
    }

    int num = 0;
    for (int i = 2; i <= n; i++) //每个正方形由2至x-1个点作为每条边
    {
        num += Judge(H, V, i);
    }
    std::cout << num << std::endl;

    return 0;
}

int Judge(std::vector<std::vector<bool>> H, std::vector<std::vector<bool>> V, int x)
{
    int num = 0;
    int n = H.size();

    for (int i = 0; i < n; i++)
    {
        if (i + x - 1 < n)
        {
            for (int j = 0; j < n; j++)
            {
                if (j + x - 1 < n)
                {
                    bool isOk = true;
                    for (int m = j; m <= j + x - 1; m++)
                    {
                        if (!H[i][m])
                        {
                            isOk = false;
                        }
                    }
                    if (isOk)
                    {
                        for (int m = j; m <= j + x - 1; m++)
                        {
                            if (!H[i + x - 1][m])
                            {
                                isOk = false;
                            }
                        }
                        if (isOk)
                        {
                            for (int m = i; m <= i + x - 1; m++)
                            {
                                if (!V[m][j])
                                {
                                    isOk = false;
                                }
                            }
                            if (isOk)
                            {
                                for (int m = i; m <= i + x - 1; m++)
                                {
                                    if (!V[m][j + x - 1])
                                    {
                                        isOk = false;
                                    }
                                }
                                if (isOk)
                                {
                                    num++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return num;
}