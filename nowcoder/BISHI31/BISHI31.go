/*
BISHI31 二进制不同位数

描述
给定两个正整数
m
m 和
n
n。将它们分别写成二进制串（不含前导
0
0），从最低位对齐后进行比较。请计算在所有对应位上二进制数字不同的位数，记为
f
(
m
,
n
)
f(m,n)。

更形式化地，设
x
=
m
xor
⁡
n
x=mxorn，则
f
(
m
,
n
)
f(m,n) 等于
x
x 的二进制表示中
1
1 的个数。
输入描述：
在一行上输入两个整数
m
,
n
(
1
≦
m
,
n
≦
1
0
9
)
m,n(1≦m,n≦10
9
 )，表示需要比较的两个正整数。
输出描述：
在一行上输出一个整数，表示
m
m 和
n
n 的二进制表示中不同的位数
f
(
m
,
n
)
f(m,n)。
示例1
输入：
15 8
复制
输出：
3
复制
说明：
在这个样例中，
m
=
15
m=15 的二进制为
(
1111
)
2
(1111)
2
​
 ，
n
=
8
n=8 的二进制为
(
1000
)
2
(1000)
2
​
 。
从最低位对齐后比较四个二进制位，有
3
3 个位置上的数字不同，因此答案为
3
3。
示例2
输入：
7 10
复制
输出：
3
复制
说明：
在这个样例中，
m
=
7
m=7 的二进制为
(
111
)
2
(111)
2
​
 ，
n
=
10
n=10 的二进制为
(
1010
)
2
(1010)
2
​
 。
补齐后比较四个二进制位：
∙

∙第
1
1 位（最低位）：
1
≠
0
1

​
 =0；
∙

∙第
2
2 位：
1
=
1
1=1；
∙

∙第
3
3 位：
1
≠
0
1

​
 =0；
∙

∙第
4
4 位：
0
≠
1
0

​
 =1。
共有
3
3 个位置不同，故答案为
3
3。
*/

package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func main() {
	data, _ := ioutil.ReadAll(os.Stdin)
	input := strings.Split(strings.TrimSpace(string(data)), " ")

	m, n := 0, 0
	m, _ = strconv.Atoi(input[0])
	n, _ = strconv.Atoi(input[1])

	f := func(m, n int) int {
		x := m ^ n
		count := 0
		for x > 0 {
			count += x & 1
			x >>= 1
		}
		return count
	}

	fmt.Println(f(m, n))
}
