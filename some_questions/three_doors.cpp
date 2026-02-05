/*
三门悖论

有三扇门，其中两扇门背后没有东西，一扇门背后有汽车，
当你选中一扇门之后，主持人排除了另外两扇门中的一扇没有中奖的门，
问，你应该换门吗？

使用蒙特卡洛模拟，换门的中奖概率约为 2/3，不换门的中奖概率约为 1/3 ，和理论分析一致，换门的中奖概率更高。
*/

#include <iomanip>
#include <iostream>
#include <random>

int main() {

    const uint64_t N = 1e8; // 模拟次数
    uint64_t a = 0;         // 不换门中奖次数

    // 随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint64_t> dist(0, 2);

    for (uint64_t i = 0; i < N; i++) {
        uint64_t car = dist(gen);    // 随机生成汽车所在门
        uint64_t choose = dist(gen); // 随机选择一扇门
        a += choose == car;
    }

    double p1 = (double)a / N; // 不换门中奖频率
    double p2 = 1 - p1;        // 换门中奖频率
    std::cout << "不换门中奖频率: " << std::fixed << std::setprecision(2) << p1 * 100 << "%" << std::endl;
    std::cout << "换门中奖频率: " << std::fixed << std::setprecision(2) << p2 * 100 << "%" << std::endl;
    std::cout << "换门中奖频率约为不换门中奖频率的倍数: " << std::fixed << std::setprecision(2) << p2 / p1 << std::endl;

    return 0;
}
