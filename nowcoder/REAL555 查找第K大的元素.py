"""
REAL555 查找第K大的元素

描述
给定一个无序的整型数组A[n],数组大小大于等于3,允许有值相同的元素;请设计算法找到该数组排序后第三大的元素值并输出.
输入描述：
一个非空的整数数组(至少有3个元素,可正可负)
输出描述：
第三大的元素值
示例1
输入：
[1,2,3,4,5]
复制
输出：
3
复制
示例2
输入：
[1,1,2,2,3]
复制
输出：
2
复制
示例3
输入：
[6,5,4,4,1,2]
复制
输出：
4
"""


def adjust(heap: list, start: int, end: int) -> None:
    while True:
        index = start
        if (left := start * 2 + 1) <= end and heap[left] < heap[index]:
            index = left
        if (right := start * 2 + 2) <= end and heap[right] < heap[index]:
            index = right
        if index == start:
            break
        heap[start], heap[index] = heap[index], heap[start]
        start = index


def build_heap(arr: list) -> None:
    n = len(arr)
    for i in range((n - 1 - 1) // 2, -1, -1):
        adjust(arr, i, n - 1)


A = eval(input().strip())
heap: list[int] = A[:3]
build_heap(heap)
for i in range(3, len(A)):
    if A[i] > heap[0]:
        heap[0] = A[i]
        adjust(heap, 0, 2)
print(min(heap))
