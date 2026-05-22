/*
 
标题：切开字符串

Pear有一个字符串，不过他希望把它切成两段。
这是一个长度为N（<=10^5）的字符串。
Pear希望选择一个位置，把字符串不重复不遗漏地切成两段，长度分别是t和N-t（这两段都必须非空）。

Pear用如下方式评估切割的方案：
定义"正回文子串"为：长度为奇数的回文子串。
设切成的两段字符串中，前一段中有A个不相同的正回文子串，后一段中有B个不相同的非正回文子串，则该方案的得分为A*B。

注意，后一段中的B表示的是："...非正回文..."，而不是: "...正回文..."。
那么所有的切割方案中，A*B的最大值是多少呢？

【输入数据】
输入第一行一个正整数N（<=10^5）
接下来一行一个字符串，长度为N。该字符串仅包含小写英文字母。
【输出数据】
一行一个正整数，表示所求的A*B的最大值。
【样例输入】
10
bbaaabcaba
【样例输出】
38
【数据范围】
对于20%的数据，N<=100
对于40%的数据，N<=1000
对于100%的数据，N<=10^5

资源约定：
峰值内存消耗（含虚拟机） < 512M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。

*/

import java.util.*;

// 回文树 (Eertree / Palindromic Tree)
class PalTree {
    int[] len, link;
    int[][] next;
    char[] s;
    int num, last;
    int oddCnt;

    PalTree(int maxN) {
        len = new int[maxN + 5];
        link = new int[maxN + 5];
        next = new int[maxN + 5][26];
        s = new char[maxN + 5];
        len[0] = -1;
        link[0] = 0;
        len[1] = 0;
        link[1] = 0;
        num = 1;
        last = 1;
        oddCnt = 0;
    }

    void add(int pos, char c) {
        s[pos] = c;
        int ci = c - 'a';
        int cur = last;
        while (true) {
            int curLen = len[cur];
            if (pos - 1 - curLen >= 0 && s[pos - 1 - curLen] == c)
                break;
            cur = link[cur];
        }
        if (next[cur][ci] != 0) {
            last = next[cur][ci];
            return;
        }
        num++;
        next[cur][ci] = num;
        len[num] = len[cur] + 2;
        if (len[num] == 1) {
            link[num] = 1;
        } else {
            int suf = link[cur];
            while (true) {
                int sufLen = len[suf];
                if (pos - 1 - sufLen >= 0 && s[pos - 1 - sufLen] == c)
                    break;
                suf = link[suf];
            }
            link[num] = next[suf][ci];
        }
        last = num;
        if (len[num] % 2 == 1)
            oddCnt++;
    }
}

// 后缀自动机 (Suffix Automaton)
class SAM {
    int[] len, link;
    int[][] next;
    int sz, last;
    long totalSub;

    SAM(int maxN) {
        int maxNodes = maxN * 2 + 5;
        len = new int[maxNodes];
        link = new int[maxNodes];
        next = new int[maxNodes][26];
        sz = 1;
        last = 1;
        len[1] = 0;
        link[1] = 0;
        totalSub = 0;
    }

    void add(char c) {
        int ci = c - 'a';
        int cur = ++sz;
        len[cur] = len[last] + 1;
        int p = last;
        while (p != 0 && next[p][ci] == 0) {
            next[p][ci] = cur;
            p = link[p];
        }
        if (p == 0) {
            link[cur] = 1;
        } else {
            int q = next[p][ci];
            if (len[p] + 1 == len[q]) {
                link[cur] = q;
            } else {
                int clone = ++sz;
                len[clone] = len[p] + 1;
                link[clone] = link[q];
                for (int i = 0; i < 26; i++)
                    next[clone][i] = next[q][i];
                while (p != 0 && next[p][ci] == q) {
                    next[p][ci] = clone;
                    p = link[p];
                }
                link[q] = link[cur] = clone;
            }
        }
        last = cur;
        totalSub += len[cur] - len[link[cur]];
    }
}

public class Main_5 {
    public static void main(String[] args) {
        // 入口委托给 Main 类
        Main.solve();
    }
}

class Main {
    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String str = sc.nextLine().trim();
        sc.close();

        char[] s = str.toCharArray();

        // 1. 正向回文树：oddPalLeft[t] = 前缀 [0, t-1] 中不同奇数回文子串数
        long[] oddPalLeft = new long[n + 1]; // 1-indexed
        PalTree pt = new PalTree(n);
        for (int i = 0; i < n; i++) {
            pt.add(i, s[i]);
            oddPalLeft[i + 1] = pt.oddCnt;
        }

        // 2. 反向回文树：oddPalRight[t] = 后缀 [t, n-1] 中不同奇数回文子串数
        long[] oddPalRight = new long[n]; // suffix starting at t
        pt = new PalTree(n);
        for (int i = n - 1, idx = 0; i >= 0; i--, idx++) {
            pt.add(idx, s[i]);
            oddPalRight[i] = pt.oddCnt;
        }

        // 3. SAM 在反转字符串上，得到后缀的不同子串总数
        long[] totalRight = new long[n]; // suffix starting at t
        SAM sam = new SAM(n);
        for (int i = n - 1, idx = 0; i >= 0; i--, idx++) {
            sam.add(s[i]);
            totalRight[i] = sam.totalSub;
        }

        // 4. 枚举切割点，求最大 A*B
        long ans = 0;
        for (int t = 1; t < n; t++) {
            long a = oddPalLeft[t]; // 左段不同奇数回文
            long b = totalRight[t] - oddPalRight[t]; // 右段不同非正回文子串
            long val = a * b;
            if (val > ans)
                ans = val;
        }
        System.out.println(ans);
    }
}
