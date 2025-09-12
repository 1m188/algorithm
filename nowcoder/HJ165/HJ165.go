/*
HJ165 小红的优惠券

描述
小红的购物车结算金额为
n
n 元，她手中有
m
m 张优惠券。第
j
j 张优惠券的规则为“满
a
j
a
j
​
  元立减
b
j
b
j
​
  元”，即若
n
≧
a
j
n≧a
j
​
 ，则使用该券后需支付
n
−
b
j
n−b
j
​
  元。

小红至多使用一张优惠券，请问最少需要支付多少元？
输入描述：
第一行输入两个整数
n
,
m
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
m
≦
100
)
n,m(1≦n≦10
5
 ; 1≦m≦100)。
接下来
m
m 行，第
j
j 行输入两个整数
a
j
,
b
j
(
1
≦
b
j
≦
a
j
≦
1
0
5
)
a
j
​
 ,b
j
​
 (1≦b
j
​
 ≦a
j
​
 ≦10
5
 )，描述第
j
j 张优惠券。
输出描述：
输出一个整数，表示小红使用最优策略后需支付的最少金额。
示例1
输入：
100 3
300 50
200 30
50 5
复制
输出：
95
复制
说明：
仅第三张券可用，支付
100
−
5
=
95
100−5=95 元。
*/

package main

import (
	"bufio"
	"os"
	"strconv"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	n, _ := strconv.Atoi(in.Text())

	in.Scan()
	m, _ := strconv.Atoi(in.Text())

	a := make([]int, m)
	b := make([]int, m)
	for i := 0; i < m; i++ {
		in.Scan()
		a[i], _ = strconv.Atoi(in.Text())
		in.Scan()
		b[i], _ = strconv.Atoi(in.Text())
	}

	idx := -1
	for i := 0; i < m; i++ {
		if a[i] <= n {
			if idx == -1 || b[i] > b[idx] {
				idx = i
			}
		}
	}

	if idx != -1 {
		out.WriteString(strconv.Itoa((n - b[idx])) + "\n")
	} else {
		out.WriteString(strconv.Itoa(n) + "\n")
	}

}
