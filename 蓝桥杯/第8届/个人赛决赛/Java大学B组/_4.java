/*

标题：小计算器

模拟程序型计算器，依次输入指令，可能包含的指令有

1. 数字：'NUM X'，X为一个只包含大写字母和数字的字符串，表示一个当前进制的数
2. 运算指令：'ADD','SUB','MUL','DIV','MOD'，分别表示加减乘，除法取商，除法取余
3. 进制转换指令：'CHANGE K'，将当前进制转换为K进制(2≤K≤36)
4. 输出指令：'EQUAL'，以当前进制输出结果
5. 重置指令：'CLEAR'，清除当前数字

指令按照以下规则给出：
数字，运算指令不会连续给出，进制转换指令，输出指令，重置指令有可能连续给出
运算指令后出现的第一个数字，表示参与运算的数字。且在该运算指令和该数字中间不会出现运算指令和输出指令
重置指令后出现的第一个数字，表示基础值。且在重置指令和第一个数字中间不会出现运算指令和输出指令
进制转换指令可能出现在任何地方

运算过程中中间变量均为非负整数，且小于2^63。
以大写的'A'~'Z'表示10~35

[输入格式]
第1行：1个n，表示指令数量
第2..n+1行：每行给出一条指令。指令序列一定以'CLEAR'作为开始，并且满足指令规则

[输出格式]
依次给出每一次'EQUAL'得到的结果

[样例输入]
7
CLEAR
NUM 1024
CHANGE 2
ADD
NUM 100000
CHANGE 8
EQUAL

[样例输出]
2040

补充说明：
1. n 值范围: 1<= n < 50000
2. 初始默认的进制是十进制



资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。


*/

import java.io.*;

public class _4 {
    // 当前进制（2 ≤ base ≤ 36，初始为十进制）
    static int base = 10;
    // 当前计算结果（非负整数，< 2^63）
    static long value = 0;
    // 当前等待执行的运算（空操作表示无待执行运算）
    static String pendingOp = null;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String line = br.readLine().trim();
            if (line.startsWith("CLEAR")) {
                // 重置：清零，取消待执行运算
                value = 0;
                pendingOp = null;
            } else if (line.startsWith("NUM")) {
                // 解析当前进制下的数字字符串
                String numStr = line.substring(4);
                long num = parse(numStr);
                if (pendingOp == null) {
                    // 无待执行运算，设置基础值
                    value = num;
                } else {
                    // 执行待处理的运算
                    value = compute(value, pendingOp, num);
                    pendingOp = null;
                }
            } else if (line.startsWith("CHANGE")) {
                // 切换进制
                base = Integer.parseInt(line.substring(7));
            } else if (line.startsWith("EQUAL")) {
                // 以当前进制输出结果
                System.out.println(format(value));
            } else if (line.equals("ADD") || line.equals("SUB") ||
                    line.equals("MUL") || line.equals("DIV") ||
                    line.equals("MOD")) {
                // 记录待执行的运算
                pendingOp = line;
            }
        }
        br.close();
    }

    /** 将当前进制下的字符串 s 解析为 long 值 */
    static long parse(String s) {
        long result = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int digit;
            if (c >= '0' && c <= '9')
                digit = c - '0';
            else
                digit = c - 'A' + 10;
            result = result * base + digit;
        }
        return result;
    }

    /** 将 long 值格式化为当前进制下的字符串 */
    static String format(long val) {
        if (val == 0)
            return "0";
        StringBuilder sb = new StringBuilder();
        while (val > 0) {
            int digit = (int) (val % base);
            if (digit < 10)
                sb.append((char) ('0' + digit));
            else
                sb.append((char) ('A' + digit - 10));
            val /= base;
        }
        return sb.reverse().toString();
    }

    /** 执行二元运算 */
    static long compute(long a, String op, long b) {
        if (op.equals("ADD"))
            return a + b;
        if (op.equals("SUB"))
            return a - b;
        if (op.equals("MUL"))
            return a * b;
        if (op.equals("DIV"))
            return a / b;
        if (op.equals("MOD"))
            return a % b;
        return 0;
    }
}
