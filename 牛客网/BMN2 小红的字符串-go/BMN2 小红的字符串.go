package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	str := ""
	fmt.Fscan(in, &str)

	li := []string{}
	for i := 0; i < len(str)-1; i++ {
		li = append(li, str[i:i+2])
	}

	sort.Strings(li)

	for _, v := range li {
		fmt.Fprintln(out, v)
	}
}
