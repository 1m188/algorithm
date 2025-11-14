/*
BISHI9 田忌赛马

描述
田忌与齐威王正在赛马，比赛一共三局，三局两胜，当一方马匹速度严格大于另一方时获胜，每匹马只能出场一次。
现在你已经知道了齐威王的马匹上场的顺序，将在第一、二、三场上场的马匹速度分别为
v
1
,
v
2
,
v
3
v
1
​
 ,v
2
​
 ,v
3
​
 。同时，你也已经知道了田忌所拥有的马匹速度，分别为
a
1
,
a
2
,
a
3
a
1
​
 ,a
2
​
 ,a
3
​
 。
你可以调整田忌的马匹出场顺序，你能否帮助田忌赢得这场比赛？
输入描述：
第一行输入三个整数
v
1
,
v
2
,
v
3
(
1
≤
v
i
≤
9
)
v
1
​
 ,v
2
​
 ,v
3
​
 (1≤v
i
​
 ≤9) 代表齐威王按上场顺序的马匹速度。
第二行输入三个整数
a
1
,
a
2
,
a
3
(
1
≤
a
i
≤
9
)
a
1
​
 ,a
2
​
 ,a
3
​
 (1≤a
i
​
 ≤9) 代表田忌拥有的马匹速度。顺序可以任意调整。
输出描述：
如果田忌可以获胜，直接输出
Y
e
s
Yes，否则输出
N
o
No。
示例1
输入：
3 2 1
1 2 3
复制
输出：
Yes
复制
说明：
在这个样例中，田忌可以在第一局派出速度为
1
1 的马匹，在第二局派出速度为
3
3 的马匹，在第三局派出速度为
2
2 的马匹。如此一来，他会赢得两局比赛，从而获胜。
示例2
输入：
2 2 2
2 2 3
复制
输出：
No
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');

    let mut v = iter
        .next()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
    v.sort_by(|a, b| b.cmp(a));

    let mut a = iter
        .next()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
    a.sort_by(|a, b| b.cmp(a));

    if a[0] > v[0] {
        if a[1] > v[1] || a[1] > v[2] {
            print!("Yes\n");
            return;
        }
    } else if a[0] > v[1] {
        if a[1] > v[2] {
            print!("Yes\n");
            return;
        }
    }
    print!("No\n");
}
