/*
BISHI15 小红的夹吃棋

描述
在一个
3
×
3
3×3 棋盘上，小红（执黑 ``
*
*``）与小紫（执白 ``
o
o``）进行“夹吃棋”。

规则：若某棋子在横向或纵向上被对方两个棋子夹住（即三连中间为对方棋子），该中间棋子被“夹吃”。

胜负判定：
∙

∙ 若仅一方存在被夹吃的棋子，则对方获胜；
∙

∙ 若双方均无被夹吃，或双方均被夹吃，则为平局。

给定若干局面，判断结果。
输入描述：
第一行输入整数
t
t（询问次数）。
每组询问输入
3
3 行，每行长度为
3
3 的字符串，仅含 ``
o
o``（白子）、``
’*’
’*’``（黑子）、``
’.’
’.’``（未落子），表示棋盘状态。
输出描述：
对每局输出一行：
∙

∙ 小红胜输出 ``
kou
kou``；
∙

∙ 小紫胜输出 ``
yukari
yukari``；
∙

∙ 平局输出 ``
draw
draw``。
示例1
输入：
3
...
o*o
...
o**
ooo
..*
o*o
*o*
o*o
复制
输出：
yukari
kou
draw
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');

    let t: usize = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let mut board: [[u8; 3]; 3] = [[0; 3]; 3];
        for r in 0..3 {
            let line = iter.next().unwrap().as_bytes();
            for i in 0..3 {
                board[r][i] = line[i];
            }
        }

        let mut kou = 0;
        let mut yukari = 0;
        for row in 0..3 {
            if board[row][0] == b'*' && board[row][1] == b'o' && board[row][2] == b'*' {
                kou += 1;
            } else if board[row][0] == b'o' && board[row][1] == b'*' && board[row][2] == b'o' {
                yukari += 1;
            }
        }
        for col in 0..3 {
            if board[0][col] == b'*' && board[1][col] == b'o' && board[2][col] == b'*' {
                kou += 1;
            } else if board[0][col] == b'o' && board[1][col] == b'*' && board[2][col] == b'o' {
                yukari += 1;
            }
        }

        if (kou == 0 && yukari == 0) || (kou != 0 && yukari != 0) {
            println!("draw");
        } else if kou != 0 {
            println!("kou");
        } else {
            println!("yukari");
        }
    }
}
