/*
HJ148 迷宫寻路

描述
旺仔哥哥被困在一个
n
×
m
n×m 的矩形迷宫里。每个格子要么是空地 (用符号 `.` 表示)，要么是墙 (用符号 `#` 表示)。旺仔哥哥只能从一个空地移动到其上下左右相邻的空地。
已知旺仔哥哥的起点为左上角
(
1
,
1
)
(1,1)，终点为右下角
(
n
,
m
)
(n,m)。请判断他是否能够到达终点。
输入描述：
第一行输入两个正整数
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
100
)
n,m (1≦n,m≦100)。
接下来的
n
n 行每行输入一个长为
m
m 的仅包含字符 `.` 与 `#` 的字符串，描述整个迷宫。
保证起点
(
1
,
1
)
(1,1) 和终点
(
n
,
m
)
(n,m) 均为空地。
输出描述：
若旺仔哥哥可以走到终点，则输出单词
Yes
Yes；否则输出
No
No。
示例1
输入：
3 5
.##.#
.#...
...#.
复制
输出：
Yes
复制
说明：
路线如下：
(
1
,
1
)
→
(
2
,
1
)
→
(
3
,
1
)
→
(
3
,
2
)
→
(
3
,
3
)
→
(
2
,
3
)
→
(
2
,
4
)
→
(
2
,
5
)
→
(
3
,
5
)
(1,1)→(2,1)→(3,1)→(3,2)→(3,3)→(2,3)→(2,4)→(2,5)→(3,5)
*/

package main

import (
	"fmt"
)

var n, m int
var mat [][]byte
var flags [][]bool

func input() {
	fmt.Scan(&n, &m)
	mat = make([][]byte, n)
	for i := 0; i < n; i++ {
		mat[i] = make([]byte, m)
		var s string
		fmt.Scan(&s)
		copy(mat[i], []byte(s))
	}
	flags = make([][]bool, n)
	for i := 0; i < n; i++ {
		flags[i] = make([]bool, m)
	}
}

func dfs(a, b int) bool {
	if a == n-1 && b == m-1 {
		return true
	}

	for _, na := range []int{a - 1, a + 1} {
		nb := b
		if na >= 0 && na < n && mat[na][nb] == '.' && !flags[na][nb] {
			flags[na][nb] = true
			f := dfs(na, nb)
			flags[na][nb] = false
			if f {
				return f
			}
		}
	}

	for _, nb := range []int{b - 1, b + 1} {
		na := a
		if nb >= 0 && nb < m && mat[na][nb] == '.' && !flags[na][nb] {
			flags[na][nb] = true
			f := dfs(na, nb)
			flags[na][nb] = false
			if f {
				return f
			}
		}
	}

	return false
}

func bfs() bool {
	flags[n-1][m-1] = true
	queue := make([][2]int, 0, n*m)
	queue = append(queue, [2]int{n - 1, m - 1})

	for len(queue) > 0 {
		a, b := queue[0][0], queue[0][1]
		queue = queue[1:]

		for _, na := range []int{a - 1, a + 1} {
			nb := b
			if na >= 0 && na < n && mat[na][nb] == '.' && !flags[na][nb] {
				flags[na][nb] = true
				queue = append(queue, [2]int{na, nb})
			}
		}

		for _, nb := range []int{b - 1, b + 1} {
			na := a
			if nb >= 0 && nb < m && mat[na][nb] == '.' && !flags[na][nb] {
				flags[na][nb] = true
				queue = append(queue, [2]int{na, nb})
			}
		}
	}

	return flags[0][0]
}

func main() {

	input()

	// flags[0][0] = true
	// f := dfs(0, 0)
	f := bfs()

	if f {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}

}
