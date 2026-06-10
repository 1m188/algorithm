/*
 *
 * 标题：区间移位
 *
 * 数轴上有 n 个闭区间：D1,...,Dn。
 * 其中区间 Di 用一对整数 [ai, bi] 来描述，满足 ai < bi。
 * 已知这些区间的长度之和至少有 10000。
 * 所以，通过适当的移动这些区间，你总可以使得它们的"并"覆盖 [0, 10000]
 * ——也就是说 [0, 10000] 这个区间内的每一个点都落于至少一个区间内。
 * 你希望找一个移动方法，使得位移差最大的那个区间的位移量最小。
 *
 * 具体来说，假设你将 Di 移动到 [ai+ci, bi+ci] 这个位置。你希望使得
 * max_i {|ci|} 最小。
 *
 * 【输入格式】
 * 输入的第一行包含一个整数 n，表示区间的数量。
 * 接下来有 n 行，每行 2 个整数 ai, bi，以一个空格分开，表示区间 [ai, bi]。
 * 保证区间的长度之和至少是 10000。
 *
 * 【输出格式】
 * 输出一个数字，表示答案。如果答案是整数，只输出整数部分。
 * 如果答案不是整数，输出时四舍五入保留一位小数。
 *
 * 【样例输入】
 * 2
 * 10 5010
 * 4980 9980
 *
 * 【样例输出】
 * 20
 *
 * 【样例说明】
 * 第一个区间往左移动 10；第二个区间往右移动 20。
 *
 * 【样例输入】
 * 4
 * 0 4000
 * 3000 5000
 * 5001 8000
 * 7000 10000
 * 【样例输出】
 * 0.5
 * 【样例说明】
 * 第 2 个区间往右移 0.5；第 3 个区间往左移 0.5 即可。
 *
 * 【数据规模与约定】
 * 对于 30% 的评测用例，1 <= n <= 10；
 * 对于 100% 的评测用例，1 <= n <= 10000，0 <= ai < bi <= 10000。
 *
 *
 * 资源约定：
 * 峰值内存消耗 < 256M
 * CPU 消耗    < 1000ms
 *
 * 请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。
 *
 * 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
 *
 * 注意: main 函数需要返回 0
 * 注意: 只使用 ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
 * 注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>，不能通过工程设置而省略常用头文件。
 *
 * 提交时，注意选择所期望的编译器类型。
 *
 *
 *
 * ============================================================
 * 解法说明：
 *   本题采用「二分答案 + 贪心检测」的经典策略。
 *
 * 1. 二分答案：
 *    答案（最大位移量 d）的可行范围在 [0, 10000] 之间。
 *    由于答案只可能是整数或 .5 的形式（区间端点为整数），
 *    我们将所有坐标和 d 都放大 2 倍，全部使用整数运算，
 *    避免浮点误差。二分查找最小的可行 d（放大 2 倍后的值）。
 *
 * 2. 检测函数 check(d)：
 *    对于给定的最大位移 d（放大 2 倍），判断能否覆盖 [0, 20000]。
 *
 *    每个区间 i 在最大位移 d 的限制下：
 *      - 最早可以被使用的位置（释放时间）：release = ai - d
 *      - 最晚可以覆盖到的位置（截止时间）：deadline = bi + d
 *      - "激活"阈值：threshold = ai + d
 *        （当当前位置 >= threshold 时，该区间可以直接"跳跃"到 deadline）
 *
 *    区间 i 在当前位置 pos 处被使用后，新位置为：
 *      - 若 pos <  threshold：区间从 pos 开始，延伸 len = bi - ai，
 *        即 pos' = pos + len
 *      - 若 pos >= threshold：区间跳跃到 deadline，即 pos' = deadline
 *
 *    贪心策略（类似"最早截止优先" EDF 调度）：
 *      - 将所有区间按 释放时间 排序。
 *      - 维护一个最小堆，堆顶是 deadline 最小的已释放区间。
 *      - 每次从堆中弹出 deadline 最小的区间尝试扩展：
 *        * 若其 deadline <= pos，说明该区间完全在当前位置左侧，丢弃。
 *        * 否则根据 pos 与 threshold 的关系，计算新的 pos。
 *      - 若堆为空时仍未覆盖到 20000，说明当前 d 不可行。
 *      - 这种策略的正确性可以由 EDF 的最优性保证：优先使用截止时间
 *        最紧迫的区间，可以最大程度避免区间"过期"浪费。
 *
 * 3. 输出：
 *    将二分得到的 ans（放大 2 倍的值）还原：
 *      - 若 ans % 2 == 0，输出整数 ans / 2
 *      - 否则输出 ans / 2.0，即一位小数的形式（此时为 .5）。
 * ============================================================
 */

