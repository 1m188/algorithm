package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	x := 0
	fmt.Fscan(in, &x)

	str := strconv.Itoa(x)
	for i := 0; i <= len(str); i++ {
		for n := '0'; n <= '9'; n++ {
			xx := str[:i] + string(n) + str[i:]
			tmp, _ := strconv.ParseInt(xx, 10, 64)
			if tmp%7 == 0 {
				fmt.Fprintln(out, xx) // 原来这里不是输出数字，而是输出加了数的字符串，这意味着可以出现前导零...
				return
			}
		}
	}
}
