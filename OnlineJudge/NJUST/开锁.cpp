/*
Description
有一天，胡新杰听说鱼头办公室里有一本《魏冬冬难题》，想要去鱼头办公室里去拿，结果因为长得太抽象而被鱼头拒绝，当时胡新杰太饥渴那本书，于是顿时一想，想去偷，结果发现鱼头的锁很特别，锁是由一个环形的的字符串组成的，当然钥匙也是一个环形的只有当锁和钥匙的上的字符一一对应时，门才能打开，钥匙插上后，胡新杰可以旋转钥匙。胡新杰在一个地方配了一把这样的钥匙，现在胡新杰想知道他手上的钥匙能不能打开鱼头的门，拿到《魏冬冬难题》，由于这个时间的原因，所以他想让你帮帮他。

Input
给你 2 个字符串 S1 , S2 ( 0 < 长度 < = 10^6 );(字母在 A ~ Z  );S1表示鱼头锁上面的字符串的相对顺序，S2表示胡新杰手上的钥匙上面的字符串的相对顺序。有多组case，每组case占2行。第一行是S1，第二行是S2。

Output
如果胡新杰手上的钥匙可以打开门，输出YES，否则输出NO。

Sample Input
ABCA
AABC
AC
AB

Sample Output
YES
NO
*/

#include "iostream"
#include "string"
int main()
{
    std::string s1 = "";
    std::cin >> s1;
    std::string s2 = "";
    std::cin >> s2;

    if (s1.size() == s2.size())
    {
        int size = s2.size();
        for (int i = 0; i < s2.size(); i++)
        {
            if (!size)
            {
                std::cout << "No\n";
                return 0;
            }
            else if (s2[i] != s1[i])
            {
                char a = s2[0];
                s2.erase(s2.begin());
                s2 += a;
                size--;
                i = -1;
            }
        }
        std::cout << "Yes\n";
    }

    return 0;
}