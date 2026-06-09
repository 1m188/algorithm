/*

标题：方格计数

如图p1.png所示，在二维平面上有无数个1x1的小方格。


我们以某个小方格的一个顶点为圆心画一个半径为 50000 的圆。
你能计算出这个圆里有多少个完整的小方格吗？ 

注意：需要提交的是一个整数，不要填写任何多余内容。

*/

public class _4 {
    public static void main(String[] args) {
        long r = 50000;
        long count = 0;
        for (long x = 1; x <= r; x++) {
            long y = (long) Math.floor(Math.sqrt(r * r - x * x));
            count += y;
        }
        count *= 4;
        System.out.println(count);
    }
}
