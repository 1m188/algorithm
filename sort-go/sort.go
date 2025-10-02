/*

一个用golang编写的排序算法文件

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
