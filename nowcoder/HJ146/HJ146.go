/*
HJ146 谐距下标对

描述
给定一个长度为
n
n 的整数数组
{
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
}
{a
1
​
 ,a
2
​
 ,…,a
n
​
 }。若下标满足
i
<
j
i<j 且
a
j
−
a
i
=
j
−
i
a
j
​
 −a
i
​
 =j−i，则称
(
i
,
j
)
(i,j) 为一对谐距下标对。

请计算数组中的谐距下标对数量。
输入描述：
第一行输入整数
n
(
1
≦
n
≦
1
0
5
)
n(1≦n≦10
5
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
5
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
5
 )。
输出描述：
输出一个整数，表示谐距下标对数量。
示例1
输入：
6
1 2 3 4 5 6
复制
输出：
15
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

	n := 0
	in.Scan()
	n, _ = strconv.Atoi(in.Text())

	a := make([]int, n)
	for i := 0; i < n; i++ {
		in.Scan()
		a[i], _ = strconv.Atoi(in.Text())
		a[i] -= i
	}

	mmap := make(map[int]int, n)
	for _, v := range a {
		mmap[v]++
	}

	res := 0

	for _, v := range mmap {
		res += v * (v - 1) / 2
	}

	out.WriteString(strconv.Itoa(res))

}
