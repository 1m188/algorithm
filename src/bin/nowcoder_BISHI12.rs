/*
BISHI12 元素方碑

描述


菲谢尔在稻妻冒险途中遇到一排神奇的元素方碑，其中第
i
i 个方碑初始时的能量为
a
i
a
i
​
 。只要她对第
i
i 块方碑施放雷元素，就会发生能量转移：

∙

∙正面轰击：雷元素从第
i
−
1
i−1 块流向第
i
+
1
i+1 块，使
a
i
−
1
a
i−1
​
  减
1
1、
a
i
+
1
a
i+1
​
  加
1
1；
∙

∙反面轰击：雷元素从第
i
+
1
i+1 块流向第
i
−
1
i−1 块，使
a
i
+
1
a
i+1
​
  减
1
1、
a
i
−
1
a
i−1
​
  加
1
1。

操作只能在
2
≦
i
≦
n
−
1
2≦i≦n−1 的方碑上进行，且任何时刻所有方碑能量
a
i
a
i
​
  必须保持非负。
当所有方碑的能量
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
a
1
​
 ,a
2
​
 ,…,a
n
​
  全部相等时，菲谢尔即可开启隐藏宝箱。
菲谢尔可以无限次进行操作。请判断，她是否一定能够让所有方碑能量相等。
输入描述：
第一行输入一个整数
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
 )——测试用例组数。
对于每组测试数据：
∙

∙第一行输入一个整数
n
(
1
≦
n
≦
2
×
1
0
5
)
n(1≦n≦2×10
5
 )——方碑数量；
∙

∙第二行输入
n
n 个整数
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
≦
a
i
≦
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
 (1≦a
i
​
 ≦10
9
 )——初始能量。

除此之外，保证单个测试文件中全部测试用例的
n
n 之和不超过
2
×
1
0
5
2×10
5
 。
输出描述：
对每组测试数据，在一行上输出
YES
YES 或
NO
NO，表示能否通过若干次操作使所有方碑能量相等。
示例1
输入：
8
3
3 2 1
3
1 1 3
4
1 2 5 4
4
1 6 6 1
5
6 2 1 4 2
4
1 4 2 1
5
3 1 2 1 3
3
2 4 2
复制
输出：
YES
NO
YES
NO
YES
NO
NO
NO
复制
说明：
在第一组样例中：
∙

∙对于数组
{
3
,
2
,
1
}
{3,2,1}，先对下标
i
=
2
i=2 正面轰击一次，得到
{
2
,
2
,
2
}
{2,2,2}，能量已全部相等；
∙

∙对于数组
{
1
,
2
,
5
,
4
}
{1,2,5,4}，可依次正面轰击
i
=
3
i=3，反面轰击
i
=
2
i=2，最终得到
{
3
,
3
,
3
,
3
}
{3,3,3,3}；
∙

∙对于数组
{
2
,
4
,
2
}
{2,4,2}，无论如何操作，总能量
∑
a
i
∑a
i
​
  不是
n
n 的倍数，因此无法全等，答案为
NO
NO。
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');

    let t: i32 = iter.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();
        if n == 1 {
            println!("YES");
            iter.next(); // 注意要过一次 next 防止下一次读 n 读到了上一次的 a
            continue;
        }
        let a: Vec<i32> = iter
            .next()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        if n == 2 {
            if a[0] == a[1] {
                println!("YES");
            } else {
                println!("NO");
            }
            continue;
        }

        let mut x1: i32 = 0;
        let mut n1: i32 = 0;
        for i in (0..n).step_by(2) {
            x1 += a[i];
            n1 += 1;
        }
        let mut x2: i32 = 0;
        let mut n2: i32 = 0;
        for i in (1..n).step_by(2) {
            x2 += a[i];
            n2 += 1;
        }

        if x1 % n1 == 0 && x2 % n2 == 0 && x1 / n1 == x2 / n2 {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}
