/*
BISHI55 判断质数

描述
给定一个正整数
n
n，请判断
n
n 是否为质数。

【名词解释】
∙

∙质数是指仅能被
1
1 和其自身整除、且大于
1
1 的正整数。
输入描述：
在一行上输入一个整数
n
(
1
≦
n
≦
1
0
12
)
n(1≦n≦10
12
 )。
输出描述：
如果
n
n 为质数，在一行上输出
"Yes"
"Yes"；否则，直接输出
"No"
"No"。
示例1
输入：
2
复制
输出：
Yes
复制
说明：
由于
2
2 仅能被
1
1 和
2
2 整除，因此是质数。
示例2
输入：
3
复制
输出：
Yes
复制
示例3
输入：
4
复制
输出：
No
复制
说明：
因为
4
4 可以被
2
2 整除，因此不是质数。
*/

package main

import (
	"fmt"
)

func main() {

	judge := func(n int64) bool {
		if n <= 1 {
			return false
		}
		if n == 2 {
			return true
		}
		if n&0x1 == 0 {
			return false
		}
		for i := int64(3); i*i <= n; i += 2 {
			if n%i == 0 {
				return false
			}
		}
		return true
	}

	var n int64
	fmt.Scan(&n)
	if judge(n) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}

}
