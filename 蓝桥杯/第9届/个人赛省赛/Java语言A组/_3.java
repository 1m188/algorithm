/*

标题：复数幂

设i为虚数单位。对于任意正整数n，(2+3i)^n 的实部和虚部都是整数。
求 (2+3i)^123456 等于多少？ 即(2+3i)的123456次幂，这个数字很大，要求精确表示。



答案写成 "实部±虚部i" 的形式，实部和虚部都是整数（不能用科学计数法表示），中间任何地方都不加空格，实部为正时前面不加正号。(2+3i)^2 写成: -5+12i，
(2+3i)^5 的写成: 122-597i


注意：需要提交的是一个很庞大的复数，不要填写任何多余内容。


*/

import java.math.BigInteger;

public class _3 {

    public static void main(String[] args) {
        BigInteger resReal = BigInteger.ONE;
        BigInteger resImag = BigInteger.ZERO;
        BigInteger baseReal = BigInteger.valueOf(2);
        BigInteger baseImag = BigInteger.valueOf(3);
        int n = 123456;

        while (n > 0) {
            if ((n & 1) == 1) {
                BigInteger newResReal = resReal.multiply(baseReal).subtract(resImag.multiply(baseImag));
                BigInteger newResImag = resReal.multiply(baseImag).add(resImag.multiply(baseReal));
                resReal = newResReal;
                resImag = newResImag;
            }
            BigInteger newBaseReal = baseReal.multiply(baseReal).subtract(baseImag.multiply(baseImag));
            BigInteger newBaseImag = baseReal.multiply(baseImag).add(baseImag.multiply(baseReal));
            baseReal = newBaseReal;
            baseImag = newBaseImag;
            n >>= 1;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(resReal.toString());
        if (resImag.compareTo(BigInteger.ZERO) >= 0) {
            sb.append("+");
        }
        sb.append(resImag.toString());
        sb.append("i");
        System.out.println(sb.toString());
    }
}
