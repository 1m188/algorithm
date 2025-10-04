/*
HJ156 走迷宫

描述
给定一个
n
×
m
n×m 的网格。你从起点
(
x
s
,
y
s
)
(x
s
​
 ,y
s
​
 ) 出发，每一次可以向上、下、左、右移动一步（若不超出边界）。某些格子上存在障碍物，无法经过。求从
(
x
s
,
y
s
)
(x
s
​
 ,y
s
​
 ) 移动到终点
(
x
t
,
y
t
)
(x
t
​
 ,y
t
​
 ) 的最少步数；若无法到达，输出
−
1
−1。
输入描述：
在一行上输入两个整数
n
,
m
(
1
≦
n
,
m
≦
1000
)
n,m(1≦n,m≦1000)，代表网格的行数与列数。
在一行上输入四个整数
x
s
,
y
s
,
x
t
,
y
t
(
1
≦
x
s
,
x
t
≦
n
;

1
≦
y
s
,
y
t
≦
m
)
x
s
​
 ,y
s
​
 ,x
t
​
 ,y
t
​
 (1≦x
s
​
 ,x
t
​
 ≦n; 1≦y
s
​
 ,y
t
​
 ≦m)，代表起点与终点的坐标。
此后
n
n 行，第
i
i 行输入一个长度为
m
m 的字符串
g
i
g
i
​
 ，其中
∙

∙若
g
i
,
j
=
"*"
g
i,j
​
 ="*"，表示第
i
i 行第
j
j 列为障碍物；
∙

∙若
g
i
,
j
=
"."
g
i,j
​
 ="."，表示该格子可通行。
保证起点所在格子可通行。
输出描述：
输出一个整数，表示最少移动次数；若无法到达，输出
−
1
−1。
示例1
输入：
5 5
1 1 5 5
.....
****.
.....
**.**
.....
复制
输出：
12
复制
示例2
输入：
5 5
1 1 4 5
.....
****.
.....
**.**
.....
复制
输出：
-1
复制
示例3
输入：
5 5
1 1 5 5
.....
****.
.....
*****
.....
复制
输出：
-1
*/

package main

import (
	"fmt"
)

func main() {

	n, m := 0, 0
	fmt.Scan(&n, &m)
	xs, ys, xt, yt := 0, 0, 0, 0
	fmt.Scan(&xs, &ys, &xt, &yt)
	xs--
	ys--
	xt--
	yt--

	grid := make([][]byte, n)
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		grid[i] = []byte(s)
	}

	que := make([][]int, 0, n*m)
	qque := make([][]int, 0, n*m)
	que = append(que, []int{xs, ys})
	vis := make([][]bool, n)
	for i := 0; i < n; i++ {
		vis[i] = make([]bool, m)
	}
	vis[xs][ys] = true
	cnt := 0
	for len(que) > 0 {
		qque = qque[:0]
		for _, v := range que {
			x, y := v[0], v[1]

			if x == xt && y == yt {
				fmt.Println(cnt)
				return
			}

			for _, v := range []int{-1, 1} {
				if x+v >= 0 && x+v < n && !vis[x+v][y] && grid[x+v][y] != '*' {
					qque = append(qque, []int{x + v, y})
					vis[x+v][y] = true
				}
				if y+v >= 0 && y+v < m && !vis[x][y+v] && grid[x][y+v] != '*' {
					qque = append(qque, []int{x, y + v})
					vis[x][y+v] = true
				}
			}
		}

		if len(qque) > 0 {
			cnt++
		}
		que = que[:0]
		que = append(que, qque...)
	}

	fmt.Println(-1)

}
