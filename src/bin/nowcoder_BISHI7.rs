/*
BISHI7 字符串哈希

描述
给定
N
N 个字符串
s
1
,
s
2
,
…
,
s
N
s
1
​
 ,s
2
​
 ,…,s
N
​
 ，其中每个字符串仅由数字和大小写字母组成且区分大小写。请计算这
N
N 个字符串中不同字符串的个数。
输入描述：
第一行输入整数
N

(
1
≦
N
≦
1
0
4
)
N (1≦N≦10
4
 )。
接下来
N
N 行，每行输入一个字符串
s
i
s
i
​
 ，满足
1
≦
∣
s
i
∣
≦
1500
1≦∣s
i
​
 ∣≦1500。
输出描述：
输出一个整数，表示不同字符串的数量。
示例1
输入：
6
Hello
World
hello
HELLO
Code
Hello
复制
输出：
5
复制
说明：
在该样例中，输入的字符串集合为
{
Hello
,
World
,
hello
,
HELLO
,
Code
,
Hello
}
{Hello,World,hello,HELLO,Code,Hello}，不同字符串共有 5 个。
*/

use std::{
    collections::HashSet,
    io::{self, Read},
};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');
    let n: i32 = iter.next().unwrap().parse().unwrap();

    let mut set: HashSet<&str> = HashSet::new();

    for _ in 0..n {
        let s = iter.next().unwrap();
        set.insert(s);
    }

    print!("{}\n", set.len());
}
