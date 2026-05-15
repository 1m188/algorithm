/*

标题：交换次数

IT产业人才需求节节攀升。业内巨头百度、阿里巴巴、腾讯（简称BAT）在某海滩进行招聘活动。
招聘部门一字排开。由于是自由抢占席位，三大公司的席位随机交错在一起，形如：
ABABTATT，这使得应聘者十分别扭。
于是，管理部门要求招聘方进行必要的交换位置，使得每个集团的席位都挨在一起。即最后形如：
BBAAATTT 这样的形状，当然，也可能是：
AAABBTTT 等。

现在，假设每次只能交换2个席位，并且知道现在的席位分布，
你的任务是计算：要使每个集团的招聘席位都挨在一起需要至少进行多少次交换动作。

输入是一行n个字符（只含有字母B、A或T），表示现在的席位分布。
输出是一个整数，表示至少交换次数。

比如，输入：
TABTABBTTTT

程序应该输出：
3

再比如，输入：
TTAAABB

程序应该输出：
0

我们约定，输入字符串的长度n 不大于10万

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。


*/

import java.util.Scanner;

public class Main_5 {

    // 计算按(x,y,z)排列时所需的最少交换次数
    // Zone1放x, Zone2放y, Zone3放z
    // 公式: swaps = (2*M - C) / 3
    // M = 总错位数, C = 可直接互换的对数(2-cycle)
    static int calc(String s, char x, char y, char z) {
        int n = s.length();
        int cntX = 0, cntY = 0;
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == x)
                cntX++;
            else if (c == y)
                cntY++;
            else {
            }
        }

        // 统计各区域中的错位字符数
        int y1 = 0, z1 = 0; // Zone1中y和z的个数
        int x2 = 0, z2 = 0; // Zone2中x和z的个数
        int x3 = 0, y3 = 0; // Zone3中x和y的个数

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (i < cntX) {
                if (c == y)
                    y1++;
                else if (c == z)
                    z1++;
            } else if (i < cntX + cntY) {
                if (c == x)
                    x2++;
                else if (c == z)
                    z2++;
            } else {
                if (c == x)
                    x3++;
                else if (c == y)
                    y3++;
            }
        }

        int M = y1 + z1 + x2 + z2 + x3 + y3;
        int c12 = Math.min(y1, x2);
        int c13 = Math.min(z1, x3);
        int c23 = Math.min(z2, y3);
        int C = c12 + c13 + c23;

        return (2 * M - C) / 3;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            String s = sc.next();

            int ans = Integer.MAX_VALUE;
            // 枚举所有6种排列
            ans = Math.min(ans, calc(s, 'B', 'A', 'T'));
            ans = Math.min(ans, calc(s, 'B', 'T', 'A'));
            ans = Math.min(ans, calc(s, 'A', 'B', 'T'));
            ans = Math.min(ans, calc(s, 'A', 'T', 'B'));
            ans = Math.min(ans, calc(s, 'T', 'B', 'A'));
            ans = Math.min(ans, calc(s, 'T', 'A', 'B'));

            System.out.println(ans);
        }
    }
}
