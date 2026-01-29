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

	stack := []int{}

	n := 0
	fmt.Fscan(in, &n)

	for ; n > 0; n-- {
		op := ""
		fmt.Fscan(in, &op)
		if op == "push" {
			x := 0
			fmt.Fscan(in, &x)
			stack = append(stack, x)
		} else if op == "pop" {
			if len(stack) == 0 {
				fmt.Fprintln(out, "error")
			} else {
				x := stack[len(stack)-1]
				stack = stack[:len(stack)-1]
				fmt.Fprintln(out, x)
			}
		} else if op == "top" {
			if len(stack) == 0 {
				fmt.Fprintln(out, "error")
			} else {
				x := stack[len(stack)-1]
				fmt.Fprintln(out, x)
			}
		}
	}
}
