/*

标题：填字母游戏

小明经常玩 LOL 游戏上瘾，一次他想挑战K大师，不料K大师说：
“我们先来玩个空格填字母的游戏，要是你不能赢我，就再别玩LOL了”。

K大师在纸上画了一行n个格子，要小明和他交替往其中填入字母。

并且：

1. 轮到某人填的时候，只能在某个空格中填入L或O
2. 谁先让字母组成了“LOL”的字样，谁获胜。
3. 如果所有格子都填满了，仍无法组成LOL，则平局。

小明试验了几次都输了，他很惭愧，希望你能用计算机帮他解开这个谜。

本题的输入格式为：
第一行，数字n（n<10），表示下面有n个初始局面。
接下来，n行，每行一个串，表示开始的局面。
  比如：“******”, 表示有6个空格。
  “L****”,   表示左边是一个字母L，它的右边是4个空格。

要求输出n个数字，表示对每个局面，如果小明先填，当K大师总是用最强着法的时候，小明的最好结果。
1 表示能赢
-1 表示必输
0 表示可以逼平


例如，
输入：
4
***
L**L
L**L***L
L*****L

则程序应该输出：
0
-1
1
1

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。


*/

import java.io.*;
import java.util.*;

public class _5 {
    // 记忆化：局面 → 当前玩家结果（1 赢，-1 输，0 平）
    static HashMap<String, Integer> memo = new HashMap<String, Integer>();

    /**
     * 返回当前局面对当前走棋方的结局
     * 1：当前玩家必胜
     * -1：当前玩家必败
     * 0：平局
     */
    static int dfs(char[] s) {
        String key = new String(s);
        Integer cached = memo.get(key);
        if (cached != null)
            return cached;

        // 无空格可填 → 平局
        boolean hasStar = false;
        for (char c : s) {
            if (c == '*') {
                hasStar = true;
                break;
            }
        }
        if (!hasStar) {
            memo.put(key, 0);
            return 0;
        }

        int best = -1; // 当前玩家最差初始结果

        for (int i = 0; i < s.length; i++) {
            if (s[i] != '*')
                continue;

            // 尝试填 L
            s[i] = 'L';
            if (containsLOL(s)) {
                best = 1; // 直接获胜
                s[i] = '*';
                break;
            }
            int opp = dfs(s);
            if (opp == -1) {
                best = 1;
                s[i] = '*';
                break;
            } // 对手必败 → 我必胜
            if (opp == 0 && best < 0)
                best = 0; // 对手可平 → 至少平
            s[i] = '*';

            // 尝试填 O
            s[i] = 'O';
            if (containsLOL(s)) {
                best = 1;
                s[i] = '*';
                break;
            }
            opp = dfs(s);
            if (opp == -1) {
                best = 1;
                s[i] = '*';
                break;
            }
            if (opp == 0 && best < 0)
                best = 0;
            s[i] = '*';
        }

        memo.put(key, best);
        return best;
    }

    /** 检查字符数组中是否存在子串 "LOL" */
    static boolean containsLOL(char[] s) {
        for (int i = 0; i <= s.length - 3; i++) {
            if (s[i] == 'L' && s[i + 1] == 'O' && s[i + 2] == 'L')
                return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int t = 0; t < n; t++) {
            String line = br.readLine().trim();
            // 初始局面不应包含 "LOL"，若有则已结束（按规则不会出现）
            int result = dfs(line.toCharArray());
            System.out.println(result);
            memo.clear(); // 不同局面间清理记忆化缓存
        }
        br.close();
    }
}
