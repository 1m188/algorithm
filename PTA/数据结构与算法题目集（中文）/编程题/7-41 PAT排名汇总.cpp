/**
 * @file 7-41 PAT排名汇总.cpp
 * @date 2022-05-14
 */

/*
计算机程序设计能力考试（Programming Ability Test，简称PAT）
旨在通过统一组织的在线考试及自动评测方法客观地评判考生的算法设计与程序设计实现能力，
科学的评价计算机程序设计人才，为企业选拔人才提供参考标准（网址http://www.patest.cn）。

每次考试会在若干个不同的考点同时举行，每个考点用局域网，产生本考点的成绩。考试结束后，
各个考点的成绩将即刻汇总成一张总的排名表。

现在就请你写一个程序自动归并各个考点的成绩并生成总排名表。

输入格式:
输入的第一行给出一个正整数N（≤100），代表考点总数。随后给出N个考点的成绩，
格式为：首先一行给出正整数K（≤300），代表该考点的考生总数；
随后K行，每行给出1个考生的信息，包括考号（由13位整数字组成）和得分（为[0,100]区间内的整数），
中间用空格分隔。

输出格式:
首先在第一行里输出考生总数。随后输出汇总的排名表，每个考生的信息占一行，顺序为：
考号、最终排名、考点编号、在该考点的排名。
其中考点按输入给出的顺序从1到N编号。
考生的输出须按最终排名的非递减顺序输出，获得相同分数的考生应有相同名次，并按考号的递增顺序输出。

输入样例:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

输出样例:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 简单题，却有大坑。

首先分组读入排序给一个考场排名，之后总的归并（题目里已经暗示了）一遍，给个排名，
再然后直接输出即可。

大坑：

注意题目里说的考号是   13    位数字！！！！！！！！！！！！！！！！！！！！！！！！

考虑到题目里最多有300个考场，每个考场最多有100名学生，也就是说最多能有30000名学生，
30000个考号，而看例子中给出来的123456789xxxx，空出来的四位显然够不了30000个数字，
也就是说，最多的情况的时候，考号可能最前面有0！！！！！！

那么考虑到13位数字的要求，最后输出的时候如果考号用的是longlong，注意要补0！！！

关键pta里面判定的时候，他还不说是格式错误，他只说是答案错误

照着人家网上的代码调了好久，才找到这个问题，类目 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 考生信息
 */
struct Info {
    long long id; // 考号（13位数字，输出的时候不足的位数记得用0补足！！！）
    int grade;    // 成绩
    int frank;    // 总排名
    int exampl;   // 考场号
    int plrank;   // 考场排名

    /* 重载一些运算符，对于sort默认从小往大排，那这里就是更小的话，成绩更大，
    成绩相同的话，id小的更小 */

    bool operator>(const Info &e) {
        return grade == e.grade ? id > e.id : grade < e.grade;
    }
    bool operator<(const Info &e) {
        return grade == e.grade ? id < e.id : grade > e.grade;
    }
    bool operator==(const Info &e) { return id == e.id && grade == e.grade; }
    bool operator>=(const Info &e) { return !(*this < e); }
    bool operator<=(const Info &e) { return !(*this > e); }
};

vector<vector<Info>> info; // 用来存储各个有序的归并段
vector<Info> ans;          // 最终结果

/**
 * @brief 输入初始化
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0; // 考场数
    cin >> n;

    for (int exampl = 1; exampl <= n; exampl++) {
        int k = 0; // 考场内考生数
        cin >> k;

        vector<Info> vec(k, {0, 0, 0, exampl, 0});
        for (int i = 0; i < k; i++)
            cin >> vec[i].id >> vec[i].grade;

        sort(vec.begin(), vec.end());

        // 考场内学生排名
        vec[0].plrank = 1;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].grade == vec[i - 1].grade)
                vec[i].plrank = vec[i - 1].plrank;
            else
                vec[i].plrank = i + 1;
        }

        info.push_back(move(vec));
    }
}

/**
 * @brief 归并，将所有有序的考场内学生排名归并段归并成一整个排名
 */
void merge() {

    for (auto &vec : info) {

        vector<Info> tans(ans.size() + vec.size());
        merge(ans.begin(), ans.end(), vec.begin(), vec.end(), tans.begin());
        ans = move(tans);
    }

    // 总排名
    ans[0].frank = 1;
    for (int i = 1; i < ans.size(); i++)
        if (ans[i].grade == ans[i - 1].grade)
            ans[i].frank = ans[i - 1].frank;
        else
            ans[i].frank = i + 1;
}

/**
 * @brief 输出
 */
void print() {
    cout << ans.size() << '\n';
    for (const auto &e : ans)
        cout << setw(13) << setfill('0') << e.id << ' ' << e.frank << ' ' << e.exampl << ' ' << e.plrank << '\n';
    // 千万要注意补足不足13位的考号的位数！！！！！！！
    // 干脆下次一律用string得了。。。。。。我不就是想比的快一些吗。。。。。。
}

int main() {
    input();
    merge();
    print();
    return 0;
}