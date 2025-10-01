/*
HJ79 支付宝消费打折

描述
众所周知，在一些消费支付的场合中，往往有“支付宝九五折”的优惠。
这天小苯来到了超市购买物品，一共有
n
n 种物品，每种物品只能购买一个，但有的物品支持优惠活动，有的并不支持。恰好本超市的结账是有“支付宝九五折”优惠的，小苯的支付宝余额还剩
k
k 元，他想知道他仅使用支付宝进行支付的话，最多能买几件物品？
输入描述：
输入包含三行。
第一行两个正整数
n
,
k

(
1
≤
n
≤
1
0
5
)
,

(
1
≤
k
≤
1
0
9
)
n,k (1≤n≤10
5
 ), (1≤k≤10
9
 )。
第二行包含
n
n 个正整数
a
i
(
1
≤
a
i
≤
1
0
4
)
a
i
​
 (1≤a
i
​
 ≤10
4
 ) 表示每个物品的价格。
第三行一个长度为
n
n 的只含有
0
0 和
1
1 的字符串，表示每个物品是否支持优惠。（如果是
1
1 代表第
i
i 个物品支持优惠，否则不支持。）
输出描述：
输出一行一个整数表示答案。
示例1
输入：
5 9
3 4 2 3 1
11101
复制
输出：
4
复制
说明：
选择买第 1，3，4，5 个物品。
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {

	in := bufio.NewReader(os.Stdin)

	n, k := 0, 0
	s, _ := in.ReadString(' ')
	n, _ = strconv.Atoi(s[:len(s)-1])
	s, _ = in.ReadString('\n')
	k, _ = strconv.Atoi(s[:len(s)-1])

	a := make([]float64, n)
	s, _ = in.ReadString('\n')
	s = s[:len(s)-1]
	li := strings.Split(s, " ")
	for i := 0; i < n; i++ {
		x, _ := strconv.Atoi(li[i])
		a[i] = float64(x)
	}

	flags := make([]byte, n)
	for i := 0; i < n; i++ {
		b, _ := in.ReadByte()
		flags[i] = b
	}

	for i := 0; i < n; i++ {
		if flags[i] == '1' {
			a[i] *= 0.95
		}
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})

	res := 0
	kk := float64(k)
	for i := 0; i < n; i++ {
		if kk >= a[i] {
			kk -= a[i]
			res++
		} else {
			break
		}
	}

	fmt.Println(res)

}
