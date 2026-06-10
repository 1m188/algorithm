/*

标题：打印大X

如下的程序目的是在控制台打印输出大X。
可以控制两个参数：图形的高度，以及笔宽。

用程序中的测试数据输出效果：
(如果显示有问题，可以参看p1.png)

高度=15, 笔宽=3
***           ***
 ***         ***
  ***       ***
   ***     ***
    ***   ***
     *** ***
      *****
       ***
      *****
     *** ***
    ***   ***
   ***     ***
  ***       ***
 ***         ***
***           ***
高度=8, 笔宽=5
*****  *****
 **********
  ********
   ******
   ******
  ********
 **********
*****  *****

请仔细分析程序流程，填写缺失的代码。


public class A
{
	static void f(int h, int w){
		System.out.println(String.format("高度=%d, 笔宽=%d",h,w));
		int a1 = 0;
		int a2 = h - 1;
		
		for(int k=0; k<h; k++){
			int p = Math.min(a1,a2);
			int q = Math.max(a1+w,a2+w);
			
			for(int i=0; i<p; i++) System.out.print(" ");
			
			if(q-p<w*2){
				____________________________________________ ; //填空
			}
			else{
				for(int i=0; i<w; i++) System.out.print("*");
				for(int i=0; i<q-p-w*2; i++) System.out.print(" ");
				for(int i=0; i<w; i++) System.out.print("*");
			}
			System.out.println();
			a1++;
			a2--;
		}
	}
	
	public static void main(String[] args){
		f(15,3);
		f(8,5);
	}
}

注意：只填写缺失的代码，不要拷贝已经存在的代码。


*/

public class _6 {

    /**
     * 打印大X
     *
     * 程序在控制台打印由 '*' 组成的大 X 图形。
     * 参数 h 控制图形高度，w 控制笔宽。
     *
     * 核心思路：
     * 每一行，左对角线从左侧向右移动（a1 递增），
     * 右对角线从右侧向左移动（a2 递减）。
     * 当两根笔画不重叠时（q-p >= 2w），分别打印两个 w 宽的星号块，
     * 中间填充空格。
     * 当两根笔画重叠时（q-p < 2w），中间的间隙消失，
     * 整段连成一片星号区域，直接打印一长条星号。
     *
     * 填空处说明：
     * 重叠时两根笔画融合，需要从最左侧 p 到最右侧 q 全部打印星号，
     * 星号个数 = q - p。
     */

    static void f(int h, int w) {
        System.out.println(String.format("高度=%d, 笔宽=%d", h, w));
        int a1 = 0; // 左对角线（\）的起始列，逐行右移
        int a2 = h - 1; // 右对角线（/）的起始列，逐行左移

        for (int k = 0; k < h; k++) {
            /*
             * p：两根笔画在本行占据的最左列
             * q：两根笔画在本行占据的最右列（不含）
             * 左笔占据列 [a1, a1+w)，右笔占据列 [a2, a2+w)
             */
            int p = Math.min(a1, a2);
            int q = Math.max(a1 + w, a2 + w);

            /* 打印本行前导空格 */
            for (int i = 0; i < p; i++)
                System.out.print(" ");

            if (q - p < w * 2) {
                /*
                 * 重叠情况：两根笔画融为一体，
                 * 从 p 到 q 的整段全为星号。
                 */
                for (int i = 0; i < q - p; i++)
                    System.out.print("*"); // 填空
            } else {
                /* 不重叠：先印左笔，再印中间空格，最后印右笔 */
                for (int i = 0; i < w; i++)
                    System.out.print("*");
                for (int i = 0; i < q - p - w * 2; i++)
                    System.out.print(" ");
                for (int i = 0; i < w; i++)
                    System.out.print("*");
            }
            System.out.println();
            a1++; // 左笔向右移一列
            a2--; // 右笔向左移一列
        }
    }

    /**
     * 测试主方法：
     * 使用题目给出的两组数据验证输出。
     */
    public static void main(String[] args) {
        f(15, 3);
        System.out.println(); // 分隔两组输出
        f(8, 5);
    }
}
