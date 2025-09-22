/*
HJ102 字符统计

描述
对于给定的由小写字母和数字构成的字符串
s
s，统计出现的每一个字符的出现次数，按出现次数从多到少排序后依次输出。特别地，如果出现次数相同，则按照 ASCII 码由小到大排序。
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
1
0
3
1≦len(s)≦10
3
 、由小写字母和数字构成的字符串
s
s。
输出描述：
在一行上输出一个字符串，代表按频次统计后的结果。
示例1
输入：
aaddccdc
复制
输出：
cda
复制
说明：
在这个样例中，字符
‘c’
‘c’ 和
‘d’
‘d’ 出现的次数最多，均为
3
3 次，而前者 ASCII 码更小，因此先输出。
*/

package main

import (
	"fmt"
	"sort"
)

type Alpha struct {
	Char byte
	Cnt  int
}

func Less(a, b Alpha) bool {
	if a.Cnt == b.Cnt {
		return a.Char > b.Char
	}
	return a.Cnt < b.Cnt
}

func main() {

	var s string
	fmt.Scan(&s)

	mmap := make(map[byte]int)
	for _, v := range s {
		mmap[byte(v)]++
	}

	var alphas []Alpha = make([]Alpha, 0, len(mmap))
	for k, v := range mmap {
		alphas = append(alphas, Alpha{Char: k, Cnt: v})
	}

	sort.Slice(alphas, func(i, j int) bool {
		return !Less(alphas[i], alphas[j])
	})

	for _, v := range alphas {
		fmt.Printf("%c", v.Char)
	}

}
