/*
数据范围：字符串长度满足 
1
≤
n
≤
1000
 
1≤n≤1000  ， 
1
≤
k
≤
n
 
1≤k≤n 
输入描述：
1.输入待截取的字符串

2.输入一个正整数k，代表截取的长度

输出描述：
截取后的字符串

示例1
输入：
abABCcDEF
6
复制
输出：
abABCc
复制
示例2
输入：
bdxPKBhih
6
复制
输出：
bdxPKB
*/

package main

import (
	"fmt"
)

func main() {
	s := ""
	k := 0
	fmt.Scan(&s, &k)
	fmt.Println(s[:k])
}
