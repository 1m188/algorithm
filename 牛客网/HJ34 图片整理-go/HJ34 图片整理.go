/*
描述
Lily上课时使用字母数字图片教小朋友们学习英语单词，每次都需要把这些图片按照大小（ASCII码值从小到大）排列收好。请大家给Lily帮忙，通过代码解决。
Lily使用的图片使用字符"A"到"Z"、"a"到"z"、"0"到"9"表示。

数据范围：每组输入的字符串长度满足
1
≤
n
≤
1000

1≤n≤1000

输入描述：
一行，一个字符串，字符串中的每个字符表示一张Lily使用的图片。

输出描述：
Lily的所有图片按照从小到大的顺序输出

示例1
输入：
Ihave1nose2hands10fingers
复制
输出：
0112Iaadeeefghhinnnorsssv
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	s := ""
	fmt.Fscan(in, &s)

	li := make([]byte, len(s))
	for i, _ := range li {
		li[i] = s[i]
	}

	sort.Slice(li, func(i, j int) bool {
		return li[i] < li[j]
	})

	for _, v := range li {
		fmt.Fprintf(out, "%c", v)
	}
}
