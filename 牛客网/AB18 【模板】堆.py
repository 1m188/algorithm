'''
描述
请你实现一个堆(大根堆)。
操作：
push x：将
x
x加入堆。保证
x
x为int型整数。不输出任何内容。
top：输出堆顶元素。若堆为空，输出"empty"(不含引号)。
pop：输出堆顶元素，且弹出堆顶。若堆为空，输出"empty"(不含引号)。
输入描述：
第一行输入一个整数
n
n (
1
≤
n
≤
1
0
5
1≤n≤10 
5
 )，表示操作次数。
接下来的
n
n行，每行一个字符串，表示一个操作。保证操作是题目描述中的一种。
输出描述：
按对应操作要求输出。
示例1
输入：
11
push 1
top
push 3
top
push 2
top
pop
pop
pop
top
pop
复制
输出：
1
3
3
3
2
1
empty
empty
'''

import sys

print = sys.stdout.write
input = sys.stdin.readline


class Heap:

    def __init__(self):
        self.heap = []

    def adjust(self, index: int):
        n = len(self.heap)
        while True:
            idx = index
            left = idx * 2 + 1
            right = idx * 2 + 2
            if left < n and self.heap[left] > self.heap[idx]:
                idx = left
            if right < n and self.heap[right] > self.heap[idx]:
                idx = right
            if idx == index: break
            self.heap[index], self.heap[idx] = self.heap[idx], self.heap[index]
            index = idx

    def push(self, x):
        self.heap.append(x)
        index = len(self.heap) - 1
        while index > 0:  # 堆化
            father = (index - 1) // 2
            if self.heap[index] > self.heap[father]:
                self.heap[index], self.heap[father] = self.heap[father], self.heap[index]
                index = father
            else:
                break

    def top(self):
        if len(self.heap) == 0: print('empty\n')
        else: print(f'{self.heap[0]}\n')

    def pop(self):
        if len(self.heap) == 0: print('empty\n')
        else:
            print(f'{self.heap[0]}\n')
            self.heap[0], self.heap[-1] = self.heap[-1], self.heap[0]
            self.heap.pop()
            self.adjust(0)


n = int(input().rstrip())
heap = Heap()

for line in sys.stdin:
    s = line.rstrip()
    if s[0] == 'p':
        if s[1] == 'u':
            x = int(s.split(' ')[1])
            heap.push(x)
        else:
            heap.pop()
    else:
        heap.top()
