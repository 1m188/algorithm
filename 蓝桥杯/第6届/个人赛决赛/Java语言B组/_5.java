/*
 
标题：表格计算

某次无聊中， atm 发现了一个很老的程序。这个程序的功能类似于 Excel ，它对一个表格进行操作。
不妨设表格有 n 行，每行有 m 个格子。
每个格子的内容可以是一个正整数，也可以是一个公式。
公式包括三种：
1. SUM(x1,y1:x2,y2) 表示求左上角是第 x1 行第 y1 个格子，右下角是第 x2 行第 y2 个格子这个矩形内所有格子的值的和。
2. AVG(x1,y1:x2,y2) 表示求左上角是第 x1 行第 y1 个格子，右下角是第 x2 行第 y2 个格子这个矩形内所有格子的值的平均数。
3. STD(x1,y1:x2,y2) 表示求左上角是第 x1 行第 y1 个格子，右下角是第 x2 行第 y2 个格子这个矩形内所有格子的值的标准差。

标准差即为方差的平方根。
方差就是：每个数据与平均值的差的平方的平均值，用来衡量单个数据离开平均数的程度。

公式都不会出现嵌套。

如果这个格子内是一个数，则这个格子的值等于这个数，否则这个格子的值等于格子公式求值结果。

输入这个表格后，程序会输出每个格子的值。atm 觉得这个程序很好玩，他也想实现一下这个程序。

「输入格式」
第一行两个数 n, m 。
接下来 n 行输入一个表格。每行 m 个由空格隔开的字符串，分别表示对应格子的内容。
输入保证不会出现循环依赖的情况，即不会出现两个格子 a 和 b 使得 a 的值依赖 b 的值且 b 的值依赖 a 的值。

「输出格式」
输出一个表格，共 n 行，每行 m 个保留两位小数的实数。
数据保证不会有格子的值超过 1e6 。

「样例输入」
3 2
1 SUM(2,1:3,1)
2 AVG(1,1:1,2)
SUM(1,1:2,1) STD(1,1:2,2)

「样例输出」
1.00 5.00
2.00 3.00
3.00 1.48

「数据范围」
对于 30% 的数据，满足： n, m <= 5
对于 100% 的数据，满足： n, m <= 50


资源约定：
峰值内存消耗（含虚拟机） < 512M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。
*/

import java.util.*;

/**
 * 解法：DFS + 记忆化求值
 *
 * 每个格子可能是纯数字或公式（SUM / AVG / STD）。
 * 公式不会嵌套（语法层面），但可以引用其他公式格子的值。
 * 无循环依赖保证 DFS 必定终止。
 *
 * 解析公式时提取类型和矩形范围（1-based 坐标转 0-based），
 * 递归求值并用 Double 数组缓存结果，避免重复计算。
 * 标准差 = sqrt(方差)，方差 = 每个值与均值差的平方的平均值。
 */
public class _5 {
    public static void main(String[] args) {
        Main.solve();
    }
}

class Main {

    static int n, m;
    static String[][] raw; // 原始输入字符串
    static Double[][] cache; // 记忆化缓存
    static boolean[][] computing; // 计算中标记（检测循环依赖，本题保证不存在）

    // 公式类型
    static final int TYPE_NUM = 0;
    static final int TYPE_SUM = 1;
    static final int TYPE_AVG = 2;
    static final int TYPE_STD = 3;

    // 解析后的公式信息
    static int[][] type; // 格子类型
    static int[][] x1, y1, x2, y2; // 公式矩形范围（1-based 转为 0-based 存储）
    static double[][] numVal; // 纯数字格子的值

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();

        raw = new String[n][m];
        cache = new Double[n][m];
        computing = new boolean[n][m];
        type = new int[n][m];
        x1 = new int[n][m];
        y1 = new int[n][m];
        x2 = new int[n][m];
        y2 = new int[n][m];
        numVal = new double[n][m];

