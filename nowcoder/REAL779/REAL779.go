/*
REAL779 诗

描述
游游有一个由小写字母组成的字符串
s
s ，他按照以下方式从头开始书写这个字符串：
∙

∙ 书写接下来的
1
1 个字母，换行；
∙

∙ 书写接下来的
2
2 个字母，换行；
∙

∙ ……
∙

∙ 书写接下来的
i
i 个字母，换行；
∙

∙ 书写接下来的
i
+
1
i+1 个字母，换行；
当字符串剩余的字符不足以满足当前需要书写的字符数时，书写完剩余字符后停止。直接输出将每一行首字母从上到下依次连接得到的字符串。
输入描述：
在一行上输入一个仅由小写字母组成的字符串
s
s ，长度为
1
≦
∣
s
∣
≦
1
0
5
1≦∣s∣≦10
5
  。
输出描述：
在一行上输出一个字符串代表答案。
示例1
输入：
helloworld
复制
输出：
helo
复制
说明：
书写过程：
∙

∙ 第一行：h （取 1 个字母）
∙

∙ 第二行：el （取 2 个字母）
∙

∙ 第三行：low （取 3 个字母）
∙

∙ 第四行：orld （取 4 个字母）
每行的首字母依次为：h、e、l、o 。
示例2
输入：
hello
复制
输出：
hel
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
	s := strings.TrimSpace(string(data))
	res := make([]byte, 0)
	cnt := 1
	index := 0
	for index+cnt <= len(s) {
		res = append(res, s[index : index+cnt][0])
		index += cnt
		cnt++
	}
	if index < len(s) {
		res = append(res, s[index])
	}
	fmt.Println(string(res))
}
