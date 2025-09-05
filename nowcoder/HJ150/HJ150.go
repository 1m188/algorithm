/*
HJ150 全排列

描述
给定一个整数
n
n，请按 字典序 输出数字
1
∼
n
1∼n 的所有排列。
输入描述：
一行一个整数
n
(
1
≦
n
≦
9
)
n(1≦n≦9)。
输出描述：
按字典序输出所有排列，每行输出
n
n 个整数，数字之间用单个空格分隔。
示例1
输入：
3
复制
输出：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var in = bufio.NewScanner(os.Stdin)
	var out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	n, _ := strconv.Atoi(in.Text())

	li := make([]int, n)
	flags := make([]bool, n+1)

	var dfs func(int)
	dfs = func(idx int) {
		if idx >= n {
			fmt.Fprintf(out, "%d", li[0])
			for i := 1; i < n; i++ {
				fmt.Fprintf(out, " %d", li[i])
			}
			out.WriteByte('\n')
			return
		}

		for i := 1; i <= n; i++ {
			if !flags[i] {
				flags[i] = true
				li[idx] = i
				dfs(idx + 1)
				flags[i] = false
			}
		}
	}

	dfs(0)
}
