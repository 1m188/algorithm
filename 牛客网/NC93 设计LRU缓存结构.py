'''
描述
设计LRU(最近最少使用)缓存结构，该结构在构造时确定大小，假设大小为 capacity ，操作次数是 n ，并有如下功能:
1. Solution(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
2. get(key)：如果关键字 key 存在于缓存中，则返回key对应的value值，否则返回 -1 。
3. set(key, value)：将记录(key, value)插入该结构，如果关键字 key 已经存在，则变更其数据值 value，如果不存在，则向缓存中插入该组 key-value ，如果key-value的数量超过capacity，弹出最久未使用的key-value

提示:
1.某个key的set或get操作一旦发生，则认为这个key的记录成了最常使用的，然后都会刷新缓存。
2.当缓存的大小超过capacity时，移除最不经常使用的记录。
3.返回的value都以字符串形式表达，如果是set，则会输出"null"来表示(不需要用户返回，系统会自动输出)，方便观察
4.函数set和get必须以O(1)的方式运行
5.为了方便区分缓存里key与value，下面说明的缓存里key用""号包裹
数据范围:
1\leq capacity<=10^51≤capacity<=10 
5
 
0\leq key,val \leq 2\times 10^9 \0≤key,val≤2×10 
9
  
1\leq n\leq 10^51≤n≤10 
5
 

示例1
输入：
["set","set","get","set","get","set","get","get","get"],[[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]],2
复制
返回值：
["null","null","1","null","-1","null","-1","3","4"]
复制
说明：
我们将缓存看成一个队列，最后一个参数为2代表capacity，所以
Solution s = new Solution(2);
s.set(1,1); //将(1,1)插入缓存，缓存是{"1"=1}，set操作返回"null"
s.set(2,2); //将(2,2)插入缓存，缓存是{"2"=2，"1"=1}，set操作返回"null"
output=s.get(1);// 因为get(1)操作，缓存更新，缓存是{"1"=1，"2"=2}，get操作返回"1"
s.set(3,3); //将(3,3)插入缓存，缓存容量是2，故去掉某尾的key-value，缓存是{"3"=3，"1"=1}，set操作返回"null" 
output=s.get(2);// 因为get(2)操作，不存在对应的key，故get操作返回"-1"
s.set(4,4); //将(4,4)插入缓存，缓存容量是2，故去掉某尾的key-value，缓存是{"4"=4，"3"=3}，set操作返回"null" 
output=s.get(1);// 因为get(1)操作，不存在对应的key，故get操作返回"-1"
output=s.get(3);//因为get(3)操作，缓存更新，缓存是{"3"=3，"4"=4}，get操作返回"3"
output=s.get(4);//因为get(4)操作，缓存更新，缓存是{"4"=4，"3"=3}，get操作返回"4"        
'''


class Solution:

    def __init__(self, capacity: int):
        # write code here

        self.size = capacity
        self.li = []

    def get(self, key: int) -> int:
        # write code here

        for i, [k, v] in enumerate(self.li):
            if k == key:
                self.li.insert(0, self.li.pop(i))
                return v
        return -1

    def set(self, key: int, value: int) -> None:
        # write code here

        for i, [k, v] in enumerate(self.li):
            if k == key:
                self.li[i][1] = value
                self.li.insert(0, self.li.pop(i))
                return
        if len(self.li) == self.size: self.li.pop()
        self.li.insert(0, [key, value])


# Your Solution object will be instantiated and called as such:
# solution = Solution(capacity)
# output = solution.get(key)
# solution.set(key,value)