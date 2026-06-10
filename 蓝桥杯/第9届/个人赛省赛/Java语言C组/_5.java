/*

标题：书号验证

2004年起，国际ISBN中心出版了《13位国际标准书号指南》。
原有10位书号前加978作为商品分类标识；校验规则也改变。
校验位的加权算法与10位ISBN的算法不同，具体算法是：
用1分别乘ISBN的前12位中的奇数位（从左边开始数起），用3乘以偶数位，乘积之和以10为模，10与模值的差值再对10取模（即取个位的数字）即可得到校验位的值，其值范围应该为0~9。

下面的程序实现了该算法，请仔细阅读源码，填写缺失的部分。

public class A
{
	static boolean f(String s){
		int k=1;
		int sum = 0;
		for(int i=0; i<s.length(); i++){
			char c = s.charAt(i);
			if(c=='-' || c==' ') continue;
			sum += ______________________________;  //填空
			k++;
			if(k>12) break; 
		}
		
		return s.charAt(s.length()-1)-'0' == (10-sum % 10)%10;
	}
	
	public static void main(String[] args){
		System.out.println(f("978-7-301-04815-3"));
		System.out.println(f("978-7-115-38821-6"));
	}
}


注意：只提交空缺的代码，不要抄写已经存在的代码。


*/

public class _5 {

    /**
     * 书号验证（ISBN-13 校验算法）
     *
     * 校验规则：
     * 对 ISBN-13 前 12 位数字，从左边起：
     * - 奇数位（第 1、3、5、... 位）加权值为 1
     * - 偶数位（第 2、4、6、... 位）加权值为 3
     * 将各数字乘对应权值后求和，记和为 S。
     * 校验位 = (10 - S % 10) % 10，取值范围 0~9。
     *
     * 填空处说明：
     * 变量 k 从 1 开始，每处理一个有效数字（非 '-' 非空格）后自增，
     * 表示当前数字在 13 位 ISBN 中的序号（1-based）。
     * 当 k 为奇数时权值为 1，偶数时权值为 3。
     *
     * @param s ISBN-13 字符串（含分隔符 '-' 和空格）
     * @return true 表示校验通过，false 表示校验失败
     */
    static boolean f(String s) {
        int k = 1; // 数字序号（从 1 开始）
        int sum = 0; // 加权和
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            /* 跳过分隔符 '-' 和空格 */
            if (c == '-' || c == ' ')
                continue;

            /*
             * 填空：
             * (c - '0') 将字符转为数字值；
             * (k % 2 == 1 ? 1 : 3) 根据序号奇偶性选择权值。
             * 等价于：奇数位 ×1，偶数位 ×3。
             */
            sum += (c - '0') * (k % 2 == 1 ? 1 : 3);
            k++;
            /* 仅处理前 12 位数字 */
            if (k > 12)
                break;
        }

        /*
         * 计算理论校验位并与实际最后一位比较：
         * 理论值 = (10 - sum % 10) % 10
         * 实际值 = 字符串最后一位字符对应的数字
         */
        return s.charAt(s.length() - 1) - '0' == (10 - sum % 10) % 10;
    }

    /**
     * 测试主方法：
     * 使用题目给出的两个 ISBN-13 示例进行验证。
     */
    public static void main(String[] args) {
        System.out.println(f("978-7-301-04815-3")); // 期望 true
        System.out.println(f("978-7-115-38821-6")); // 期望 true
    }
}
