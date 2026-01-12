/*
REAL646 小红浏览论坛

描述
小红喜欢浏览论坛。论坛的每个贴子能被浏览者点赞或反对。假设点赞数为
a
a，反对数为
b
b，小红喜欢阅读
∣
a
−
b
∣
≥
x
∣a−b∣≥x的贴子。
现在有
n
n个贴子，给出每个帖子的点赞数和反对数，问小红喜欢阅读其中多少个帖子？
输入描述：
第一行输入两个整数
n
,
x
n,x。
接下来
n
n行每行输入两个整数
a
i
,
b
i
a
i
​
 ,b
i
​
 ，代表每个帖子的点赞数和反对数。
1
≤
n
,
x
,
a
i
,
b
i
≤
100
1≤n,x,a
i
​
 ,b
i
​
 ≤100
输出描述：
输出一个整数。
示例1
输入：
3 2
1 3
2 1
4 2
复制
输出：
2
*/

package main

import (
	"fmt"
	"io/ioutil"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	data, _ := ioutil.ReadAll(os.Stdin)
	input := strings.Split(strings.TrimSpace(string(data)), "\n")
	// n, _ := strconv.Atoi(strings.Split(input[0], " ")[0])
	x, _ := strconv.Atoi(strings.Split(input[0], " ")[1])
	var res int
	for i := 1; i < len(input); i++ {
		ab := strings.Split(input[i], " ")
		a, _ := strconv.Atoi(ab[0])
		b, _ := strconv.Atoi(ab[1])
		if int(math.Abs(float64(a-b))) >= x {
			res++
		}
	}
	fmt.Println(res)
}
