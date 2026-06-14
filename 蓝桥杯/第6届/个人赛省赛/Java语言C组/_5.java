/*
格子中输出

stringInGrid方法会在一个指定大小的格子中打印指定的字符串。
要求字符串在水平、垂直两个方向上都居中。
如果字符串太长，就截断。
如果不能恰好居中，可以稍稍偏左或者偏上一点。

下面的程序实现这个逻辑，请填写划线部分缺少的代码。

	public static void stringInGrid(int width, int height, String s)
	{
		if(s.length()>width-2) s = s.substring(0,width-2);
		System.out.print("+");
		for(int i=0;i<width-2;i++) System.out.print("-");
		System.out.println("+");
		
		for(int k=1; k<(height-1)/2;k++){
			System.out.print("|");
			for(int i=0;i<width-2;i++) System.out.print(" ");
			System.out.println("|");
		}
		
		System.out.print("|");
		
		String ff = _______________________________________________________;  //填空
		System.out.print(String.format(ff,"",s,""));
		          
		System.out.println("|");
		
		for(int k=(height-1)/2+1; k<height-1; k++){
			System.out.print("|");
			for(int i=0;i<width-2;i++) System.out.print(" ");
			System.out.println("|");
		}	
		
		System.out.print("+");
		for(int i=0;i<width-2;i++) System.out.print("-");
		System.out.println("+");	
	}

对于题目中数据，应该输出：
+------------------+
|                  |
|     abcd1234     |
|                  |
|                  |
+------------------+

（如果出现对齐问题，参看【图1.jpg】）
*/

/*
 * 填空解析：
 * String.format(ff, "", s, "") 用三个参数填充格式字符串 ff：
 * 格式为 "%*s%s%*s"，三个参数：
 *   1. 左侧空格宽度 = (width-2 - s.length()) / 2 → ""（空串填充）
 *   2. 字符串 s 本身
 *   3. 右侧空格宽度 = (width-2 - s.length() + 1) / 2 → ""（空串填充）
 * %*s 的第一个参数表示宽度，用空字符串填充即可。
 *
 * 即：ff = "%" + left + "s%s%" + right + "s"
 * 或直接写：ff = "%" + ((width-s.length()-2)/2) + "s%s%" + ((width-s.length()-1)/2) + "s"
 */
public class _5 {

    public static void stringInGrid(int width, int height, String s) {
        if (s.length() > width - 2)
            s = s.substring(0, width - 2);
        System.out.print("+");
        for (int i = 0; i < width - 2; i++)
            System.out.print("-");
        System.out.println("+");

        for (int k = 1; k < (height - 1) / 2; k++) {
            System.out.print("|");
            for (int i = 0; i < width - 2; i++)
                System.out.print(" ");
            System.out.println("|");
        }

        System.out.print("|");

        // 填空：构造格式字符串
        int left = (width - 2 - s.length()) / 2;
        int right = (width - 2 - s.length() + 1) / 2;
        String ff = "%" + left + "s%s%" + right + "s"; // 填空

        System.out.print(String.format(ff, "", s, ""));

        System.out.println("|");

        for (int k = (height - 1) / 2 + 1; k < height - 1; k++) {
            System.out.print("|");
            for (int i = 0; i < width - 2; i++)
                System.out.print(" ");
            System.out.println("|");
        }

        System.out.print("+");
        for (int i = 0; i < width - 2; i++)
            System.out.print("-");
        System.out.println("+");
    }

    public static void main(String[] args) {
        stringInGrid(20, 6, "abcd1234");
    }
}
