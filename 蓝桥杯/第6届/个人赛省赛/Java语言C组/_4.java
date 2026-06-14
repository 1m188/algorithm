/*
循环节长度

两个整数做除法，有时会产生循环小数，其循环部分称为：循环节。
比如，11/13=6=>0.846153846153.....  其循环节为[846153] 共有6位。
下面的方法，可以求出循环节的长度。

请仔细阅读代码，并填写划线部分缺少的代码。

	public static int f(int n, int m)
	{
		n = n % m;	
		Vector v = new Vector();
		
		for(;;)
		{
			v.add(n);
			n *= 10;
			n = n % m;
			if(n==0) return 0;
			if(v.indexOf(n)>=0)  _________________________________ ;  //填空
		}
	}

注意，只能填写缺少的部分，不要重复抄写已有代码。不要填写任何多余的文字。
*/

/*
 * 填空解析：
 * 模拟长除法：将每次余数存入 Vector。
 * 当某个余数再次出现时，进入循环节。
 * 循环节长度 = 当前大小 - 该余数首次出现位置。
 * 即：return v.size() - v.indexOf(n);
 */
import java.util.Vector;

public class _4 {
    public static int f(int n, int m) {
        n = n % m;
        Vector<Integer> v = new Vector<>();

        for (;;) {
            v.add(n);
            n *= 10;
            n = n % m;
            if (n == 0)
                return 0;
            if (v.indexOf(n) >= 0)
                return v.size() - v.indexOf(n); // 填空
        }
    }

    public static void main(String[] args) {
        System.out.println(f(11, 13)); // 输出 6
    }
}
