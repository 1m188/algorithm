/*
三门悖论

有三扇门，其中两扇门背后没有东西，一扇门背后有汽车，
当你选中一扇门之后，主持人排除了另外两扇门中的一扇没有中奖的门，
问，你应该换门吗？

使用蒙特卡洛模拟，不换门中奖频率约为 1/3 ，换门中奖频率约为 2/3 ，与理论相符。
*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	const N uint64 = 1e8 // 总共模拟次数
	var a uint64         // 不换门中奖次数

	for range N {
		reward := rand.Intn(3) // 随机生成一个中奖门
		chose := rand.Intn(3)  // 随机生成一个选择门

		// 如果刚好中奖，则不换门中奖次数加1
		if chose == reward {
			a++
		}
	}

	f1 := float64(a) / float64(N)
	f2 := float64(N-a) / float64(N)
	fmt.Printf("不换门中奖频率: %f\n", f1)
	fmt.Printf("换门中奖频率: %f\n", f2)
	fmt.Printf("换门中奖频率约为不换门中奖频率的: %f倍\n", f2/f1)
}
