/*
REAL640 小红的矩阵

描述
小红拿到了一个
n
n行
m
m列的矩阵，请你回答该矩阵中有多少个元素的个位数是 9。
输入描述：
第一行输入两个正整数
n
n和
m
m，代表矩阵的行数和列数。
接下来的
n
n行，每行输入
m
m个正整数
a
i
j
a
ij
​
 ，代表矩阵的元素。
1
≤
n
,
m
,
a
i
j
≤
100
1≤n,m,a
ij
​
 ≤100
输出描述：
一个整数，代表矩阵中个位数是 9 的元素数量。
示例1
输入：
3 4
1 2 3 4
5 6 7 8
9 10 24 39
复制
输出：
2

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
	input := strings.Split(strings.TrimSpace(string(data)), "\n")

	nm := strings.Split(input[0], " ")
	n, _ := strconv.Atoi(nm[0])
	m, _ := strconv.Atoi(nm[1])

	res := 0
	for i := 1; i <= n; i++ {
		line := strings.Split(input[i], " ")
		for j := 0; j < m; j++ {
			num, _ := strconv.Atoi(line[j])
			if num%10 == 9 {
				res++
			}
		}
	}

	fmt.Println(res)
}
