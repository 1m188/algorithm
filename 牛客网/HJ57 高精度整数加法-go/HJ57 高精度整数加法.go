/*
描述
输入两个用字符串 str 表示的整数，求它们所表示的数之和。

数据范围：
1
≤
l
e
n
(
s
t
r
)
≤
10000

1≤len(str)≤10000
输入描述：
输入两个字符串。保证字符串只含有'0'~'9'字符

输出描述：
输出求和后的结果

示例1
输入：
9876543210
1234567890
复制
输出：
11111111100
*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	str1, str2 := "", ""
	fmt.Scan(&str1, &str2)

	for len(str1) < len(str2) {
		str1 = "0" + str1
	}
	for len(str2) < len(str1) {
		str2 = "0" + str2
	}

	res := []byte{}
	x := byte(0)
	for i := len(str1) - 1; i >= 0; i-- {
		y := str1[i] - '0' + str2[i] - '0' + x
		res = append(res, y%10+'0')
		x = y / 10
	}
	if x > 0 {
		res = append(res, x+'0')
	}

	str := strings.Builder{}
	for i := len(res) - 1; i >= 0; i-- {
		str.WriteByte(res[i])
	}
	fmt.Println(str.String())

}
