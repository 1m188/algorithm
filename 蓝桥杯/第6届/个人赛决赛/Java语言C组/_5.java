/*
密文搜索

福尔摩斯从X星收到一份资料，全部是小写字母组成。
他的助手提供了另一份资料：许多长度为8的密码列表。
福尔摩斯发现，这些密码是被打乱后隐藏在先前那份资料中的。

请你编写一个程序，从第一份资料中搜索可能隐藏密码的位置。要考虑密码的所有排列可能性。

数据格式：

输入第一行：一个字符串s，全部由小写字母组成，长度小于1024*1024
紧接着一行是一个整数n,表示以下有n行密码，1<=n<=1000
紧接着是n行字符串，都是小写字母组成，长度都为8

要求输出：
一个整数, 表示每行密码的所有排列在s中匹配次数的总和。

例如：
用户输入：
aaaabbbbaabbcccc
2
aaaabbbb
abcabccc

则程序应该输出：
4
*/

import java.util.HashMap;
import java.util.Scanner;

public class _5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();
        String[] pwd = new String[n];
        for (int i = 0; i < n; i++)
            pwd[i] = sc.next();
        sc.close();

        // 预计算每个密码的字母频次签名，存入 HashMap
        HashMap<String, Integer> map = new HashMap<>();
        for (String pw : pwd) {
            String sig = signature(pw);
            map.put(sig, map.getOrDefault(sig, 0) + 1);
        }

        long ans = 0;
        if (s.length() < 8) {
            System.out.println(0);
            return;
        }

        // 滑动窗口维护当前 8 字符的频次
        int[] cnt = new int[26];
        for (int i = 0; i < 8; i++)
            cnt[s.charAt(i) - 'a']++;

        String sig = sigFromCnt(cnt);
        ans += map.getOrDefault(sig, 0);

        for (int i = 8; i < s.length(); i++) {
            cnt[s.charAt(i - 8) - 'a']--;
            cnt[s.charAt(i) - 'a']++;
            sig = sigFromCnt(cnt);
            ans += map.getOrDefault(sig, 0);
        }

        System.out.println(ans);
    }

    /** 计算字符串中每个字母的出现次数并编码为签名 */
    static String signature(String w) {
        int[] cnt = new int[26];
        for (char c : w.toCharArray())
            cnt[c - 'a']++;
        return sigFromCnt(cnt);
    }

    /** 将频次数组编码为简短的签名（按字母顺序列出非零项） */
    static String sigFromCnt(int[] cnt) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                sb.append((char) ('a' + i));
                sb.append(cnt[i]);
            }
        }
        return sb.toString();
    }
}
