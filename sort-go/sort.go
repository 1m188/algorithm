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
