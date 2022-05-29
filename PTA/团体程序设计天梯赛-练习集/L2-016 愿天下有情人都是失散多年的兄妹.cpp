/**
 * @file L2-016 愿天下有情人都是失散多年的兄妹.cpp
 * @date 2022-05-29
 */

/*
呵呵。大家都知道五服以内不得通婚，即两个人最近的共同祖先如果在五代以内（即本人、父母、祖父母、曾祖父母、高祖父母）则不可通婚。本题就请你帮助一对有情人判断一下，他们究竟是否可以成婚？

输入格式：
输入第一行给出一个正整数N（2 ≤ N ≤10 
4
 ），随后N行，每行按以下格式给出一个人的信息：

本人ID 性别 父亲ID 母亲ID
其中ID是5位数字，每人不同；性别M代表男性、F代表女性。如果某人的父亲或母亲已经不可考，则相应的ID位置上标记为-1。

接下来给出一个正整数K，随后K行，每行给出一对有情人的ID，其间以空格分隔。

注意：题目保证两个人是同辈，每人只有一个性别，并且血缘关系网中没有乱伦或隔辈成婚的情况。

输出格式：
对每一对有情人，判断他们的关系是否可以通婚：如果两人是同性，输出Never Mind；如果是异性并且关系出了五服，输出Yes；如果异性关系未出五服，输出No。

输入样例：
24
00001 M 01111 -1
00002 F 02222 03333
00003 M 02222 03333
00004 F 04444 03333
00005 M 04444 05555
00006 F 04444 05555
00007 F 06666 07777
00008 M 06666 07777
00009 M 00001 00002
00010 M 00003 00006
00011 F 00005 00007
00012 F 00008 08888
00013 F 00009 00011
00014 M 00010 09999
00015 M 00010 09999
00016 M 10000 00012
00017 F -1 00012
00018 F 11000 00013
00019 F 11100 00018
00020 F 00015 11110
00021 M 11100 00020
00022 M 00016 -1
00023 M 10012 00017
00024 M 00022 10013
9
00021 00024
00019 00024
00011 00012
00022 00018
00001 00004
00013 00016
00017 00015
00019 00021
00010 00011
输出样例：
Never Mind
Yes
Never Mind
No
Yes
No
Yes
No
No
代码长度限制
16 KB
时间限制
200 ms
内存限制
64 MB
*/

/* 用map保存一个人id和其性别，父母id的映射关系，给出两个id，
需要判断他们五服以内的祖先有没有重复的部分，有则不能结婚，没有
则可以结婚。

需要注意的是，后台输入数据会输入已经是父母的id，也就是说在最开始输入的时候，
给出父母的时候，父母的性别也要设置一下，这样后面的判断不会进入同性结婚的部分，
并且在判断的时候也不会因为map里没有而直接返回false，对于父母的五服可能不够长，
循环里会空转，但最后还是会返回true */

#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/**
 * @brief 保存个人信息
 */
struct Info {
    char gender = 0; // 性别
    int fid = -1,    // 父亲id
        mid = -1;    // 母亲id
};

// 保存 个人id-个人信息 的映射关系
unordered_map<int, Info> ump;

/**
 * @brief 输入
 */
void input() {
    int n = 0;
    scanf("%d", &n);
    getchar();

    while (n--) {
        int id = 0;
        scanf("%d", &id);
        getchar();

        auto &info = ump[id];

        scanf("%c", &info.gender);

        scanf("%d %d", &info.fid, &info.mid);

        /* 注意！！！！  这里需要对父母的性别也要初始化 */
        ump[info.fid].gender = 'M';
        ump[info.mid].gender = 'F';
    }
}

/**
 * @brief 判断两个异性id是否能够结婚
 * @param id1 
 * @param id2 
 * @return true 
 * @return false 
 */
bool judge(int id1, int id2) {

    // 某个id找不到...不行，（或许不加这一句也可以？没试过...）
    if (ump.find(id1) == ump.end() || ump.find(id2) == ump.end())
        return false;

    // 本人判断
    if (id1 == id2)
        return false;

    // 拿个set不断试
    unordered_set<int> uset({id1, id2});

    // 对于五服祖先而言，每一辈的祖先都加入set，每加入一次
    // 则计数，到最后比较set里元素数目和计数的结果，
    // 如果有重复的话set里的元素肯定要少一些
    for (int i = 1; i < 5; i++) {

        int num = 0;
        unordered_set<int> nuset;

        for (const int &id : uset) {

            auto it = ump.find(id);

            if (it == ump.end())
                continue;

            Info &info = it->second;

            if (info.fid != -1) {
                num++;
                nuset.insert(info.fid);
            }
            if (info.mid != -1) {
                num++;
                nuset.insert(info.mid);
            }
        }

        if (nuset.size() != num)
            return false;

        uset.swap(nuset);
    }

    return true;
}

/**
 * @brief 判断计算并输出
 */
void calc() {
    int k = 0;
    scanf("%d", &k);

    while (k--) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);

        Info &infoa = ump[a], &infob = ump[b];

        if (infoa.gender == infob.gender) {
            printf("Never Mind\n");
        } else if (judge(a, b)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

int main() {
    input();
    calc();
    return 0;
}