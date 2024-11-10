package main

import (
	"fmt"
	"strconv"
)

func main() {
	x := 0
	fmt.Scan(&x)

	str := strconv.Itoa(x)
	for i := 0; i <= len(str); i++ {
		for n := '0'; n <= '9'; n++ {
			xx := str[:i] + string(n) + str[i:]
			tmp, _ := strconv.Atoi(xx)
			if tmp%7 == 0 {
				fmt.Println(xx) // 原来这里不是输出数字，而是输出加了数的字符串，这意味着可以出现前导零...
				return
			}
		}
	}
}
