package main

import (
	"fmt"
	"strings"
)

func main() {
	n, k := 0, 0
	fmt.Scan(&n, &k)

	if k*3 > n {
		fmt.Println(-1)
		return
	}

	res := strings.Builder{}
	for i := 0; i < k; i++ {
		res.WriteString("you")
	}
	for res.Len() < n {
		res.WriteRune('u')
	}
	fmt.Println(res.String())
}
