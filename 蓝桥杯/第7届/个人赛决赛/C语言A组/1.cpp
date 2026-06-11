/*
 * 随意组合
 *
 * 【题目描述】
 *   小明被绑架到X星球的巫师W那里。
 *
 *   其时，W正在玩弄两组数据 (2 3 5 8) 和 (1 4 6 7)
 *   他命令小明从一组数据中分别取数与另一组中的数配对，共配成4对（组中的每个数必被用到）。
 *   小明的配法是：{(8,7),(5,6),(3,4),(2,1)}
 *
 *   巫师凝视片刻，突然说这个配法太棒了！
 *
 *   因为：
 *   每个配对中的数字组成两位数，求平方和，无论正倒，居然相等：
 *   87^2 + 56^2 + 34^2 + 21^2  =  12302
 *   78^2 + 65^2 + 43^2 + 12^2  =  12302
 *
 *   小明想了想说："这有什么奇怪呢，我们地球人都知道，随便配配也可以啊！"
 *   {(8,6),(5,4),(3,1),(2,7)}
 *
 *   86^2 + 54^2 + 31^2 + 27^2 = 12002
 *   68^2 + 45^2 + 13^2 + 72^2 = 12002
 *
 *   巫师顿时凌乱了。。。。。
 *
 *   请你计算一下，包括上边给出的两种配法，巫师的两组数据一共有多少种配对方案具有该特征。
 *   配对方案计数时，不考虑配对的出现次序。
 *   就是说：
 *   {(8,7),(5,6),(3,4),(2,1)}
 *   与
 *   {(5,6),(8,7),(3,4),(2,1)}
 *   是同一种方案。
 *
 *   注意：需要提交的是一个整数，不要填写任何多余内容（比如，解释说明文字等）
 *
 * 【求解思路】
 *   数学化简：(10a+b)² - (10b+a)² = (100a²+20ab+b²) - (100b²+20ab+a²) = 99(a² - b²)
 *   因此条件等价于 Σ(a_i²) = Σ(b_i²)，即第一组元素的平方和等于第二组元素的平方和。
 *
 *   对于给定数据：sumSq({2,3,5,8}) = 4+9+25+64 = 102
 *                 sumSq({1,4,6,7}) = 1+16+36+49 = 102
 *   两者相等，故任意配对方案均满足条件。答案 = 4! = 24。
 *
 *   原代码逻辑正确，但使用 pow(双精度浮点) 配合 == 比较有精度风险，
 *   已改为 long long 整数运算，确保精确无误。
 */

#include <iostream>
#include <vector>

// DFS 枚举所有配对方案（有序配对），统计满足条件的个数
// 最终除以 4! = 24 消去配对顺序，得到不同方案数
int countPairs(const std::vector<std::vector<int>> &data,
               std::vector<std::pair<int, int>> &pair,
               std::vector<std::vector<bool>> &sign,
               int depth = 0) {
    static int orderedCount = 0; // 有序配对中满足条件的计数

    // 4 对全部配好，检查正序和倒序平方和是否相等
    if (depth == 4) {
        long long forward = 0, reverse = 0;
        for (int k = 0; k < 4; k++) {
            int a = pair[k].first, b = pair[k].second;
            int f = a * 10 + b, r = b * 10 + a;
            forward += (long long)f * f;
            reverse += (long long)r * r;
        }
        if (forward == reverse) orderedCount++;
        return 0;
    }

    // 枚举未使用的 (第一组元素, 第二组元素) 配对
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!(sign[0][i] || sign[1][j])) {
                sign[0][i] = 1;
                sign[1][j] = 1;
                pair[depth] = std::pair<int, int>(data[0][i], data[1][j]);
                countPairs(data, pair, sign, depth + 1);
                sign[0][i] = 0;
                sign[1][j] = 0;
            }
        }
    }

    // 有序配对方案数 ÷ 4! = 无序配对方案数
    return orderedCount / 24;
}

int main() {
    const std::vector<std::vector<int>> data{
        std::vector<int>{2, 3, 5, 8},
        std::vector<int>{1, 4, 6, 7}};
    std::vector<std::vector<bool>> sign(2, std::vector<bool>(4, 0));
    std::vector<std::pair<int, int>> pair(4);
    std::cout << countPairs(data, pair, sign) << std::endl;

    return 0;
}
