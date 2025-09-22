/*
HJ43 迷宫问题

描述
有一个
h
h 行
w
w 列的网格，我们使用
(
i
,
j
)
(i,j) 表示网格中从上往下数第
i
i 行和从左往右数第
j
j 列的单元格。每个方格要么是可以通过的空方格
‘0’
‘0’ ，要么是不可通过的墙方格
‘1’
‘1’ ，特别的，网格的四周都是墙方格，你可以沿着空方格上下左右随意移动：从
(
x
,
y
)
(x,y) 向上移动一格即抵达
(
x
−
1
,
y
)
(x−1,y) 、向下移动一格即抵达
(
x
+
1
,
y
)
(x+1,y) 、向左移动一格即抵达
(
x
,
y
−
1
)
(x,y−1) 、向右移动一格即抵达
(
x
,
y
+
1
)
(x,y+1) 。
现在，你位于迷宫的入口
(
0
,
0
)
(0,0) ，想要前往终点
(
h
−
1
,
w
−
1
)
(h−1,w−1) 。请输出一条从起点到终点的可行路径。

保证起点和终点一定为空方格，你始终可以找到且能唯一找到一条从起点出发到达终点的可行路径。
输入描述：
第一行输入两个整数
h
,
w
(
1
≦
h
,
w
≦
100
)
h,w(1≦h,w≦100) 代表迷宫的行数和列数。
此后
h
h 行，第
i
i 行输入
w
w 个整数
a
i
,
1
,
a
i
,
2
,
…
,
a
i
,
w
(
0
≦
a
i
,
j
≦
1
)
a
i,1
​
 ,a
i,2
​
 ,…,a
i,w
​
 (0≦a
i,j
​
 ≦1) 代表迷宫的布局。其中，
a
i
,
j
=
0
a
i,j
​
 =0 表示单元格
(
i
,
j
)
(i,j) 是空方格，
a
i
,
j
=
1
a
i,j
​
 =1 表示单元格
(
i
,
j
)
(i,j) 是墙方格。
输出描述：
输出若干行，第
i
i 行输出两个整数
x
i
,
y
i
x
i
​
 ,y
i
​
  ，表示路径的第
i
i 步抵达的单元格坐标为
(
x
i
,
y
i
)
(x
i
​
 ,y
i
​
 ) 。

你需要保证输出的路径是符合题目要求的，即从起点
(
0
,
0
)
(0,0) 出发，到达终点
(
h
−
1
,
w
−
1
)
(h−1,w−1) ，且路径上每个单元格都是空方格，行走的单元格都是彼此相邻的。
示例1
输入：
5 5
0 1 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
复制
输出：
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)
复制
示例2
输入：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 1
0 1 1 1 0
0 0 0 0 0
复制
输出：
(0,0)
(1,0)
(2,0)
(3,0)
(4,0)
(4,1)
(4,2)
(4,3)
(4,4)
*/

package main

import (
	"fmt"
)

func main() {

	h, w := 0, 0
	fmt.Scan(&h, &w)

	grid := make([][]int, h)
	for i := 0; i < h; i++ {
		grid[i] = make([]int, w)
		for j := 0; j < w; j++ {
			fmt.Scan(&grid[i][j])
		}
	}

	flags := make([][]bool, h)
	for i := 0; i < h; i++ {
		flags[i] = make([]bool, w)
	}

	paths := make([][]int, 0, h*w)
	f := false

	var dfs func([]int)
	dfs = func(now []int) {
		if now[0] == h-1 && now[1] == w-1 {
			f = true
			return
		}

		for _, d := range [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}} {
			next := []int{now[0] + d[0], now[1] + d[1]}
			if next[0] >= 0 && next[0] < h &&
				next[1] >= 0 && next[1] < w &&
				grid[next[0]][next[1]] == 0 &&
				!flags[next[0]][next[1]] {
				flags[next[0]][next[1]] = true
				paths = append(paths, next)
				dfs(next)
				if f {
					return
				}
				paths = paths[:len(paths)-1]
				flags[next[0]][next[1]] = false
			}
		}
	}

	paths = append(paths, []int{0, 0})
	dfs([]int{0, 0})

	for _, p := range paths {
		fmt.Printf("(%d,%d)\n", p[0], p[1])
	}

}
