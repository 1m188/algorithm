/*
HJ170 01序列

描述
给定一个数组metrix，数组中只包含1和0，且数组中的1都不相邻，输入一个数n，问能否在将数组中n个0替代换成1后不破坏1都不相邻的条件。
例1 metrix=[1,0,0,0,1],n=1输出true
例2 metrix=[1,0,0,0,1],n=2输出false
输入描述：
输入一个数m(1≤m≤100000)表示metrix的长度

第二行m个数 0或1 表示改位置数组中的元素是0还是1

第三行输入一个数n
输出描述：
输出true或false
示例1
输入：
5
1 0 0 0 1
1
复制
输出：
true
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

	m := 0
	in.Scan()
	m, _ = strconv.Atoi(in.Text())

	res := 0
	left, mid, right := -1, -1, -1
	for m > 0 {
		m--
		in.Scan()
		x, _ := strconv.Atoi(in.Text())
		left, mid, right = mid, right, x
		if mid == -1 || mid == 1 {
			continue
		}
		if left != 1 && right != 1 {
			res++
			mid = 1
		}
	}

	n := 0
	in.Scan()
	n, _ = strconv.Atoi(in.Text())
	if res >= n {
		fmt.Println("true")
	} else {
		fmt.Println("false")
	}

}
