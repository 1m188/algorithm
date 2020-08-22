/*
搭积木

小明最近喜欢搭数字积木，
一共有10块积木，每个积木上有一个数字，0~9。

搭积木规则：
每个积木放到其它两个积木的上面，并且一定比下面的两个积木数字小。
最后搭成4层的金字塔形，必须用完所有的积木。

下面是两种合格的搭法：

   0
  1 2
 3 4 5
6 7 8 9

   0
  3 1
 7 5 2
9 8 6 4    

请你计算这样的搭法一共有多少种？

请填表示总数目的数字。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

public class _3 {

    private static int[] blocks = new int[10];
    private static boolean[] digits = new boolean[10];
    private static int num = 0;

    public static void main(String[] args) {
        dajimu(0);
        System.out.println(num);
    }

    private static void dajimu(int index) {
        if (index == 10) {
            num++;
        } else {
            for (int i = index; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (!digits[j]) {
                        blocks[i] = j;
                        digits[j] = true;
                        if (judge(i)) {
                            dajimu(index + 1);
                        }
                        blocks[i] = 0;
                        digits[j] = false;
                    }
                }
            }
        }
    }

    private static boolean judge(int index) {
        if (index < 4) {
            return true;
        } else if (index >= 4 && index < 7) {
            return blocks[index] < blocks[index - 4] && blocks[index] < blocks[index - 3];
        } else if (index >= 7 && index < 9) {
            return blocks[index] < blocks[index - 3] && blocks[index] < blocks[index - 2];
        } else {
            return blocks[index] < blocks[index - 2] && blocks[index] < blocks[index - 1];
        }
    }
}