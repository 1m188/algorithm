/*

标题：海盗与金币

12名海盗在一个小岛上发现了大量的金币，后统计一共有将近5万枚。
登上小岛是在夜里，天气又不好。由于各种原因，有的海盗偷拿了很多，有的拿了很少。
后来为了"均贫富"，头目提出一个很奇怪的方案：
每名海盗都把自己拿到的金币放在桌上。然后开始一个游戏。
金币最多的海盗要拿出自己的金币来补偿其他人。
补偿的额度为正好使被补偿人的金币数目翻番(即变为原来的2倍)。
游戏要一直进行下去，直到无法完成。
（当金币数最多的不只一个人或最多金币的人持有金币数不够补偿他人的）

游戏就这样紧张地进行了，一直进行了12轮，恰好每人都"放血"一次，
更离奇的是，刚好在第12轮后，每个人的金币数居然都相等了！！ 这难道是天意吗？

请你计算，游戏开始前，所有海盗的初始金币数目，从小到大排列，中间有一个空格分开。

答案形如：
8 15 29 58 110 ...
当然，这个不是正确答案。

注意：
需要提交的是一行空格分开的整数，不要提交任何多余的内容。
分隔符要用一个西文的空格，不要用其它符号（比如逗号，中文符号等）


*/

public class _2 {
    public static void main(String[] args) {
        int n = 12;
        long[] state = new long[n];
        // 最终每人金币相等，设为 K = 2^12 = 4096（保证反向推演时所有分数皆为整数）
        long K = 1L << n; // 4096
        for (int i = 0; i < n; i++) {
            state[i] = K;
        }
        // 固定补偿顺序不影响最终初始金币的集合（仅为分配不同）
        // 反向推演 12 轮：第 i 轮补偿者为 pirate i（正向第 1 轮补偿者是 0，…，第 12 轮补偿者是 11）
        for (int round = n - 1; round >= 0; round--) {
            int c = round; // 本轮（反向）的补偿者
            long sumHalf = 0;
            for (int j = 0; j < n; j++) {
                if (j != c) {
                    sumHalf += state[j] / 2;
                }
            }
            for (int j = 0; j < n; j++) {
                if (j != c) {
                    state[j] /= 2;
                }
            }
            state[c] = state[c] + sumHalf;
        }
        // 排序后输出
        java.util.Arrays.sort(state);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (i > 0)
                sb.append(' ');
            sb.append(state[i]);
        }
        System.out.println(sb.toString());
    }
}
