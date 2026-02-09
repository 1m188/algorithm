/*
REAL622 小红的顺子

描述
小红有一个长度为
n
−
1
n−1 的数组，满足
1
≤
a
i
≤
n
,
a
i
<
a
i
+
1
1≤a
i
​
 ≤n,a
i
​
 <a
i+1
​
 ，求顺子的最大长度。
顺子的定义为：对于长度为
m
m 的数组
b
b，如果
b
i
+
1
=
b
i
+
1
b
i
​
 +1=b
i+1
​
 ，
1
≤
i
<
m
1≤i<m，则称
b
b 是顺子。
输入描述：
一行一个整数
n
n，表示排列的长度。
一行
n
−
1
n−1 个整数，表示数组
a
a。
2
≤
n
≤
1
0
5
2≤n≤10
5

1
≤
a
i
<
a
i
+
1
≤
n
1≤a
i
​
 <a
i+1
​
 ≤n
输出描述：
一个整数，表示顺子的最大长度。
示例1
输入：
5
1 2 4 5
复制
输出：
2
复制
说明：
有两个顺子，分别是
[
1
,
2
]
[1,2] 和
[
4
,
5
]
[4,5]，最大长度为
2
2。
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
	a := make([]int, 0)
	for _, v := range strings.Split(input[1], " ") {
		num, _ := strconv.Atoi(v)
		a = append(a, num)
	}

	maxLen := 0
	start := 0
	for start < n-1 {
		end := start + 1
		for end < n-1 && a[end] == a[end-1]+1 {
			end++
		}
		if end-start > maxLen {
			maxLen = end - start
		}
		start = end
	}
	fmt.Println(maxLen)
}
