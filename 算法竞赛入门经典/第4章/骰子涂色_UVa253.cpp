#include "iostream"
#include "string"

std::string Rotate(std::string &cube, int f_up, int f_front, int f_left); //用来把每个骰子旋转方位的函数

int main()
{
    std::string cube1 = "", cube2 = "";
    std::cin >> cube1 >> cube2;

    for (int i = 1; i <= 6; i++) //循环确定旋转骰子之后新的上、前、左面
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j != i && j != 7 - i)
            {
                for (int k = 1; k <= 6; k++)
                {
                    if (k != i && k != 7 - i && k != j && k != 7 - j)
                    {
                        if (cube1 == Rotate(cube2, i, j, k))
                        {
                            std::cout << "Yes\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    std::cout << "No\n";

    return 0;
}

std::string Rotate(std::string &cube, int f_up, int f_front, int f_left)
{
    std::string newCube = "";
    newCube += cube[f_up - 1];
    newCube += cube[f_front - 1];
    newCube += cube[f_left - 1];
    newCube += cube[7 - f_left - 1];
    newCube += cube[7 - f_front - 1];
    newCube += cube[7 - f_up - 1];
    return newCube;
}