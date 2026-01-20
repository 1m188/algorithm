/*
REAL714 小红的数列

描述
小红拿到了一个数列，数列满足以下性质：
a
1
=
1
,
a
2
=
2
a
1
​
 =1,a
2
​
 =2，从第三项开始，
a
i
=
a
⌊
i
/
3
⌋
+
a
⌊
i
∗
2
/
3
⌋
a
i
​
 =a
⌊i/3⌋
​
 +a
⌊i∗2/3⌋
​

现在给定
n
n，请你求出该数列的前
n
n项。
a
⌊
i
/
3
⌋
a
⌊i/3⌋
​
 表示 "
i
/
3
i/3"的向下取整。
输入描述：
一个正整数
n
n
1
≤
n
≤
200000
1≤n≤200000
输出描述：
n
n个整数，用空格隔开。
示例1
输入：
5
复制
输出：
1 2 3 3 4
复制
说明：
a
1
=
1
a
1
​
 =1
a
2
=
2
a
2
​
 =2
a
3
=
a
1
+
a
2
=
3
a
3
​
 =a
1
​
 +a
2
​
 =3
a
4
=
a
1
+
a
2
=
3
a
4
​
 =a
1
​
 +a
2
​
 =3
a
5
=
a
1
+
a
3
=
4
a
5
​
 =a
1
​
 +a
3
​
 =4
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

	dp := make([]uint64, n+1)
	dp[1] = 1
	dp[2] = 2
	for i := 3; i <= n; i++ {
		dp[i] = dp[i/3] + dp[i*2/3]
	}

	for i := 1; i <= n; i++ {
		fmt.Printf("%d ", dp[i])
	}
}
