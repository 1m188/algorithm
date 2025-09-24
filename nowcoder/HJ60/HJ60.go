/*
HJ60 查找组成一个偶数最接近的两个素数

描述
对于给定的偶数
n
n，找出两个素数
a
,
b
a,b，满足：
∙

∙它们的和等于
n
n；
∙

∙它们的差值的绝对值最小。

我们可以证明，
a
,
b
a,b 一定存在，从小到大输出满足条件的素数对。
输入描述：
输入一个整数
n
(
4
≦
n
≦
1
0
3
)
n(4≦n≦10
3
 )。保证
n
n 是偶数。
输出描述：
第一行输出一个整数
a
a，代表满足条件的素数对中的较小者。
第二行输出一个整数
b
b，代表满足条件的素数对中的较大者。
示例1
输入：
20
复制
输出：
7
13
复制
示例2
输入：
4
复制
输出：
2
2
*/

package main

import (
	"fmt"
)

func main() {

	n := 0
	fmt.Scan(&n)

	judge := func(n int) bool {
		if n <= 1 {
			return false
		}
		if n == 2 {
			return true
		}
		if n&1 == 0 {
			return false
		}
		for i := 3; i*i <= n; i += 2 {
			if n%i == 0 {
				return false
			}
		}
		return true
	}

	a, b := 0, 0
	if n&1 == 0 {
		a, b = n/2, n/2
	} else {
		a, b = n/2, n/2+1
	}

	for !judge(a) || !judge(b) {
		a--
		b++
	}
	fmt.Printf("%d\n%d\n", a, b)

}
