/*
Description
The expression s!, read as "s factorial," denotes the product of the first s positive integers, where s is nonnegative. So, for example, 
s s! 
0 1 
1 1 
2 2 
3 6 
4 24 
5 120 
10 3628800 

For this problem, you are to write a program that can compute the last non-zero digit of the factorial for s. For example, if your program is asked to compute the last nonzero digit of 5!, your program should produce "2" because 5! = 120, and 2 is the last nonzero digit of 120. 

Input
Input to the program is a series of nonnegative integers, each on its own line with no other letters, digits or spaces. For each integer s, you should read the value and compute the last nonzero digit of s!.

Output
For each integer input, the program should print exactly one line of output containing the single last non-zero digit of s!.

Sample Input
1 
2 
26 
125 
3125 
9999

Sample Output
1
2
4
8
2
8
*/

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

int main() //AC.网上找的思路看不懂...
{
    const std::vector<int> mod{1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2}; //前20个数的阶乘中将5的倍数用1代替的结果

    std::string s = ""; //由于有大数，因此要用字符串处理
    std::vector<std::string> input{};
    while (std::cin >> s && !std::cin.eof()) //输入
    {
        input.push_back(s);
    }

    for (std::vector<std::string>::iterator it = input.begin(); it != input.end(); it++)
    {
        int len = (*it).size();
        std::vector<int> a(len, 0);
        std::reverse((*it).begin(), (*it).end());
        for (int i = 0; i < len; i++) //将每个字符串逆序输入到数组中，并且变成相应的数字
        {
            a[i] = (*it)[i] - '0';
        }

        int c = 0, t = 1;
        while (len) //关键的地方来了...看不懂...
        {
            len -= !a[len - 1];
            t = t * mod[a[1] % 2 * 10 + a[0]] % 10;
            c = 0;
            for (int i = len - 1; i >= 0; i--)
            {
                c = c * 10 + a[i];
                a[i] = c / 5;
                c %= 5;
            }
        }
        std::cout << t << std::endl;
    }

    return 0;
}

/*
另附网上找的思路:

我们设F(N)表示N!的尾数。

先考虑简单的。考虑某一个N!(N < 10)，我们先将所有5的倍数提出来，用1代替原来
5的倍数的位置。由于5的倍数全被提走了，所以这样就不会出现尾数0了。我们先把
0..9的阶乘的尾数列出来（注意，5的倍数的位置上是1），可以得到table[0..9] =
(1, 1, 2, 6, 4, 4, 4, 8, 4, 6)。对于N < 5，直接输出table[N]即可；对于N >
= 5，由于提出了一个5，因此需要一个2与之配成10，即将尾数除以2。注意到除了0
!和1!，阶乘的最后一个非零数字必为偶数，所以有一个很特别的除法规律：2 / 2
= 6，4 / 2 = 2，6 / 2 = 8，8 / 2 =　4。比较特殊的就是2 / 2 = 12 / 2 = 6，
6 / 2 = 16 / 2 = 8。这样我们就可以得到如下式子：
代码:

      table[N]
F(N) = ------------ (0 <= N < 10)
      2^([N/5])

再考虑复杂的。考虑某一个N!(N >= 10)，我们先将所有5的倍数提出来，用1代替原
来5的倍数的位置。由于5的倍数全被提走了，所以这样就不会出现尾数0了。我们观
察一下剩下的数的乘积的尾数，通过table表，我们发现这10个数的乘积的尾数是6，
6 * 6的尾数还是6，因此我们将剩下的数每10个分成一组，则剩下的数的乘积的尾数
只与最后一组的情况有关，即与N的最后一位数字有关。由于我们把5的倍数提出来了
，N!中一次可以提出[N/5]个5的倍数，有多少个5，就需要有多少个2与之配成10，所
以有多少个5，最后就要除以多少个2。注意到除2的结果变化是4个一循环，因此如果
有A个5，只需要除(A MOD 4)次2就可以了。A MOD 4只与A的最后两位数有关，很好求
算。剩下的5的倍数，由于5已经全部处理掉了，就变成[N/5]!。于是，我们可以得到
一个递归关系：
代码:

      F([N/5]) * table[N的尾数] * 6
F(N) = ----------------------------------- (N > 10)
          2^([N/5] MOD 4)

这样我们就得到了一个O(log5(N))的算法，整除5可以用高精度加法做，乘2再除10即
可。整个算法相当巧妙，写起来也比较轻松。
 
 
 
 
因为 2^N 是以4为循环节的
而且table[N]是以10为循环节的
所以从10开始
     F([N/5]) * table[N的尾数] * 6
F(N) = ----------------------------------- (N > 10)
          2^([N/5] MOD 4)
右边的式子除了F[n/5]外 是以20为循环节的
写出循环的末尾数字mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2}
 
整体思路解决了
*/