/*
BISHI6 【模板】整数优先队列

描述
给定一个初始为空的多重集合
S
S，支持以下操作：
1.

1.
​
  插入操作：给定整数
x
x，将
x
x 加入集合
S
S；
2.

2.
​
  查询操作：输出
S
S 中的最小元素；
3.

3.
​
  删除操作：删除
S
S 中的一个最小元素。
输入描述：
第一行包含整数
n

(
1
≤
n
≤
1
0
6
)
n (1≤n≤10
6
 )，表示操作总数。
接下来
n
n 行，每行包含整数
o
p
op 和（可选的）
x
x，其含义如下：
∙

∙ 若
o
p
=
1
op=1，则后接整数
x

(
1
≤
x
<
2
31
)
x (1≤x<2
31
 )；
∙

∙ 若
o
p
=
2
op=2 或
o
p
=
3
op=3，则仅包含
o
p
op。
输出描述：
对于每个查询操作（
o
p
=
2
op=2），输出一行，包含当前多重集合中最小元素。
示例1
输入：
7
1 5
1 3
2
1 10
2
3
2
复制
输出：
3
3
5
*/

use std::{
    collections::BTreeMap,
    io::{self, Read},
};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');
    let n: i32 = iter.next().unwrap().parse().unwrap();

    let mut map: BTreeMap<i32, i32> = BTreeMap::new();

    for _ in 0..n {
        let line = iter.next().unwrap();
        let op = line.chars().nth(0).unwrap();
        if op == '1' {
            let x: i32 = line.split_whitespace().nth(1).unwrap().parse().unwrap();
            map.entry(x).and_modify(|val| *val += 1).or_insert(1);
        } else if op == '2' {
            print!("{}\n", map.keys().next().unwrap());
        } else {
            let key = map.keys().next().unwrap().clone();
            let val = map.get_mut(&key).unwrap();
            *val -= 1;
            if *val == 0 {
                map.remove(&key);
            }
        }
    }
}
