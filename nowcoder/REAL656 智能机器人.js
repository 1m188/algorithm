/*
REAL656 智能机器人

描述
小阅（掌阅吉祥物）正在进行一项有趣的测试，以评估机器人在解决迷宫问题上的智能程度。因此他将机器人放在一个n*m的迷宫中，看机器人最少需要走多少步到达目的地。
输入描述：
输入包含两行，第一行代表n和m，n和m的范围是[2, 1000]，接下来n行，每行包含m个字符，代表迷宫的方格。包含四种字符：‘s’代表机器人出发点，‘e’代表机器人终点，‘.’代表可通过，‘#’代表禁止通过。
输出描述：
  输出最短需要时间，如果不能到达则输出-1。
示例1
输入：
3 3
.s.
#..
e..
复制
输出：
3
复制
说明：
3*3的迷宫，从s到e，最少走3步
示例2
输入：
3 3
.s.
###
e..
复制
输出：
-1
复制
说明：
3*3的迷宫，无法从s走到e
*/

(() => {

    const rl = require('readline').createInterface({ input: process.stdin, output: process.stdout });
    let iter = rl[Symbol.asyncIterator]();
    const readline = async () => (await iter.next()).value;

    (async () => {

        const [n, m] = (await readline()).trim().split(' ').map(Number);

        /** @type {number[][]} */
        let g = Array.from({ length: n }, () => Array(m).fill(0));

        for (let i = 0; i < n; i++) {
            g[i] = (await readline()).trim().split('');
        }

        /**
         * @type {number[][]}
         */
        let queue = [];

        (() => {
            for (let i = 0; i < n; i++) {
                for (let j = 0; j < m; j++) {
                    if (g[i][j] === 's') {
                        queue.push([i, j]);
                        return;
                    }
                }
            }
        })();

        let ans = 0;
        let f = false;
        let flags = Array.from({ length: n }, () => Array(m).fill(false));
        while (queue.length > 0) {
            ans++;

            let len = queue.length;
            for (let i = 0; i < len; i++) {
                let [x, y] = queue.shift();

                for (let [dx, dy] of [[0, 1], [0, -1], [1, 0], [-1, 0]]) {
                    let nx = x + dx, ny = y + dy;

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }

                    if (flags[nx][ny]) {
                        continue;
                    }

                    if (g[nx][ny] === '#') {
                        continue;
                    }

                    if (g[nx][ny] === 'e') {
                        f = true;
                        break;
                    }

                    queue.push([nx, ny]);
                    flags[nx][ny] = true;
                }

                if (f) break;

            }

            if (f) {
                break;
            }
        }

        console.log(f ? ans : -1);

    })();

})();
