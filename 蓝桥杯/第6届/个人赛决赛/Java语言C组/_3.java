/*
空心菱形

小明刚刚开发了一个小程序，可以打印出任意规模的空心菱形，规模为6时，如下图：
****** ******
*****   *****
****     ****
***       ***
**         **
*           *
**         **
***       ***
****     ****
*****   *****
****** ******

他一高兴，踢掉了电源，最后一次修改没有保存.....
毛病出在划线的部分。
请你帮助小明分析程序，填写划线部分缺失的代码。
*/
public class _3 {
    static String pr(int m, int n) {
        String s = "";
        for (int i = 0; i < n; i++)
            s += " ";
        for (int i = 0; i < m; i++)
            s = "*" + s + "*";
        return s;
    }

    static void f(int n) {
        String s = pr(1, n * 2 - 1) + "\n";
        String s2 = s;

        for (int i = 1; i < n; i++) {
            // 第 i 层（从中心向外）：每侧 i+1 颗星，中间 2*(n-i)-1 个空格
            s = pr(i + 1, n * 2 - 1 - 2 * i) + "\n"; // 填空位置
            s2 = s + s2 + s;
        }

        System.out.print(s2);
    }

    public static void main(String[] args) {
        f(6);
    }
}
