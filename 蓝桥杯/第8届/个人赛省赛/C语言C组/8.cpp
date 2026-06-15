/*
标题：九宫幻方

    小明最近在教邻居家的小朋友小学奥数，而最近正好讲述到了三阶幻方这个部分，三阶幻方指的是将1~9不重复的填入一个3*3的矩阵当中，使得每一行、每一列和每一条对角线的和都是相同的。

    三阶幻方又被称作九宫格，在小学奥数里有一句非常有名的口诀："二四为肩，六八为足，左三右七，戴九履一，五居其中"，通过这样的一句口诀就能够非常完美的构造出一个九宫格来。

4 9 2
3 5 7
8 1 6

    有意思的是，所有的三阶幻方，都可以通过这样一个九宫格进行若干镜像和旋转操作之后得到。现在小明准备将一个三阶幻方（不一定是上图中的那个）中的一些数抹掉，交给邻居家的小朋友来进行还原，并且希望她能够判断出究竟是不是只有一组解。

    而你，也被小明交付了同样的任务，但是不同的是，你需要写一个程序~

输入格式：
输入仅包含单组测试数据。
每组测试数据为一个3*3的矩阵，其中为0的部分表示被小明抹去的部分。
对于100%的数据，满足给出的矩阵至少能还原出一组可行的三阶幻方。

输出格式：
如果仅能还原出一组可行的三阶幻方，则将其输出，否则输出"Too Many"（不包含引号）。

样例输入
0 7 2
0 5 0
0 3 0

样例输出
6 7 2
1 5 9
8 3 4


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。
*/

/*
 * 解题思路：
 * 三阶幻方只有 8 种（基本型旋转0°/90°/180°/270°，以及翻转后旋转）。
 * 生成全部 8 个幻方，与输入比对，匹配的即为候选。
 * 若有且仅有一个候选，输出；否则输出 "Too Many"。
 */
#include <iostream>
using namespace std;

int base[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};

void rotate(int src[3][3], int dst[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            dst[j][2 - i] = src[i][j];
}

void reflect(int src[3][3], int dst[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            dst[i][2 - j] = src[i][j];
}

bool match(int m[3][3], int in[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (in[i][j] != 0 && in[i][j] != m[i][j])
                return false;
    return true;
}

int main() {
    int input[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> input[i][j];

    int best[3][3];
    int cnt = 0;

    int cur[3][3], tmp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cur[i][j] = base[i][j];

    for (int flip = 0; flip < 2; flip++) {
        int m[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                m[i][j] = cur[i][j];

        for (int rot = 0; rot < 4; rot++) {
            if (match(m, input)) {
                cnt++;
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        best[i][j] = m[i][j];
            }
            rotate(m, tmp);
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    m[i][j] = tmp[i][j];
        }
        reflect(cur, tmp);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cur[i][j] = tmp[i][j];
    }

    if (cnt == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j > 0) cout << " ";
                cout << best[i][j];
            }
            cout << "\n";
        }
    } else {
        cout << "Too Many" << endl;
    }
    return 0;
}
