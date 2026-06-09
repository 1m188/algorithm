/*
 
标题：分数

1/1 + 1/2 + 1/4 + 1/8 + 1/16 + .... 
每项是前一项的一半，如果一共有20项,
求这个和是多少，结果用分数表示出来。
类似：
3/2
当然，这只是加了前2项而已。分子分母要求互质。

注意：
需要提交的是已经约分过的分数，中间任何位置不能含有空格。
请不要填写任何多余的文字或符号。

*/

public class _1 {
    public static void main(String[] args) {
        // 分子：2^20 - 1
        long numerator = (1L << 20) - 1;
        // 分母：2^19
        long denominator = 1L << 19;
        long g = gcd(numerator, denominator);
        System.out.println((numerator / g) + "/" + (denominator / g));
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
