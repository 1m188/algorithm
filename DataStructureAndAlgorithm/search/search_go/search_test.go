package searchgo

import "testing"

func TestSearch(t *testing.T) {
	arr := []int{10, 1, 9, 2, 3, 8, 4, 7, 5, 6}
	index := LinearSearch(arr, 10)
	if index != 0 {
		t.Fatalf("LinearSearch failed, expected 0, got %d", index)
	}
	index = LinearSearch(arr, 6)
	if index != 9 {
		t.Fatalf("LinearSearch failed, expected 9, got %d", index)
	}
	index = LinearSearch(arr, 8)
	if index != 5 {
		t.Fatalf("LinearSearch failed, expected 5, got %d", index)
	}
	index = LinearSearch(arr, 100)
	if index != -1 {
		t.Fatalf("LinearSearch failed, expected -1, got %d", index)
	}

	arr = []int{1}
	index = LinearSearch(arr, 1)
	if index != 0 {
		t.Fatalf("LinearSearch failed, expected 0, got %d", index)
	}
	index = LinearSearch(arr, 2)
	if index != -1 {
		t.Fatalf("LinearSearch failed, expected -1, got %d", index)
	}

	arr = []int{}
	index = LinearSearch(arr, 1)
	if index != -1 {
		t.Fatalf("LinearSearch failed, expected -1, got %d", index)
	}

	arr = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	index = BinarySearch(arr, 10)
	if index != 9 {
		t.Fatalf("BinarySearch failed, expected 9, got %d", index)
	}
	index = BinarySearch(arr, 6)
	if index != 5 {
		t.Fatalf("BinarySearch failed, expected 5, got %d", index)
	}
	index = BinarySearch(arr, 8)
	if index != 7 {
		t.Fatalf("BinarySearch failed, expected 7, got %d", index)
	}
	index = BinarySearch(arr, 100)
	if index != -1 {
		t.Fatalf("BinarySearch failed, expected -1, got %d", index)
	}

	arr = []int{1}
	index = BinarySearch(arr, 1)
	if index != 0 {
		t.Fatalf("BinarySearch failed, expected 0, got %d", index)
	}
	index = BinarySearch(arr, 2)
	if index != -1 {
		t.Fatalf("BinarySearch failed, expected -1, got %d", index)
	}

	arr = []int{}
	index = BinarySearch(arr, 1)
	if index != -1 {
		t.Fatalf("BinarySearch failed, expected -1, got %d", index)
	}
}
