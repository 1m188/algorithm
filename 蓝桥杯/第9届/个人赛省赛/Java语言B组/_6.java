/*

标题：递增三元组

给定三个整数数组
A = [A1, A2, ... AN], 
B = [B1, B2, ... BN], 
C = [C1, C2, ... CN]，
请你统计有多少个三元组(i, j, k) 满足：

1. 1 <= i, j, k <= N  
2. Ai < Bj < Ck  

【输入格式】
第一行包含一个整数N。
第二行包含N个整数A1, A2, ... AN。
第三行包含N个整数B1, B2, ... BN。
第四行包含N个整数C1, C2, ... CN。

对于30%的数据，1 <= N <= 100  
对于60%的数据，1 <= N <= 1000 
对于100%的数据，1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000 

【输出格式】
一个整数表示答案

【输入样例】
3
1 1 1
2 2 2
3 3 3

【输出样例】
27 


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。


*/

public class _6 {

    /**
     * 在已排序数组 arr 中查找第一个 >= target 的元素下标（下界）。
     * 若所有元素都 < target，返回 arr.length。
     * 此函数找到的位置之前的所有元素均严格小于 target。
     *
     * @param arr    已升序排序的整数数组
     * @param target 查找目标值
     * @return 第一个 >= target 的元素下标
     */
    static int lowerBound(int[] arr, int target) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    /**
     * 在已排序数组 arr 中查找第一个 > target 的元素下标（上界）。
     * 若所有元素都 <= target，返回 arr.length。
     * 此函数找到的位置及其之后的元素均严格大于 target。
     *
     * @param arr    已升序排序的整数数组
     * @param target 查找目标值
     * @return 第一个 > target 的元素下标
     */
    static int upperBound(int[] arr, int target) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N];

        for (int i = 0; i < N; i++)
            A[i] = scanner.nextInt();
        for (int i = 0; i < N; i++)
            B[i] = scanner.nextInt();
        for (int i = 0; i < N; i++)
            C[i] = scanner.nextInt();

        /*
         * 对三个数组分别排序。
         * 排序后，可以使用二分查找快速统计满足大小关系的元素个数。
         */
        java.util.Arrays.sort(A);
        java.util.Arrays.sort(B);
        java.util.Arrays.sort(C);

        /*
         * 核心思路：
         * 对于每个 B[j]，统计有多少 A[i] < B[j] 以及有多少 C[k] > B[j]。
         * 由于 A 和 C 的选择是独立的，以 B[j] 为"中值"的三元组数量
         * 等于 (A中小于B[j]的元素数) × (C中大于B[j]的元素数)。
         *
         * 最终答案 = Σ_{j=0}^{N-1} countA × countC
         *
         * 使用二分查找在已排序的 A 和 C 中高效定位：
         * - countA = lowerBound(A, B[j])：A 中第一个 >= B[j] 的位置，
         * 即严格小于 B[j] 的元素个数
         * - countC = N - upperBound(C, B[j])：C 中第一个 > B[j] 的位置之后
         * 的元素个数，即严格大于 B[j] 的元素个数
         *
         * 答案可能非常大（N=10^5，最坏情况 ~10^15），需要使用 long 类型。
         */
        long answer = 0;
        for (int j = 0; j < N; j++) {
            int countA = lowerBound(A, B[j]);
            int countC = N - upperBound(C, B[j]);
            answer += (long) countA * countC;
        }

        System.out.println(answer);
    }
}
