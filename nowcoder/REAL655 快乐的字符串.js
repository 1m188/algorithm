/*
REAL655 快乐的字符串

描述
牛牛是一个善于寻找快乐的人。

对于一个字符串 
s
s ，牛牛认为它是“快乐的”当且仅当其包含以下任意一个连续子串：
cheerful
glad
happy
pleased

对于输入的字符串 
s
s ，请你判断这个字符串是否是“快乐的”。
输入描述：
本题中，每个测试点包含多组测试数据。

第一行一个整数 
T
(
1
≤
T
≤
10
)
T(1≤T≤10) ，表示数据的组数。

对于每组数据：

输入仅一行，包含一个字符串 
s
s 。

数据保证 
s
s 的长度不超过 
100
100 ，且仅由小写字母构成。
输出描述：
对于每组数据，如果 
s
s 是“快乐的”，请输出 
Y
e
s
Yes ，否则请输出 
N
o
No 。
示例1
输入：
2
happydays
saddays
复制
输出：
Yes
No
*/

(() => {

    const rl = require("readline").createInterface({ input: process.stdin });
    let iter = rl[Symbol.asyncIterator]();
    const readline = async () => (await iter.next()).value;

    (async () => {

        let T = parseInt((await readline()).trim());
        while (T--) {
            let s = (await readline()).trim();
            s.includes("cheerful") || s.includes("glad") || s.includes("happy") || s.includes("pleased") ? console.log("Yes") : console.log("No");
        }

    })();

})();
