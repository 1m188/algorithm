/*
HJ49 分数线划定

描述
某市为世博会选拔志愿者，先进行笔试，再按笔试成绩划定面试分数线。规则如下：
∙

∙ 计划最终录取
m
m 名志愿者；
∙

∙ 面试名额定为
m
m 的
150
%
150%，向下取整，记为
t
=
⌊
1.5
m
⌋
t=⌊1.5m⌋；
∙

∙ 将所有报名号及笔试成绩按成绩从高到低、成绩相同报名号从小到大排序；
∙

∙ 第
t
t 名选手的成绩即为面试分数线；
∙

∙ 所有笔试成绩不低于该分数线的选手均进入面试。

请输出面试分数线及所有进入面试选手的信息（按排序后的顺序）。
输入描述：
第一行输入两个整数
n
,
m
(
5
≦
n
≦
5000
;

3
≦
m
≦
n
)
n,m(5≦n≦5000; 3≦m≦n)，分别表示报名人数与计划录取人数。
接下来
n
n 行，每行输入两个整数
k
,
s

(
1000
≦
k
≦
9999
;

1
≦
s
≦
100
)
k,s (1000≦k≦9999; 1≦s≦100)，分别为报名号与笔试成绩。报名号保证唯一。
输出描述：
第一行输出两个整数：面试分数线
line
line 与进入面试的人数
c
n
t
cnt。
接下来
c
n
t
cnt 行，按排序顺序输出每位选手的报名号
k
k 与成绩
s
s，每行两个整数，用空格分隔。
示例1
输入：
6 3
9848 90
6731 88
1422 95
7483 84
8805 95
4162 88
复制
输出：
88 5
1422 95
8805 95
9848 90
4162 88
6731 88
复制
说明：
计算：
t
=
⌊
1.5
×
3
⌋
=
4
t=⌊1.5×3⌋=4，第
4
4 名成绩为
88
88，故分数线
=
88
=88；所有
≧
88
≧88 的共有
5
5 人。
*/

package main

import (
	"fmt"
	"sort"
)

type Student struct {
	ID    int
	Score int
}

func (s Student) Cmp(other Student) int {
	if s.Score == other.Score {
		return other.ID - s.ID
	}
	return s.Score - other.Score
}

func main() {

	var n, m int
	fmt.Scan(&n, &m)

	stus := make([]Student, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&stus[i].ID, &stus[i].Score)
	}

	sort.Slice(stus, func(i, j int) bool {
		return stus[i].Cmp(stus[j]) > 0
	})

	t := int(1.5 * float64(m))
	if t >= n {
		t = n
	}

	line, cnt := stus[t-1].Score, t
	for i := t; i < n; i++ {
		if stus[i].Score == line {
			cnt++
		}
	}

	fmt.Println(line, cnt)
	for i := 0; i < cnt; i++ {
		fmt.Println(stus[i].ID, stus[i].Score)
	}

}
