/*
REAL666 数字颠倒

描述
输入一个整数 a，将这个整数颠倒再输出。
例如输入为123000，则输出为000321。
输入描述：
一个整数 a。

0
≤
a
<
2
31
0≤a<2 
31
 
输出描述：
这个整数颠倒之后的结果。
示例1
输入：
123000
复制
输出：
000321
*/

(() => {

    const rl = require('readline').createInterface({ input: process.stdin });
    let iter = rl[Symbol.asyncIterator]();
    const readline = async () => (await iter.next()).value;

    (async () => {

        let a = (await readline()).trim();
        console.log(a.split('').reverse().join(''))

    })();

})();
