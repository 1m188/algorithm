/*
标题：杨辉三角

杨辉三角也叫帕斯卡三角，在很多数量关系中可以看到，十分重要。

第0行：           1
第1行：          1 1
第2行：         1 2 1
...

两边的元素都是1， 中间的元素是左上角的元素与右上角的元素和。

我们约定，行号，列号都从0计数。
所以： 第6行的第2个元素是15，第3个元素是20

public class A
{
    // 杨辉三角形的第row行第col列
    static long f(int row, int col){
        if(row<2) return 1;
        if(col==0) return 1;
        if(col==row) return 1;

        long[] a = new long[row+1];
        a[0]=1;
        a[1]=1;

        int p = 2;

        while(p<=row){
            a[p] = 1;
            for( __________________ ) a[q] = a[q] + a[q-1];
            p++;
        }

        return a[col];
    }

    public static void main(String[] args){
        System.out.println(f(6,2));
        System.out.println(f(6,3));
    }
}


解题思路：
一维滚动数组模拟杨辉三角，从后往前更新避免覆盖。
填空：q = p - 1; q >= 1; q--
*/
public class _5 {
    static long f(int row, int col) {
        if (row < 2) return 1;
        if (col == 0) return 1;
        if (col == row) return 1;

        long[] a = new long[row + 1];
        a[0] = 1;
        a[1] = 1;
        int p = 2;

        while (p <= row) {
            a[p] = 1;
            for (int q = p - 1; q >= 1; q--) // 填空
                a[q] = a[q] + a[q - 1];
            p++;
        }
        return a[col];
    }

    public static void main(String[] args) {
        System.out.println(f(6, 2));
        System.out.println(f(6, 3));
    }
}
