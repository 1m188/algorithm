/*
BISHI14 特殊的科学计数法

描述
给定一个正整数
N
N（位数可达
1
0
5
10
5
 ），请将其转写为科学计数法形式，形如：

a
.
b
×
1
0
c
a.b×10
c


具体而言，有如下要求：
∙

∙
a
a 为
[
1
,
9
]
[1,9] 之间的整数；
∙

∙
b
b 为对
N
N 的第二位数字进行四舍五入后的小数部分（保留一位小数）；
∙

∙
c
c 为整数指数；
∙

∙ 输出格式严格为 ``\text{a.b*10^c}``，无多余空格。
输入描述：
一行输入正整数
N
(
1
0
2
≦
N
≦
1
0
100000
)
N(10
2
 ≦N≦10
100000
 )，不含前导零。
输出描述：
输出
N
N 的科学计数法表示 ``\text{a.b*10^c}``。
示例1
输入：
299792458
复制
输出：
3.0*10^8
复制
示例2
输入：
602214129000000000000000
复制
输出：
6.0*10^23
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let str = buf.trim().as_bytes();

    let mut c = str.len() - 1; // 指数
    let mut a = str[0] - '0' as u8;
    let mut b = str[1] - '0' as u8;
    let d = str[2] - '0' as u8;

    if d >= 5 {
        b += 1;
        if b == 10 {
            b = 0;
            a += 1;
            if a == 10 {
                a = 1;
                c += 1;
            }
        }
    }

    println!("{}.{}*10^{}", a, b, c);
}
