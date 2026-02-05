/*
三门悖论

有三扇门，其中两扇门背后没有东西，一扇门背后有汽车，
当你选中一扇门之后，主持人排除了另外两扇门中的一扇没有中奖的门，
问，你应该换门吗？

使用蒙特卡洛模拟，换门的中奖概率约为 2/3，不换门的中奖概率约为 1/3 ，和理论分析一致，换门的中奖概率更高。
*/

const ulong N = 10_000_000UL; // 模拟次数
ulong a = 0; // 不换门中奖的次数

// 随机数
var random = new Random();

for (ulong i = 0; i < N; i++)
{
    var door = random.Next(1, 4); // 1, 2, 3
    var car = random.Next(1, 4); // 1, 2, 3
    if (door == car) a++;
}

double p1 = a / (double)N; // 不换门中奖的频率
double p2 = 1 - p1; // 换门中奖的频率
Console.WriteLine($"不换门中奖频率: {p1}");
Console.WriteLine($"换门中奖频率: {p2}");
Console.WriteLine($"换门中奖的频率约为不换门中奖的频率的倍数: {p2 / p1}");
