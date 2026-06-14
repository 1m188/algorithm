/*

愤怒小鸟

X星球愤怒的小鸟喜欢撞火车！

一根平直的铁轨上两火车间相距 1000 米
两火车 （不妨称A和B） 以时速 10米/秒 相对行驶。

愤怒的小鸟从A车出发，时速50米/秒，撞向B车，
然后返回去撞A车，再返回去撞B车，如此往复....
两火车在相距1米处停车。

问：这期间愤怒的小鸟撞 B 车多少次？

注意：需要提交的是一个整数（表示撞B车的次数），不要填写任何其它内容。

*/

public class _1 {
    public static void main(String[] args) {
        double d = 1000.0; // 两火车初始距离（米）
        double vb = 50.0; // 小鸟速度（米/秒）
        double vt = 10.0; // 火车速度（米/秒）
        double target = 1.0; // 停车距离（米）

        int bHits = 0; // 撞击 B 车的次数
        boolean goingToB = true; // 当前飞行方向：A→B 为 true

        while (d > target) {
            // 小鸟完成本次飞行所需的时间（相向飞行，相对速度 vb+vt）
            double tFlight = d / (vb + vt);
            // 两火车减速到 target 所需的时间
            double tStop = (d - target) / (2 * vt);

            if (tStop < tFlight)
                break; // 火车先停，本次飞行未完成

            // 本次飞行完成：更新距离，若本次飞向 B 则计数
            d = d - 2 * vt * tFlight; // 等价于 d = d * 2 / 3
            if (goingToB)
                bHits++;

            goingToB = !goingToB; // 调转方向
        }

        System.out.println(bHits);
    }
}
