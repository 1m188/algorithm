/*

斐波那契

*/

/**
 * 递归
 * @param {number} n 第几个
 * @returns {number} 指定第几个的斐波那契数
 */
function Fib_recur(n) {
    return n <= 1 ? 1 : Fib_recur(n - 1) + Fib_recur(n - 2);
}

/**
 * 尾递归
 * @param {number} a 当前项
 * @param {number} b 前一项
 * @returns {number} 指定第几个的斐波那契数
 */
function Fib_tailRecur(n, a = 1, b = 1) {
    return n <= 1 ? a : Fib_tailRecur(n - 1, a + b, a);
}

/** 
 * 循环
 * @param {number} n 第几个
 * @returns {number} 指定第几个的斐波那契数
 */
function Fib_c(n) {
    if (n <= 1) return 1;

    let ans = 0;
    let last = 1, ntlast = 1;
    for (let i = 2; i <= n; i++) {
        ans = last + ntlast;
        ntlast = last;
        last = ans;
    }

    return ans;
}

function main() {

    // 0代表第一项，1代表第二项...以此类推

    const n = 5;

    console.log("fib " + n);
    console.log("recur: " + Fib_recur(n));
    console.log("tailRecur: " + Fib_tailRecur(n));
    console.log("c: " + Fib_c(n));
}

main();