/*
REAL692 小红的笔记打卡

描述
小红经常去小红书发布笔记。这天她统计了她一周每天的发布笔记情况，请你计算小红一共有多少天发布了笔记。
输入描述：
一个长度为 7 的、仅由'O'和'X'组成的字符串。'O'代表当天发布了笔记，'X'代表未发布笔记。
输出描述：
一个整数，代表发布了笔记的天数。
示例1
输入：
OXXXXXO
复制
输出：
2
复制
说明：
只有周一和周日发布了笔记。
*/

package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

func main() {
	data, _ := ioutil.ReadAll(os.Stdin)
	input := strings.TrimSpace(string(data))
	res := 0
	for _, v := range input {
		if v == 'O' {
			res++
		}
	}
	fmt.Println(res)
}
