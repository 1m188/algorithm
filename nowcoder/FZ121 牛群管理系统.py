'''

描述
农场主需要管理他的牛群，他想要设计一个系统来存储牛群中每头牛的编号。为了方便管理，他决定使用哈希集合（HashSet）来存储牛的编号。

实现一个名为CowHashSet的类，包含以下方法：

void add(int id)：向哈希集合中插入牛的编号id。
bool contains(int id)：返回哈希集合中是否存在编号为id的牛。
void remove(int id)：将编号为id的牛从哈希集合中删除。如果哈希集合中没有这个编号，什么也不做。
请实现一个名为manageCows的函数，接收两个参数：

vector<string> operations：表示操作的字符串数组，包含"CowHashSet"、"add"、"contains"和"remove"。
vector<vector<int>> args：表示操作对应的参数数组。
返回一个vector<string>，表示操作的输出结果。

示例1
输入：
["CowHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"],[[], [1], [2], [1], [3], [2], [2], [2], [2]]
复制
返回值：
["null","null","null","true","false","null","true","null","false"]
复制
备注：
0 <= id <= 10^6
最多调用 10^4 次 add、remove 和 contains

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param operations string字符串一维数组
# @param args int整型二维数组
# @return string字符串一维数组
#
class Solution:

    def manageCows(self, operations: List[str], args: List[List[int]]) -> List[str]:
        # write code here

        class CowHashSet:

            def __init__(self):
                self.se = set()

            def add(self, id_: int):
                self.se.add(id_)
                return 'null'

            def contains(self, id_: int) -> bool:
                f = id_ in self.se
                f = str(f)
                f = f[0].lower() + f[1:]
                return f

            def remove(self, id_: int):
                self.se.remove(id_)
                return 'null'

        res = []
        hset = CowHashSet()
        for i, v in enumerate(operations):
            if v == 'add': res.append(hset.add(args[i][0]))
            elif v == 'contains': res.append(hset.contains(args[i][0]))
            elif v == 'remove': res.append(hset.remove(args[i][0]))
            else: res.append('null')
        return res
