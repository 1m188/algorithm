/*
问题描述
杨辉三角形又称Pascal三角形，它的第i+1行是(a+b)i的展开式的系数。

　　
它的一个重要性质是：三角形中的每个数字等于它两肩上的数字相加。

　　
下面给出了杨辉三角形的前4行：

　　
   1

　　
  1 1

　　
 1 2 1

　　
1 3 3 1

　　
给出n，输出它的前n行。

输入格式
输入包含一个数n。

输出格式
输出杨辉三角形的前n行。每一行从这一行的第一个数开始依次输出，中间使用一个空格分隔。请不要在前面输出多余的空格。
样例输入
4
样例输出
1
1 1
1 2 1
1 3 3 1
数据规模与约定
1 <= n <= 34。
*/

#include "iostream"
#include "vector"

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<std::vector<int>> vec(n);

    //对每一行操作
    for (int i = 0; i < n; i++)
    {
        //确定该行大小
        vec[i].resize(i + 1);

        //确定首尾的1
        vec[i][0] = 1;
        if (i != 0)
        {
            vec[i][i] = 1;
        }

        //输出首位的1之后进行后面的数字的计算和输出，每个数字都是其两肩上的数字之和
        std::cout << 1 << ' ';
        for (int j = 1; j < i; j++)
        {
            vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
            std::cout << vec[i][j] << ' ';
        }

        //输出末尾的1
        if (i != 0)
        {
            std::cout << 1;
        }
        //换行
        std::cout << std::endl;
    }

    return 0;
}