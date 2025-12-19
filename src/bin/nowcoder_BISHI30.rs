/*
BISHI30 二进制数1

描述
给定一个非负整数
x
x，请计算
x
x 的二进制表示中数字
1
1 的数量。

【名词解释】
∙

∙ 二进制表示：二进制表示 指将整数用基数
2
2 的形式书写，不含前导零；
∙

∙ 位计数：位计数 是指统计一个整数二进制表示中
1
1 的数量，也称为
popcount
⁡
popcount。
输入描述：
在一行上输入一个整数
x
(
0
≦
x
≦
1
0
18
)
x(0≦x≦10
18
 )，表示待统计的数值。
输出描述：
在一行上输出一个整数，表示
x
x 的二进制表示中
1
1 的数量。
示例1
输入：
3
复制
输出：
2
复制
说明：
3
3 的二进制表示为
(
11
)
2
(11)
2
​
 ，其中包含两个
1
1。
示例2
输入：
65
复制
输出：
2
复制
说明：
65
65 的二进制表示为
(
1000001
)
2
(1000001)
2
​
 ，其中包含两个
1
1。
*/

use std::io::Read;

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();

    let mut x: u64 = buf.trim().parse().unwrap();
    let mut count = 0;
    while x > 0 {
        if x & 1 == 1 {
            count += 1;
        }
        x >>= 1;
    }
    println!("{}", count);
}
