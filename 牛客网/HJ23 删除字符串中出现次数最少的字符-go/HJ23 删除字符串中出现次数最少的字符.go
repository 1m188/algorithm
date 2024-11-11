/*
描述
实现删除字符串中出现次数最少的字符，若出现次数最少的字符有多个，则把出现次数最少的字符都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。

数据范围：输入的字符串长度满足
1
≤
n
≤
20

1≤n≤20  ，保证输入的字符串中仅出现小写字母
输入描述：
字符串只包含小写英文字母, 不考虑非法输入，输入的字符串长度小于等于20个字节。

输出描述：
删除字符串中出现次数最少的字符后的字符串。

示例1
输入：
aabcddd
复制
输出：
aaddd
*/

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	s := ""
	fmt.Fscan(in, &s)

	cnts := make([][]int, 26)
	for i, _ := range cnts {
		cnts[i] = make([]int, 2)
		cnts[i][0] = 'a' + i
	}

	for _, c := range s {
		cnts[c-'a'][1]++
	}

	idx := 0
	for i := 0; i < len(cnts); i++ {
		if cnts[i][1] == 0 {
			continue
		}
		if cnts[idx][1] == 0 {
			idx = i
			continue
		}
		if cnts[i][1] < cnts[idx][1] {
			idx = i
		}
	}

	flags := make([]bool, 26)
	for i := 0; i < len(cnts); i++ {
		if cnts[i][1] == cnts[idx][1] {
			flags[cnts[i][0]-'a'] = true
		}
	}

	for _, c := range s {
		if flags[c-'a'] {
			continue
		}
		fmt.Fprintf(out, "%c", c)
	}
}
