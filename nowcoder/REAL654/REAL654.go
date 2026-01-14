/*
REAL654 讨厌鬼购物

描述
讨厌鬼正在商场购物，现在有两家店
a
a和
b
b正在出售相同的
n
n类商品。第
i
i类商品在
a
a店出售
a
i
a
i
​
 元，在
b
b店出售
b
i
b
i
​
 元。
由于生产商的不同，
a
a店和
b
b店的同一类商品的品质也各有不同。
讨厌鬼在网上搜索后得到
a
a店的第
i
i类商品的评分
c
i
c
i
​
 ，
b
b店的第
i
i类商品评分为
d
i
d
i
​
 分。如果一类商品在其中一个店的价格小于对方的同时，评分大于对方，那么讨厌鬼就一定会买下这类商品。

请问讨厌鬼在购物完之后，一定会购买几类商品？
输入描述：
第一行输入一个整数
n
(
1
≤
n
≤
50000
)
n(1≤n≤50000)
第二行输入
n
n个整数
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
9
)
a
i
​
 (1≤a
i
​
 ≤10
9
 )
第三行输入
n
n个整数
b
i
(
1
≤
b
i
≤
1
0
9
)
b
i
​
 (1≤b
i
​
 ≤10
9
 )
第四行输入
n
n个整数
c
i
(
1
≤
c
i
≤
1
0
9
)
c
i
​
 (1≤c
i
​
 ≤10
9
 )
第五行输入
n
n个整数
d
i
(
1
≤
d
i
≤
1
0
9
)
d
i
​
 (1≤d
i
​
 ≤10
9
 )
输出描述：
一行一个整数，表示讨厌鬼一定购买的商品数。
示例1
输入：
3
1 4 3
2 2 5
1 2 2
2 3 1
复制
输出：
2
复制
说明：
讨厌鬼一定会在
b
b店购买第二件，在
a
a店购买第三件商品。
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
	a := make([]int, n)
	for i, v := range strings.Split(input[1], " ") {
		a[i], _ = strconv.Atoi(v)
	}
	b := make([]int, n)
	for i, v := range strings.Split(input[2], " ") {
		b[i], _ = strconv.Atoi(v)
	}
	c := make([]int, n)
	for i, v := range strings.Split(input[3], " ") {
		c[i], _ = strconv.Atoi(v)
	}
	d := make([]int, n)
	for i, v := range strings.Split(input[4], " ") {
		d[i], _ = strconv.Atoi(v)
	}

	res := 0
	for i := 0; i < n; i++ {
		if (a[i] < b[i] && c[i] > d[i]) || (a[i] > b[i] && c[i] < d[i]) {
			res++
		}
	}
	fmt.Println(res)
}
