/*
 * @lc app=leetcode.cn id=3692 lang=rust
 * @lcpr version=30204
 *
 * [3692] 众数频率字符
 *
 * https://leetcode.cn/problems/majority-frequency-characters/description/
 *
 * algorithms
 * Easy (66.83%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    1.8K
 * Total Submissions: 2.7K
 * Testcase Example:  '"aaabbbccdddde"'
 *
 * 给你一个由小写英文字母组成的字符串 s。
 *
 * 对于一个值 k，频率组 是在 s 中恰好出现 k 次的字符集合。
 *
 * 众数频率组 是包含 不同 字符数量最多的频率组。
 *
 * 返回一个字符串，包含众数频率组中的所有字符，字符的顺序 不限 。如果两个或多个频率组的大小并列最大，则选择其频率 k 较大 的那个组。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "aaabbbccdddde"
 *
 * 输出: "ab"
 *
 * 解释:
 *
 *
 *
 *
 * 频率 (k)
 * 组中不同字符
 * 组大小
 * 是否众数?
 *
 *
 *
 *
 * 4
 * {d}
 * 1
 * 否
 *
 *
 * 3
 * {a, b}
 * 2
 * 是
 *
 *
 * 2
 * {c}
 * 1
 * 否
 *
 *
 * 1
 * {e}
 * 1
 * 否
 *
 *
 *
 *
 * 字符 'a' 和 'b' 的频率相同，都为 3，它们在众数频率组中。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "abcd"
 *
 * 输出: "abcd"
 *
 * 解释:
 *
 *
 *
 *
 * 频率 (k)
 * 组中不同字符
 * 组大小
 * 是否众数?
 *
 *
 *
 *
 * 1
 * {a, b, c, d}
 * 4
 * 是
 *
 *
 *
 *
 * 所有字符的频率都相同，都为 1，它们都在众数频率组中。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "pfpfgi"
 *
 * 输出: "fp"
 *
 * 解释:
 *
 *
 *
 *
 * 频率 (k)
 * 组中不同字符
 * 组大小
 * 是否众数?
 *
 *
 *
 *
 * 2
 * {p, f}
 * 2
 * 是
 *
 *
 * 1
 * {g, i}
 * 2
 * 否 (组大小并列，选择频率更大的 k = 2)
 *
 *
 *
 *
 * 字符 'p' 和 'f' 的频率相同，都为 2，它们在众数频率组中。频率为 1 的组大小并列，但我们选择频率更高的组 2。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= s.length <= 100
 * s 只包含小写英文字母。
 *
 *
 */

// @lcpr-template-start
#![no_main]
#![allow(dead_code)]
struct Solution {}
// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn majority_frequency_group(s: String) -> String {
        let mut cnts: [i32; 26] = [0; 26];
        s.chars().for_each(|c| cnts[(c as u8 - b'a') as usize] += 1);

        struct Node {
            chars: Vec<char>,
            cnt: i32,
        }

        let mut nodes: Vec<Node> = Vec::new();
        for i in 0..cnts.len() {
            if cnts[i] <= 0 {
                continue;
            }
            nodes.push(Node {
                chars: vec![(i as u8 + b'a') as char],
                cnt: cnts[i],
            })
        }

        nodes.sort_by(|a, b| a.cnt.cmp(&b.cnt));

        let mut index: usize = 0;
        while index < nodes.len() - 1 {
            if nodes[index].cnt == nodes[index + 1].cnt {
                let (left, right) = nodes.split_at_mut(index + 1);
                left.last_mut()
                    .unwrap()
                    .chars
                    .append(&mut right.first_mut().unwrap().chars);
                nodes.remove(index + 1);
            } else {
                index += 1;
            }
        }

        nodes.sort_by(|a, b| {
            if a.chars.len() != b.chars.len() {
                b.chars.len().cmp(&a.chars.len())
            } else {
                b.cnt.cmp(&a.cnt)
            }
        });

        String::from_iter(nodes[0].chars.iter())
    }
}
// @lc code=end

/*
// @lcpr case=start
// "aaabbbccdddde"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n
// @lcpr case=end

// @lcpr case=start
// "pfpfgi"\n
// @lcpr case=end

 */
