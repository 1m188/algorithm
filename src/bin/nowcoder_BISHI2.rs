/*
BISHI2 【模板】栈的操作

描述
实现一个初始为空的栈，支持以下操作：
∙

∙ push(x)：将整数
x
x 入栈；
∙

∙ pop()：若栈非空，则删除栈顶元素；否则输出
Empty
Empty；
∙

∙ query()：若栈非空，则输出栈顶元素；否则输出
Empty
Empty；
∙

∙ size()：输出栈中元素的数量。
输入描述：
输入的第一行包含一个整数
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
 )，表示操作总数；
接下来的
n
n 行，每行描述一条操作，格式如下：
∘

∘ “push x”，将整数
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
x (−10
9
 ≦x≦10
9
 ) 入栈；
∘

∘ “pop”、“query”、“size”，执行对应操作。
输出描述：
对每组数据，按操作顺序依次输出所有需要输出的结果，每次输出占一行。
示例1
输入：
7
push 1
push 2
size
query
pop
pop
query
复制
输出：
2
2
Empty
复制
说明：
执行 push 1、push 2 后，size 输出 2，query 输出 2。
两次 pop 后栈被清空，query 输出 Empty。
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');

    let n: i32 = iter.next().unwrap().parse().unwrap();
    let mut stack: Vec<i32> = Vec::new();

    for _ in 0..n {
        let line = iter.next().unwrap();
        if line.contains("push") {
            let x: i32 = line.split_whitespace().nth(1).unwrap().parse().unwrap();
            stack.push(x);
        } else if line.contains("pop") {
            if !stack.is_empty() {
                stack.pop();
            } else {
                print!("Empty\n");
            }
        } else if line.contains("query") {
            if !stack.is_empty() {
                print!("{}\n", stack.last().unwrap());
            } else {
                print!("Empty\n");
            }
        } else {
            print!("{}\n", stack.len());
        }
    }
}
