/*
REAL681 数颜色

描述
对于一种颜色，它总是由红色(R),绿色(G),蓝色(B)构成的。现在你有一种由R,G,B三种颜色构成的彩虹，想请你计算出这道彩虹中每种颜色出现的次数是多少，并且使用(R,G,B)的形式输出。例如如果这束彩虹为"RRGBBRG"(不含引号），那么你应该输出"(3,2,2)" (不含引号）。
输入描述：
一行一个仅由'R','G','B'构成的字符串
S
,
(
1
≤
∣
S
∣
≤
1
0
5
)
S,(1≤∣S∣≤10
5
 )
输出描述：
一个三元组表示答案。
示例1
输入：
RRGBBRG
复制
输出：
(3,2,2)
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
	S := strings.TrimSpace(string(data))
	R, G, B := 0, 0, 0
	for _, c := range S {
		switch c {
		case 'R':
			R++
		case 'G':
			G++
		case 'B':
			B++
		}
	}
	fmt.Printf("(%d,%d,%d)\n", R, G, B)
}
