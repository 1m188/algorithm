/*
REAL665 小红的优惠券

描述
小红在上次双十一买了非常多的东西，订单总价为 
n
n 元。

小红有好多优惠券，每张优惠券都是满 
a
a 元减 
b
b 元，意思是，如果 
n
≥
a
n≥a ，那么小红只需要花费 
n
−
b
n−b 元就可以了。

小红只能用一张优惠券，她想知道她最少需要花多少钱。
输入描述：
第一行输入两个整数 
n
(
1
≤
n
≤
1
0
5
)
,
m
(
1
≤
m
≤
100
)
n(1≤n≤10 
5
 ),m(1≤m≤100) 分别表示订单总价和优惠券数量。

接下来 
m
m 行，每行输入两个整数 
a
,
b
(
1
≤
b
≤
a
≤
1
0
5
)
a,b(1≤b≤a≤10 
5
 ) 。
输出描述：
输出一个整数表示答案。
示例1
输入：
100 3
300 50
200 30
50 5
复制
输出：
95
复制
说明：
小红只能用第三张优惠券。
*/

(() => {

    const rl = require('readline').createInterface({ input: process.stdin, output: process.stdout });
    let iter = rl[Symbol.asyncIterator]();
    const readline = async () => (await iter.next()).value;

    (async () => {

        const [n, m] = (await readline()).trim().split(' ').map(Number);
        let min_val = n;
        for (let i = 0; i < m; i++) {
            const [a, b] = (await readline()).trim().split(' ').map(Number);
            if (n >= a) {
                min_val = Math.min(min_val, n - b);
            }
        }
        console.log(min_val);

    })();

})();
