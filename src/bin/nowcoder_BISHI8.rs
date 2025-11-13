/*
BISHI8 大整数哈希

描述
给定初始映射
f
⁣
:
[
0
,
2
64
)
→
[
0
,
2
64
)
f:[0,2
64
 )→[0,2
64
 )，对任意
x
x 初始
f
(
x
)
=
0
f(x)=0。共有
n
n 次操作，每次给定一对整数
(
x
,
y
)
(x,y)，执行：
∙

∙ 输出
f
(
x
)
f(x) 的当前值记为
a
n
s
i
ans
i
​
 ；
∙

∙ 更新
f
(
x
)
←
y
f(x)←y。

 求
∑
i
=
1
n
i
×
a
n
s
i
(
m
o
d
2
64
)
∑
i=1
n
​
 i×ans
i
​
 (mod2
64
 )。
输入描述：
第一行包含整数
n

(
1
≤
n
≤
5
×
1
0
6
)
n (1≤n≤5×10
6
 )；
接下来的
n
n 行，每行包含两个整数
x
,
y

(
0
≤
x
,
y
<
2
64
)
x,y (0≤x,y<2
64
 )。
输出描述：
输出一个整数，表示
∑
i
=
1
n
i
×
a
n
s
i
(
m
o
d
2
64
)
∑
i=1
n
​
 i×ans
i
​
 (mod2
64
 )。
示例1
输入：
3
1 5
2 4
1 7
复制
输出：
15
复制
说明：
第1次
a
n
s
1
=
f
(
1
)
=
0
ans
1
​
 =f(1)=0；第2次
a
n
s
2
=
f
(
2
)
=
0
ans
2
​
 =f(2)=0；第3次
a
n
s
3
=
f
(
1
)
=
5
ans
3
​
 =f(1)=5；结果
1
×
0
+
2
×
0
+
3
×
5
=
15
1×0+2×0+3×5=15。
*/

use std::{
    collections::HashMap,
    io::{self, Read},
};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');
    let n: u64 = iter.next().unwrap().parse().unwrap();

    let mut map: HashMap<u64, u64> = HashMap::new();
    let mut res: u64 = 0;

    for i in 0..n {
        let mut iter = iter.next().unwrap().split_whitespace();
        let x: u64 = iter.next().unwrap().parse().unwrap();
        let y: u64 = iter.next().unwrap().parse().unwrap();

        res += (i + 1)
            * match map.get_mut(&x) {
                Some(ans) => *ans,
                None => 0,
            };

        map.entry(x).and_modify(|val| *val = y).or_insert(y);
    }

    print!("{}\n", res);
}
