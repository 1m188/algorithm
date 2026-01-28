/*
ACM3723 hanayo和米饭

hanayo很喜欢吃米饭。
有一天，她拿出了
n

n  个碗，第一个碗装了
1

1  粒米饭，第二个碗装了
2

2  粒米饭，以此类推，第
n

n  个碗装了
n

n  粒米饭。
然而，爱搞恶作剧的rin把所有的碗的顺序打乱，并拿走了一个碗。hanayo想知道，rin拿走的碗里有多少粒米饭？
输入描述：
第一行输入一个正整数
n

n  。代表原始的总碗数。
第二行输入
n
−
1

n−1  个正整数
a
i
a
i
​
  ，代表目前每碗里米饭数量。
保证输入合法。
(
2
≤
n
≤
100000
，
1
≤
a
i
≤
n
)

(2≤n≤100000，1≤a
i
​
 ≤n)
输出描述：
输出一个正整数，代表rin拿走的碗里米饭数量。
示例1
输入：
5
2 5 1 3
复制
输出：
4
复制
说明：
开始共有5个碗，每个碗内分别有1、2、3、4、5粒米饭。rin拿走的是第四碗。这么简单的样例连tairitsu都看得懂好伐~
备注：
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
	n, _ := strconv.Atoi(inputs[0])

	res := 0
	for i := 1; i <= n; i++ {
		res ^= i
	}

	for _, v := range strings.Split(inputs[1], " ") {
		a, _ := strconv.Atoi(v)
		res ^= a
	}

	fmt.Println(res)
}
