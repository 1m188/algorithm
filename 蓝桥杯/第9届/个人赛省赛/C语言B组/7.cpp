/*

标题：螺旋折线

如图p1.png所示的螺旋折线经过平面上所有整点恰好一次。
对于整点(X, Y)，我们定义它到原点的距离dis(X, Y)是从原点到(X, Y)的螺旋折线段的长度。

例如dis(0, 1)=3, dis(-2, -1)=9

给出整点坐标(X, Y)，你能计算出dis(X, Y)吗？

【输入格式】
X和Y

对于40%的数据，-1000 <= X, Y <= 1000
对于70%的数据，-100000 <= X， Y <= 100000
对于100%的数据, -1000000000 <= X, Y <= 1000000000

【输出格式】
输出dis(X, Y)


【样例输入】
0 1

【样例输出】
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
 *   螺旋方向顺序：L, U, R, D，每轮长度递增 1：
 *     第1轮: L1, U1, R2, D2
 *     第2轮: L3, U3, R4, D4
 *     第3轮: L5, U5, R6, D6  ...
 *   第 t 轮各段：
 *     L(2t-1): y = -(t-1), x ∈ [-(t), t-1]
 *     U(2t-1): x = -t,      y ∈ [-(t-1), t]
 *     R(2t):   y = t,       x ∈ [-t, t]
 *     D(2t):   x = t,       y ∈ [-t, t]
 *   第 t 轮起点 (t-1, -(t-1)) 距离 = 4(t-1)^2 + 2(t-1)。
 *
 *   令 k = max(|x|, |y|)，按位置分类：
 *     1. y = -k               → 底部 (L 段)，t = k+1，dis = 4k^2 + 3k - x
 *     2. x = -k  且 y > -k     → 左侧 (U 段)，t = k,  dis = 4(k-1)^2 + y + 5k - 4
 *     3. y = k                → 顶部 (R 段)，t = k,  dis = 4(k-1)^2 + x + 7k - 4
 *     4. x = k                → 右侧 (D 段)，t = k,  dis = 4(k-1)^2 + 9k - y - 4
 *   原点 (0,0) 特殊处理，dis = 0。
 *   答案可达 4×10^18，需用 long long。
 */

#include "cstdlib"
#include "iostream"

int main() {
    long long x, y;
    std::cin >> x >> y;

    if (x == 0 && y == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    long long k = std::llabs(x) > std::llabs(y) ? std::llabs(x) : std::llabs(y);

    long long dis = 0;

    if (y == -k) {
        // 底部：L(2k+1) 段
        long long t = k + 1;
        dis = 4LL * (t - 1) * (t - 1) + 3LL * (t - 1) - x;
    } else if (x == -k) {
        // 左侧：U(2k-1) 段
        long long t = k;
        dis = 4LL * (t - 1) * (t - 1) + y + 5LL * t - 4;
    } else if (y == k) {
        // 顶部：R(2k) 段
        long long t = k;
        dis = 4LL * (t - 1) * (t - 1) + x + 7LL * t - 4;
    } else if (x == k) {
        // 右侧：D(2k) 段
        long long t = k;
        dis = 4LL * (t - 1) * (t - 1) + 9LL * t - y - 4;
    }

    std::cout << dis << std::endl;

    return 0;
}
