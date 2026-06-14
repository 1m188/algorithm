/*

广场舞

LQ市的市民广场是一个多边形，广场上铺满了大理石的地板砖。

地板砖铺得方方正正，就像坐标轴纸一样。
以某四块砖相接的点为原点，地板砖的两条边为两个正方向，一块砖的边长为横纵坐标的单位长度，则所有横纵坐标都为整数的点都是四块砖的交点（如果在广场内）。

广场的砖单调无趣，却给跳广场舞的市民们提供了绝佳的参照物。每天傍晚，都会有大批市民前来跳舞。
舞者每次都会选一块完整的砖来跳舞，两个人不会选择同一块砖，如果一块砖在广场边上导致缺角或者边不完整，则没人会选这块砖。
（广场形状的例子参考【图1.png】）

现在，告诉你广场的形状，请帮LQ市的市长计算一下，同一时刻最多有多少市民可以在广场跳舞。



【输入格式】
输入的第一行包含一个整数n，表示广场是n边形的（因此有n个顶点）。
接下来n行，每行两个整数，依次表示n边形每个顶点的坐标（也就是说广场边缘拐弯的地方都在砖的顶角上。数据保证广场是一个简单多边形。

【输出格式】
输出一个整数，表示最多有多少市民可以在广场跳舞。

【样例输入】
5
3 3
6 4
4 1
1 -1
0 4

【样例输出】
7

【样例说明】
广场如图1.png所示，一共有7块完整的地板砖，因此最多能有7位市民一起跳舞。

【数据规模与约定】
对于30%的数据，n不超过100，横纵坐标的绝对值均不超过100。
对于50%的数据，n不超过1000，横纵坐标的绝对值均不超过1000。
对于100%的数据，n不超过1000，横纵坐标的绝对值均不超过100000000（一亿）。


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。

*/

import java.util.*;

