/*

一个用golang编写的排序算法文件

date: 202510

1. 插入排序
2. 希尔排序
3. 选择排序
4. 冒泡排序
5. 快速排序
6. 归并排序
7. 堆排序
8. 计数排序

*/

package sort_go

// 插入排序
func InsertSort[T any](arr []T, less func(i, j int) bool) {
	for i := 1; i < len(arr); i++ {
		for j := i; j > 0 && less(j, j-1); j-- {
			arr[j], arr[j-1] = arr[j-1], arr[j]
		}
	}
}

// 希尔排序
func ShellSort[T any](arr []T, less func(i, j int) bool) {
	for gap := len(arr) / 2; gap > 0; gap /= 2 {
		for i := gap; i < len(arr); i++ {
			for j := i; j >= gap && less(j, j-gap); j -= gap {
				arr[j], arr[j-gap] = arr[j-gap], arr[j]
			}
		}
	}
}

// 选择排序
func SelectSort[T any](arr []T, less func(i, j int) bool) {
	for i := range arr {
		min := i
		for j := i + 1; j < len(arr); j++ {
			if less(j, min) {
				min = j
			}
		}
		arr[i], arr[min] = arr[min], arr[i]
	}
}

// 冒泡排序
func BubbleSort[T any](arr []T, less func(i, j int) bool) {
	for i := len(arr) - 1; i > 0; i-- {
		f := false
		for j := 0; j < i; j++ {
			if less(j+1, j) {
				f = true
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
		if !f {
			break
		}
	}
}

// 快速排序
func QuickSort[T any](arr []T, less func(i, j int) bool) {
	var quickSort func(int, int)
	quickSort = func(left, right int) {
		if left >= right {
			return
		}
		start, end := left, right
		for start < end {
			for start < end && less(start, end) {
				end--
			}
			if start < end {
				arr[start], arr[end] = arr[end], arr[start]
				start++
			}
			for start < end && less(start, end) {
				start++
			}
			if start < end {
				arr[start], arr[end] = arr[end], arr[start]
				end--
			}
		}
		quickSort(left, start-1)
		quickSort(start+1, right)
	}

	quickSort(0, len(arr)-1)
}

// 归并排序
func MergeSort[T any](arr []T, less func(i, j int) bool) {
	mergeSort := func(left, mid, right int) {
		li := make([]T, 0, right-left+1)
		idx1, idx2 := left, mid+1
		for idx1 <= mid && idx2 <= right {
			if less(idx1, idx2) {
				li = append(li, arr[idx1])
				idx1++
			} else {
				li = append(li, arr[idx2])
				idx2++
			}
		}
		for idx1 <= mid {
			li = append(li, arr[idx1])
			idx1++
		}
		for idx2 <= right {
			li = append(li, arr[idx2])
			idx2++
		}

		for i := 0; i < len(li); i++ {
			arr[left+i] = li[i]
		}
	}

	var merge func(int, int)
	merge = func(left, right int) {
		if left >= right {
			return
		}
		mid := (left + right) / 2
		merge(left, mid)
		merge(mid+1, right)
		mergeSort(left, mid, right)
	}

	merge(0, len(arr)-1)
}

// 堆排序
func HeapSort[T any](arr []T, less func(i, j int) bool) {
	adjust := func(index int, end int) {
		for index < end {
			idx := index
			left := index*2 + 1
			right := index*2 + 2
			if left <= end && less(idx, left) {
				idx = left
			}
			if right <= end && less(idx, right) {
				idx = right
			}
			if idx == index {
				break
			}
			arr[index], arr[idx] = arr[idx], arr[index]
			index = idx
		}
	}

	build := func() {
		for i := (len(arr) - 1 - 1) / 2; i >= 0; i-- {
			adjust(i, len(arr)-1)
		}
	}

	build()
	for i := len(arr) - 1; i >= 0; i-- {
		arr[0], arr[i] = arr[i], arr[0]
		adjust(0, i-1)
	}
}

// 计数排序
func CountingSort[T int |
	int8 |
	int16 |
	int32 |
	int64 |
	uint |
	uint8 |
	uint16 |
	uint32 |
	uint64](arr []T, less func(i, j int) bool) {

	if len(arr) == 0 {
		return
	}

	minV, maxV := arr[0], arr[0]
	for _, v := range arr {
		if v < minV {
			minV = v
		}
		if v > maxV {
			maxV = v
		}
	}

	offset := minV
	li := make([][]T, maxV-minV+1)
	for i := range li {
		li[i] = make([]T, 0, len(arr))
	}
	for _, v := range arr {
		li[v-offset] = append(li[v-offset], v)
	}

	idx := 0
	for _, l := range li {
		for _, v := range l {
			arr[idx] = v
			idx++
		}
	}
}
