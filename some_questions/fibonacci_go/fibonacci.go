/*
基于 golang 的斐波那契数列计算实现

求 斐波那契数列的第 n 项
*/

package fibonaccigo

import (
	"fmt"
	"math/big"
)

// 斐波那契数列计算(非递归)
func fibonacci_circle(n *big.Int) (*big.Int, error) {
	if n.Cmp(big.NewInt(0)) <= 0 {
		return nil, fmt.Errorf("n must be greater than 0")
	}

	if n.Cmp(big.NewInt(1)) == 0 {
		return big.NewInt(1), nil
	}

	if n.Cmp(big.NewInt(2)) == 0 {
		return big.NewInt(1), nil
	}

	a, b := big.NewInt(1), big.NewInt(1)
	for i := big.NewInt(3); i.Cmp(n) <= 0; i.Add(i, big.NewInt(1)) {
		a, b = b, a.Add(a, b)
	}
	return b, nil
}

// 斐波那契数列计算(递归)
func fibonacci_recursion(n *big.Int) (*big.Int, error) {
	if n.Cmp(big.NewInt(0)) <= 0 {
		return nil, fmt.Errorf("n must be greater than 0")
	}

	if n.Cmp(big.NewInt(1)) == 0 {
		return big.NewInt(1), nil
	}

	if n.Cmp(big.NewInt(2)) == 0 {
		return big.NewInt(1), nil
	}

	a, _ := fibonacci_recursion((&big.Int{}).Sub(n, big.NewInt(1)))
	b, _ := fibonacci_recursion((&big.Int{}).Sub(n, big.NewInt(2)))
	return a.Add(a, b), nil
}

// 斐波那契数列计算(尾递归)
func fibonacci_recursion_tail(n *big.Int) (*big.Int, error) {
	if n.Cmp(big.NewInt(0)) <= 0 {
		return nil, fmt.Errorf("n must be greater than 0")
	}

	if n.Cmp(big.NewInt(1)) == 0 {
		return big.NewInt(1), nil
	}

	if n.Cmp(big.NewInt(2)) == 0 {
		return big.NewInt(1), nil
	}

	var tail func(a, b *big.Int, n *big.Int) *big.Int
	tail = func(a, b *big.Int, n *big.Int) *big.Int {
		if n.Cmp(big.NewInt(2)) == 0 {
			return b
		}
		return tail(b, a.Add(a, b), n.Sub(n, big.NewInt(1)))
	}
	return tail(big.NewInt(1), big.NewInt(1), n), nil
}
