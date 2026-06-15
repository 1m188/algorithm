/*
标题：拉马车

小的时候，你玩过纸牌游戏吗？
有一种叫做"拉马车"的游戏，规则很简单，却很吸引小朋友。

其规则简述如下：
假设参加游戏的小朋友是A和B，游戏开始的时候，他们得到的随机的纸牌序列如下：
A方：[K, 8, X, K, A, 2, A, 9, 5, A]
B方：[2, 7, K, 5, J, 5, Q, 6, K, 4]

其中的X表示"10"，我们忽略了纸牌的花色。

从A方开始，A、B双方轮流出牌。

当轮到某一方出牌时，他从自己的纸牌队列的头部拿走一张，放到桌上，并且压在最上面一张纸牌上（如果有的话）。

此例中，游戏过程：
A出K，B出2，A出8，B出7，A出X，此时桌上的序列为：K,2,8,7,X

当轮到B出牌时，他的牌K与桌上的纸牌序列中的K相同，则把包括K在内的以及两个K之间的纸牌都赢回来，放入自己牌的队尾。注意：为了操作方便，放入牌的顺序是与桌上的顺序相反的。
此时，A、B双方的手里牌为：
A方：[K, A, 2, A, 9, 5, A]
B方：[5, J, 5, Q, 6, K, 4, K, X, 7, 8, 2, K]

赢牌的一方继续出牌。也就是B接着出5，A出K，B出J，A出A，B出5，又赢牌了。

    注意：更多的时候赢牌的一方并不能把桌上的牌都赢走，而是拿走相同牌点及其中间的部分。但无论如何，都是赢牌的一方继续出牌，有的时候刚一出牌又赢了，也是允许的。

    当某一方出掉手里最后一张牌，但无法从桌面上赢取牌时，游戏立即结束。

    对于本例的初始手牌情况下，最后A会输掉，而B最后的手里牌为：9K2A62KAX58K57KJ5

输入为2行，2个串，分别表示A、B双方初始手里的牌序列。
输出为1行，1个串，表示A先出牌，最后赢的一方手里的牌序。当游戏无法结束时，输出-1。

例如，
输入：96J5A898QA \n 6278A7Q973 → 输出：2J9A7QA6Q6889977
输入：25663K6X7448 \n J88A5KJXX45A → 输出：6KAJ458KXAX885XJ645

资源约定：峰值内存消耗 < 256M，CPU消耗 < 1000ms
主类的名字必须是：Main


解题思路：
用双端队列模拟双方手牌，String 模拟桌面牌。
关键规则：
1. 出牌方从手牌头部取一张放桌面末尾
2. 若该牌点与桌面已有的某张牌点相同，赢回从匹配位到末尾的所有牌（逆序加入手牌），继续出牌
3. 若一方出完手牌且无法赢牌，游戏结束，另一方获胜
4. 用 Set 记录状态检测无限循环
*/
import java.util.*;

public class _8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sa = sc.next(), sb = sc.next();
        sc.close();

        Deque<Character> A = new ArrayDeque<>();
        Deque<Character> B = new ArrayDeque<>();
        for (char c : sa.toCharArray()) A.addLast(c);
        for (char c : sb.toCharArray()) B.addLast(c);

        StringBuilder table = new StringBuilder();
        int turn = 0; // 0=A, 1=B
        Set<String> seen = new HashSet<>();

        for (int step = 0; step < 1000000; step++) {
            // 循环检测
            StringBuilder state = new StringBuilder();
            for (char c : A) state.append(c); state.append('|');
            for (char c : B) state.append(c); state.append('|');
            state.append(table); state.append('|'); state.append(turn);
            String key = state.toString();
            if (!seen.add(key)) {
                System.out.println(-1);
                return;
            }

            Deque<Character> player = (turn == 0) ? A : B;
            Deque<Character> opponent = (turn == 0) ? B : A;

            if (player.isEmpty()) {
                for (char c : opponent) System.out.print(c);
                System.out.println();
                return;
            }

            char card = player.pollFirst();
            String t = table.toString();
            int pos = -1;
            // 在桌面已有的牌中找相同牌点（不含刚放上去的牌）
            for (int i = 0; i < t.length(); i++) {
                if (t.charAt(i) == card) {
                    pos = i;
                    break;
                }
            }
            table.append(card);

            if (pos >= 0) {
                // 赢回从 pos 到末尾的所有牌，逆序加入手牌
                String win = table.substring(pos);
                table.setLength(pos);
                for (int i = win.length() - 1; i >= 0; i--)
                    player.addLast(win.charAt(i));
                // 赢牌方继续出牌，不切换 turn
            } else {
                if (player.isEmpty()) {
                    for (char c : opponent) System.out.print(c);
                    System.out.println();
                    return;
                }
                turn = 1 - turn;
            }
        }
        System.out.println(-1);
    }
}
