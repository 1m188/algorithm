/*
八皇后问题

有一个8x8的棋盘，要求在棋盘上放置8个皇后，使得每个皇后不能互相攻击，即任意两个皇后不能在同一行、同一列或同一对角线上。
问有多少种解决方案？

解决思路：回溯
*/



(() => {

    /**
     * 回溯算法，推广至 N 皇后
     * @param n 棋盘大小
     * @return 求解方案数
     */
    function queenN(n: number): number {
        if (n <= 0) return 0; // 棋盘大小不合法
        if (n == 1) return 1; // 棋盘大小为1，只有一种解决方案

        let vec: boolean[][] = Array.from({ length: n }, () => new Array(n).fill(false));
        let ans: number = 0;

        // 判断当前位置是否可以放置皇后
        function judge(row: number, col: number): boolean {
            for (let i = 0; i < n; i++) {
                if (i != col && vec[row][i]) return false;
                if (i != row && vec[i][col]) return false;
            }
            for (let i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if (vec[i][j]) return false;
            }
            for (let i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if (vec[i][j]) return false;
            }
            for (let i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
                if (vec[i][j]) return false;
            }
            for (let i = row + 1, j = col + 1; i < n && j < n; i++, j++) {
                if (vec[i][j]) return false;
            }
            return true;
        }

        // 回溯法
        function dfs(row: number = 0): void {
            if (row == n) {
                ans++;
                return;
            }
            for (let i = 0; i < n; i++) {
                if (judge(row, i)) {
                    vec[row][i] = true;
                    dfs(row + 1);
                    vec[row][i] = false;
                }
            }
        }
        dfs();

        return ans;
    }

    let n: number = 8;
    console.log(`八皇后问题共有解决方案数目: ${queenN(n)}`);

})();
