/*
三门悖论

有三扇门，其中两扇门背后没有东西，一扇门背后有汽车，
当你选中一扇门之后，主持人排除了另外两扇门中的一扇没有中奖的门，
问，你应该换门吗？

使用蒙特卡洛模拟，换门的中奖概率约为 2/3，不换门的中奖概率约为 1/3 ，和理论分析一致，换门的中奖概率更高。
*/

function main() {
    const N = 1e8; // 模拟次数
    let a = 0; // 不换门的中奖次数

    for (let i = 0; i < N; i++) {
        let reward = Math.floor(Math.random() * 3);
        let chose = Math.floor(Math.random() * 3);
        if (chose === reward) {
            a++;
        }
    }

    let p1 = a / N; // 不换门的中奖频率
    let p2 = 1 - p1; // 换门的中奖频率
    console.log(`不换门的中奖频率: ${p1}`);
    console.log(`换门的中奖频率: ${p2}`);
    console.log(`换门的中奖频率约为不换门的中奖频率的倍数: ${p2 / p1}`);
}

main()
