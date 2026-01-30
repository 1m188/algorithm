/*
三门悖论

有三扇门，其中两扇门背后没有东西，一扇门背后有汽车，
当你选中一扇门之后，主持人排除了另外两扇门中的一扇没有中奖的门，
问，你应该换门吗？

使用蒙特卡洛模拟，换门的中奖概率约为 2/3，不换门的中奖概率约为 1/3 ，和理论分析一致，换门的中奖概率更高。
*/

(function () {

    const N: number = 1e7; // 模拟次数
    let win: number = 0; // 不换门中奖次数

    for (let i = 0; i < N; i++) {
        let reward: number = Math.floor(Math.random() * 3); // 随机生成一个中奖门
        let choice: number = Math.floor(Math.random() * 3); // 随机选择一个门

        if (choice === reward) {
            // 如果选中的门就是中奖门，则不换门
            win++;
        }
    }

    let p1: number = win / N; // 不换门中奖概率
    let p2: number = 1 - p1; // 换门中奖概率
    console.log(`不换门中奖频率: ${p1}`);
    console.log(`换门中奖频率: ${p2}`);
    console.log(`换门中奖频率约为不换门中奖频率的倍数: ${p2 / p1}`);

})();
