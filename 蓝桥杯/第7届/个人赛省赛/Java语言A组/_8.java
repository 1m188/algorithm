/*
 * 
 * 取球博弈
 * 
 * 两个人玩取球的游戏。
 * 一共有N个球，每人轮流取球，每次可取集合{n1,n2,n3}中的任何一个数目。
 * 如果无法继续取球，则游戏结束。
 * 此时，持有奇数个球的一方获胜。
 * 如果两人都是奇数，则为平局。
 * 
 * 假设双方都采用最聪明的取法，
 * 第一个取球的人一定能赢吗？
 * 试编程解决这个问题。
 * 
 * 输入格式：
 * 第一行3个正整数n1 n2 n3，空格分开，表示每次可取的数目 (0<n1,n2,n3<100)
 * 第二行5个正整数x1 x2 ... x5，空格分开，表示5局的初始球数(0<xi<1000)
 * 
 * 输出格式：
 * 一行5个字符，空格分开。分别表示每局先取球的人能否获胜。
 * 能获胜则输出+，
 * 次之，如有办法逼平对手，输出0，
 * 无论如何都会输，则输出-
 * 
 * 例如，输入：
 * 1 2 3
 * 1 2 3 4 5
 * 
 * 程序应该输出：
 * + 0 + 0 -
 * 
 * 再例如，输入：
 * 1 4 5
 * 10 11 12 13 15
 * 
 * 程序应该输出：
 * 0 - 0 + +
 * 
 * 再例如，输入：
 * 2 3 5
 * 7 8 9 10 11
 * 
 * 程序应该输出：
 * + 0 0 0 0
 * 
 * 
 * 资源约定：
 * 峰值内存消耗（含虚拟机） < 256M
 * CPU消耗 < 3000ms
 * 
 * 
 * 请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
 * 
 * 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
 * 注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
 * 注意：主类的名字必须是：Main，否则按无效代码处理。
 * 
 */

import java.io.*;
import java.util.*;

public class _8 {
    static int[] moves = new int[3]; // 每次可取数目
    static int minMove; // 最小可取数目
    // 记忆化：memo[r][p1奇偶][p2奇偶][回合]，回合0=P1, 1=P2
    static int[][][][] memo;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 3; i++)
            moves[i] = Integer.parseInt(st.nextToken());
        minMove = Math.min(Math.min(moves[0], moves[1]), moves[2]);

        st = new StringTokenizer(br.readLine());
        // 5 局独立求解，每局重建记忆数组（剩余球数不同）
        for (int t = 0; t < 5; t++) {
            int N = Integer.parseInt(st.nextToken());
            memo = new int[N + 1][2][2][2];
            int res = dfs(N, 0, 0, 0); // 初始 P1 回合，双方均为偶数
            char c = res == 1 ? '+' : res == 0 ? '0' : '-';
            System.out.print(c + (t < 4 ? " " : "\n"));
        }
    }

    /**
     * @param r    剩余球数
     * @param p1o  P1 球数奇偶（0 偶 1 奇）
     * @param p2o  P2 球数奇偶
     * @param turn 当前回合（0=P1 1=P2）
     * @return 从 P1 视角的终局：1=P1赢 0=平 -1=P1输
     */
    static int dfs(int r, int p1o, int p2o, int turn) {
        // 终局：剩余球不够取
        if (r < minMove) {
            if (p1o == 1 && p2o == 0)
                return 1;
            if (p1o == 0 && p2o == 1)
                return -1;
            return 0;
        }
        if (memo[r][p1o][p2o][turn] != 0)
            return memo[r][p1o][p2o][turn];

        int best;
        if (turn == 0) { // P1 回合：最大化自身
            best = -1;
            for (int k : moves) {
                if (k > r)
                    continue;
                int o = dfs(r - k, p1o ^ (k & 1), p2o, 1);
                if (o == 1) {
                    best = 1;
                    break;
                }
                if (o == 0)
                    best = 0;
            }
        } else { // P2 回合：最小化 P1
            best = 1;
            for (int k : moves) {
                if (k > r)
                    continue;
                int o = dfs(r - k, p1o, p2o ^ (k & 1), 0);
                if (o == -1) {
                    best = -1;
                    break;
                }
                if (o == 0)
                    best = 0;
            }
        }
        return memo[r][p1o][p2o][turn] = best;
    }
}