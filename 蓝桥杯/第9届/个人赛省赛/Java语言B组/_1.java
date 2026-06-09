/*

标题：第几天

2000年的1月1日，是那一年的第1天。
那么，2000年的5月4日，是那一年的第几天？


注意：需要提交的是一个整数，不要填写任何多余内容。


*/

public class _1 {

    /**
     * 判断给定年份是否为闰年
     * 闰年规则：能被400整除，或者能被4整除但不能被100整除
     *
     * @param year 年份
     * @return true表示闰年，2月有29天；false表示平年，2月有28天
     */
    static boolean isLeapYear(int year) {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    /**
     * 每个月的天数（平年），索引0未使用，索引1对应1月，索引12对应12月
     */
    static int[] daysOfMonth = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    /**
     * 计算给定年份中某月某日是该年的第几天
     *
     * @param year  年份，用于判断闰年从而确定2月天数
     * @param month 月份（1-12）
     * @param day   日期（1-31）
     * @return 该日期是该年的第几天（从1开始计数）
     */
    static int dayOfYear(int year, int month, int day) {
        int total = 0;
        /* 累加1月到month-1月的完整月份天数 */
        for (int m = 1; m < month; m++) {
            total += daysOfMonth[m];
            /* 闰年的2月多1天（28→29） */
            if (m == 2 && isLeapYear(year)) {
                total += 1;
            }
        }
        /* 加上当前月份中已过的天数 */
        total += day;
        return total;
    }

    public static void main(String[] args) {
        /*
         * 2000年是闰年（能被400整除），2月有29天。
         * 计算2000年5月4日是该年的第几天：
         * 1月(31) + 2月(29) + 3月(31) + 4月(30) + 5月(4天) = 125
         */
        int result = dayOfYear(2000, 5, 4);
        System.out.println(result);
    }

    
  