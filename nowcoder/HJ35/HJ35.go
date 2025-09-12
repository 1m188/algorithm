/*
HJ35 蛇形矩阵

描述
你需要输出一个
n
n 行
n
n 列的上三角形蛇形矩阵。
具体的构造方法为，从
1
1 开始填充自然数，记第
i
i 行第
1
1 列的元素为
a
i
,
1
=
k
a
i,1
​
 =k ，将其右上角的元素
a
i
−
1
,
2
,
a
i
−
2
,
3
,
⋯

,
a
1
,
i
a
i−1,2
​
 ,a
i−2,3
​
 ,⋯,a
1,i
​
  依次赋值为
k
+
1
,
k
+
2
,
⋯

,
k
+
i
−
1
k+1,k+2,⋯,k+i−1 ，随后，将
a
i
,
2
a
i,2
​
  赋值为
k
+
i
k+i ，并重复上述过程，直到填满上三角范围
n
(
n
+
1
)
2
2
n(n+1)
​
  个格子。
输入描述：
在一行上输入一个整数
n
(
1
≦
n
≦
100
)
n(1≦n≦100) 代表矩阵的大小。
输出描述：
输出一个
n
n 行
n
n 列的上三角蛇形矩阵。
示例1
输入：
4
复制
输出：
1 3 6 10
2 5 9
4 8
7
复制
说明：
第一步，
k
=
1
k=1 ，将
a
1
,
1
=
1
a
1,1
​
 =1 ；
第二步，
k
=
2
k=2 ，将
a
2
,
1
=
2
a
2,1
​
 =2 、
a
1
,
2
=
3
a
1,2
​
 =3 ；
第三步，
k
=
4
k=4 ，将
a
3
,
1
=
4
a
3,1
​
 =4 、
a
2
,
2
=
5
a
2,2
​
 =5 、
a
1
,
3
=
6
a
1,3
​
 =6 ；
第四步，
k
=
7
k=7 ，将
a
4
,
1
=
7
a
4,1
​
 =7 、
a
3
,
2
=
8
a
3,2
​
 =8 、
a
2
,
3
=
9
a
2,3
​
 =9 、
a
1
,
4
=
10
a
1,4
​
 =10 。
[
1
]
→
[
1
3
2
]
→
[
1
3
6
2
5
4
]
→
[
1
3
6
10
2
5
9
4
8
7
]
⎣
⎢
⎢
⎡
​

1
​

​

​

​

⎦
⎥
⎥
⎤
​
 →
⎣
⎢
⎢
⎡
​

1
2
​

3
​

​

​

⎦
⎥
⎥
⎤
​
 →
⎣
⎢
⎢
⎡
​

1
2
4
​

3
5
​

6
​

​

⎦
⎥
⎥
⎤
​
 →
⎣
⎢
⎢
⎡
​

1
2
4
7
​

3
5
8
​

6
9
​

10
​

⎦
⎥
⎥
⎤
​

*/

package main

import (
	"bufio"
	"os"
	"strconv"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	n, _ := strconv.Atoi(in.Text())

	mat := make([][]int, n)
	for i := 0; i < n; i++ {
		mat[i] = make([]int, n)
	}

	k := 1
	starti := 0
	i, j := 0, 0

	for i < n {
		mat[i][j] = k
		k++
		i--
		j++
		for i >= 0 && i < n && j >= 0 && j < n {
			mat[i][j] = k
			k++
			i--
			j++
		}

		i = starti + 1
		j = 0
		starti++
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if mat[i][j] > 0 {
				out.WriteString(strconv.Itoa(mat[i][j]) + " ")
			} else {
				out.WriteString(" " + " ")
			}
		}
		out.WriteString("\n")
	}
}
