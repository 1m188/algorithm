package sort_go

import (
	"testing"
)

func testSort(t *testing.T, sortFunc func([]int, func(i, j int) bool)) {
	arr := []int{5, 4, 3, 2, 1}
	target := []int{1, 2, 3, 4, 5}
	sortFunc(arr, func(i, j int) bool { return arr[i] < arr[j] })
	for i := range arr {
		if arr[i] != target[i] {
			t.Errorf("sort failed, arr = %v, target = %v", arr, target)
			break
		}
	}

	arr = []int{10, 1, 9, 2, 4, 5, 8, 6, 3, 7}
	target = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	sortFunc(arr, func(i, j int) bool { return arr[i] < arr[j] })
	for i := range arr {
		if arr[i] != target[i] {
			t.Errorf("sort failed, arr = %v, target = %v", arr, target)
			break
		}
	}

	arr = []int{10, 10, 10, 10, 5, 5, 8, 8, 8, 1}
	target = []int{1, 5, 5, 8, 8, 8, 10, 10, 10, 10}
	sortFunc(arr, func(i, j int) bool { return arr[i] < arr[j] })
	for i := range arr {
		if arr[i] != target[i] {
			t.Errorf("sort failed, arr = %v, target = %v", arr, target)
			break
		}
	}

	arr = []int{}
	target = []int{}
	sortFunc(arr, func(i, j int) bool { return arr[i] < arr[j] })
	if len(arr) != 0 {
		t.Errorf("sort failed, arr = %v, target = %v", arr, target)
	}
}

func TestInsertSort(t *testing.T) { testSort(t, InsertSort) }
func TestShellSort(t *testing.T)  { testSort(t, ShellSort) }
func TestSelectSort(t *testing.T) { testSort(t, SelectSort) }
func TestBubbleSort(t *testing.T) { testSort(t, BubbleSort) }
func TestQuickSort(t *testing.T)  { testSort(t, QuickSort) }
func TestMergeSort(t *testing.T)  { testSort(t, MergeSort) }
