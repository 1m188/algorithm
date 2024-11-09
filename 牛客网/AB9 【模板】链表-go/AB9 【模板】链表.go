package main

import (
	"bufio"
	"fmt"
	"os"
)

type Node struct {
	val  int
	next *Node
}

func insert(head *Node, x, y int) {
	node := Node{val: y}
	cur := head
	for cur.next != nil {
		if cur.next.val == x {
			node.next = cur.next
			cur.next = &node
			return
		}
		cur = cur.next
	}
	cur.next = &node
}

func delete(head *Node, x int) {
	cur := head
	for cur.next != nil {
		if cur.next.val == x {
			cur.next = cur.next.next
			return
		}
		cur = cur.next
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	head := Node{}

	n := 0
	fmt.Fscan(in, &n)

	for ; n > 0; n-- {
		op := ""
		fmt.Fscan(in, &op)
		if op == "insert" {
			x, y := 0, 0
			fmt.Fscan(in, &x, &y)
			insert(&head, x, y)
		} else {
			x := 0
			fmt.Fscan(in, &x)
			delete(&head, x)
		}
	}

	if head.next == nil {
		fmt.Fprintln(out, "NULL")
	} else {
		fmt.Fprint(out, head.next.val)
		cur := head.next.next
		for cur != nil {
			fmt.Fprintf(out, "%c", ' ')
			fmt.Fprint(out, cur.val)
			cur = cur.next
		}
	}
}