#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

// 区间结构体，包含原始数据和用于检测的计算字段
struct Interval {
    ll a;         // 左端点（已放大 2 倍）
    ll b;         // 右端点（已放大 2 倍）
    ll len;       // 区间长度 = b - a
    ll release;   // 释放时间 = a - d（区间最早能被使用的位置）
    ll threshold; // 激活阈值 = a + d（在此位置之后使用可跳跃至 deadline）
    ll deadline;  // 截止时间 = b + d（区间能覆盖到的最右位置）
};

// 按释放时间升序排序
bool cmpByRelease(const Interval &x, const Interval &y) {
    return x.release < y.release;
}

// 优先队列的比较函数：按截止时间升序（最小堆）
struct CmpDeadline {
    bool operator()(const Interval &x, const Interval &y) const {
        return x.deadline > y.deadline;
    }
};

// 检测给定的最大位移 d（已放大 2 倍）是否能够覆盖 [0, 20000]
// @param d         最大位移量（放大 2 倍）
// @param intervals 区间列表（会修改其排序及计算字段）
// @return          是否能在位移限制 d 下完成覆盖
bool check(ll d, vector<Interval> &intervals) {
    int n = (int)intervals.size();

    // 根据当前 d 计算每个区间的派生字段
    for (int i = 0; i < n; i++) {
        intervals[i].release = intervals[i].a - d;
        intervals[i].deadline = intervals[i].b + d;
        intervals[i].threshold = intervals[i].a + d;
    }

    // 按释放时间排序，便于按顺序将区间加入候选集合
    sort(intervals.begin(), intervals.end(), cmpByRelease);

    ll pos = 0;  // 当前已经连续覆盖到的最右位置
    int idx = 0; // 扫描已排序区间的指针

    // 最小堆：存放所有已释放（可达）但尚未使用的区间，堆顶为截止时间最小者
    priority_queue<Interval, vector<Interval>, CmpDeadline> heap;

    const ll TARGET = 20000; // 覆盖目标（放大 2 倍）

    while (pos < TARGET) {
        // 将所有已释放（其释放时间 <= 当前位置）的区间加入堆中
        while (idx < n && intervals[idx].release <= pos) {
            heap.push(intervals[idx]);
            idx++;
        }

        // 从堆中寻找一个能够扩展当前位置的区间
        bool extended = false;
        while (!heap.empty()) {
            Interval cur = heap.top();
            heap.pop();

            // 该区间的最右可达位置在当前位置之左，无法扩展覆盖，丢弃
            if (cur.deadline <= pos) {
                continue;
            }

            // 根据 pos 与 threshold（ai + d）的大小关系选择扩展方式
            if (pos >= cur.threshold) {
                // 情况 1：当前位置已达到或越过"激活阈值"
                // 区间可以直接跳跃到其最右位置 deadline
                pos = cur.deadline;
            } else {
                // 情况 2：当前位置还在激活阈值之前
                // 区间从 pos 处开始，向右延伸其长度 len
                pos = pos + cur.len;
            }
            extended = true;
            break;
        }

        // 堆中所有区间都无法扩展，说明当前 d 无法完成覆盖
        if (!extended) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        // 将所有坐标值放大 2 倍，全程使用整数运算以避免浮点误差
        intervals[i].a = a * 2;
        intervals[i].b = b * 2;
        intervals[i].len = b * 2 - a * 2;
    }

    // 二分搜索最小的可行位移量 d（放大 2 倍的值）
    // 由于 ai, bi 均在 [0, 10000] 内，最大位移不会超过 10000
    ll left = 0, right = 20000, ans = 20000;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (check(mid, intervals)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // 输出答案：偶数则输出整数，奇数则输出带有 .5 的一位小数
    if (ans % 2 == 0) {
        printf("%lld\n", ans / 2);
    } else {
        printf("%.1f\n", ans / 2.0);
    }

    return 0;
}
