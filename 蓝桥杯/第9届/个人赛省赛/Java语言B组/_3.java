/*

标题：复数幂

设i为虚数单位。对于任意正整数n，(2+3i)^n 的实部和虚部都是整数。
求 (2+3i)^123456 等于多少？ 即(2+3i)的123456次幂，这个数字很大，要求精确表示。



答案写成 "实部±虚部i" 的形式，实部和虚部都是整数（不能用科学计数法表示），中间任何地方都不加空格，实部为正时前面不加正号。(2+3i)^2 写成: -5+12i，
(2+3i)^5 的写成: 122-597i


注意：需要提交的是一个很庞大的复数，不要填写任何多余内容。


*/

public class _3 {

    /**
     * 计算 (2+3i)^n 的精确值，返回实部和虚部组成的数组。
     *
     * 使用复数快速幂（二分幂）算法，将 O(n) 次乘法优化到 O(log n) 次。
     *
     * 复数乘法公式：
     * (r₁ + m₁i) × (r₂ + m₂i) = (r₁·r₂ - m₁·m₂) + (r₁·m₂ + m₁·r₂)i
     *
     * @param n 指数（正整数）
     * @return 长度为2的数组，[0]为实部，[1]为虚部
     */
    static java.math.BigInteger[] complexPow(long n) {
        /*
         * 快速幂初始化：
         * result 表示当前累乘结果，初始为 1+0i（乘法单位元）
         * base 表示当前底数，初始为 2+3i
         */
        java.math.BigInteger rResult = java.math.BigInteger.ONE;
        java.math.BigInteger mResult = java.math.BigInteger.ZERO;
        java.math.BigInteger rBase = java.math.BigInteger.valueOf(2);
        java.math.BigInteger mBase = java.math.BigInteger.valueOf(3);

        long exp = n;
        while (exp > 0) {
            /*
             * 如果当前指数为奇数，将 base 乘入 result。
             * 即 result = result × base。
             */
            if ((exp & 1) == 1) {
                java.math.BigInteger newR = rResult.multiply(rBase).subtract(mResult.multiply(mBase));
                java.math.BigInteger newM = rResult.multiply(mBase).add(mResult.multiply(rBase));
                rResult = newR;
                mResult = newM;
            }

            /*
             * 底数平方：base = base × base，为下一轮做准备。
             *
             * 复数平方公式：
             * (a+bi)² = (a² - b²) + (2ab)i
             */
            java.math.BigInteger newR = rBase.multiply(rBase).subtract(mBase.multiply(mBase));
            java.math.BigInteger newM = rBase.multiply(mBase).multiply(java.math.BigInteger.valueOf(2));
            rBase = newR;
            mBase = newM;

            exp >>= 1;
        }

        return new java.math.BigInteger[] { rResult, mResult };
    }

    /**
     * 按照题目要求的格式输出复数。
     * - 实部为正时不加正号；为负时带负号
     * - 虚部为正时输出 "+虚部i"；为负时输出 "-虚部绝对值i"
     * - 虚部为0时只输出实部
     * - 实部为0时只输出虚部（如 "123i" 或 "-123i"）
     *
     * @param r 实部
     * @param m 虚部
     */
    static void printComplex(java.math.BigInteger r, java.math.BigInteger m) {
        java.math.BigInteger zero = java.math.BigInteger.ZERO;

        if (m.equals(zero)) {
            /* 纯实数 */
            System.out.println(r);
        } else if (r.equals(zero)) {
            /* 纯虚数 */
            if (m.compareTo(zero) > 0) {
                System.out.println(m + "i");
            } else {
                System.out.println(m + "i");
            }
        } else {
            /* 一般复数：实部 + 虚部符号 + 虚部绝对值 + "i" */
            StringBuilder sb = new StringBuilder();
            sb.append(r);
            if (m.compareTo(zero) > 0) {
                sb.append("+").append(m).append("i");
            } else {
                sb.append(m).append("i");
            }
            System.out.println(sb.toString());
        }
    }

    public static void main(String[] args) {
        /*
         * 计算 (2+3i)^123456。
         * 指数很大（123456），结果是一个位数极多的精确整数复数，
         * 必须使用 BigInteger 存储实部和虚部。
         */
        java.math.BigInteger[] result = complexPow(123456);
        printComplex(result[0], result[1]);
    }
}
