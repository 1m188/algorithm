/*
BISHI10 小红的字符串修改

描述










小红有一个由小写字母构成的字符串
s
s，每次她可以把其中一个任意一个字母替换成其在字母表中相邻的字母，例如把 '
a
a' 替换成 '
b
b' 或者 '
z
z'。现在小红想知道，最少需要替换多少次，使得
s
s 成为
t
t 的子串。











如果字符串
t
t 可以通过从字符串
s
s 的开头删除若干（可能为零或全部）字符以及从结尾删除若干（可能为零或全部）字符得到，则字符串
t
t 是字符串
s
s 的子串。
输入描述：










第一行输入一个长度不超过
1
0
3
10
3
  ，且仅由小写字母构成的字符串
s
s 代表小红手中待替换的串。










第二行输入一个长度不小于
s
s 但不超过
1
0
3
10
3
  ，且仅由小写字母构成的字符串
t
t 代表目标串。
输出描述：










在一行上输出一个整数，代表最少需要替换的次数。
示例1
输入：
abc
abbc
复制
输出：
1
复制
说明：










需要进行一次替换，将 '
c
c' 替换成 '
b
b' ，此时得到 "
a
b
b
abb" ，是 "
a
b
b
c
abbc" 的子串，因为本质上是由 "
a
b
b
c
abbc" 末尾删除了一个字符得到的。
示例2
输入：
zzzzzz
xyzabc
复制
输出：
9
*/

use std::io::{self, Read};

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split('\n');

    let s = iter.next().unwrap().as_bytes();
    let t = iter.next().unwrap().as_bytes();

    mod local {
        pub fn min_replace(s: &[u8], t: &[u8]) -> i32 {
            let mut ans = 0;
            for i in 0..s.len() {
                let x = (s[i] as i32 - t[i] as i32).abs();
                ans += x.min(26 - x);
            }
            ans
        }
    }

    let mut ans = i32::MAX;
    let (mut left, mut right) = (0 as usize, s.len());
    while right <= t.len() {
        ans = ans.min(local::min_replace(s, &t[left..right]));
        left += 1;
        right += 1;
    }

    print!("{}\n", ans);
}
