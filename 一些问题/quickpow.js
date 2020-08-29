/*

快速幂

*/

/**
 * 快速幂计算
 * @param {number} num 底数
 * @param {number} pow 指数
 * @returns {number} 幂计算结果
 */
function quickpow(num, pow) {
    if (pow <= 0)
        return 1;
    else if (pow === 1)
        return num;
    else {
        let nnum = quickpow(num, parseInt(pow / 2));
        return pow % 2 ? nnum * nnum * num : nnum * nnum;
    }
}

function main() {
    console.log(quickpow(3, 3));
    console.log(quickpow(-5, 5));
    console.log(quickpow(5, 17));
}

main();