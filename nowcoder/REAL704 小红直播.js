/*
REAL704 小红直播

描述
小红每天下班后都会去小红书直播。已知她第
i
i天上班的时间为
a
i
a 
i
​
 小时，下班后直播的时间为
b
i
b 
i
​
 小时。小红每上班 1 小时会增加
x
x的焦虑度，每直播 1 小时会降低
y
y的焦虑度。
小红想知道，第
n
n天结束时，焦虑度为多少？

请注意，焦虑度不会下降到负数！
输入描述：
第一行输入三个正整数
n
,
x
,
y
n,x,y，代表总天数，上班 1 小时增加的焦虑度，直播 1 小时下降的焦虑度。
第二行输入
n
n个整数
a
i
a 
i
​
 ，代表每天的上班时间。
第三行输入
n
n个整数
b
i
b 
i
​
 ，代表每天的直播时间。
1
≤
n
≤
1
0
4
1≤n≤10 
4
 
1
≤
a
i
≤
10
1≤a 
i
​
 ≤10
1
≤
b
i
≤
5
1≤b 
i
​
 ≤5
1
≤
x
,
y
≤
1
0
5
1≤x,y≤10 
5
 
输出描述：
一个整数，代表最后一天结束后的焦虑度。
示例1
输入：
3 1 3
4 5 8
1 3 1
复制
输出：
5
复制
说明：
第一天上班增加了 4 焦虑度，下班后直播 1 小时下降了 3 焦虑度，此时有 1 焦虑度。
第二天上班增加了 5 焦虑度，变成 6 焦虑度。下班后直播 3 小时焦虑度清零。
第三天上班增加了 8 焦虑度，下班后直播 1 小时下降了 3 焦虑度，此时有 5 焦虑度。
*/

(() => {

    const rl = require('readline').createInterface(process.stdin, process.stdout);
    let iter = rl[Symbol.asyncIterator]();
    const readline = async () => (await iter.next()).value;

    (async () => {

        let [n, x, y] = (await readline()).split(' ').map(Number);
        let a = (await readline()).split(' ').map(Number);
        let b = (await readline()).split(' ').map(Number);

        let ans = 0;
        for (let i = 0; i < n; i++) {
            ans += a[i] * x - b[i] * y;
            ans = Math.max(0, ans); // 焦虑度不会下降到负数
        }
        console.log(ans);

    })();

})();
