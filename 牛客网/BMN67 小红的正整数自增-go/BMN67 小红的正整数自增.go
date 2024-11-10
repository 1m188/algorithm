package main

import (
	"fmt"
)

func main() {
	x := uint64(0)
	fmt.Scan(&x)
	fmt.Println((10 - x%10) % 10)
}
