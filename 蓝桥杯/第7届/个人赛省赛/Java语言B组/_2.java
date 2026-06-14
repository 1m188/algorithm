/*
生日蜡烛

某君从某年开始每年都举办一次生日party，并且每次都要吹熄与年龄相同根数的蜡烛。

现在算起来，他一共吹熄了236根蜡烛。

请问，他从多少岁开始过生日party的？

请填写他开始过生日party的年龄数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/
public class _2 {
    public static void main(String[] args) {
        // 枚举开始年龄 startAge 和连续年数 n
        // 使总和 (startAge + startAge+n-1) * n / 2 = 236
        for (int start = 1; start <= 100; start++) {
            int sum = 0;
            for (int n = 1; start + n - 1 <= 100; n++) {
                sum += start + n - 1;
                if (sum == 236) {
                    System.out.println(start);
                    return;
                }
                if (sum > 236)
                    break;
            }
        }
    }
}
