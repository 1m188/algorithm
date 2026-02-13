"""
REAL344 整数无序数组求第K大数

描述
给定无序整数序列，求其中第K大的数，例如{45，67，33，21}，第2大数为45
输入描述：
输入第一行为整数序列，数字用空格分隔，如：45 67 33 21 输入第二行一个整数K，K在数组长度范围内，如：2
输出描述：
输出第K大的数，本例为第2大数：45
示例1
输入：
45 67 33 21
2
复制
输出：
45
"""


def adjust(heap: list[int], start: int, end: int) -> None:
    while True:
        index = start
        if (left := start * 2 + 1) <= end and heap[left] < heap[index]:
            index = left
        if (right := start * 2 + 2) <= end and heap[right] < heap[index]:
            index = right
        if index == start:
            break
        heap[index], heap[start] = heap[start], heap[index]
        start = index


def build_heap(arr: list[int]) -> None:
    n = len(arr)
    for i in range((n - 1 - 1) // 2, -1, -1):
        adjust(arr, i, n - 1)


arr = list(map(int, input().strip().split()))
k = int(input().strip())
heap = arr[:k]
build_heap(heap)
for i in range(k, len(arr)):
    if arr[i] > heap[0]:
        heap[0] = arr[i]
        adjust(heap, 0, k - 1)
print(heap[0])
