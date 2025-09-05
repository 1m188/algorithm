/*
HJ47 【模板】排序

描述
给定一个长度为
n
n 的整数数组
A
A（允许元素重复），请将其按非递减顺序排序并输出。
输入描述：
第一行输入整数
n
(
1
≦
n
≦
1
0
5
)
n(1≦n≦10
5
 )，表示数组长度。
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
(
−
1
0
9
≦
a
i
≦
1
0
9
)
a
1
​
 ,a
2
​
 ,…,a
n
​
 (−10
9
 ≦a
i
​
 ≦10
9
 )。
输出描述：
在一行上输出排序后的数组，各元素以空格分隔。
示例1
输入：
5
5 4 3 2 1
复制
输出：
1 2 3 4 5
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	n, _ := strconv.Atoi(in.Text())

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		in.Scan()
		arr[i], _ = strconv.Atoi(in.Text())
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	fmt.Fprintf(out, "%d", arr[0])
	for i := 1; i < n; i++ {
		fmt.Fprintf(out, " %d", arr[i])
	}
}
