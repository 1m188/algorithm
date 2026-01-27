/*
REAL679 不同字符

描述
有一个长度为
n
,
(
1
≤
n
≤
1000
)
n,(1≤n≤1000)的字符串，字符串只包括大小写字母和阿拉伯数字，牛牛想知道这个字符串里面有多少个不同的字符。
输入描述：
第一行为一个正整数
n
(
1
≤
n
≤
1000
)
n(1≤n≤1000), 为字符串的长度
第二行为一个长度为n的字符串
输出描述：
输出为不同字符的个数。
示例1
输入：
5
aase3
复制
输出：
4
复制
说明：
有四个不同的字符，分别是 a s e 3
示例2
输入：
7
LAub7L0
复制
输出：
6
复制
说明：
字符串中有6个不同的字符， 分别是 L A u b 7  0
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
	inputs := strings.Split(strings.TrimSpace(string(data)), "\n")
	n, _ := strconv.Atoi(inputs[0])
	s := inputs[1]

	alpha := make([]bool, 26)
	Alpha := make([]bool, 26)
	num := make([]bool, 10)
	for i := 0; i < n; i++ {
		if s[i] >= 'a' && s[i] <= 'z' {
			alpha[s[i]-'a'] = true
		} else if s[i] >= 'A' && s[i] <= 'Z' {
			Alpha[s[i]-'A'] = true
		} else {
			num[s[i]-'0'] = true
		}
	}

	res := 0
	for _, b := range alpha {
		if b {
			res++
		}
	}
	for _, b := range Alpha {
		if b {
			res++
		}
	}
	for _, b := range num {
		if b {
			res++
		}
	}
	fmt.Println(res)
}
