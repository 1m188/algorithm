/*
标题：拉马车

小的时候，你玩过纸牌游戏吗？
有一种叫做"拉马车"的游戏，规则很简单，却很吸引小朋友。

其规则简述如下：
假设参加游戏的小朋友是A和B，游戏开始的时候，他们得到的随机的纸牌序列如下：
A方：[K, 8, X, K, A, 2, A, 9, 5, A]
B方：[2, 7, K, 5, J, 5, Q, 6, K, 4]

其中的X表示"10"，我们忽略了纸牌的花色。

从A方开始，A、B双方轮流出牌。

当轮到某一方出牌时，他从自己的纸牌队列的头部拿走一张，放到桌上，并且压在最上面一张纸牌上（如果有的话）。

此例中，游戏过程：
A出K，B出2，A出8，B出7，A出X，此时桌上的序列为：

K,2,8,7,X

当轮到B出牌时，他的牌K与桌上的纸牌序列中的K相同，则把包括K在内的以及两个K之间的纸牌都赢回来，放入自己牌的队尾。注意：为了操作方便，放入牌的顺序是与桌上的顺序相反的。
此时，A、B双方的手里牌为：
A方：[K, A, 2, A, 9, 5, A]
B方：[5, J, 5, Q, 6, K, 4, K, X, 7, 8, 2, K]

赢牌的一方继续出牌。也就是B接着出5，A出K，B出J，A出A，B出5，又赢牌了。
5,K,J,A,5
此时双方手里牌：
A方：[2, A, 9, 5, A]
B方：[Q, 6, K, 4, K, X, 7, 8, 2, K, 5, A, J, K, 5]

    注意：更多的时候赢牌的一方并不能把桌上的牌都赢走，而是拿走相同牌点及其中间的部分。但无论如何，都是赢牌的一方继续出牌，有的时候刚一出牌又赢了，也是允许的。

    当某一方出掉手里最后一张牌，但无法从桌面上赢取牌时，游戏立即结束。

    对于本例的初始手牌情况下，最后A会输掉，而B最后的手里牌为：

9K2A62KAX58K57KJ5

    本题的任务就是已知双方初始牌序，计算游戏结束时，赢的一方手里的牌序。当游戏无法结束时，输出-1。

输入为2行，2个串，分别表示A、B双方初始手里的牌序列。
输出为1行，1个串，表示A先出牌，最后赢的一方手里的牌序。

例如，
输入：
96J5A898QA
6278A7Q973

则程序应该输出：
2J9A7QA6Q6889977

再比如，
输入：
25663K6X7448
J88A5KJXX45A

则程序应该输出：
6KAJ458KXAX885XJ645

我们约定，输入的串的长度不超过30

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。

----------------------------

笨笨有话说：
    不断删除前边的，又要后边添加.... 如果用数组，需要开一个大点的，请佛祖保佑在游戏结束前，不会用到数组的边缘。

歪歪有话说：
    反正串也不长，不如每次操作都返回一个新的串。

默默有话说：
    我一般都不吱声，这是典型的队列结构，动态数组最好，没有？自己造一个呗！


解题思路：
用 deque 模拟双方手牌，string 模拟桌面牌。
关键规则：
1. 出牌方从手牌头部取一张放桌面末尾。
2. 若该牌点与桌面已有的某张牌点相同，则将那张牌及其之后的所有牌
   赢回（逆序加入手牌末尾），出牌方继续出牌。
3. 若一方出完手牌且无法赢牌，游戏结束，另一方获胜。
4. 用 set 记录状态检测无限循环。
*/
#include <deque>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    string sa, sb;
    cin >> sa >> sb;

    deque<char> A(sa.begin(), sa.end());
    deque<char> B(sb.begin(), sb.end());
    string table;
    int turn = 0; // 0=A, 1=B
    set<string> seen;

    for (int step = 0; step < 1000000; step++) {
        // 构建状态用于循环检测
        string state;
        for (char c : A)
            state += c;
        state += "|";
        for (char c : B)
            state += c;
        state += "|";
        state += table;
        state += "|";
        state += (char)(turn + '0');
        if (seen.count(state)) {
            cout << -1 << endl;
            return 0;
        }
        seen.insert(state);

        deque<char> &player = (turn == 0 ? A : B);
        deque<char> &opponent = (turn == 0 ? B : A);

        if (player.empty()) {
            // 该出牌时手牌为空，对方获胜
            deque<char> &winner = opponent;
            for (char c : winner)
                cout << c;
            cout << endl;
            return 0;
        }

        // 出牌
        char card = player.front();
        player.pop_front();
        table.push_back(card);

        // 检查桌面上（除最后一张外）是否有相同点数，取最后匹配
        size_t pos = 0;
        bool win = false;
        for (size_t p = 0; p + 1 < table.size(); p++)
            if (table[p] == card) {
                pos = p;
                win = true;
            }

        if (win) {
            // 赢取从 pos 到末尾的所有牌，逆序加入手牌
            string winCards = table.substr(pos);
            table = table.substr(0, pos);
            for (int i = (int)winCards.size() - 1; i >= 0; i--)
                player.push_back(winCards[i]);
            // 赢牌方继续出牌（turn 不变）
        } else {
            // 出完最后一张且无法赢牌 → 游戏结束，对方获胜
            if (player.empty()) {
                for (char c : opponent)
                    cout << c;
                cout << endl;
                return 0;
            }
            turn = 1 - turn;
        }
    }

    cout << -1 << endl;
    return 0;
}
