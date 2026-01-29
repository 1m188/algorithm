/*
快速幂
*/

package quickpow

import (
	"fmt"
	"math/big"
)

// 大数算法，适配高精度
func quickpow(x *big.Int, n *big.Int) (*big.Int, error) {
	if x.Cmp(big.NewInt(0)) == 0 {
		return big.NewInt(0), nil
	}

	if n.Cmp(big.NewInt(0)) < 0 {
		return x, fmt.Errorf("n: %v, which must be greater or equal than 0", n)
	}

	if n.Cmp(big.NewInt(0)) == 0 {
		return big.NewInt(1), nil
	}
	if n.Cmp(big.NewInt(1)) == 0 {
		return x, nil
	}

	n_str := n.String()
	last := n_str[len(n_str)-1]
	if last == '0' || last == '2' || last == '4' || last == '6' || last == '8' {
		x_new, n_new := new(big.Int), new(big.Int)
		return quickpow(x_new.Mul(x, x), n_new.Rsh(n, 1))
	} else {
		x_new, n_new := new(big.Int), new(big.Int)
		a, err := quickpow(x_new.Mul(x, x), n_new.Rsh(n, 1))
		if err != nil {
			return a, err
		}
		return a.Mul(x, a), nil
	}
}
