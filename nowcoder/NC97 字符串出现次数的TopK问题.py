'''
描述
给定一个字符串数组，再给定整数 k ，请返回出现次数前k名的字符串和对应的次数。
返回的答案应该按字符串出现频率由高到低排序。如果不同的字符串有相同出现频率，按字典序排序。
对于两个字符串，大小关系取决于两个字符串从左到右第一个不同字符的 ASCII 值的大小关系。
比如"ah1x"小于"ahb"，"231"<”32“
字符仅包含数字和字母

数据范围：字符串数满足 0 \le n \le 1000000≤n≤100000，每个字符串长度 0 \le n \le 100≤n≤10，0 \le k \le 25000≤k≤2500
要求：空间复杂度 O(n)O(n)，时间复杂度O(n \log k)O(nlogk)

示例1
输入：
["a","b","c","b"],2
复制
返回值：
[["b","2"],["a","1"]]
复制
说明：
"b"出现了2次，记["b","2"]，"a"与"c"各出现1次，但是a字典序在c前面，记["a","1"]，最后返回[["b","2"],["a","1"]]
   
示例2
输入：
["123","123","231","32"],2
复制
返回值：
[["123","2"],["231","1"]]
复制
说明：
 "123"出现了2次，记["123","2"]，"231"与"32"各出现1次，但是"231"字典序在"32"前面，记["231","1"]，最后返回[["123","2"],["231","1"]]   
示例3
输入：
["abcd","abcd","abcd","pwb2","abcd","pwb2","p12"],3
复制
返回值：
[["abcd","4"],["pwb2","2"],["p12","1"]]
复制
备注：
1 \leq N \leq 10^51≤N≤10 
5
'''

from typing import List
import functools


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# return topK string
# @param strings string字符串一维数组 strings
# @param k int整型 the k
# @return string字符串二维数组
#
class Solution:

    def topKstrings(self, strings: List[str], k: int) -> List[List[str]]:
        # write code here

        di = {}
        for s in strings:
            if s not in di: di[s] = 1
            else: di[s] += 1
        if k >= len(di):
            li = [[k, v] for k, v in di.items()]
        else:
            li = list(di.items())
            heap = list(map(list, li[:k]))
            self.build_heap(heap)
            for i in range(k, len(li)):
                if li[i][1] > heap[0][1] or (li[i][1] == heap[0][1]
                                             and li[i][0] < heap[0][0]):
                    heap[0] = list(li[i])
                    self.adjust(heap, 0)
            li = heap
        li.sort(key=functools.cmp_to_key(self.cmp))
        for i in range(len(li)):
            li[i][1] = str(li[i][1])
        return li

    def build_heap(self, vec: List):
        for i in range((len(vec) - 1 - 1) // 2, -1, -1):
            self.adjust(vec, i)

    def adjust(self, vec: List, idx: int):
        tmp = vec[idx]
        m = idx * 2 + 1
        while m < len(vec):
            if m + 1 < len(vec) and (vec[m + 1][1] < vec[m][1] or
                                     (vec[m + 1][1] == vec[m][1] and
                                      vec[m + 1][0] > vec[m][0])):  # 注意更小的判定方法
                m += 1
            if vec[m][1] < vec[idx][1] or (vec[m][1] == vec[idx][1]
                                           and vec[m][0] > vec[idx][0]):
                vec[m], vec[idx] = vec[idx], vec[m]
            else:
                break
            idx = m
            m = idx * 2 + 1
        vec[idx] = tmp

    def cmp(self, e1: List, e2: List) -> int:
        if e1[1] != e2[1]: return e2[1] - e1[1]
        if e1[0] < e2[0]: return -1
        else: return 1
