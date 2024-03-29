/**
 * @file L1-040 最佳情侣身高差.cpp
 * @date 2022-05-19
 */

/*
专家通过多组情侣研究数据发现，最佳的情侣身高差遵循着一个公式：（女方的身高）×1.09 =（男方的身高）。
如果符合，你俩的身高差不管是牵手、拥抱、接吻，都是最和谐的差度。

下面就请你写个程序，为任意一位用户计算他/她的情侣的最佳身高。

输入格式：
输入第一行给出正整数N（≤10），为前来查询的用户数。随后N行，
每行按照“性别 身高”的格式给出前来查询的用户的性别和身高，
其中“性别”为“F”表示女性、“M”表示男性；“身高”为区间 [1.0, 3.0] 之间的实数。

输出格式：
对每一个查询，在一行中为该用户计算出其情侣的最佳身高，保留小数点后2位。

输入样例：
2
M 1.75
F 1.8

输出样例：
1.61
1.96

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* scanf的问题，当类似于  scanf("%d\n", &n);  的代码运行的时候，会输入一个数字，
然后跳过所有的空白字符，并且等待下一个非空白输入，但是后面又没有待输入的变量，所以
等到非空白输入后会直接继续运行。

scanf并不会丢弃回车符等，尤其是在输入的末尾，回车符被保存，在下一行进行字符的输入的时候，
需要跳过回车符。

在scanf格式化字符串里，所有的空白字符（包括空格、回车、tab等）都被看作空白的内容，
表示跳过所有空白字符直到下一个非空白的输入。 */

#include <cstdio>
using namespace std;

int main() {

    int n = 0;
    scanf("%d", &n);

    while (n--) {
        char gender = 0;
        double h = 0;
        scanf(" %c%lf", &gender, &h);

        double ans = gender == 'M' ? h / 1.09 : h * 1.09;

        printf("%.2lf\n", ans);
    }

    return 0;
}