/*
HJ166 讨厌鬼进货

描述
讨厌鬼需要采购
n
n 种货物，每种货物可通过以下方式获取：
∙

∙ 在供应商
A
A 以
a
i
a
i
​
  元购得第
i
i 种；
∙

∙ 在供应商
B
B 以
b
i
b
i
​
  元购得第
i
i 种；
∙

∙ 在网购平台一次性购买全部
n
n 种，花费
x
x 元（不能拆分）。

可以自由组合以上方式，只要最终每种货物都至少购买一件。求最小总花费。
输入描述：
第一行输入两个整数
n
,
x
(
1
≦
n
≦
1
0
5
;

1
≦
x
≦
1
0
9
)
n,x(1≦n≦10
5
 ; 1≦x≦10
9
 )。
第二行输入
n
n 个整数
a
1
,
a
2
,
…
,
a
n
(
1
≦
a
i
≦
1
0
4
)
a
1
​
 ,a
2
​
 ,…,a
n
​
 (1≦a
i
​
 ≦10
4
 )。
第三行输入
n
n 个整数
b
1
,
b
2
,
…
,
b
n
(
1
≦
b
i
≦
1
0
4
)
b
1
​
 ,b
2
​
 ,…,b
n
​
 (1≦b
i
​
 ≦10
4
 )。
输出描述：
输出一个整数，表示完成采购的最少花费。
示例1
输入：
5 5
2 1 2 1 2
1 2 1 2 3
复制
输出：
5
复制
说明：
直接选择网购
5
5 元即可完成。
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Split(bufio.ScanWords)

	in.Scan()
	n, _ := strconv.Atoi(in.Text())
	in.Scan()
	x, _ := strconv.Atoi(in.Text())

	A := make([]int, n)
	for i := 0; i < n; i++ {
		in.Scan()
		A[i], _ = strconv.Atoi(in.Text())
	}

	B := make([]int, n)
	for i := 0; i < n; i++ {
		in.Scan()
		B[i], _ = strconv.Atoi(in.Text())
	}

	min := func(a, b int) int {
		if a < b {
			return a
		}
		return b
	}

	cost := 0
	for i := 0; i < n; i++ {
		cost += min(A[i], B[i])
	}

	if cost > x {
		fmt.Fprintf(out, "%d\n", x)
	} else {
		fmt.Fprintf(out, "%d\n", cost)
	}
}
