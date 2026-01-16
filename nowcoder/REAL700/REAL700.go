/*
REAL700 小红刷小红书

描述
小红很喜欢刷小红书。她记录了一周七天每天刷小红书的开始时间和结束时间。请你帮小红计算她总共刷了多少分钟。
注：小红有可能在当天的凌晨12点后结束刷小红书！
输入描述：
输入14行字符串，每两行代表一天的开始时间和结束时间。
保证开始时间一定迟于17:00，结束时间一定早于03:00（即小红在下午5点之后才会开始刷小红书，且一定会在凌晨3点前睡觉）。
输出描述：
一个整数，代表小红总共刷小红书的时间。
示例1
输入：
20:00
21:00
20:00
23:30
21:00
02:00
00:12
00:30
18:30
19:00
23:00
23:05
18:00
01:00
复制
输出：
1043
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

	time2minute := func(time string) int {
		hour, _ := strconv.Atoi(time[:2])
		minute, _ := strconv.Atoi(time[3:])
		return hour*60 + minute
	}

	var total int
	for i := 0; i < len(input); i += 2 {
		start := time2minute(input[i])
		end := time2minute(input[i+1])
		if end >= start {
			total += end - start
		} else {
			total += 24*60 - start + end
		}
	}
	fmt.Println(total)
}
