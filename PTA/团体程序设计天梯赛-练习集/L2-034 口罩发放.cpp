/**
 * @file L2-034 口罩发放.cpp
 * @date 2022-06-17
 */

/*
为了抗击来势汹汹的 COVID19 新型冠状病毒，全国各地均启动了各项措施控制疫情发展，其中一个重要的环节是口罩的发放。

某市出于给市民发放口罩的需要，推出了一款小程序让市民填写信息，方便工作的开展。小程序收集了各种信息，包括市民的姓名、身份证、身体情况、提交时间等，但因为数据量太大，需要根据一定规则进行筛选和处理，请你编写程序，按照给定规则输出口罩的寄送名单。

输入格式:
输入第一行是两个正整数 D 和 P（1≤D,P≤30），表示有 D 天的数据，市民两次获得口罩的时间至少需要间隔 P 天。

接下来 D 块数据，每块给出一天的申请信息。第 i 块数据（i=1,⋯,D）的第一行是两个整数 T 
i
​
  和 S 
i
​
 （1≤T 
i
​
 ,S 
i
​
 ≤1000），表示在第 i 天有 T 
i
​
  条申请，总共有 S 
i
​
  个口罩发放名额。随后 T 
i
​
  行，每行给出一条申请信息，格式如下：

姓名 身份证号 身体情况 提交时间
给定数据约束如下：

姓名 是一个长度不超过 10 的不包含空格的非空字符串；
身份证号 是一个长度不超过 20 的非空字符串；
身体情况 是 0 或者 1，0 表示自觉良好，1 表示有相关症状；
提交时间 是 hh:mm，为24小时时间（由 00:00 到 23:59。例如 09:08。）。注意，给定的记录的提交时间不一定有序；
身份证号 各不相同，同一个身份证号被认为是同一个人，数据保证同一个身份证号姓名是相同的。
能发放口罩的记录要求如下：

身份证号 必须是 18 位的数字（可以包含前导0）；
同一个身份证号若在第 i 天申请成功，则接下来的 P 天不能再次申请。也就是说，若第 i 天申请成功，则等到第 i+P+1 天才能再次申请；
在上面两条都符合的情况下，按照提交时间的先后顺序发放，直至全部记录处理完毕或 S 
i
​
  个名额用完。如果提交时间相同，则按照在列表中出现的先后顺序决定。
输出格式:
对于每一天的申请记录，每行输出一位得到口罩的人的姓名及身份证号，用一个空格隔开。顺序按照发放顺序确定。

在输出完发放记录后，你还需要输出有合法记录的、身体状况为 1 的申请人的姓名及身份证号，用空格隔开。顺序按照申请记录中出现的顺序确定，同一个人只需要输出一次。

输入样例:
4 2
5 3
A 123456789012345670 1 13:58
B 123456789012345671 0 13:58
C 12345678901234567 0 13:22
D 123456789012345672 0 03:24
C 123456789012345673 0 13:59
4 3
A 123456789012345670 1 13:58
E 123456789012345674 0 13:59
C 123456789012345673 0 13:59
F F 0 14:00
1 3
E 123456789012345674 1 13:58
1 1
A 123456789012345670 0 14:11
输出样例:
D 123456789012345672
A 123456789012345670
B 123456789012345671
E 123456789012345674
C 123456789012345673
A 123456789012345670
A 123456789012345670
E 123456789012345674
样例解释：
输出中，第一行到第三行是第一天的部分；第四、五行是第二天的部分；第三天没有符合要求的市民；第六行是第四天的部分。最后两行按照出现顺序输出了可能存在身体不适的人员。

代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 模拟，注意细节 */

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct Node {
    string name;
    int lastsucctime = -1;
};

unordered_map<string, Node> ump;
vector<string> problem;
int d = 0, p = 0;

bool judgeid(const string &id) {
    if (id.size() != 18) return false;
    for (const char &c : id)
        if (!isdigit(c)) return false;
    return true;
}

void in_str(string &s) {
    s.resize(20, '\0');
    scanf("%s", &s[0]);
    for (int i = 0; i < 20; i++) {
        if (s[i] == '\0') {
            s.resize(i);
            break;
        }
    }
}

int main() {

    scanf("%d %d", &d, &p);
    for (int i = 0; i < d; i++) {

        int ti = 0, si = 0;
        scanf("%d %d", &ti, &si);
        vector<pair<string, int>> vec;

        while (ti--) {

            string id, name;
            int body = -1, comtime = -1;
            in_str(name), in_str(id);
            scanf("%d", &body);

            int h = 0, m = 0;
            scanf("%d:%d", &h, &m);
            comtime = h * 60 + m;

            // 身份证一定要合法，不合法的都不录入
            if (!judgeid(id)) continue;

            vec.push_back({id, comtime});
            if (ump.find(id) == ump.end())
                ump[id] = {name, -1};
            // 不仅身体要有病，而且还不能重复，前面的条件还有身份证合法
            if (body == 1 && find(problem.begin(), problem.end(), id) == problem.end())
                problem.push_back(id);
        }

        if (si <= 0) continue; // 注意没有口罩的情况

        // sort无论如何也无法保证相对顺序，尤其是考虑到类似于快速排序这种左右穿插的
        // 元素移动方式，这里使用stable sort保证元素之间的相对顺序不变
        stable_sort(vec.begin(), vec.end(), [](const pair<string, int> &e1, const pair<string, int> &e2) {
            return e1.second < e2.second;
        });

        for (auto &e : vec) {
            auto &x = ump[e.first];
            if (x.lastsucctime != -1 && i < x.lastsucctime + p + 1) continue;
            printf("%s %s\n", ump[e.first].name.c_str(), e.first.c_str());
            x.lastsucctime = i;
            if (--si <= 0) break;
        }
    }

    for (const auto &id : problem)
        printf("%s %s\n", ump[id].name.c_str(), id.c_str());

    return 0;
}