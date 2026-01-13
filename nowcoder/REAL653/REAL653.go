/*
REAL653 藻类植物

描述
我们用
x
i
x
i
​
  表示第
i
i 年年初池塘中藻类植物的总重量，那么池塘中藻类植物的发展满足这个规律：
x
i
+
1
=
r
×
x
i
−
d
x
i+1
​
 =r×x
i
​
 −d
现在给你
r
,
d
,
x
2024
r,d,x
2024
​
 ，请你计算未来十年里每年年初池塘中藻类植物的总重量。
输入描述：
在一行中给出三个正整数
r
,
d
,
x
2024
r,d,x
2024
​
  ，含义如题所示
2
≤
r
≤
5
,
1
≤
d
≤
100
,
d
≤
x
2024
≤
200
2≤r≤5,1≤d≤100,d≤x
2024
​
 ≤200
输出描述：
共输出
10
10 行，依次为
x
2025
,
x
2026
,
⋯

,
x
2034
x
2025
​
 ,x
2026
​
 ,⋯,x
2034
​

示例1
输入：
2 10 20
复制
输出：
30
50
90
170
330
650
1290
2570
5130
10250
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
	input := strings.Split(strings.TrimSpace(string(data)), " ")
	r, _ := strconv.Atoi(input[0])
	d, _ := strconv.Atoi(input[1])
	x, _ := strconv.Atoi(input[2])
	for i := 0; i < 10; i++ {
		x = r*x - d
		fmt.Println(x)
	}
}
