/*
三门悖论

有三扇门，其中两扇门背后没有东西，一扇门背后有汽车，
当你选中一扇门之后，主持人排除了另外两扇门中的一扇没有中奖的门，
问，你应该换门吗？

使用蒙特卡洛模拟，换门的中奖概率约为 2/3，不换门的中奖概率约为 1/3 ，和理论分析一致，换门的中奖概率更高。
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    const uint64_t N = 1e8; // 模拟次数
    uint64_t a = 0;         // 不换门中奖次数

    srand(time(NULL)); // 设置随机数种子
    for (uint64_t i = 0; i < N; i++) {
        uint64_t car = rand() % 3;    // 随机生成汽车所在门
        uint64_t choose = rand() % 3; // 随机选择一扇门
        a += choose == car;
    }

    double p1 = (double)a / N; // 不换门中奖频率
    double p2 = 1 - p1;        // 换门中奖频率
    printf("不换门中奖频率: %.2f%%\n", p1 * 100);
    printf("换门中奖频率: %.2f%%\n", p2 * 100);
    printf("换门中奖频率约为不换门中奖频率的倍数: %.2f倍\n", p2 / p1);

    return 0;
}
