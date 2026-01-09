/*
BISHI132 小红的地砖

描述
小红正在进行一次体能训练，场地上依次铺设了
n
n 块地砖，按照从
1
1 到
n
n 依次编号。她站在第
1
1 块地砖上，目标是走到第
n
n 块地砖。
已知走到第
i
i 块地砖需要消耗
a
i
a
i
​
  的体力值。每一次移动，小红可以选择：
∙

∙向前走
1
1 步，即从当前地砖
i
i 走到地砖
i
+
1
i+1；
∙

∙向前走
2
2 步，即从当前地砖
i
i 走到地砖
i
+
2
i+2。
请你帮助小红计算，从第
1
1 块地砖走到第
n
n 块地砖所需消耗的最小体力值。
输入描述：
第一行输入一个整数
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
 )，表示地砖的数量。
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
0
≦
a
i
≦
1
0
3
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
 (0≦a
i
​
 ≦10
3
 )，其中
a
i
a
i
​
  表示走到第
i
i 块地砖需要消耗的体力值。保证
a
1
=
a
n
=
0
a
1
​
 =a
n
​
 =0。
输出描述：
在一行上输出一个整数，代表从第
1
1 块地砖走到第
n
n 块地砖所需消耗的最小体力值。
示例1
输入：
5
0 3 2 1 0
复制
输出：
2
复制
说明：
对于第一组样例：
∙

∙一种最优走法为
1
→
3
→
5
1→3→5，实际经过的地砖编号为
{
1
,
3
,
5
}
{1,3,5}；
∙

∙对应消耗的体力值为
a
1
+
a
3
+
a
5
=
0
+
2
+
0
=
2
a
1
​
 +a
3
​
 +a
5
​
 =0+2+0=2，无法再更小。
示例2
输入：
6
0 1 0 2 1 0
复制
输出：
1
复制
说明：
对于第二组样例：
∙

∙一种最优走法为
1
→
3
→
5
→
6
1→3→5→6；
∙

∙对应消耗的体力值为
a
1
+
a
3
+
a
5
+
a
6
=
0
+
0
+
1
+
0
=
1
a
1
​
 +a
3
​
 +a
5
​
 +a
6
​
 =0+0+1+0=1。
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
	a := make([]int, 0, n+1)
	a = append(a, 0)
	for _, s := range strings.Split(input[1], " ") {
		num, _ := strconv.Atoi(s)
		a = append(a, num)
	}

	dp := make([]int, n+1)
	dp[1] = a[1]
	dp[2] = a[2]
	dp[3] = a[3]
	for i := 4; i <= n; i++ {
		x := dp[i-1]
		if dp[i-2] < x {
			x = dp[i-2]
		}
		dp[i] = a[i] + x
	}
	fmt.Println(dp[n])
}
