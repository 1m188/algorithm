/*
REAL671 小红的不动点

描述
对于一个数组，如果一个元素的值等于它在数组的出现次数，那么称这个元素是“不动点”。
小红拿到了一个数组，她想知道这个数组有多少个不动点？
输入描述：
第一行输入一个正整数
n
n，代表数组的大小。
第二行输入
n
n个正整数
a
i
a 
i
​
 ，代表数组的元素。
1
≤
n
,
a
i
≤
100
1≤n,a 
i
​
 ≤100
输出描述：
一个整数，代表不动点的数量。
示例1
输入：
6
2 1 2 3 3 3
复制
输出：
6
复制
示例2
输入：
6
1 2 3 1 2 3
复制
输出：
2
*/

(() => {

    const rl = require("readline").createInterface({ input: process.stdin });
    let iter = rl[Symbol.asyncIterator]();
    const readline = async () => (await iter.next()).value;

    (async () => {

        let n = parseInt((await readline()).trim());
        let arr = (await readline()).trim().split(" ").map(Number);

        let cnts = new Array(101).fill(0);
        arr.map((value, index, array) => { cnts[arr[index]]++; });

        let ans = 0;
        cnts.map((value, index, array) => {
            if (index == 0) return;
            ans += value == index ? value : 0;
        });

        console.log(ans);

    })();

})();
