/*
HJ144 小红书推荐系统

描述
小红书有一个推荐系统，可以根据用户搜索的关键词推荐用户希望获取的内容。
现在给定小红的搜索记录（记录为分词后的结果），我们认为当一个单词出现的次数不少于3次时，该单词为“用户期望搜索的单词”，即称为关键词。请你根据小红的记录，输出小红的用户画像对应的所有关键词。
输入描述：
一行字符串，仅由小写字母和空格组成。代表小红的搜索记录。
字符串长度不超过100000。
输出描述：
小红所有的关键词。每行输入一个。你需要按照搜索频次从高到低输出。频次相同的，你需要按字典序升序输出。
示例1
输入：
kou red game red ok who game red karaoke yukari kou red red nani kou can koukou ongakugame game
复制
输出：
red
game
kou
*/

package main

import (
	"bufio"
	"os"
	"sort"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	line, _ := in.ReadString('\n')
	line = line[:len(line)-1]
	li := strings.Split(line, " ")

	mmap := make(map[string]int)
	for _, v := range li {
		mmap[v]++
	}

	keys := make([]string, 0, len(mmap))
	for k, v := range mmap {
		if v >= 3 {
			keys = append(keys, k)
		}
	}

	sort.Slice(keys, func(i, j int) bool {
		k1, k2 := keys[i], keys[j]
		v1, v2 := mmap[k1], mmap[k2]
		if v1 != v2 {
			return v1 > v2
		}
		return k1 < k2
	})

	for _, k := range keys {
		out.WriteString(k + "\n")
	}
}
