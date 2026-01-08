/*
BISHI19 乒乓球

描述
旺仔哥哥特别喜欢打乒乓球，有一天他给你一串由字符
W
W 与
L
L 组成的比赛记录，
W
W 表示旺仔哥哥得分，
L
L 表示对手得分。

请分别按11 分制与21 分制统计比赛结果，并输出每局比分。规则如下：
∙

∙ 当且仅当一局比赛中存在某个选手分数不小于
11
11（或
21
21）且双方比分差
≧
2
≧2 时，判定一局结束，此时得分高的选手获胜；
∙

∙ 若读取结束时当前局未结束，也需输出当前比分；
∙

∙ 新局开始时比分记为
0
:
0
0:0。
输入描述：
一行一个字符串
s
(
1
≦
∣
s
∣
≦
1
0
5
,
s
i
∈
{
W
,
L
}
)
s(1≦∣s∣≦10
5
 ,s
i
​
 ∈{W,L})，表示比赛记录。
输出描述：
输出两部分，每部分若干行，每行为一局的比分，形如
旺仔哥哥的得分
:
对手得分
旺仔哥哥的得分:对手得分，按照记录顺序：
∙

∙ 第一部分为 11 分制结果；
∙

∙ 空行分隔后，第二部分为 21 分制结果。
示例1
输入：
WWWWWWWWWWWWWWWWWWWWWWLW
复制
输出：
11:0
11:0
1:1

21:0
2:1

*/

package main

import (
	"fmt"
	"io/ioutil"
	"math"
	"os"
)

func main() {
	data, _ := ioutil.ReadAll(os.Stdin)
	input := string(data)
	line := input[:len(input)-1]

	calc := func(score int) {
		W, L := 0, 0
		for _, c := range line {
			if c == 'W' {
				W++
			} else {
				L++
			}
			if (W >= score || L >= score) && math.Abs(float64(W-L)) >= 2 {
				fmt.Printf("%d:%d\n", W, L)
				W, L = 0, 0
			}
		}
		fmt.Printf("%d:%d\n", W, L)
	}

	calc(11)
	fmt.Println()
	calc(21)
}
