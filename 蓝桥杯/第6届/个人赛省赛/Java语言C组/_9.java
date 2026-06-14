/*
打印大X

小明希望用星号拼凑，打印出一个大X，他要求能够控制笔画的宽度和整个字的高度。
为了便于比对空格，所有的空白位置都以句点符来代替。

要求输入两个整数m n，表示笔的宽度，X的高度。用空格分开(0<m<n, 3<n<1000, 保证n是奇数)
要求输出一个大X

例如，用户输入：
3 9
程序应该输出：
***.....***
.***...***.
..***.***..
...*****...
....***....
...*****...
..***.***..
.***...***.
***.....***

（如有对齐问题，参看【图1.jpg】）


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。
*/

/*
 * 解题思路：
 * X 的总宽度 = n + m - 1。
 * 逐行输出 (0 ≤ i < n)：
 *   左斜杠起始列 = i（主对角线方向，延伸 m 个 *）
 *   右斜杠起始列 = n-1-i（反对角线方向，延伸 m 个 *）
 *   两斜杠可能在中部重叠，重叠处只输出一次 *。
 */
import java.util.Scanner;

public class _9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        sc.close();

        int width = n + m - 1; // X 的总宽度
        for (int i = 0; i < n; i++) {
            int left = i;            // 左斜杠起始列
            int right = n - 1 - i;   // 右斜杠起始列
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < width; j++) {
                boolean inLeft = (j >= left && j < left + m);
                boolean inRight = (j >= right && j < right + m);
                if (inLeft || inRight)
                    sb.append('*');
                else
                    sb.append('.');
            }
            System.out.println(sb);
        }
    }
}
