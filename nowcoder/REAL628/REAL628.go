/*
REAL628 分组

描述
现在有
n
n 个同学，老师要把他们分成若干组去做游戏，每个组的同学必须要不少于
3
3 个人，请问这
n
n 个同学最多可以分成多少组。
输入描述：
在一行中给出一个正整数
n
n
3
≤
n
≤
1000
3≤n≤1000



输出描述：
输出一个整数，代表分组的个数

示例1
输入：
8
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
	n, _ := strconv.Atoi(strings.TrimSpace(string(data)))
	fmt.Println(n / 3)
}
