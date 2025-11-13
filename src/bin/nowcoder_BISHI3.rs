/*
BISHI3 【模板】队列操作

描述
给定一个空队列，依次执行
n
n 个操作，操作类型定义如下：
∙

∙`1 x`：将整数
x
(
−
1
0
9
≦
x
≦
1
0
9
)
x(−10
9
 ≦x≦10
9
 ) 入队；
∙

∙`2`：若队列非空，则仅将队头元素出队，否则输出 `ERR_CANNOT_POP`；
∙

∙`3`：查询并输出队首元素，队列为空时输出 `ERR_CANNOT_QUERY`；
∙

∙`4`：输出队列当前元素数量。
输入描述：
第一行包含整数
n

(
1
≦
n
≦
1
0
5
)
n (1≦n≦10
5
 )，表示操作总数。
接下来
n
n 行，每行描述一个操作，格式如上所述。
输出描述：
对于每个操作 `2`、`3`、`4`，按执行顺序，每行输出对应的结果。
示例1
输入：
7
1 10
1 20
3
4
2
3
2
复制
输出：
10
2
20
复制
说明：
在样例中：
∙

∙执行 `1 10` 和 `1 20` 后队列为
[
10
,
20
]
[10,20]；
∙

∙`3` 输出队首
10
10；
∙

∙`4` 输出队列大小
2
2；
∙

∙`2` 出队并输出
10
10；队列变为
[
20
]
[20]；
∙

∙`3` 输出队首
20
20；
∙

∙`2` 出队并输出
20
20；此后队列为空。
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');

    let mut que: Vec<i32> = Vec::new();

    let n: i32 = iter.next().unwrap().parse().unwrap();
    for _ in 0..n {
        let cmd = iter.next().unwrap();
        let opt = cmd.chars().nth(0).unwrap();
        if opt == '1' {
            let x: i32 = cmd.split_whitespace().nth(1).unwrap().parse().unwrap();
            que.push(x);
        } else if opt == '2' {
            if !que.is_empty() {
                que.remove(0);
            } else {
                print!("{}\n", "ERR_CANNOT_POP");
            }
        } else if opt == '3' {
            match que.first() {
                Some(x) => print!("{}\n", x),
                None => print!("{}\n", "ERR_CANNOT_QUERY"),
            }
        } else {
            print!("{}\n", que.len());
        }
    }
}
