/*

标题：最大乘积

把 1~9 这9个数字分成两组，中间插入乘号，
有的时候，它们的乘积也只包含1~9这9个数字，而且每个数字只出现1次。

比如：
984672 * 351 = 345619872
98751 * 3462 = 341875962
9 * 87146325 = 784316925
...

符合这种规律的算式还有很多，请你计算在所有这些算式中，乘积最大是多少？

注意，需要提交的是一个整数，表示那个最大的积，不要填写任何多余的内容。
（只提交乘积，不要提交整个算式）

*/

public class _2 {
    static long maxProduct = 0;

    public static void main(String[] args) {
        int[] digits = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        permute(digits, 0);
        System.out.println(maxProduct);
    }

    static void permute(int[] arr, int start) {
        if (start == arr.length) {
            check(arr);
            return;
        }
        for (int i = start; i < arr.length; i++) {
            swap(arr, start, i);
            permute(arr, start + 1);
            swap(arr, start, i);
        }
    }

    static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    static void check(int[] arr) {
        for (int split = 1; split <= 8; split++) {
            long a = 0;
            for (int i = 0; i < split; i++) {
                a = a * 10 + arr[i];
            }
            long b = 0;
            for (int i = split; i < 9; i++) {
                b = b * 10 + arr[i];
            }
            long product = a * b;
            if (product > maxProduct && isPandigital(product)) {
                maxProduct = product;
            }
        }
    }

    static boolean isPandigital(long n) {
        if (n < 100000000 || n > 999999999)
            return false;
        int mask = 0;
        while (n > 0) {
            int d = (int) (n % 10);
            if (d == 0)
                return false;
            if ((mask & (1 << d)) != 0)
                return false;
            mask |= (1 << d);
            n /= 10;
        }
        return mask == 1022; // 二进制的 1111111110，即 bit 1~9 全部置位
    }
}
