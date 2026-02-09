package fibonaccigo

import (
	"math/big"
	"runtime/debug"
	"testing"
)

func testFib(t *testing.T, fib func(*big.Int) (*big.Int, error)) {
	assert := func(condition bool, message string) {
		if !condition {
			t.Fatal(message + "\n\n" + string(debug.Stack()))
		}
	}

	x, e := fib(big.NewInt(0))
	assert(e != nil, "fib(0) error")

	x, e = fib(big.NewInt(-1))
	assert(e != nil, "fib(-1) error")

	x, e = fib(big.NewInt(1))
	assert(e == nil && x.Cmp(big.NewInt(1)) == 0, "fib(1) error")

	x, e = fib(big.NewInt(2))
	assert(e == nil && x.Cmp(big.NewInt(1)) == 0, "fib(2) error")

	x, e = fib(big.NewInt(3))
	assert(e == nil && x.Cmp(big.NewInt(2)) == 0, "fib(3) error")

	x, e = fib(big.NewInt(4))
	assert(e == nil && x.Cmp(big.NewInt(3)) == 0, "fib(4) error")

	x, e = fib(big.NewInt(5))
	assert(e == nil && x.Cmp(big.NewInt(5)) == 0, "fib(5) error")

	x, e = fib(big.NewInt(6))
	assert(e == nil && x.Cmp(big.NewInt(8)) == 0, "fib(6) error")

	x, e = fib(big.NewInt(7))
	assert(e == nil && x.Cmp(big.NewInt(13)) == 0, "fib(7) error")

	x, e = fib(big.NewInt(8))
	assert(e == nil && x.Cmp(big.NewInt(21)) == 0, "fib(8) error")

	x, e = fib(big.NewInt(9))
	assert(e == nil && x.Cmp(big.NewInt(34)) == 0, "fib(9) error")

	x, e = fib(big.NewInt(10))
	assert(e == nil && x.Cmp(big.NewInt(55)) == 0, "fib(10) error")
}

func TestFib(t *testing.T) {
	testFib(t, fibonacci_circle)
	testFib(t, fibonacci_recursion)
	testFib(t, fibonacci_recursion_tail)

	x, _ := fibonacci_circle(big.NewInt(114514))
	t.Logf("fib(114514) = %v", x)
}
