/*
BISHI11 变幻莫测

描述
给定两个整数
X
,
Y
X,Y，你可以任意顺序多次执行以下两种操作之一：
1.

1.
​
 交换：
(
X
,
Y
)
=
(
Y
,
X
)
(X,Y)=(Y,X)；
2.

2.
​
 变换：
(
X
,
Y
)
=
(
X
+
Y
,
X
−
Y
)
(X,Y)=(X+Y,X−Y)。
求使
X
=
Y
X=Y 成立所需的最少操作次数；如无法实现，输出
−
1
−1。
输入描述：
输入一行，包含两个整数
X
,
Y

(
−
100
≤
X
,
Y
≤
100
)
X,Y (−100≤X,Y≤100)。
输出描述：
输出一个整数——使
X
=
Y
X=Y 所需的最少操作次数；如无法实现，输出
−
1
−1。
示例1
输入：
5 8
复制
输出：
-1
复制
说明：
对
(
5
,
8
)
(5,8) 无论如何操作，无法使两者相等，故输出
−
1
−1。
示例2
输入：
5 -5
复制
输出：
3
复制
说明：
一种最优操作序列为：

1.

1.
​
 变换：
(
5
,
−
5
)
→
(
0
,
10
)
(5,−5)→(0,10)；
2.

2.
​
 交换：
(
0
,
10
)
→
(
10
,
0
)
(0,10)→(10,0)；
3.

3.
​
 变换：
(
10
,
0
)
→
(
10
,
10
)
(10,0)→(10,10)。

共
3
3 步使得
X
=
Y
X=Y。
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');

    let mut line = iter
        .next()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<i32>().unwrap());
    let (x, y) = (line.next().unwrap(), line.next().unwrap());

    if x == y {
        println!("0");
    } else if y == 0 {
        println!("1");
    } else if x == 0 {
        println!("2");
    } else if x + y == 0 {
        println!("3");
    } else {
        println!("-1");
    }
}
