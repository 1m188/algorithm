/**
 * @file L2-020 功夫传人.cpp
 * @date 2022-06-09
 */

/*
一门武功能否传承久远并被发扬光大，是要看缘分的。一般来说，师傅传授给徒弟的武功总要打个折扣，于是越往后传，弟子们的功夫就越弱…… 直到某一支的某一代突然出现一个天分特别高的弟子（或者是吃到了灵丹、挖到了特别的秘笈），会将功夫的威力一下子放大N倍 —— 我们称这种弟子为“得道者”。

这里我们来考察某一位祖师爷门下的徒子徒孙家谱：假设家谱中的每个人只有1位师傅（除了祖师爷没有师傅）；每位师傅可以带很多徒弟；并且假设辈分严格有序，即祖师爷这门武功的每个第i代传人只能在第i-1代传人中拜1个师傅。我们假设已知祖师爷的功力值为Z，每向下传承一代，就会减弱r%，除非某一代弟子得道。现给出师门谱系关系，要求你算出所有得道者的功力总值。

输入格式：
输入在第一行给出3个正整数，分别是：N（≤10 
5
 ）——整个师门的总人数（于是每个人从0到N−1编号，祖师爷的编号为0）；Z——祖师爷的功力值（不一定是整数，但起码是正数）；r ——每传一代功夫所打的折扣百分比值（不超过100的正数）。接下来有N行，第i行（i=0,⋯,N−1）描述编号为i的人所传的徒弟，格式为：

K 
i
​
  ID[1] ID[2] ⋯ ID[K 
i
​
 ]

其中K 
i
​
 是徒弟的个数，后面跟的是各位徒弟的编号，数字间以空格间隔。K 
i
​
 为零表示这是一位得道者，这时后面跟的一个数字表示其武功被放大的倍数。

输出格式：
在一行中输出所有得道者的功力总值，只保留其整数部分。题目保证输入和正确的输出都不超过10 
10
 。

输入样例：
10 18.0 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
输出样例：
404
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 广度优先搜索求解深度和每个人的功力 */

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    vector<int> tudi;
    double gongli = 0;
    double dedaobeishu = 1;
};

vector<Node> vec;
int n = 0;
double z = 0, r = 0;

void input() {
    scanf("%d %lf %lf", &n, &z, &r);

    vec.resize(n);
    vec[0].gongli = z;

    for (int i = 0; i < n; i++) {
        int ki = 0;
        scanf("%d", &ki);
        if (ki) {
            vec[i].tudi.resize(ki);
            for (auto &e : vec[i].tudi) {
                scanf("%d", &e);
            }
        } else
            scanf("%lf", &vec[i].dedaobeishu);
    }
}

void bfs() {
    double ans = 0;
    queue<int> que({0});
    // 考虑整个门派只有祖师爷一人，并且他本人就是得道者的情况，他的功力应该直接放大
    // （虽然我觉得一开始输入的功力就应该是他自己放大后的功力来着，毕竟功力放大
    // 也是从师父那里继承过来才会放大）
    if (vec[0].tudi.empty()) ans += vec[0].gongli * vec[0].dedaobeishu;
    while (!que.empty()) {
        int shifu = que.front();
        que.pop();

        for (const auto &id : vec[shifu].tudi) {
            vec[id].gongli = vec[shifu].gongli * (1 - r / 100) * vec[id].dedaobeishu;
            if (vec[id].tudi.empty()) ans += vec[id].gongli;

            que.push(id);
        }
    }

    printf("%d", int(ans));
}

int main() {
    input();
    bfs();
    return 0;
}