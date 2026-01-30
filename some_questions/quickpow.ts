/*
快速幂
*/

(() => {

    /**
     * 快速幂，采用大数算法，适配高精度
     * @param x 底数
     * @param n 幂次（需要非负整数）
     * @returns x^n
     */
    function quickPow(x: bigint, n: bigint): bigint {
        if (n < 0n) throw new Error("n must be positive");
        if (n == 0n) return 1n;
        if (n == 1n) return x;
        return quickPow(x * x, n >> 1n) * ((n & 0x1n) == 0n ? 1n : x);
    }

    let x = 2n;
    let n = 10n;
    console.log(quickPow(x, n).toString()); // 1024

    x = 3n;
    n = 46n;
    console.log(quickPow(x, n).toString()); // 8862938119652501095929

})();
