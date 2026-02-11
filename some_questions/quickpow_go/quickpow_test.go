package quickpow

import (
	"math/big"
	"testing"
)

func TestQuickPow(t *testing.T) {

	test := func(x *big.Int, n *big.Int, z *big.Int) {
		ans, err := QuickPow(x, n)
		if err != nil {
			t.Fatal(err)
		}
		if ans.Cmp(z) != 0 {
			t.Fatalf("%v ^ %v = %v, expect %v", x, n, ans, z)
		}
		t.Logf("%v ^ %v = %v\n", x, n, ans)
	}

	z, _ := new(big.Int).SetString("1024", 10)
	test(big.NewInt(2), big.NewInt(10), z)

	z, _ = new(big.Int).SetString("129140163", 10)
	test(big.NewInt(3), big.NewInt(17), z)

	z, _ = new(big.Int).SetString("2384185791015625", 10)
	test(big.NewInt(5), big.NewInt(22), z)

	z, _ = new(big.Int).SetString("-106993205379072", 10)
	test(big.NewInt(-12), big.NewInt(13), z)

	z, _ = new(big.Int).SetString("1", 10)
	test(big.NewInt(1228), big.NewInt(0), z)

	z, _ = new(big.Int).SetString("0", 10)
	test(big.NewInt(0), big.NewInt(128), z)

	z, _ = new(big.Int).SetString("11790184577738583171520872861412518665678211592275841109096961", 10)
	test(big.NewInt(3), big.NewInt(128), z)

}
