/*
标题：兴趣小组

为丰富同学们的业余文化生活，某高校学生会创办了3个兴趣小组
（以下称A组，B组，C组）。
每个小组的学生名单分别在【A.txt】,【B.txt】和【C.txt】中。
每个文件中存储的是学生的学号。

由于工作需要，我们现在想知道：
    既参加了A组，又参加了B组，但是没有参加C组的同学一共有多少人？

请你统计该数字并通过浏览器提交答案。

注意：答案是一个整数，不要提交任何多余的内容。

--------------------

笨笨有话说：
    哇塞！数字好多啊！一眼望过去就能发现相同的，好像没什么指望。
不过，可以排序啊，要是每个文件都是有序的，那就好多了。

歪歪有话说：
    排什么序啊，这么几行数字对计算机不是太轻松了吗？
    我看着需求怎么和中学学过的集合很像啊.....


解题思路：
读取三个文件中的学号(逗号分隔)，存入Set。
计算 |A ∩ B| - |A ∩ B ∩ C| = 出现在A和B中但不在C中的学号数。
答案：20
*/
import java.io.*;
import java.util.*;

public class _2 {
    public static void main(String[] args) throws IOException {
        Set<String> A = readSet("2/A.txt");
        Set<String> B = readSet("2/B.txt");
        Set<String> C = readSet("2/C.txt");

        int cnt = 0;
        for (String id : A) {
            if (B.contains(id) && !C.contains(id))
                cnt++;
        }
        System.out.println(cnt);
    }

    static Set<String> readSet(String path) throws IOException {
        Set<String> set = new HashSet<>();
        BufferedReader br = new BufferedReader(new FileReader(path));
        String line;
        while ((line = br.readLine()) != null) {
            for (String id : line.split(",")) {
                id = id.trim();
                if (!id.isEmpty())
                    set.add(id);
            }
        }
        br.close();
        return set;
    }
}
