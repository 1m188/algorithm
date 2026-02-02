/*
REAL629 小红的多彩糖葫芦

描述
小红喜欢吃多彩糖葫芦，多彩糖葫芦上的每一个糖葫芦都有一种颜色。
但小红有非常严重的强迫症，她绝对不会连续吃两个相同颜色的糖葫芦。
一串糖葫芦只能从上往下吃，一旦小红发现下一颗糖葫芦和她刚吃过的糖葫芦颜色相同时，小红就会把整串多彩糖葫芦丢掉。

小红想知道她吃一串多彩糖葫芦时可以吃到几颗糖葫芦。
输入描述：
输入一个字符串，按从前往后的顺序表示多彩糖葫芦串上从上到下每一颗糖葫芦的颜色。

字符串长度不超过 
1
0
5
10 
5
  。
输出描述：
输出一个整数表示答案。
示例1
输入：
abccca
复制
输出：
3
复制
说明：
小红吃完了第三个糖葫芦后，就会把糖葫芦串丢掉。
*/

(() => {

    const rl = require("readline").createInterface({ input: process.stdin });
    let iter = rl[Symbol.asyncIterator]();
    const readline = async () => (await iter.next()).value;

    (async () => {

        let s = (await readline()).trim();
        let pre = "";
        let ans = 0;
        for (let i = 0; i < s.length; i++) {
            if (s[i] != pre) {
                ans++;
                pre = s[i];
            } else {
                break;
            }
        }
        console.log(ans);

    })();

})();
