// 剪邮票

// 如【图1.jpg】, 有12张连在一起的12生肖的邮票。  3 x 4 大小
// 现在你要从中剪下5张来，要求必须是连着的。
// （仅仅连接一个角不算相连）
// 比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。

// 请你计算，一共有多少种不同的剪取方法。

// 请填写表示方案数目的整数。
// 注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

import java.util.LinkedList;
import java.util.Queue;

public class _7 {
    private static boolean[] flag = new boolean[12];
    private static int res;

    public static void main(String[] args) {
        getFive(0, 0);
        System.out.println(res);
    }

    // 递归获取五个数的组合
    private static void getFive(int index, int f) {
        if (f >= 5) {
            if (bfs()) {
                res++;
            }
        } else {
            for (int i = index; i < flag.length; i++) {
                if (!flag[i]) {
                    flag[i] = true;
                    getFive(i + 1, f + 1);
                    flag[i] = false;
                }
            }
        }
    }

    // bfs判定五个选的数是否连通
    private static boolean bfs() {
        Queue<Integer> pos = new LinkedList<>();
        boolean[] f = new boolean[12];
        for (int i = 0; i < flag.length; i++) {
            if (flag[i]) {
                pos.offer(i);
                f[i] = true;
                break;
            }
        }

        int num = 0;
        while (!pos.isEmpty()) {
            int p = pos.poll();
            num++;
            if (p - 4 >= 0 && flag[p - 4] && !f[p - 4]) {
                pos.offer(p - 4);
                f[p - 4] = true;
            }
            if (p + 4 < flag.length && flag[p + 4] && !f[p + 4]) {
                pos.offer(p + 4);
                f[p + 4] = true;
            }
            if (p - 1 >= 0 && (p - 1) / 4 == p / 4 && flag[p - 1] && !f[p - 1]) {
                pos.offer(p - 1);
                f[p - 1] = true;
            }
            if (p + 1 < flag.length && (p + 1) / 4 == p / 4 && flag[p + 1] && !f[p + 1]) {
                pos.offer(p + 1);
                f[p + 1] = true;
            }
        }
        return num == 5;
    }
}