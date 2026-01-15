/*
REAL788 小O的五号倍数

描述
小O有一个正整数
x
x ，他希望删除
x
x 中的一些数位，使得
x
x 变为
5
5 的倍数，请问最少需要删除多少个数位呢？
输入描述：
每个测试文件均包含多个测试点。第一行输入一个整数
T

(
1
≤
T
≤
1
0
5
)
T (1≤T≤10
5
 ) 代表测试数据组数，每组测试数据描述如下：
第一行输入一个正整数
x

(
1
≤
x
≤
1
0
9
)
x (1≤x≤10
9
 ) ，表示小O询问的数字
x
x。
输出描述：
对于每一个测试点，在一行上输出一个正整数代表最少的删除数位数。
示例1
输入：
3
154
100
1
复制
输出：
1
0
1
复制
说明：
三个数据分别删除为：
15， 100， 0
（可以全部删除，然后 x 视为 0。）
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
	T, _ := strconv.Atoi(input[0])
	for i := 1; i <= T; i++ {
		x, _ := strconv.Atoi(input[i])
		res := 0
		for x > 0 {
			n := x % 10
			x /= 10
			if n != 5 && n != 0 {
				res++
			} else {
				break
			}
		}
		fmt.Println(res)
	}
}
