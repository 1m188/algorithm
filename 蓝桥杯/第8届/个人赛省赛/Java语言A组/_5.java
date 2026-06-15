/*
标题：字母组串

由 A,B,C 这3个字母就可以组成许多串。
比如："A","AB","ABC","ABA","AACBB" ....

现在，小明正在思考一个问题：
如果每个字母的个数有限定，能组成多少个已知长度的串呢？

他请好朋友来帮忙，很快得到了代码，
解决方案超级简单，然而最重要的部分却语焉不详。

请仔细分析源码，填写划线部分缺少的内容。


public class A
{
    // a个A，b个B，c个C 字母，能组成多少个不同的长度为n的串。
    static int f(int a, int b, int c, int n)
    {
        if(a<0 || b<0 || c<0) return 0;
        if(n==0) return 1; 

        return ________________________________;  //填空
    }

    public static void main(String[] args)
    {
        System.out.println(f(1,1,1,2));
        System.out.println(f(1,2,3,3));
    }
}

对于上面的测试数据，小明口算的结果应该是：
6
19


注意：只填写划线部分缺少的代码，不要提交任何多余内容或说明性文字。


解题思路：
递归枚举长度为 n 的串的每一位：
第一位可以是 A、B 或 C（只要还有剩余），
剩下的 n-1 位从剩余的字母中选取。
填空：f(a-1,b,c,n-1) + f(a,b-1,c,n-1) + f(a,b,c-1,n-1)

验证：f(1,1,1,2) = f(0,1,1,1)+f(1,0,1,1)+f(1,1,0,1) = 2+2+2 = 6 ✓
*/
public class _5 {
    // a个A，b个B，c个C 字母，能组成多少个不同的长度为n的串。
    static int f(int a, int b, int c, int n) {
        if (a < 0 || b < 0 || c < 0)
            return 0;
        if (n == 0)
            return 1;

        return f(a - 1, b, c, n - 1) + f(a, b - 1, c, n - 1)
                + f(a, b, c - 1, n - 1); // 填空
    }

    public static void main(String[] args) {
        System.out.println(f(1, 1, 1, 2));
        System.out.println(f(1, 2, 3, 3));
    }
}
