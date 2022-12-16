'''
描述
MP3 Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，用户要通过上下键才能浏览所有的歌曲。为了简化处理，假设每屏只能显示4首歌曲，光标初始的位置为第1首歌。


现在要实现通过上下键控制光标移动来浏览歌曲列表，控制逻辑如下：

歌曲总数<=4的时候，不需要翻页，只是挪动光标位置。

光标在第一首歌曲上时，按Up键光标挪到最后一首歌曲；光标在最后一首歌曲时，按Down键光标挪到第一首歌曲。



其他情况下用户按Up键，光标挪到上一首歌曲；用户按Down键，光标挪到下一首歌曲。



2. 歌曲总数大于4的时候（以一共有10首歌为例）：


特殊翻页：屏幕显示的是第一页（即显示第1 – 4首）时，光标在第一首歌曲上，用户按Up键后，屏幕要显示最后一页（即显示第7-10首歌），同时光标放到最后一首歌上。同样的，屏幕显示最后一页时，光标在最后一首歌曲上，用户按Down键，屏幕要显示第一页，光标挪到第一首歌上。



一般翻页：屏幕显示的不是第一页时，光标在当前屏幕显示的第一首歌曲时，用户按Up键后，屏幕从当前歌曲的上一首开始显示，光标也挪到上一首歌曲。光标当前屏幕的最后一首歌时的Down键处理也类似。



其他情况，不用翻页，只是挪动光标就行。

数据范围：命令长度1\le s\le 100\1≤s≤100 ，歌曲数量1\le n \le 150\1≤n≤150 
进阶：时间复杂度：O(n)\O(n) ，空间复杂度：O(n)\O(n) 
输入描述：
输入说明：
1 输入歌曲数量
2 输入命令 U或者D

输出描述：
输出说明
1 输出当前列表
2 输出当前选中歌曲

示例1
输入：
10
UUUU
复制
输出：
7 8 9 10
7
'''

n = int(input())
order = input()
cur = 1

if n <= 4:
    for i in order:
        if i == 'U':
            cur -= 1
            if cur == 0: cur = n
        else:
            cur += 1
            if cur > n: cur = 1
    print(1, end='')
    for i in range(2, n + 1):
        print(f' {i}', end='')
    print(f'\n{cur}')

else:
    songs = [1, 2, 3, 4]
    for i in order:
        if i == 'U':
            if songs[0] == 1 and cur == songs[0]:
                songs = [j for j in range(n - 3, n + 1)]
                cur = n
            elif songs[0] != 1 and cur == songs[0]:
                cur -= 1
                songs = list(map(lambda x: x - 1, songs))
            else:
                cur -= 1
        else:
            if songs[-1] == n and cur == songs[-1]:
                songs = [1, 2, 3, 4]
                cur = 1
            elif songs[-1] != n and cur == songs[-1]:
                cur += 1
                songs = list(map(lambda x: x + 1, songs))
            else:
                cur += 1
    print(songs[0], end='')
    for i in range(1, 4):
        print(f' {songs[i]}', end='')
    print(f'\n{cur}')
