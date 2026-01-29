/*
REAL712 小红的粉丝数量

描述
小红有
n
n 个小红书账号，第
i
i 个账号中都有
m
i
m
i
​
  个粉丝，但有些粉丝可能关注了小红多个账号。

小红现在已知了自己每个账号中所有粉丝的ID（假设ID是唯一的，每个账号内的粉丝ID都不相同），他想知道自己共有多少粉丝。
输入描述：
输入包含若干行。
第一行一个正整数
n
(
1
≤
n
≤
300
)
n(1≤n≤300)，表示小红的账号个数。
接下来，对于每个账号，输入包含两行。
第一行一个正整数
m
(
1
≤
m
≤
300
)
m(1≤m≤300)，表示小红第
i
i 个账号的粉丝数。
第二行
m
m 个字符串，表示小红第
i
i 个账号中，所有粉丝的 ID。（保证ID长度不超过20，且仅由小写英文字母组成）
输出描述：
输出包含一行一个正整数，表示小红的总粉丝数。
示例1
输入：
3
4
qcjj qsmcgogo ducksajin acidlemon
4
qionghua benh jch qsmcgogo
2
qcjj pcmsdodo
复制
输出：
8
复制
说明：
他共有：qcjj, qsmcgogo, ducksajin, acidlemon, qionghua, benh, jch, pcmsdodo 这8个粉丝
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

	fans := make(map[string]struct{})

	for i := 1; i <= n*2; i += 2 {
		IDs := strings.Split(inputs[i+1], " ")
		for _, id := range IDs {
			fans[id] = struct{}{}
		}
	}

	fmt.Println(len(fans))
}
