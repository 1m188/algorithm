/**
 * @file L2-027 名人堂与代金券.cpp
 * @date 2022-06-12
 */

/*
对于在中国大学MOOC（http://www.icourse163.org/ ）学习“数据结构”课程的学生，想要获得一张合格证书，总评成绩必须达到 60 分及以上，并且有另加福利：总评分在 [G, 100] 区间内者，可以得到 50 元 PAT 代金券；在 [60, G) 区间内者，可以得到 20 元PAT代金券。全国考点通用，一年有效。同时任课老师还会把总评成绩前 K 名的学生列入课程“名人堂”。本题就请你编写程序，帮助老师列出名人堂的学生，并统计一共发出了面值多少元的 PAT 代金券。

输入格式：
输入在第一行给出 3 个整数，分别是 N（不超过 10 000 的正整数，为学生总数）、G（在 (60,100) 区间内的整数，为题面中描述的代金券等级分界线）、K（不超过 100 且不超过 N 的正整数，为进入名人堂的最低名次）。接下来 N 行，每行给出一位学生的账号（长度不超过15位、不带空格的字符串）和总评成绩（区间 [0, 100] 内的整数），其间以空格分隔。题目保证没有重复的账号。

输出格式：
首先在一行中输出发出的 PAT 代金券的总面值。然后按总评成绩非升序输出进入名人堂的学生的名次、账号和成绩，其间以 1 个空格分隔。需要注意的是：成绩相同的学生享有并列的排名，排名并列时，按账号的字母序升序输出。

输入样例：
10 80 5
cy@zju.edu.cn 78
cy@pat-edu.com 87
1001@qq.com 65
uh-oh@163.com 96
test@126.com 39
anyone@qq.com 87
zoe@mit.edu 80
jack@ucla.edu 88
bob@cmu.edu 80
ken@163.com 70
输出样例：
360
1 uh-oh@163.com 96
2 jack@ucla.edu 88
3 anyone@qq.com 87
3 cy@pat-edu.com 87
5 bob@cmu.edu 80
5 zoe@mit.edu 80
代码长度限制
16 KB
时间限制
150 ms
内存限制
64 MB
*/

/* 模拟，计算，注意大小排序，以及，输出格式 */

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string id = string(15, '\0');
    int grade = 0;
    int rank = 0;

    bool operator>(const Node &e) const {
        if (grade != e.grade) return grade > e.grade;
        return id < e.id;
    }
};

vector<Node> vec;
int n = 0, g = 0, k = 0;
int cost = 0;

int main() {

    scanf("%d %d %d", &n, &g, &k);
    vec.resize(n);
    for (Node &e : vec) {
        scanf("%s %d", &e.id[0], &e.grade);
        for (int i = 0; i < 15; i++) {
            if (e.id[i] == '\0') {
                e.id.resize(i);
                break;
            }
        }

        if (e.grade >= 60 && e.grade < g)
            cost += 20;
        else if (e.grade >= g)
            cost += 50;
    }

    printf("%d\n", cost);

    sort(vec.begin(), vec.end(), [](const Node &e1, const Node &e2) {
        return e1 > e2;
    });

    vec[0].rank = 1;
    printf("%d %s %d\n", vec[0].rank, vec[0].id.c_str(), vec[0].grade);
    for (int i = 1; i < n; i++) {
        vec[i].rank = vec[i].grade == vec[i - 1].grade ? vec[i - 1].rank : i + 1;
        if (vec[i].rank > k) break;
        printf("%d %s %d\n", vec[i].rank, vec[i].id.c_str(), vec[i].grade);
    }

    return 0;
}