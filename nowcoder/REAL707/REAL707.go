/*
REAL707 小苯的文章浏览

描述
小苯是小红书的忠实用户之一。

这天，在“小红书app”发了一篇文章后，收获了若干浏览量。但其中有人浏览了多次，小苯现在想知道所有人第一次浏览的先后顺序，请你帮帮他吧。
输入描述：
输入包含
n
+
1
n+1 行。
第一行一个正整数
n

(
1
≤
n
≤
1
0
5
)
n (1≤n≤10
5
 )，表示小苯拿到的浏览记录的记录条数。
接下来每行一个字符串
s
s（长度在20）以内，表示 id 为
s
s 的用户此时浏览了一次小苯的文章。
输出描述：
输出包含若干行，每行一个字符串
s
s，表示用户的 id。按照每个浏览的用户第一次浏览的顺序输出。
示例1
输入：
8
qcjj
benh
qsmcgogo
qcjj
ducksajin
benh
ducksajin
acidlemon
复制
输出：
qcjj
benh
qsmcgogo
ducksajin
acidlemon
复制
说明：
共有以上5人点赞，按照第一次点的顺序输出即可。
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

	set := make(map[string]struct{}, 0)
	res := make([]string, 0)

	for i := 1; i <= n; i++ {
		if _, ok := set[input[i]]; !ok {
			set[input[i]] = struct{}{}
			res = append(res, input[i])
		}
	}

	ans := strings.Join(res, "\n")
	fmt.Println(ans)
}
