/*
HJ94 记票统计

描述
某场选举一共有
n
n 位候选人入选，候选人的名字均由大写字母构成，且互不相同，使用
c
1
,
c
2
,
…
,
c
n
c
1
​
 ,c
2
​
 ,…,c
n
​
  表示。
选举结束后，统计了
m
m 张选票，每张选票上均写有候选人的名字，使用
v
1
,
v
2
,
…
,
v
m
v
1
​
 ,v
2
​
 ,…,v
m
​
  表示。
求解每个候选人获得的票数。特别地，如果某张选票上的候选人名字不在候选名单中，则该票视为无效票。你需要同时统计无效票的数量。
输入描述：
第一行输入一个整数
n
(
1
≦
n
≦
100
)
n(1≦n≦100) 代表候选人数。
第二行输入
n
n 个长度为
1
≦
l
e
n
(
c
i
)
≦
10
1≦len(c
i
​
 )≦10、仅由大写字母构成的字符串
c
1
,
c
2
,
…
,
c
n
c
1
​
 ,c
2
​
 ,…,c
n
​
 ，代表候选人的名字。保证候选人的名字互不相同。
第三行输入一个整数
m
(
1
≦
m
≦
100
)
m(1≦m≦100) 代表投票人数。
第四行输入
m
m 个长度为
1
≦
l
e
n
(
v
i
)
≦
10
1≦len(v
i
​
 )≦10、仅由大写字母构成的字符串
v
1
,
v
2
,
…
,
v
m
v
1
​
 ,v
2
​
 ,…,v
m
​
 ，代表投票内容。
输出描述：
对于每一位候选人，新起一行。先输出其名字，随后输出一个空格、一个冒号、一个空格作为间隔，最后输出其获得的票数。形如
c
i

:

n
u
m
b
e
r
s
i
c
i
​
  : numbers
i
​
 ，其中
c
i
c
i
​
  是候选人的名字，
n
u
m
b
e
r
s
i
numbers
i
​
  是候选人的票数。
最后一行以相同的格式输出无效票的数量。形如
Invalid

:

n
u
m
b
e
r
s
Invalid : numbers，其中
n
u
m
b
e
r
s
numbers 是无效票的数量。
示例1
输入：
4
A B C D
8
A D E CF A GG A B
复制
输出：
A : 3
B : 1
C : 0
D : 1
Invalid : 3
复制
说明：
在这个样例中，
E
,
CF
,
GG
E,CF,GG 三张票是无效的。
*/

package main

import (
	"fmt"
)

func main() {

	n := 0
	fmt.Scan(&n)
	c := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&c[i])
	}
	m := 0
	fmt.Scan(&m)
	v := make([]string, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&v[i])
	}

	mmap := make(map[string]int, n)
	for _, v := range c {
		mmap[v] = 0
	}

	invalid := 0

	for _, v := range v {
		if _, ok := mmap[v]; ok {
			mmap[v]++
		} else {
			invalid++
		}
	}

	for _, v := range c {
		fmt.Printf("%s : %d\n", v, mmap[v])
	}
	fmt.Printf("Invalid : %d\n", invalid)

}
