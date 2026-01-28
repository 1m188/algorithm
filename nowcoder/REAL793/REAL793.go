/*
REAL793 小O的糖果

描述
小O有三盒糖果，糖果数分别为
a
,
b
a,b 和
c
c 。
现在小O又有了
x
x 颗糖果，他要把这
x
x 颗糖果恰好分到新的
k
k 个盒子里面去，保证每一个盒子里至少有一颗糖果。这样他就拥有了
k
+
3
k+3 盒糖果，然后他会在这
k
+
3
k+3 盒糖果中挑选出最多的那一盒糖果。
显然，
x
x 颗糖果分到
k
k 个盒子里往往不止一种方案。小O想知道，无论他如何分配这
x
x 颗糖果，糖果最多的那一个盒子的编号是否确定且唯一。
输入描述：
第一行输入三个整数
a
,
b
a,b 和
c

(
1
≤
a
,
b
,
c
≤
1
0
9
)
c (1≤a,b,c≤10
9
 ) 表示初始三盒糖果的个数。
第二行输入两个整数
x
x 和
k

(
1
≤
k
≤
x
≤
1
0
9
)
k (1≤k≤x≤10
9
 ) 代表小O新获得的糖果个数，和需要新放入糖果的盒子数。
输出描述：
如果糖果最多的那一个盒子的编号确定且唯一，输出“
Y
E
S
YES”
，否则，输出“
N
O
NO”。

示例1
输入：
4 2 3
2 2
复制
输出：
YES
复制
示例2
输入：
5 3 6
100 2
复制
输出：
NO
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
	inputs := strings.Split(strings.TrimSpace(string(data)), "\n")

	abc := strings.Split(inputs[0], " ")
	a, _ := strconv.Atoi(abc[0])
	b, _ := strconv.Atoi(abc[1])
	c, _ := strconv.Atoi(abc[2])

	xk := strings.Split(inputs[1], " ")
	x, _ := strconv.Atoi(xk[0])
	k, _ := strconv.Atoi(xk[1])

	if k == 1 {
		if a != b && a != c && a != x && b != c && b != x && c != x {
			fmt.Println("YES")
			return
		}
	} else {
		max_val := a
		if b > max_val {
			max_val = b
		}
		if c > max_val {
			max_val = c
		}

		if max_val > x-k+1 {
			fmt.Println("YES")
			return
		}
	}

	fmt.Println("NO")
}
