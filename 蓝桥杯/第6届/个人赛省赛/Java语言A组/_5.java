/*
打印菱形

给出菱形的边长，在控制台上打印出一个菱形来。
为了便于比对空格，我们把空格用句点代替。
当边长为8时，菱形为：
.......*
......*.*
.....*...*
....*.....*
...*.......*
..*.........*
.*...........*
*.....*
.*...........*
..*.........*
...*.......*
....*.....*
.....*...*
......*.*
.......*

下面的程序实现了这个功能，但想法有点奇怪。
请仔细分析代码，并填写划线部分缺失的代码。

public class A
{
	public static void f(int n)
	{
		String s = "*";
		for(int i=0; i<2*n-3; i++) s += ".";
		s += "*";

		String s1 = s + "\n";
		String s2 = "";

		for(int i=0; i<n-1; i++){
			//System.out.println("=>"+s);
			s = "." + _____________________________________ + "*";  //填空
			s1 = s + "\n" + s1;
			s2 += s + "\n";
		}
		System.out.println(s1+s2);
	}

	public static void main(String[] args)
	{
		f(8);
	}
}

注意，只能填写缺少的部分，不要重复抄写已有代码。不要填写任何多余的文字。
*/

/*
 * 填空解析：
 * 初始 s 为菱形中间行："*.............*"（长度 2n-1）。
 * 每次迭代：新 s = "." + (旧 s 去掉末尾 2 个字符) + "*"
 * 即取 s 从头到倒数第 3 个字符的子串（去掉末尾的 ".*" 两字符）。
 * 这样 s 每次缩短 1 个字符，先产生近中间行的内容，逐步扩展到两端。
 * s.substring(0, s.length()-3) 恰好去掉末尾 3 个字符（2 个用于补偿
 * 新加的 "." 和 "*"，1 个用于缩短长度）。
 */
public class _5 {
    public static void f(int n) {
        String s = "*";
        for (int i = 0; i < 2 * n - 3; i++)
            s += ".";
        s += "*";

        String s1 = s + "\n";
        String s2 = "";

        for (int i = 0; i < n - 1; i++) {
            // System.out.println("=>"+s);
            s = "." + s.substring(0, s.length() - 3) + "*"; // 填空
            s1 = s + "\n" + s1;
            s2 += s + "\n";
        }
        System.out.println(s1 + s2);
    }

    public static void main(String[] args) {
        f(8);
    }
}
