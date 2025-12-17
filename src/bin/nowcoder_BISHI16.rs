/*
BISHI16 计算一年中的第几天

描述
今年的第几天？

输入年、月、日，计算该天是本年的第几天。

输入描述：
包括三个整数年(1<=Y<=3000)、月(1<=M<=12)、日(1<=D<=31)。
输出描述：
输入可能有多组测试数据，对于每一组测试数据，
输出一个整数，代表Input中的年、月、日对应本年的第几天。
示例1
输入：
1990 9 20
2000 5 1
复制
输出：
263
122
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let iter = buf.split('\n');

    let mut days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

    for line in iter {
        if line.is_empty() {
            break;
        }
        let mut nums = line.split(' ');
        let year = nums.next().unwrap().parse::<i32>().unwrap();
        let month = nums.next().unwrap().parse::<i32>().unwrap();
        let day = nums.next().unwrap().parse::<i32>().unwrap();

        if (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 {
            days[2] = 29;
        } else {
            days[2] = 28;
        }

        let mut sum = 0;
        for i in 1..month {
            sum += days[i as usize];
        }
        sum += day;

        println!("{}", sum);
    }
}
