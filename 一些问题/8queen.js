/*

八皇后

*/

/*** N皇后 */
class NQueen {

    /*** 方案数目 */
    #num = 0;
    /*** 保存皇后坐标位置的递归数组 */
    #qp = new Array();

    /**
     * 判断当前皇后坐标是否可行
     * @param p 当前皇后坐标
     * @returns bool值，是/否
     */
    #isqpok = function (p) {
        for (let e of this.#qp)
            if (e[0] === p[0] || e[1] === p[1] || Math.abs(e[0] - p[0]) === Math.abs(e[1] - p[1]))
                return false;
        return true;
    }

    /**
     * 内部递归计算
     * @param n 皇后数量
     * @param r 当前行数
     */
    #nq = function (n, r = 0) {
        if (r >= n) {
            this.#num++;
            return;
        }

        for (let i = 0; i < n; i++) {
            let p = [i, r];
            if (this.#isqpok(p)) {
                this.#qp.push(p);
                this.#nq(n, r + 1);
                this.#qp.pop();
            }
        }
    }

    /**
     * n皇后计算
     * @param qn 皇后数量
     * @returns 方案数
     */
    nQueen(qn) {
        if (qn <= 0 || typeof (qn) != "number")
            return 0;
        qn = parseInt(qn);
        this.#num = 0;
        this.#qp.length = 0;
        this.#nq(qn);
        return this.#num;
    }
}

function main() {
    let nqueen = new NQueen();
    console.log(nqueen.nQueen(8));
    console.log(nqueen.nQueen(10));
}

main();