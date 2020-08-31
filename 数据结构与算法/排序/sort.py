'''

排序算法

'''

from random import randint
from copy import deepcopy
from queue import Queue
from typing import List


# 生成一个随机整数组
def genrandvec(length: int, left: int, right: int) -> List[int]:
    vec = []
    while length > 0:
        vec.append(randint(left, right))
        length -= 1
    return vec


# 输出一个数组
# prefix为输出前缀
def printvec(vec: list, prefix: str):
    print(f"{prefix}:", end="")
    for e in vec:
        print(f" {e}", end="")
    print()


# ###################### 插入类排序算法 ######################


# 直接插入排序
# 时间复杂度最坏为O(n^2)，最好O(n)，平均O(n^2)
# 空间复杂度O(1)
# 是一个稳定的算法
def insertSort(vec: list):
    for i in range(1, len(vec)):
        tmp = vec[i]
        idx = i - 1
        while idx >= 0 and vec[idx] > tmp:
            vec[idx + 1] = vec[idx]
            idx -= 1
        vec[idx + 1] = tmp


# 有序序列中获取待插入索引
def bindex(vec: list, left: int, right: int, target) -> int:
    mid = int((left + right) / 2)
    while left < right:
        if vec[mid] == target:
            return mid + 1
        elif vec[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
        mid = int((left + right) / 2)
    return mid + 1 if vec[mid] <= target else mid


# 折半插入排序
# 时间复杂度最好O(nlog2n)，最坏O(n^2)，平均O(n^2)
# 空间复杂度O(1)
# 是一个稳定的算法
def binsertSort(vec: list):
    for i in range(1, len(vec)):
        index = bindex(vec, 0, i - 1, vec[i])
        tmp = vec[i]
        idx = i - 1
        while idx >= index:
            vec[idx + 1] = vec[idx]
            idx -= 1
        vec[idx + 1] = tmp


# 希尔排序
# 具体时间复杂度和增量选取有关，/2的复杂度为O(n^2)，平均O(nlog2n)
# 空间复杂度O(1)
# 是一个不稳定的算法
def shellSort(vec: list, k: int, kfun):
    while k > 1:
        for i in range(0, k):
            for j in range(i + k, len(vec), k):
                tmp = vec[j]
                idx = j - k
                while idx >= i and vec[idx] > tmp:
                    vec[idx + k] = vec[idx]
                    idx -= k
                vec[idx + k] = tmp
        k = kfun(k)
    for i in range(1, len(vec)):
        tmp = vec[i]
        idx = i - 1
        while idx >= 0 and vec[idx] > tmp:
            vec[idx + 1] = vec[idx]
            idx -= 1
        vec[idx + 1] = tmp


# ###################### 交换类排序算法 ######################


# 冒泡排序
# 时间复杂度最坏为O(n^2)，最好O(n)，平均O(n^2)
# 空间复杂度O(1)
# 稳定
def bubbleSort(vec: list):
    for i in range(len(vec) - 1, 0, -1):
        flag = False
        for j in range(0, i):
            if vec[j] > vec[j + 1]:
                vec[j], vec[j + 1] = vec[j + 1], vec[j]
                flag = True
        if not flag:
            return


# 快速排序
# 时间复杂度最好O(nlog2n)，最坏O(n^2)，平均O(nlog2n)，基本操作次数是所有O(nlog2n)算法里最少的
# 空间复杂度O(log2n)
# 不稳定
def quickSort(vec: list, left: int, right: int):
    if left >= right:
        return
    tmp = vec[left]
    low = left
    high = right
    while low < high:
        while low < high and vec[high] > tmp:
            high -= 1
        if low < high:
            vec[low] = vec[high]
            low += 1
        while low < high and vec[low] < tmp:
            low += 1
        if low < high:
            vec[high] = vec[low]
            high -= 1
    vec[low] = tmp
    quickSort(vec, left, low - 1)
    quickSort(vec, low + 1, right)


# ###################### 选择类排序算法 ######################


# 直接选择排序
def selectSort(vec: list):
    for i in range(0, len(vec) - 1):
        idx = i
        for j in range(i + 1, len(vec)):
            if vec[j] < vec[idx]:
                idx = j
        vec[i], vec[idx] = vec[idx], vec[i]


# 在数组的某个范围中调整根节点
def heapAdjust(vec: list, left: int, right: int):
    tmp = vec[left]
    m = left * 2 + 1
    while m <= right:
        if m + 1 <= right and vec[m + 1] > vec[m]:  # 选一个最大的出来
            m += 1
        if vec[m] > tmp:
            vec[left] = vec[m]
            left = m
            m = left * 2 + 1
        else:
            break
    vec[left] = tmp


# 堆排序
# 时间复杂度O(nlog2n)
# 空间复杂度O(1)，在所有时间O(nlog2n)算法中最好
# 不稳定
# 适合关键字多的场景
def heapSort(vec: list):
    for i in range(int((len(vec) - 2) / 2), -1, -1):
        heapAdjust(vec, i, len(vec) - 1)
    for i in range(len(vec) - 1, 0, -1):
        vec[0], vec[i] = vec[i], vec[0]
        heapAdjust(vec, 0, i - 1)


# ###################### 其他排序算法 ######################


# 合并数组的两个有序部分
def merge(vec: list, left: int, mid: int, right: int):
    a = vec[left:mid + 1]
    b = vec[mid + 1:right + 1]
    ai = 0
    bi = 0
    while ai < len(a) and bi < len(b):
        if a[ai] <= b[bi]:
            vec[left] = a[ai]
            ai += 1
        else:
            vec[left] = b[bi]
            bi += 1
        left += 1
    while ai < len(a):
        vec[left] = a[ai]
        ai += 1
        left += 1
    while bi < len(b):
        vec[left] = b[bi]
        bi += 1
        left += 1


# 二路归并排序
# 时间复杂度O(nlog2n)
# 空间复杂度O(n)
# 稳定
def mergeSort(vec: list, left: int, right: int):
    if left >= right:
        return
    mid = int((left + right) / 2)
    mergeSort(vec, left, mid)
    mergeSort(vec, mid + 1, right)
    merge(vec, left, mid, right)


# 针对某个数位上的数进行的排序
def radix(vec: list, k: int):
    qvec = []
    for i in range(10):
        qvec.append(Queue())
    m = 10**(k - 1)
    for i in vec:
        qvec[int(i / m) % 10].put(i)
    vec.clear()
    for q in qvec:
        while not q.empty():
            vec.append(q.get())


# 基数排序 最低位优先
# 貌似只能排正数，如果有负数的话需要额外九个桶
# 时间复杂度O(d*(rd+n))，其中d为关键字位数（跑几轮排序），rd为关键字基的位数（几个桶），n为关键字个数
# 空间复杂度为O(rd)（桶）
def radixSort(vec: list, k: int):
    for i in range(1, k + 1):
        radix(vec, i)


# 双向冒泡排序
# 时间复杂度最好O(n)，前后扫描两遍，最坏O(n^2)，一直扫描到两边指针碰头
# 空间复杂度O(1)，没有随规模变化的额外空间
# 稳定
def dbubbleSort(vec: list):
    left = 0
    right = len(vec) - 1
    while left < right:
        flag = False
        for i in range(left, right):
            if vec[i] > vec[i + 1]:
                vec[i], vec[i + 1] = vec[i + 1], vec[i]
                flag = True
        right -= 1
        for i in range(right, left, -1):
            if vec[i] < vec[i - 1]:
                vec[i], vec[i - 1] = vec[i - 1], vec[i]
                flag = True
        left += 1
        if not flag:
            return


# 计数排序
# 要求待排序数组内每个元素都不相同
# 时间复杂度O(n^2)，因为对于每个元素都要扫描一遍数组
# 空间复杂度O(n)，因为有额外的辅助数组
# 谈不上稳不稳定，因为它根本就没有相同的元素
def calcSort(vec: list, rvec: list):
    for i in vec:
        idx = 0
        for j in vec:
            if j < i:
                idx += 1
        rvec[idx] = i


if __name__ == "__main__":
    length = 10
    randvec = genrandvec(length, 0, 100)
    printvec(randvec, "original vec")

    vec = deepcopy(randvec)
    insertSort(vec)
    printvec(vec, "after insert sort")

    vec = deepcopy(randvec)
    binsertSort(vec)
    printvec(vec, "after binary insert sort")

    vec = deepcopy(randvec)
    shellSort(vec, 5, lambda x: x // 2)
    printvec(vec, "after shell sort")

    vec = deepcopy(randvec)
    bubbleSort(vec)
    printvec(vec, "after bubble sort")

    vec = deepcopy(randvec)
    quickSort(vec, 0, length - 1)
    printvec(vec, "after quick sort")

    vec = deepcopy(randvec)
    selectSort(vec)
    printvec(vec, "after select sort")

    vec = deepcopy(randvec)
    heapSort(vec)
    printvec(vec, "after heap sort")

    vec = deepcopy(randvec)
    mergeSort(vec, 0, length - 1)
    printvec(vec, "after binary merge sort")

    vec = deepcopy(randvec)
    radixSort(vec, 3)
    printvec(vec, "after radix sort")

    vec = deepcopy(randvec)
    dbubbleSort(vec)
    printvec(vec, "after dbubble sort")

    vec = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    rvec = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    calcSort(vec, rvec)
    printvec(rvec, "after calc sort")
