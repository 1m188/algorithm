/*
描述：正则问题

考虑一种简单的正则表达式：
只由 x ( ) | 组成的正则表达式。
小明想求出这个正则表达式能接受的最长字符串的长度。  

例如 ((xx|xxx)x|(x|xx))xx 能接受的最长字符串是： xxxxxx，长度是6。

输入
一个由x()|组成的正则表达式。输入长度不超过100，保证合法。  

输出
这个正则表达式能接受的最长字符串的长度。  

例如，
输入：
((xx|xxx)x|(x|xx))xx  

程序应该输出：
6  

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。


解题思路：
递归下降解析：
- expr(): 返回当前表达式的最大匹配长度
  - 遇到 | 表示或，取左右两侧最大值
  - 遇到 x 计数 +1
  - 遇到 ( 递归解析，遇到 ) 返回
- 用全局索引 pos 遍历输入串
*/
import java.util.Scanner;

public class _7 {
    static char[] s;
    static int pos;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.nextLine().toCharArray();
        sc.close();
        pos = 0;
        System.out.println(expr());
    }

    // expr := seq ('|' seq)*  返回最大值
    static int expr() {
        int res = seq();
        while (pos < s.length && s[pos] == '|') {
            pos++; // 跳过 '|'
            res = Math.max(res, seq());
        }
        return res;
    }

    // seq := term+  返回连续 term 的长度之和
    static int seq() {
        int sum = 0;
        while (pos < s.length && s[pos] != ')' && s[pos] != '|') {
            sum += term();
        }
        return sum;
    }

    // term := 'x' | '(' expr ')'
    static int term() {
        if (s[pos] == 'x') {
            pos++;
            return 1;
        } else { // '('
            pos++; // 跳过 '('
            int v = expr();
            pos++; // 跳过 ')'
            return v;
        }
    }
}
