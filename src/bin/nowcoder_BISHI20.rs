/*
BISHI20 回文日期

描述
一个日期用
Y
Y
Y
Y
M
M
D
D
YYYYMMDD 的
8
8 位数字表示，其中前四位为年份，接着两位为月份，最后两位为日期。

若这
8
8 位数字本身是一个回文数，则称该日期为回文日期。

给定起始日期
a
a 与终止日期
b
b（均包含在内，且满足
a
≦
b
a≦b），请计算区间内真实存在的回文日期数量。

【名词解释】回文数：一个数字从左往右读与从右往左读完全相同。

【日期合法性】
∙

∙ 1,3,5,7,8,10,12 月有
31
31 天；
∙

∙ 4,6,9,11 月有
30
30 天；
∙

∙ 2 月在闰年有
29
29 天，平年有
28
28 天。

【闰年判定】
∙

∙ 能被
4
4 整除但不能被
100
100 整除的年份；
∙

∙ 或能被
400
400 整除的年份。
输入描述：
第一行输入
8
8 位整数
a
a，表示起始日期。
第二行输入
8
8 位整数
b
b，表示终止日期。
输出描述：
输出一个整数，表示
[
a
,
b
]
[a,b] 区间内回文日期的数量。
示例1
输入：
20110101
20111231
复制
输出：
1
复制
说明：
在这个样例中，在
20110101
20110101 和
20111231
20111231 之间，回文日期有
1
1 个，即
20111102
20111102 。
示例2
输入：
20000101
20101231
复制
输出：
2
复制
说明：
在这个样例中，在
20000101
20000101 和
20101231
20101231 之间，回文日期有
2
2 个，即
20010002
20010002 和
20100102
20100102 。
*/

use std::io;

fn main() {
    let mut start_date = String::new();
    let mut end_date = String::new();
    io::stdin().read_line(&mut start_date).unwrap();
    io::stdin().read_line(&mut end_date).unwrap();
    start_date = start_date.trim().to_string();
    end_date = end_date.trim().to_string();

    let start_year = start_date[0..4].parse::<i32>().unwrap();
    let start_month = start_date[4..6].parse::<i32>().unwrap();
    let start_day = start_date[6..8].parse::<i32>().unwrap();

    mod local {
        pub fn is_leap(y: &i32) -> bool {
            (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)
        }
        pub fn is_palindrome(s: &str) -> bool {
            s.chars().eq(s.chars().rev())
        }
    }

    let days_in_month = vec![31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let mut count = 0;
    let mut year = start_year;
    let mut month = start_month;
    let mut day = start_day;
    loop {
        let date = format!("{:04}{:02}{:02}", year, month, day);
        if local::is_palindrome(&date) {
            count += 1;
        }
        if date == end_date {
            break;
        }

        let mut x = days_in_month[month as usize - 1];
        if month == 2 && local::is_leap(&year) {
            x += 1;
        }

        day += 1;
        if day > x {
            day = 1;
            month += 1;
            if month > 12 {
                month = 1;
                year += 1;
            }
        }
    }

    println!("{}", count);
}
