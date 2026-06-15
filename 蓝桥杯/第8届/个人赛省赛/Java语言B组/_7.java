/*
标题：日期问题

小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。  

比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。  

给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？

输入
一个日期，格式是"AA/BB/CC"。  (0 <= A, B, C <= 9)  

输出
输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。  

样例输入
02/03/04  

样例输出
2002-03-04  
2004-02-03  
2004-03-02  

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms
所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。


解题思路：
对三种解释分别尝试：
  1. 年-月-日 (AA-BB-CC)
  2. 月-日-年 (CC-AA-BB)
  3. 日-月-年 (CC-BB-AA)
判断日期合法性（1960~2059），去重后按日期排序输出。
*/
import java.util.*;

public class _7 {
    static int[] days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    static boolean isLeap(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    static boolean valid(int y, int m, int d) {
        if (m < 1 || m > 12) return false;
        int maxD = days[m];
        if (m == 2 && isLeap(y)) maxD = 29;
        return d >= 1 && d <= maxD;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] parts = sc.next().split("/");
        sc.close();
        int a = Integer.parseInt(parts[0]);
        int b = Integer.parseInt(parts[1]);
        int c = Integer.parseInt(parts[2]);

        Set<String> set = new TreeSet<>();
        // 年-月-日
        int y1 = (a >= 60 ? 1900 + a : 2000 + a);
        if (valid(y1, b, c))
            set.add(String.format("%d-%02d-%02d", y1, b, c));
        // 月-日-年
        int y2 = (c >= 60 ? 1900 + c : 2000 + c);
        if (valid(y2, a, b))
            set.add(String.format("%d-%02d-%02d", y2, a, b));
        // 日-月-年
        if (valid(y2, b, a))
            set.add(String.format("%d-%02d-%02d", y2, b, a));

        for (String s : set)
            System.out.println(s);
    }
}
