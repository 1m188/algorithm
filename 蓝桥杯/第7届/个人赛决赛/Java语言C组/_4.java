/*

赢球票

某机构举办球票大奖赛。获奖选手有机会赢取若干球票。

主持人拿出 N 张卡片，上面写着 1~N 的数字，按顺时针顺序排成一个圆圈。
你可以从任意一张卡片开始顺时针报数: 1,2,3.....
如果报出的数和某卡片上的数相同，则把该卡片收入囊中，从下一张卡片重新开始报数。
直到无法收获任何卡片，游戏结束。囊中所有卡片数字的和就是赢取的球票张数。

比如：
卡片排列是：1 2 3
我们从1号卡开始数，就把1号卡拿走。再从2号卡开始数，报数1对应卡片2，但数字不对，报数2对应卡片3，数字不对，报数3对应卡片1...但卡片1已经被拿走，所以跳过。随着报数越来越大，不可能再拿走卡片了。因此最终只赢了1张球票。

如果我们换种玩法，在游戏开始前傻傻地从卡片序号2开始数，那就一张卡拿不到了。

如果运气好，卡片排列是 2 1 3
那我们就可以把全部卡片都拿走！

本题的任务是：已知顺时针卡片序列。
随便你从哪里开始数，求最多能赢取多少球票（所有收入卡片的数字之和）？

输入数据：
第一行一个整数N(N<100)，表示卡片数目
第二行 N 个整数，表示顺时针排列的卡片

输出数据：
一行，一个整数，表示最好情况下能赢得多少球票

例如：
用户输入：
3
1 2 3

程序应该输出：
1

例如：
用户输入：
3
2 1 3

程序应该输出：
6


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。

*/

import java.util.Scanner;

public class _4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] cards = new int[N];
        for (int i = 0; i < N; i++)
            cards[i] = sc.nextInt();
        sc.close();

        int best = 0; // 最佳总分

        // 由于 N < 100，枚举所有可能的起始位置并模拟
        for (int start = 0; start < N; start++) {
            boolean[] taken = new boolean[N]; // 标记已取走的卡片
            int pos = start; // 当前数到的位置
            int num = 1; // 当前报数
            int score = 0;
            int takenCnt = 0; // 已取走卡片数

            while (takenCnt < N && num <= N) {
                if (!taken[pos]) {
                    if (cards[pos] == num) { // 报数与卡片数字匹配
                        score += cards[pos];
                        taken[pos] = true;
                        takenCnt++;
                        num = 1; // 重新从 1 报数
                        pos = (pos + 1) % N; // 从下一张卡开始
                        continue; // 跳过本次 pos 自增
                    } else {
                        num++; // 继续报下一个数
                    }
                }
                pos = (pos + 1) % N; // 顺时针移到下一张
            }
            if (score > best)
                best = score;
        }
        System.out.println(best);
    }
}