public class _5 {
    static int n;
    static long[] px, py;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        px = new long[n];
        py = new long[n];
        long minX = Long.MAX_VALUE, maxX = Long.MIN_VALUE;
        long minY = Long.MAX_VALUE, maxY = Long.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            px[i] = sc.nextLong();
            py[i] = sc.nextLong();
            if (px[i] < minX)
                minX = px[i];
            if (px[i] > maxX)
                maxX = px[i];
            if (py[i] < minY)
                minY = py[i];
            if (py[i] > maxY)
                maxY = py[i];
        }
        sc.close();

        long ans;
        // 对于坐标范围较小的情况，直接暴力枚举每块砖
        if (maxX - minX <= 2000 && maxY - minY <= 2000) {
            ans = bruteForce(minX, maxX, minY, maxY);
        } else {
            // 大范围采用扫描线 + floor_sum 算法
            ans = scanline(minX, maxX, minY, maxY);
        }
        System.out.println(ans);
    }

    // 暴力枚举：对每块单位砖检查是否完整（砖的闭包 ⊆ 多边形闭包）
    static long bruteForce(long minX, long maxX, long minY, long maxY) {
        long cnt = 0;
        for (long x = minX; x < maxX; x++) {
            for (long y = minY; y < maxY; y++) {
                if (tileComplete(x, y))
                    cnt++;
            }
        }
        return cnt;
    }

    // 判断单位砖 [x, x+1] × [y, y+1] 是否完整位于多边形内部
    // 条件：中心在多边形内部，且没有任何多边形边穿过砖的内部
    static boolean tileComplete(long x, long y) {
        // 砖的中心必须在多边形内部（严格）
        if (!pointInPolygonStrict(x + 0.5, y + 0.5))
            return false;
        // 检查是否有边穿过砖的内部：多边形边与砖四条边发生非端点相交
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            // 跳过水平或竖直边——它们只会贴齐砖边，不会穿入砖内部
            if (px[i] == px[j] || py[i] == py[j]) {
                // 水平/竖直边：如果与砖边重合则砖不完整
                if (px[i] == px[j]) { // 竖直边 x = c
                    if (px[i] > x && px[i] < x + 1
                            && Math.min(py[i], py[j]) <= y && Math.max(py[i], py[j]) >= y + 1) {
                        return false; // 砖被竖直边切过内部
                    }
                    // 砖的竖直边与多边形边重合
                    if ((px[i] == x || px[i] == x + 1)
                            && overlap(Math.min(py[i], py[j]), Math.max(py[i], py[j]), y, y + 1)) {
                        return false;
                    }
                } else { // 水平边 y = c
                    if (py[i] > y && py[i] < y + 1
                            && Math.min(px[i], px[j]) <= x && Math.max(px[i], px[j]) >= x + 1) {
                        return false; // 砖被水平边切过内部
                    }
                    if ((py[i] == y || py[i] == y + 1)
                            && overlap(Math.min(px[i], px[j]), Math.max(px[i], px[j]), x, x + 1)) {
                        return false;
                    }
                }
            } else {
                // 斜边：检查是否与砖的四条内部边相交
                if (segIntersectInterior(px[i], py[i], px[j], py[j], x, y, x, y + 1))
                    return false;
                if (segIntersectInterior(px[i], py[i], px[j], py[j], x, y + 1, x + 1, y + 1))
                    return false;
                if (segIntersectInterior(px[i], py[i], px[j], py[j], x + 1, y, x + 1, y + 1))
                    return false;
                if (segIntersectInterior(px[i], py[i], px[j], py[j], x, y, x + 1, y))
                    return false;
            }
        }
        return true;
    }

    // 判断两个区间是否重叠（长度 > 0）
    static boolean overlap(double a1, double a2, double b1, double b2) {
        return Math.max(a1, b1) < Math.min(a2, b2);
    }

    // 判断线段 (x1,y1)-(x2,y2) 与 (x3,y3)-(x4,y4) 是否在非端点处相交
    static boolean segIntersectInterior(
            double x1, double y1, double x2, double y2,
            double x3, double y3, double x4, double y4) {
        double d1 = cross(x1, y1, x2, y2, x3, y3);
        double d2 = cross(x1, y1, x2, y2, x4, y4);
        double d3 = cross(x3, y3, x4, y4, x1, y1);
        double d4 = cross(x3, y3, x4, y4, x2, y2);
        // 任何一端点在另一线段上 → 视为边界接触，不算切割
        if (Math.abs(d1) < 1e-12 || Math.abs(d2) < 1e-12
                || Math.abs(d3) < 1e-12 || Math.abs(d4) < 1e-12)
            return false;
        return (d1 > 0) != (d2 > 0) && (d3 > 0) != (d4 > 0);
    }

    static double cross(double x1, double y1, double x2, double y2, double x3, double y3) {
        return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    }

    // 射线法判断点 (px, py) 是否严格在多边形内部
    static boolean pointInPolygonStrict(double px, double py) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            double x1 = _5.px[i], y1 = _5.py[i];
            double x2 = _5.px[j], y2 = _5.py[j];
            // 检查点是否在边上（包括端点），若在边上则不算严格内部
            if (Math.abs(cross(x1, y1, x2, y2, px, py)) < 1e-12) {
                if (Math.min(x1, x2) - 1e-12 <= px && px <= Math.max(x1, x2) + 1e-12
                        && Math.min(y1, y2) - 1e-12 <= py && py <= Math.max(y1, y2) + 1e-12)
                    return false;
            }
            if ((y1 > py) != (y2 > py)) {
                double xint = x1 + (py - y1) * (x2 - x1) / (y2 - y1);
                if (px < xint)
                    cnt++;
            }
        }
        return (cnt & 1) == 1;
    }

    // ===== 大范围扫描线：统计中心在多边形内部的单位砖 =====
    // 原理：将多边形平移 (-0.5,-0.5)，问题转化为统计平移后多边形内部的整点数。
    // 在每条水平条带中，左/右边界为线性函数 x=(A*y+B)/M，用 floor_sum 快速累加。
    static long scanline(long minX, long maxX, long minY, long maxY) {
        // 收集所有不同的顶点 y 坐标（整数值）
        TreeSet<Long> ys = new TreeSet<>();
        for (int i = 0; i < n; i++)
            ys.add(py[i]);
        Long[] yArr = ys.toArray(new Long[0]);

        long total = 0;

        // 对每条水平条带 [yLow, yHigh) 处理（yLow、yHigh 为相邻顶点 y 坐标）
        for (int k = 0; k + 1 < yArr.length; k++) {
            long yLow = yArr[k];
            long yHigh = yArr[k + 1];
            long H = yHigh - yLow; // 条带中整 Y 值的个数

            // 收集穿过此条带的非水平边
            long[] edgeA = new long[n];
            long[] edgeB = new long[n];
            long[] edgeM = new long[n];
            int edgeCnt = 0;

            for (int i = 0; i < n; i++) {
                int j = (i + 1) % n;
                if (py[i] == py[j])
                    continue; // 水平边不影响整 Y 处的 x 交点

                long yi = py[i], yj = py[j];
                long xi = px[i], xj = px[j];
                // 确保 yi < yj（向上边），同时对应交换 x
                if (yi > yj) {
                    long ty = yi;
                    yi = yj;
                    yj = ty;
                    long tx = xi;
                    xi = xj;
                    xj = tx;
                }

                // 仅保留与条带相交的边：yi < yHigh && yj > yLow
                if (yi >= yHigh || yj <= yLow)
                    continue;

                long dx = xj - xi, dy = yj - yi; // dy > 0
                long A = 2 * dx;
                long M = 2 * dy;
                // B = dx*(1 - 2*yi) + dy*(2*xi - 1)
                long B = dx * (1 - 2 * yi) + dy * (2 * xi - 1);

                edgeA[edgeCnt] = A;
                edgeB[edgeCnt] = B;
                edgeM[edgeCnt] = M;
                edgeCnt++;
            }

            if (edgeCnt == 0)
                continue;

            // 在条带中点处按 x 坐标排序各边
            double yMid = yLow + H * 0.5;
            Integer[] idx = new Integer[edgeCnt];
            for (int i = 0; i < edgeCnt; i++)
                idx[i] = i;
            Arrays.sort(idx, new Comparator<Integer>() {
                public int compare(Integer a, Integer b) {
                    double xa = (edgeA[a] * yMid + edgeB[a]) / (double) edgeM[a];
                    double xb = (edgeA[b] * yMid + edgeB[b]) / (double) edgeM[b];
                    return Double.compare(xa, xb);
                }
            });

            // 配对：对于简单多边形，排序后的交点按 0-1、2-3... 成对构成内部区间
            for (int p = 0; p + 1 < edgeCnt; p += 2) {
                int li = idx[p], ri = idx[p + 1];
                long Al = edgeA[li], Bl = edgeB[li], Ml = edgeM[li];
                long Ar = edgeA[ri], Br = edgeB[ri], Mr = edgeM[ri];

                // sum floor(x_left(Y)) for Y = yLow .. yLow+H-1
                long sumLeft = floorSumRange(H, Ml, Al, Al * yLow + Bl);
                // sum ceil(x_right(Y)) = sum floor((Ar*Y + Br + Mr - 1) / Mr)
                long sumRight = floorSumRange(H, Mr, Ar, Ar * yLow + Br + Mr - 1);

                // 该区间在当前条带中贡献的整 X 个数
                long contrib = sumRight - sumLeft - H;
                if (contrib > 0)
                    total += contrib;
            }
        }
        return total;
    }

    // sum_{i=0}^{n-1} floor((a*i + b) / m)，处理 a 可为负值的情况
    static long floorSumRange(long n, long m, long a, long b) {
        if (a < 0) {
            // floor((-|a|*i + b)/m) = -ceil((|a|*i - b)/m)
            // = -floor((|a|*i + (-b) + m - 1) / m)
            return -floorSum(n, m, -a, -b + m - 1);
        }
        return floorSum(n, m, a, b);
    }

    // AtCoder library floor_sum: sum_{i=0}^{n-1} floor((a*i + b) / m)
    // 要求 a >= 0, m > 0；所有中间结果均不超出 long 范围。
    static long floorSum(long n, long m, long a, long b) {
        if (n == 0)
            return 0;
        long ans = 0;
        if (a >= m) {
            ans += (n - 1) * n / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }
        long yMax = (a * n + b) / m;
        if (yMax == 0)
            return ans;
        long xMax = yMax * m - b;
        ans += (n - (xMax + a - 1) / a) * yMax;
        ans += floorSum(yMax, a, m, (a - xMax % a) % a);
        return ans;
    }
}
