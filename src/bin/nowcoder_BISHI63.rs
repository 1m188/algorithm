/*
BISHI63 计算阶乘

描述
给定
T
T 个正整数
n
n，请你计算
n
!

m
o
d

(
1
0
9
+
7
)
n!mod(10
9
 +7) 的值并输出。
输入描述：
第一行输入一个整数
T
(
1
≦
T
≦
1
0
3
)
T(1≦T≦10
3
 ) 表示测试数据数量。
接下来
T
T 行，每行输入一个整数
n
(
1
≦
n
≦
1
0
6
)
n(1≦n≦10
6
 )。
输出描述：
输出共
T
T 行，其中第
i
i 行输出
n
i
!

m
o
d

1

000

000

007
n
i
​
 !mod1000000007 的结果。
示例1
输入：
1
1
复制
输出：
1
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');

    const MOD: u64 = 1_000_000_007;

    let t: usize = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: u64 = iter.next().unwrap().parse().unwrap();
        let mut ans: u64 = 1;
        for i in 1..=n {
            ans = (ans * i) % MOD;
        }
        println!("{}", ans)
    }
}
