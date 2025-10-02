package sort_go

import (
	"testing"
)

func TestInsertSort(t *testing.T) {
	arr := []int{5, 4, 3, 2, 1}
	target := []int{1, 2, 3, 4, 5}
	InsertSort(arr, func(i, j int) bool { return arr[i] < arr[j] })
	f := true
	for i := range arr {
		if arr[i] != target[i] {
			f = false
		}
	}
	if !f {
		t.Errorf("InsertSort failed, arr = %v, target = %v", arr, target)
	}

	arr = []int{10, 1, 9, 2, 4, 5, 8, 6, 3, 7}
	target = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	InsertSort(arr, func(i, j int) bool { return arr[i] < arr[j] })
	f = true
	for i := range arr {
		if arr[i] != target[i] {
			f = false
		}
	}
	if !f {
		t.Errorf("InsertSort failed, arr = %v, target = %v", arr, target)
	}

	arr = []int{}
	target = []int{}
	InsertSort(arr, func(i, j int) bool { return arr[i] < arr[j] })
	if len(arr) != 0 {
		t.Errorf("InsertSort failed, arr = %v, target = %v", arr, target)
	}
}
