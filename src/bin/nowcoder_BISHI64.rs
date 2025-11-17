/*
BISHI64 【模板】快速幂Ⅰ ‖ 整数

描述
对于给定的三个正整数
a
,
b
,
p
a,b,p ，计算
a
b

m
o
d

p
a
b
 modp 。
输入描述：
每个测试文件均包含多组测试数据。第一行输入一个整数
T
(
1
≦
T
≦
5
×
1
0
5
)
T(1≦T≦5×10
5
 ) 代表数据组数，每组测试数据描述如下：

一行上输入三个整数
a
,
b
,
p
(
0
≦
a
,
b
≦
1
0
9
;

0
<
a
+
b
;

1
≦
p
≦
1
0
9
)
a,b,p(0≦a,b≦10
9
 ; 0<a+b; 1≦p≦10
9
 ) 代表底数、指数和模数。
输出描述：
对于每一组测试数据，在一行上输出一个整数，代表式子的答案。
示例1
输入：
4
1 0 1
0 1 10
2 3 10
3 3 12
复制
输出：
0
0
8
3
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');

    mod local {
        pub fn pow(a: i64, b: i64, p: i64) -> i64 {
            if a == 0 || a == 1 {
                return a % p;
            }
            if b == 0 {
                return 1 % p;
            }
            if b == 1 {
                return a % p;
            }
            if b == 2 {
                return (a * a) % p;
            }
            if b & 0x1 == 0 {
                return pow((a * a) % p, b >> 1, p);
            } else {
                return (a * pow((a * a) % p, b >> 1, p)) % p;
            }
        }
    }

    let t: i32 = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let mut line = iter.next().unwrap().split(' ');
        let (a, b, p) = (
            line.next().unwrap().parse::<i64>().unwrap(),
            line.next().unwrap().parse::<i64>().unwrap(),
            line.next().unwrap().parse::<i64>().unwrap(),
        );
        println!("{}", local::pow(a, b, p));
    }
}
