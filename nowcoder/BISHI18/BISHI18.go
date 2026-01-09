/*
BISHI18 多项式输出

描述
给定一元
n
n 次多项式

f
(
x
)
=
a
n
x
n
+
a
n
−
1
x
n
−
1
+
⋯
+
a
1
x
+
a
0
f(x)=a
n
​
 x
n
 +a
n−1
​
 x
n−1
 +⋯+a
1
​
 x+a
0
​
 ，

其中
a
n
≠
0
a
n
​


​
 =0，系数
a
i

(
0
≦
i
≦
n
)
a
i
​
  (0≦i≦n) 满足
−
100
≦
a
i
≦
100
−100≦a
i
​
 ≦100。

请按如下规则将多项式输出为字符串：
∙

∙ 从高次到低次依次输出；
∙

∙ 系数为
0
0 的项完全省略；
∙

∙ 对于次数大于等于
1
1 的项，若其系数为
1
1 或
−
1
−1，则省略系数的绝对值
1
1（常数项即使为
1
1 或
−
1
−1 也应完整输出）；
∙

∙ 次数为
0
0 仅输出常数；次数为
1
1 输出
x
x；次数
≧
2
≧2 输出 \texttt{x^} k；
∙

∙ 输出的第一个非零项（即最高次项）若系数为正，不输出前导加号；后续正系数项前需加
+
+，负系数项加
-
-。
输入描述：
第一行输入整数
n
(
1
≦
n
≦
100
)
n(1≦n≦100)，表示多项式次数。
第二行输入
n
+
1
n+1 个整数
a
n
,
a
n
−
1
,
…
,
a
0
a
n
​
 ,a
n−1
​
 ,…,a
0
​
 ，依次为
n
n 次项到
0
0 次项（常数项）的系数。
输出描述：
在一行输出格式化后的多项式字符串。
示例1
输入：
5
100 -1 1 -3 0 10
复制
输出：
100x^5-x^4+x^3-3x^2+10
复制
示例2
输入：
3
-50 0 0 1
复制
输出：
-50x^3+1
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

	xishu := strings.Split(input[1], " ")
	a := make([]int, n+1)
	for i := 0; i < n+1; i++ {
		a[i], _ = strconv.Atoi(xishu[i])
	}

	for i := 0; i < n+1; i++ {
		ai := a[i]
		if ai == 0 {
			continue
		}

		switch ai {
		case 1:
			if i > 0 {
				fmt.Print("+")
			}
			if i == n {
				fmt.Print("1")
			}
		case -1:
			fmt.Print("-")
			if i == n {
				fmt.Print("1")
			}
		default:
			if i == 0 {
				fmt.Printf("%d", ai)
			} else {
				if ai > 0 {
					fmt.Printf("+%d", ai)
				} else {
					fmt.Printf("%d", ai)
				}
			}
		}

		if i == n-1 {
			fmt.Print("x")
		} else if i < n-1 {
			fmt.Printf("x^%d", n-i)
		}
	}
}
