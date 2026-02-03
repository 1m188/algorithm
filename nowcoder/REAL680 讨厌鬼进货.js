/*
REAL680 讨厌鬼进货

描述
讨厌鬼的店铺要进
n
n个货物，以及两个供货商
a
a和
b
b，第
i
i件货物在
a
a供货商处需要
a
i
a 
i
​
 元，在
b
b供货商处需要
b
i
b 
i
​
 元。
讨厌鬼还有第三个选择就是在京东上网购，网购只能一次买齐 
n
n 种货物，网购这
n
n个货物的总价格为
x
x元。
通过三种方式购买的 
n
n 种货物都是一样的，可以在不同的供货商
a
a和
b
b处购买商品，我们的目标是需要买齐这 
n
n 种货物。
讨厌鬼想知道，进这
n
n个货物最少需要花多少元。

输入描述：
第一行输入两个整数
n
,
x
(
1
≤
n
≤
1
0
5
,
1
≤
x
≤
1
0
9
)
n,x(1≤n≤10 
5
 ,1≤x≤10 
9
 )，代表货物数量和网购总价格。
第二行输入
n
n个整数
a
i
(
1
≤
a
i
≤
1
0
4
a 
i
​
 (1≤a 
i
​
 ≤10 
4
 )，代表在a供应商处每件货物的价格。
第三行输入
n
n个整数
b
i
(
1
≤
b
i
≤
1
0
4
b 
i
​
 (1≤b 
i
​
 ≤10 
4
 )，代表在b供应商处每件货物的价格。
输出描述：
一个整数，表示最少花钱数。
示例1
输入：
5 5
2 1 2 1 2
1 2 1 2 3
复制
输出：
5
复制
说明：
显然网购更加划算。
*/

(() => {

    const rl = require('readline').createInterface(process.stdin, process.stdout);
    let iter = rl[Symbol.asyncIterator]();
    const readLine = async () => (await iter.next()).value;

    (async () => {

        let [n, x] = (await readLine()).trim().split(' ').map(Number);
        let a = (await readLine()).trim().split(' ').map(Number);
        let b = (await readLine()).trim().split(' ').map(Number);

        let cost = 0;
        for (let i = 0; i < n; i++) {
            cost += Math.min(a[i], b[i]);
        }

        console.log(Math.min(cost, x));

    })();

})();
