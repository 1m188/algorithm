/*
煤球数目

有一堆煤球，堆成三角棱锥形。具体：
第一层放1个，
第二层3个（排列成三角形），
第三层6个（排列成三角形），
第四层10个（排列成三角形），
....
如果一共有100层，共有多少个煤球？

请填表示煤球总数目的数字。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

public class _1 {
    public static void main(String[] args) {
        int num = 0;
        for (int i = 1; i <= 100; i++) {
            num += sum(i);
        }
        System.out.println(num);
    }

    private static int sum(int x) {
        int result = 0;
        for (int i = 1; i <= x; i++) {
            result += i;
        }
        return result;
    }
}