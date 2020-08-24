/*

kmp

*/

public class kmp {

    /**
     * @param s 待匹配字符串
     * @return next数组
     */
    private static int[] get_next(final String s) {
        int[] next = new int[s.length()];
        next[0] = -1;
        for (int i = 1; i < next.length; i++) {
            int idx = next[i - 1];
            while (idx >= 0 && s.charAt(idx) != s.charAt(i - 1))
                idx = next[idx];
            next[i] = idx + 1;
        }
        return next;
    }

    /**
     * @param str 原串
     * @param s   待匹配字符串
     * @return s在str中的开始索引，倘若不存在则返回-1
     */
    private static int Kmp(final String str, final String s) {
        int[] next = get_next(s);
        int stri = 0, si = 0;
        while (stri < str.length() && si < s.length())
            if (str.charAt(stri) == s.charAt(si) || (si = next[si]) == -1) {
                stri++;
                si++;
            }
        return si >= s.length() ? stri - s.length() : -1;
    }

    public static void main(String[] args) {
        String str = "googloogle", s = "google";
        System.out.println(Kmp(str, s));

        str = "asdfgs";
        s = "dfg";
        System.out.println(Kmp(str, s));
    }
}