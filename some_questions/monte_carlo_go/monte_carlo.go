/*
在一个边长为2的正方形里面有一个与正方形边相切的半径为1的圆，然后往正方形里面抛一些点，问这些点恰好落在圆里面的概率是多少？

使用蒙特卡洛方法进行模拟
*/

package main

import (
	"fmt"
	"math"
	"math/rand"
)

func main() {
	const N uint64 = 1e8 // 模拟次数
	var n float64 = 1    // 半径
	var cnt uint64 = 0   // 落在圆内的点数

	for range N {
		x := rand.Float64()*2 - 1
		y := rand.Float64()*2 - 1
		distance := math.Sqrt(x*x + y*y)
		if distance <= n {
			cnt++
		}
	}

	fmt.Printf("概率为: %.6f\n", float64(cnt)/float64(N))
	fmt.Printf("期望值: %.6f\n", math.Pi/4)
}
