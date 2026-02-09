/*
ACM3717 大水题

描述
对于一个数，把它所有位上的数字进行加和，得到新的数。
重复执行若干次，直到结果是个位数为止。输出最终的这个个位数。
输入描述：
在一行上输入一个整数 
n
(
1
≤
n
≤
1
0
9
)
n(1≤n≤10 
9
 ) 代表初始数字。
输出描述：
在一行上输出一个整数，代表最终的结果。
示例1
输入：
38
复制
输出：
2
复制
说明：
对于这一组测试数据，操作过程为 
38
→
3
+
8
=
11
→
1
+
1
=
2
38→3+8=11→1+1=2 。
示例2
输入：
1
复制
输出：
1
*/

(() => {

    const rl = require("readline").createInterface({ input: process.stdin, output: process.stdout });
    let iter = rl[Symbol.asyncIterator]();
    const readline = async () => (await iter.next()).value;

    (async function () {

        let n = Number((await readline()).trim());
        while (n >= 10) {
            n = String(n).split('').reduce((a, b) => a + Number(b), 0);
        }
        console.log(n);

    })();

})();
