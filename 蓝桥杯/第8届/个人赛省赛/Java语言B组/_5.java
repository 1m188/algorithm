/*
标题：取数位

求1个整数的第k位数字有很多种方法。
以下的方法就是一种。

public class Main
{
    static int len(int x){
        if(x<10) return 1;
        return len(x/10)+1;
    }

    // 取x的第k位数字
    static int f(int x, int k){
        if(len(x)-k==0) return x%10;
        return ______________________;  //填空
    }

    public static void main(String[] args)
    {
        int x = 23513;
        System.out.println(f(x,3));  // 应输出 5
    }
}

注意：只提交缺失的代码，不要填写任何已有内容或说明性的文字。


解题思路：
递归去掉末位，直到剩余长度等于 k。
填空：f(x/10, k)
验证：f(23513,3) → len=5, 5-3=2≠0 → f(2351,3) → len=4, 4-3=1≠0 → f(235,3) → len=3, 3-3=0 → 5 ✓
*/
public class _5 {
    static int len(int x) {
        if (x < 10)
            return 1;
        return len(x / 10) + 1;
    }

    static int f(int x, int k) {
        if (len(x) - k == 0)
            return x % 10;
        return f(x / 10, k); // 填空
    }

    public static void main(String[] args) {
        int x = 23513;
        System.out.println(f(x, 3));
    }
}
