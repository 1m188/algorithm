/*
描述
输入一个 int 型的正整数，计算出该 int 型数据在内存中存储时 1 的个数。

数据范围：保证在 32 位整型数字范围内
输入描述：
 输入一个整数（int类型）

输出描述：
 这个数转换成2进制后，输出1的个数

示例1
输入：
5
复制
输出：
2
复制
示例2
输入：
0
复制
输出：
0
*/

package main

import (
	"fmt"
)

func main() {
	x := 0
	fmt.Scan(&x)

	cnt := 0
	for x != 0 {
		cnt++
		x = x & (x - 1)
	}

	fmt.Println(cnt)
}
