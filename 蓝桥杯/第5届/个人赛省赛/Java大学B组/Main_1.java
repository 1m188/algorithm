/*

java中提供了对正则表达式的支持。
有的时候，恰当地使用正则，可以让我们的工作事半功倍！

如下代码用来检验一个四则运算式中数据项的数目，请填写划线部分缺少的代码。

注意：只填写缺少代码，不要写任何多余内容，例如，已有的双引号。


public class A
{
	public static int f(String s)
	{
		return s.split("________________").length;
	}
	
	public static void main(String[] args)
	{
		System.out.println(f("12+35*5-2*18/9-3")); //7
		System.out.println(f("354*12+3-14/7*6")); //6
	}
}

*/

public class Main_1 {
	public static int f(String s) {
		return s.split("[-+*/]").length;
	}

	/**
	 * 主方法，用于测试f函数的计算结果
	 * 
	 * @param args 命令行参数，本程序中未使用
	 */
	/**
	 * // 测试f函数的第一个表达式，输出结果应为7
	 * 主方法，用于测试自定义的f方法
	 * // 测试f函数的第二个表达式，输出结果应为6
	 * 
	 * @param args 命令行参数，本程序中未使用
	 */
	public static void main(String[] args) {
		// 测试f方法，传入第一个表达式"12+35*5-2*18/9-3"，预期输出结果为7
		System.out.println(f("12+35*5-2*18/9-3")); // 7
		// 测试f方法，传入第二个表达式"354*12+3-14/7*6"，预期输出结果为6
		System.out.println(f("354*12+3-14/7*6")); // 6
	}
}
