/*
REAL672 Nowcoder

描述
给出一个长度和
Nowcoder
Nowcoder 等长的字符串
s
s，请你计算要更改
s
s 中的几个字符可以使得字符串
s
s 和
Nowcoder
Nowcoder 相等
输入描述：
在一行中输入一个长度和
Nowcoder
Nowcoder 等长的字符串
s
s
保证字符串中只包含大小写字母和数字
输出描述：
在一行中输出一个数字代表要更改的次数
示例1
输入：
nowcoder
复制
输出：
1
复制
示例2
输入：
nOWcoDeR
复制
输出：
5
*/

package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

func main() {
	data, _ := ioutil.ReadAll(os.Stdin)
	s := strings.TrimSpace(string(data))

	const target = "Nowcoder"

	res := 0
	for i := 0; i < len(target); i++ {
		if s[i] != target[i] {
			res++
		}
	}
	fmt.Println(res)
}
