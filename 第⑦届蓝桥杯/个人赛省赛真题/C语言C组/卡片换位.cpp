/*

卡片换位

你玩过华容道的游戏吗？
这是个类似的，但更简单的游戏。
看下面 3 x 2 的格子

+---+---+---+
| A | * | * |
+---+---+---+
| B |   | * |
+---+---+---+

在其中放5张牌，其中A代表关羽，B代表张飞，* 代表士兵。
还有一个格子是空着的。

你可以把一张牌移动到相邻的空格中去(对角不算相邻)。
游戏的目标是：关羽和张飞交换位置，其它的牌随便在哪里都可以。

输入格式：
输入两行6个字符表示当前的局面

输出格式：
一个整数，表示最少多少步，才能把AB换位（其它牌位置随意）

例如，输入：
* A
**B

程序应该输出：
17

再例如，输入：
A B
***

程序应该输出：
12


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。
*/

#include "iostream"
#include "vector"
#include "string"

int DFS(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> s, const std::pair<int, int> A, const std::pair<int, int> B, bool sign[3][3][3][3][3][3], const std::vector<std::vector<int>> &go, int x = 0)
{ //深度优先搜索（一个新的用法，不仅可以用来做填数之类的题，还可以做路线题目，话说这本来就是图论算法啊）
    static int stepNum = 1000;

    if (x > stepNum) //由于对于2x3的格子估计不会有比1000步更多的了，如果有更多的话一定有比其更小的解法，另外由于是取所有遍历情况最小的一种情况，
    {                //而一开始stepNum又不能够取0（这样每次取最小值会只取到本身），因此需要一个较大的值来为第一次的取最小值做铺垫，
        return 0;    //另外，至于为什么大于了stepNum就return，是为了排除所有比目前的步数更多的解法，
    }                //从而同时取各个遍历中最小的值。至于为什么不把这一段去掉直接在下面取最小值是因为这种办法效率很低，虽然回头路的问题不必担心，但是如果有反复走的情况发生那就要等到递归1000遍以后才会结束，效率太低

    if (a.first == B.first && a.second == B.second && b.first == A.first && b.second == A.second) //判断递归终点情况——交换A，B坐标
    {
        stepNum = x; //由于上面已经排除了所有比目前stepNum更大的数，因此现在的步数如果是解法那一定比目前的stepNum小，可以放心赋值
        return 0;
    }

    if (a.first < 0 || a.first > 2 || a.second < 0 || a.second > 1 || b.first < 0 || b.first > 2 || b.second < 0 || b.second > 1 || s.first < 0 || s.first > 2 || s.second < 0 || s.second > 1 || sign[a.first][a.second][b.first][b.second][s.first][s.second])
    { //判断越界情况，如果有任意坐标超过边界或者是该点已经被标记过，那么结束这次遍历，返回到上一个情况继续
        return 0;
    }

    sign[a.first][a.second][b.first][b.second][s.first][s.second] = 1; //如果判断通过，那么标记这个点，说明这种情况已经出现过，这样可以防止某些反复的情况发生，也可以防止走回头路

    for (int i = 0; i < 4; i++) //对四个方向迭代遍历所有走法
    {
        int newX = s.first + go[i][0];
        int newY = s.second + go[i][1];
        if (newX == a.first && newY == a.second)
        {
            DFS(s, b, a, A, B, sign, go, x + 1);
        }
        else if (newX == b.first && newY == b.second)
        {
            DFS(a, s, b, A, B, sign, go, x + 1);
        }
        else
        {
            DFS(a, b, std::pair<int, int>(newX, newY), A, B, sign, go, x + 1);
        }
    }

    sign[a.first][a.second][b.first][b.second][s.first][s.second] = 0;

    return stepNum;
}

int main()
{
    std::string str = "";
    std::pair<int, int> aPos{}, bPos{}, spacePos{};
    for (int num = 0; num < 2; num++)
    {
        std::getline(std::cin, str);
        for (int i = 0; i < 3; i++)
        {
            if (str[i] == 'A')
            {
                aPos.first = i;
                aPos.second = num;
            }
            else if (str[i] == 'B')
            {
                bPos.first = i;
                bPos.second = num;
            }
            else if (str[i] == ' ')
            {
                spacePos.first = i;
                spacePos.second = num;
            }
        }
    }
    bool sign[3][3][3][3][3][3]{}; //标记，便于递归遍历不走回头路以及对每一种情况的遍历

    const std::vector<std::vector<int>> go{std::vector<int>{0, -1}, std::vector<int>{0, 1}, std::vector<int>{-1, 0}, std::vector<int>{1, 0}}; //上下左右走的时候对xy坐标的操作

    std::cout << DFS(aPos, bPos, spacePos, aPos, bPos, sign, go) << std::endl;

    return 0;
}