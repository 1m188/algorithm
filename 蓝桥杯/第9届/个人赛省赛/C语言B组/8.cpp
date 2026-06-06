/*

标题：日志统计

小明维护着一个程序员论坛。现在他收集了一份"点赞"日志，日志共有N行。其中每一行的格式是：

ts id

表示在ts时刻编号id的帖子收到一个"赞"。

现在小明想统计有哪些帖子曾经是"热帖"。如果一个帖子曾在任意一个长度为D的时间段内收到不少于K个赞，小明就认为这个帖子曾是"热帖"。

具体来说，如果存在某个时刻T满足该帖在[T, T+D)这段时间内(注意是左闭右开区间)收到不少于K个赞，该帖就曾是"热帖"。

给定日志，请你帮助小明统计出所有曾是"热帖"的帖子编号。

【输入格式】
第一行包含三个整数N、D和K。
以下N行每行一条日志，包含两个整数ts和id。

对于50%的数据，1 <= K <= N <= 1000
对于100%的数据，1 <= K <= N <= 100000 0 <= ts <= 100000 0 <= id <= 100000

【输出格式】
按从小到大的顺序输出热帖id。每个id一行。

【输入样例】
7 10 2
0 1
0 10
10 10
10 1
9 1
100 3
100 3

【输出样例】
1
3


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

*/

/*
 * 分析：
 *   按 id 分组收集所有时间戳，每组排序后用双指针滑动窗口判断：
 *   若存在窗口内首尾时间差 < D 且窗口内元素数 ≥ K，则为热帖。
 *   时间复杂度 O(N log N)，其中 id ≤ 100000，可用桶 vector<int>[] 分组。
 */

#include "algorithm"
#include "iostream"
#include "vector"

const int MAX_ID = 100000;

std::vector<int> posts[MAX_ID + 1];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, D, K;
    std::cin >> N >> D >> K;

    for (int i = 0; i < N; i++) {
        int ts, id;
        std::cin >> ts >> id;
        posts[id].push_back(ts);
    }

    // 对每个 id 检查是否为热帖
    for (int id = 0; id <= MAX_ID; id++) {
        if (posts[id].empty())
            continue;

        std::vector<int> &ts_list = posts[id];
        std::sort(ts_list.begin(), ts_list.end());

        // 双指针滑动窗口
        int left = 0;
        bool hot = false;
        for (int right = 0; right < (int)ts_list.size(); right++) {
            // 移动左指针使得窗口内时间差 < D
            while (ts_list[right] - ts_list[left] >= D) {
                left++;
            }
            // 窗口内元素数 ≥ K 则为热帖
            if (right - left + 1 >= K) {
                hot = true;
                break;
            }
        }

        if (hot) {
            std::cout << id << std::endl;
        }
    }

    return 0;
}
