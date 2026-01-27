/*
REAL731 串

描述
给出
n
n个只包含小写字母的字符串，将长度为奇数的字符串按顺序拼接后输出。

输入描述：
第一行输入一个整数
n
n。
(
1
≤
n
≤
1
0
5
)
(1≤n≤10
5
 )
接下来
n
n行，每行一个字符串。
字符串的长度总和不超过
1
0
5
10
5

输出描述：
输出一行一个字符串，表示答案。
示例1
输入：
3
abc
ab
a
复制
输出：
abca
复制
说明：
"abc","a"长度为奇数，按顺序拼接后为"abca"
示例2
输入：
4
aaaa
bsd
we
lzwrue
复制
输出：
bsd
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
	var res strings.Builder
	for i := 1; i <= n; i++ {
		if len(inputs[i])&0x1 == 1 {
			res.WriteString(inputs[i])
		}
	}
	fmt.Println(res.String())
}
