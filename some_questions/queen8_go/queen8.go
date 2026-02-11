/*
八皇后问题

棋盘上八行八列，有八个皇后，每个皇后不能在同一行、同一列、同一对角线上，求出所有解法的数目

经典回溯算法
*/

package queen8go

// 推广到一般 N 皇后问题上
func QueenN(n int) int {
	if n <= 0 {
		return 0
	}
	if n == 1 {
		return 1
	}

	vec := make([][]bool, n)
	for i := range n {
		vec[i] = make([]bool, n)
	}

	var count int

	judge := func(row, col int) bool {
		for i := range n {
			if (i != row && vec[i][col]) || (i != col && vec[row][i]) {
				return false
			}
		}

		for i, j := row, col; i >= 0 && j >= 0; i, j = i-1, j-1 {
			if i != row && j != col && vec[i][j] {
				return false
			}
		}
		for i, j := row, col; i >= 0 && j < n; i, j = i-1, j+1 {
			if i != row && j != col && vec[i][j] {
				return false
			}
		}
		for i, j := row, col; i < n && j >= 0; i, j = i+1, j-1 {
			if i != row && j != col && vec[i][j] {
				return false
			}
		}
		for i, j := row, col; i < n && j < n; i, j = i+1, j+1 {
			if i != row && j != col && vec[i][j] {
				return false
			}
		}

		return true
	}

	var calc func(int)
	calc = func(row int) {
		if row >= n {
			count++
			return
		}

		for i := range n {
			if judge(row, i) {
				vec[row][i] = true
				calc(row + 1)
				vec[row][i] = false
			}
		}
	}

	calc(0)
	return count
}
