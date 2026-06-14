/*
取球博弈

两个人玩取球的游戏。
一共有N个球，每人轮流取球，每次可取集合{n1,n2,n3}中的任何一个数目。
如果无法继续取球，则游戏结束。
此时，持有奇数个球的一方获胜。
如果两人都是奇数，则为平局。

假设双方都采用最聪明的取法，
第一个取球的人一定能赢吗？
试编程解决这个问题。

输入格式：
第一行3个正整数n1 n2 n3，空格分开，表示每次可取的数目 (0<n1,n2,n3<100)
第二行5个正整数x1 x2 ... x5，空格分开，表示5局的初始球数(0<xi<1000)

输出格式：
一行5个字符，空格分开。分别表示每局先取球的人能否获胜。
能获胜则输出+，
次之，如有办法逼平对手，输出0，
无论如何都会输，则输出-

例如，输入：
1 2 3
1 2 3 4 5

程序应该输出：
+ 0 + 0 -

再例如，输入：
1 4 5
10 11 12 13 15

程序应该输出：
0 - 0 + +

再例如，输入：
2 3 5
7 8 9 10 11

程序应该输出：
+ 0 0 0 0


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。
*/

import java.util.Arrays;
import java.util.Scanner;

public class _9 {
    static int[] move = new int[3];          // 可取数目
    static int minMove;                      // 最小可取数
    static int[] memo;                       // 记忆化：-2=未访问, -3=访问中(判环)

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        move[0] = sc.nextInt();
        move[1] = sc.nextInt();
        move[2] = sc.nextInt();
        // 排序方便计算最小可取数
        Arrays.sort(move);
        minMove = move[0];

        int[] balls = new int[5];
        for (int i = 0; i < 5; i++)
            balls[i] = sc.nextInt();
        sc.close();

        // memo 编码：(n*4 + p0*2 + p1)，最大 n=1000，p0,p1∈{0,1}
        int maxN = 1000;
        memo = new int[(maxN + 1) * 4];
        Arrays.fill(memo, -2);               // 未访问

        StringBuilder sb = new StringBuilder();
        for (int n : balls) {
            int res = solve(n, 0, 0);        // 初始双方均为偶数
            sb.append(res == 1 ? '+' : res == 0 ? '0' : '-').append(' ');
        }
        System.out.println(sb.toString().trim());
    }

    /** 编码状态的唯一键 */
    static int key(int n, int p0, int p1) {
        return n * 4 + p0 * 2 + p1;
    }

    /**
     * 递归求解：剩余 n 个球，当前玩家已有球数奇偶为 p0，对手为 p1。
     * 返回值: 1=当前玩家必胜, 0=平局, -1=必败
     */
    static int solve(int n, int p0, int p1) {
        int k = key(n, p0, p1);
        if (memo[k] != -2)
            return memo[k] == -3 ? 0 : memo[k]; // 环中默认为平局

        // 终局：无法取球
        if (n < minMove) {
            if (p0 == 1 && p1 == 0)
                return memo[k] = 1;
            if (p0 == 0 && p1 == 1)
                return memo[k] = -1;
            return memo[k] = 0;
        }

        memo[k] = -3;                        // 标记访问中，防循环
        boolean canDraw = false;

        for (int take : move) {
            if (take > n)
                continue;
            // 取走 take 个球后，轮到对手
            int sub = solve(n - take, p1, p0 ^ (take & 1));
            if (sub == -1) {                 // 对手必败 → 我必胜
                return memo[k] = 1;
            }
            if (sub == 0)                    // 对手可平 → 我可平
                canDraw = true;
        }

        if (canDraw)
            return memo[k] = 0;
        return memo[k] = -1;                 // 所有分支都必败
    }
}
