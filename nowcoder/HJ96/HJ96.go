/*
HJ96 表示数字

描述
对于给定的由字母和数字混合构成的字符串
s
s，找到全部的连续数字子串，并在每一个子串的前后添加星号（
*
*）；其余字符保持不变。

子串为从原字符串中，连续的选择一段字符（可以全选、可以不选）得到的新字符串。
输入描述：
在一行上输入一个长度为
1
≦
l
e
n
(
s
)
≦
100
1≦len(s)≦100、由大小写字母和数字混合构成的字符串
s
s。
输出描述：
在一行上输出处理后的字符串
s
s。
示例1
输入：
Jkdi234klowe90a3
复制
输出：
Jkdi*234*klowe*90*a*3*
*/

package main

import (
	"fmt"
)

func main() {

	var s string
	fmt.Scan(&s)
	sli := []byte(s)
	res := make([]byte, 0, len(sli)*2+1)
	f := false
	for i := 0; i < len(sli); i++ {
		if sli[i] >= '0' && sli[i] <= '9' {
			if !f {
				f = true
				res = append(res, '*')
			}
		} else {
			if f {
				f = false
				res = append(res, '*')
			}
		}
		res = append(res, sli[i])
	}
	if f {
		f = false
		res = append(res, '*')
	}
	fmt.Println(string(res))

}
