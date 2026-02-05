"""
基于 Python 实现的常用查找算法
"""


def sequential_search(arr: list, target) -> int:
    """
    线性查找算法

    :param arr: 待查找数组
    :param target: 待查找元素
    :return: 元素索引，如果不存在则返回 -1
    """

    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1


def binary_search(arr: list, target) -> int:
    """
    二分查找算法

    :param arr: 待查找数组（升序有序）
    :param target: 待查找元素
    :return: 元素索引，如果不存在则返回 -1
    """

    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1


if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    assert sequential_search(arr, 1) == 0
    assert sequential_search(arr, 5) == 4
    assert sequential_search(arr, 10) == 9
    assert sequential_search(arr, 11) == -1

    arr = list(reversed(arr))
    assert sequential_search(arr, 10) == 0
    assert sequential_search(arr, 1) == 9
    assert sequential_search(arr, 5) == 5
    assert sequential_search(arr, 11) == -1

    arr = [1]
    assert sequential_search(arr, 1) == 0
    assert sequential_search(arr, 2) == -1

    arr = []
    assert sequential_search(arr, 1) == -1

    arr = [i for i in range(1, 11)]
    assert binary_search(arr, 1) == 0
    assert binary_search(arr, 5) == 4
    assert binary_search(arr, 10) == 9
    assert binary_search(arr, 11) == -1

    arr = [i for i in range(1, 11, 3)]
    assert binary_search(arr, 1) == 0
    assert binary_search(arr, 10) == 3
    assert binary_search(arr, 5) == -1

    arr = [1]
    assert binary_search(arr, 1) == 0
    assert binary_search(arr, 2) == -1

    arr = []
    assert binary_search(arr, 1) == -1

    print("All tests passed!")
