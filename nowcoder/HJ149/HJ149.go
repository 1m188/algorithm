/*
HJ149 数水坑

描述
由于降雨，水在农夫约翰的田地里积聚成水坑。田地是一个
N
×
M
N×M 的矩形网格，每个格子要么是水 `W`，要么是干地 `.`。
若两个水格子在 八连通 （上下左右及四条对角线）意义下互达，则它们属于同一个水坑。
给出田地示意图，计算水坑数量。
输入描述：
第一行输入两个整数
N
,
M
(
1
≦
N
,
M
≦
100
)
N,M(1≦N,M≦100)。
接下来
N
N 行，每行
M
M 个字符组成的字符串，字符集为 `W` 与 `.`，中间无空格。
输出描述：
输出一行一个整数，即水坑的数量。
示例1
输入：
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
复制
输出：
3
复制
说明：
共有三个水塘：一个在左上角，一个在左下角，还有一个沿着右侧。
*/

package main

import (
	"fmt"
)

func main() {

	N, M := 0, 0
	fmt.Scan(&N, &M)
	grid := make([][]byte, N)
	for i := 0; i < N; i++ {
		grid[i] = make([]byte, M)
		var s string
		fmt.Scan(&s)
		copy(grid[i], []byte(s))
	}

	flags := make([][]bool, N)
	for i := 0; i < N; i++ {
		flags[i] = make([]bool, M)
	}

	var dfs func(x, y int)
	dfs = func(x, y int) {
		for i := -1; i <= 1; i++ {
			for j := -1; j <= 1; j++ {
				if i == 0 && j == 0 {
					continue
				}
				nx, ny := x+i, y+j
				if nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == 'W' && !flags[nx][ny] {
					flags[nx][ny] = true
					dfs(nx, ny)
				}
			}
		}
	}

	var ans int
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			if grid[i][j] == 'W' && !flags[i][j] {
				ans++
				flags[i][j] = true
				dfs(i, j)
			}
		}
	}

	fmt.Println(ans)
}
