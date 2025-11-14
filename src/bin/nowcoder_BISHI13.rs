/*
BISHI13 九倍平方数

描述
给定一个不含前导零的十进制数字串
n
n（长度
≦
1
0
5
≦10
5
 ）。你可以多次执行以下操作：
∙

∙ 选择
n
n 中的某一位数字
x

(
0
≦
x
≦
9
)
x (0≦x≦9)；
∙

∙ 若
x
2
<
10
x
2
 <10，将该位替换为
x
2
x
2
 。

若通过若干次（可为
0
0 次）操作可以使最终数字能被
9
9 整除，则称数字串
n
n 为好数。判断每个测试用例的数字串
n
n 是否为好数。
输入描述：
第一行输入整数
t
(
1
≦
t
≦
1
0
4
)
t(1≦t≦10
4
 )，表示测试用例数量。
随后
t
t 行，每行一个数字串
n
n，长度
≦
1
0
5
≦10
5
 ，保证所有用例数字串
n
n 的总长度
≦
1
0
5
≦10
5
 。
输出描述：
对每个用例输出 ``
YES
YES`` 或 ``
NO
NO``（大写），表示是否存在操作序列使得最终数字能被
9
9 整除。
示例1
输入：
9
123
322
333333333333
9997
5472778912773
1234567890
23
33
52254522632
复制
输出：
NO
YES
YES
NO
NO
YES
NO
YES
YES
复制
说明：
在第一组样例中，从整数
123
123 中只能得到
123
123 、
143
143 、
129
129 和
149
149 ，它们都不能被
9
9 整除。

在第二组样例中，需要将第二个数字替换为它的平方，那么
n
n 就等于
342
=
38
⋅
9
342=38⋅9 。

在第三组样例中，整数已经可以被
9
9 整除。
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');

    let t: i32 = iter.next().unwrap().parse().unwrap();
    'outer: for _ in 0..t {
        let n = iter.next().unwrap().as_bytes();
        let mut sum = 0;
        let (mut cnt2, mut cnt3) = (0, 0);
        for &b in n {
            sum += (b - b'0') as i32;
            if b == b'2' {
                cnt2 += 1;
            } else if b == b'3' {
                cnt3 += 1;
            }
        }

        let target = (9 - sum % 9) % 9;
        for i in 0..=cnt2 {
            for j in 0..=cnt3 {
                if (i * 2 + j * 6) % 9 == target {
                    println!("YES");
                    continue 'outer;
                }
            }
        }
        println!("NO");
    }
}
