/*
REAL789 小O的数位翻转

描述
小O有一个长度为 
n
n 的数组 
a
a，他现在想要选择其中一个数字进行“二进制翻转”操作，他想知道有多少种可能的选择方式，使得操作后的数组总和比不操作更大。

二进制翻转：指将 
x
x 的二进制翻转，翻转后去除前导 0。
（例如：
12
=
(
1100
)
2
，
f
(
12
)
=
(
0011
)
2
=
3
12=(1100) 
2
​
 ，f(12)=(0011) 
2
​
 =3。）
输入描述：
第一行输入一个正整数 
n
 
(
1
≤
n
≤
2
∗
1
0
5
)
n (1≤n≤2∗10 
5
 )，表示数组 
a
a 的长度。
第二行输入 
n
n 个正整数 
a
1
,
a
2
,
…
,
a
n
 
(
1
≤
a
i
≤
1
0
9
)
a 
1
​
 ,a 
2
​
 ,…,a 
n
​
  (1≤a 
i
​
 ≤10 
9
 )，表示数组 
a
a 的元素。
输出描述：
在一行上输出一个整数，表示合法的方案数。
示例1
输入：
5
11 12 11 13 12
复制
输出：
2
复制
说明：
(
11
)
10
=
(
1011
)
2
(11) 
10
​
 =(1011) 
2
​
  ，翻转后变为 
(
1101
)
2
(1101) 
2
​
  ，大于翻转前；
(
12
)
10
=
(
1100
)
2
(12) 
10
​
 =(1100) 
2
​
  和 
(
13
)
10
=
(
1101
)
2
(13) 
10
​
 =(1101) 
2
​
  翻转后均小于翻转前。
示例2
输入：
6
1 2 3 4 5 6
复制
输出：
0
*/

(() => {

    const rl = require("readline").createInterface({ input: process.stdin });
    let iter = rl[Symbol.asyncIterator]();
    const readline = async () => (await iter.next()).value;

    (async () => {

        let n = Number((await readline()).trim());
        let a = (await readline()).trim().split(' ').map(Number);

        let ans = 0;
        for (let i = 0; i < n; i++) {
            let b = parseInt(a[i].toString(2).split('').reverse().join(''), 2);
            if (b > a[i]) ans++;
        }

        console.log(ans);

    })();

})();