        for (int i = 0; i < n; i++) {
            String line = sc.nextLine().trim();
            String[] parts = line.split(" ");
            for (int j = 0; j < m; j++) {
                raw[i][j] = parts[j];
                parse(i, j, parts[j]);
            }
        }
        sc.close();

        // 计算每个格子的值
        double[][] result = new double[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = eval(i, j);
            }
        }

        // 输出，保留两位小数
        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < m; j++) {
                if (j > 0)
                    sb.append(' ');
                sb.append(String.format("%.2f", result[i][j]));
            }
            System.out.println(sb.toString());
        }
    }

    // 解析单个格子的内容
    static void parse(int r, int c, String s) {
        if (s.charAt(0) >= '0' && s.charAt(0) <= '9' || s.charAt(0) == '-') {
            // 纯数字（题目说正整数，但保留负号兼容性）
            type[r][c] = TYPE_NUM;
            numVal[r][c] = Double.parseDouble(s);
        } else {
            // 公式：SUM(x1,y1:x2,y2) / AVG(...) / STD(...)
            int colon = s.indexOf(':');
            int leftParen = s.indexOf('(');
            int comma = s.indexOf(',');

            // 提取类型
            String funcName = s.substring(0, leftParen);
            if (funcName.equals("SUM")) {
                type[r][c] = TYPE_SUM;
            } else if (funcName.equals("AVG")) {
                type[r][c] = TYPE_AVG;
            } else { // STD
                type[r][c] = TYPE_STD;
            }

            // 解析 x1,y1
            int x1Val = Integer.parseInt(s.substring(leftParen + 1, comma));
            int y1Val = Integer.parseInt(s.substring(comma + 1, colon));

            // 解析 x2,y2
            int comma2 = s.indexOf(',', colon);
            int rightParen = s.indexOf(')');
            int x2Val = Integer.parseInt(s.substring(colon + 1, comma2));
            int y2Val = Integer.parseInt(s.substring(comma2 + 1, rightParen));

            // 转为 0-based
            x1[r][c] = x1Val - 1;
            y1[r][c] = y1Val - 1;
            x2[r][c] = x2Val - 1;
            y2[r][c] = y2Val - 1;
        }
    }

    // DFS 记忆化求值
    static double eval(int r, int c) {
        if (cache[r][c] != null) {
            return cache[r][c];
        }
        if (computing[r][c]) {
            // 循环依赖，题目保证不会出现，此处防御性编程
            throw new RuntimeException("Circular dependency detected");
        }
        computing[r][c] = true;

        double result;
        if (type[r][c] == TYPE_NUM) {
            result = numVal[r][c];
        } else {
            result = evalFormula(r, c);
        }

        computing[r][c] = false;
        cache[r][c] = result;
        return result;
    }

    // 计算公式格子的值
    static double evalFormula(int r, int c) {
        int r1 = x1[r][c], c1 = y1[r][c];
        int r2 = x2[r][c], c2 = y2[r][c];

        // 收集矩形内所有格子的值
        int count = (r2 - r1 + 1) * (c2 - c1 + 1);
        double[] vals = new double[count];
        int idx = 0;
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                vals[idx++] = eval(i, j);
            }
        }

        switch (type[r][c]) {
            case TYPE_SUM: {
                double sum = 0;
                for (double v : vals)
                    sum += v;
                return sum;
            }
            case TYPE_AVG: {
                double sum = 0;
                for (double v : vals)
                    sum += v;
                return sum / count;
            }
            case TYPE_STD: {
                double sum = 0;
                for (double v : vals)
                    sum += v;
                double mean = sum / count;
                double sqSum = 0;
                for (double v : vals) {
                    double diff = v - mean;
                    sqSum += diff * diff;
                }
                double variance = sqSum / count;
                return Math.sqrt(variance);
            }
            default:
                return 0;
        }
    }
}
