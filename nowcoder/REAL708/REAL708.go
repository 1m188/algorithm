/*
REAL708 小红的购物车

描述
小红经常去小红书上购物。这天，她打开了购物车准备勾选一些订单支付。
请你判断小红一共需要支付多少钱。
输入描述：
第一行输入一个正整数
n
n，代表小红购物车中商品数量。
接下来的
n
n行，每行输入一个正整数
a
i
a
i
​
 和一个字符
c
i
c
i
​
 ，代表每个商品的价格、以及小红是否选择支付该商品。若支付，则
c
i
c
i
​
 为'O'字符。不支付则为'X'字符。
1
≤
n
≤
1
0
5
1≤n≤10
5

1
≤
a
i
≤
1
0
9
1≤a
i
​
 ≤10
9

输出描述：
一个整数，代表小红一共需要花费的金额。

示例1
输入：
3
123 O
234 X
321 O
复制
输出：
444
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
	n, _ := strconv.Atoi(input[0])
	ans := 0
	for i := 1; i <= n; i++ {
		line := strings.Split(input[i], " ")
		if line[1] == "O" {
			money, _ := strconv.Atoi(line[0])
			ans += money
		}
	}
	fmt.Println(ans)
}
