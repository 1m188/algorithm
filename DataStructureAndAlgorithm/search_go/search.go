/* 查找算法

Golang 实现 */

package searchgo

import "cmp"

// 顺序查找
func LinearSearch[T comparable](arr []T, target T) int {
	for i, v := range arr {
		if v == target {
			return i
		}
	}
	return -1
}

// 二分查找
func BinarySearch[T cmp.Ordered](arr []T, target T) int {
	left, right := 0, len(arr)-1
	for left <= right {
		mid := (left + right) / 2
		if arr[mid] == target {
			return mid
		} else if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return -1
}
