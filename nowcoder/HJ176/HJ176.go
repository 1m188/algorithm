/*
HJ176 【模板】滑动窗口

描述
给定一个长度为
n
n 的整数数组
a
a 和一个窗口大小
k
k
(
1
≦
k
≦
n
)
(1≦k≦n)。滑动窗口从左到右移动，每次右移一位（窗口覆盖下标
[
i
,
i
+
k
−
1
]
[i,i+k−1]）。对于数组的每一个窗口位置，求出窗口内元素的最大值。
输入描述：
第一行输入两个整数
n
,
k
(
1
≦
k
≦
n
≦
2
×
1
0
5
)
n,k(1≦k≦n≦2×10
5
 )。
第二行输入
n
n 个整数
a
1
,
a
2
,
…
,
a
n
a
1
​
 ,a
2
​
 ,…,a
n
​
 ，元素范围
1
≦
a
i
≦
1
0
9
1≦a
i
​
 ≦10
9
 。
输出描述：
输出共
n
−
k
+
1
n−k+1 个整数，为每个滑动窗口的最大值，数之间以单个空格分隔。
示例1
输入：
10 3
2 13 6 19 15 13 17 9 19 13
复制
输出：
13 19 19 19 17 17 19 19
复制
示例2
输入：
10 1
13 13 5 3 9 19 18 4 17 3
复制
输出：
13 13 5 3 9 19 18 4 17 3
复制
示例3
输入：
10 10
15 20 5 20 19 1 4 18 14 15
复制
输出：
20
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	n, _ := strconv.Atoi(in.Text())
	in.Scan()
	k, _ := strconv.Atoi(in.Text())

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		in.Scan()
		arr[i], _ = strconv.Atoi(in.Text())
	}

	max := func(arr []int) int {
		res := arr[0]
		for _, v := range arr {
			if v > res {
				res = v
			}
		}
		return res
	}

	left := 0
	right := k
	target := max(arr[left:right])
	fmt.Fprintf(out, "%d ", target)

	for right < n {
		left++
		right++
		target = max(arr[left:right])
		fmt.Fprintf(out, "%d ", target)
	}
}
