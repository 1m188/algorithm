package bstgo

import (
	"math/rand"
	"slices"
	"testing"
	"time"
)

// 升序返回 bst 里的数值
func find[T Ordered](root *BSTNode[T]) []T {
	res := make([]T, 0)
	var mid func(*BSTNode[T])
	mid = func(b *BSTNode[T]) {
		if b == nil {
			return
		}
		mid(b.Left)
		res = append(res, b.Val)
		mid(b.Right)
	}
	mid(root)
	return res
}

// 生成随机整数序列：长度为length，元素范围 [min, max)
func generateRandomInts(length, min, max int) []int {
	if length <= 0 || //
		max <= min || //
		length > max-min { // 保证长度小于范围，不出现重复值
		panic("invalid parameters")
	}

	rangeSize := max - min
	nums := make([]int, rangeSize)
	for i := range rangeSize {
		nums[i] = min + i
	}

	// 设置种子：用当前时间的纳秒数，确保每次运行序列不同
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	r.Shuffle(len(nums), func(i, j int) { // 打乱
		nums[i], nums[j] = nums[j], nums[i]
	})

	return nums[:length]
}

func TestNew(t *testing.T) {
	insertInts := generateRandomInts(10, 0, 100)
	bst := New(insertInts...)
	mid := find(bst)
	slices.Sort(insertInts)
	if !slices.Equal(mid, insertInts) {
		t.Fatalf("mid = %v, want %v", mid, insertInts)
	}
}

func TestInsert(t *testing.T) {
	insertInts := generateRandomInts(10, 0, 100)
	bst := New(insertInts...)
	for i := range 100 {
		bst.Insert(i)
		insertInts = append(insertInts, i)
		mid := find(bst)
		slices.Sort(insertInts)
		if !slices.Equal(mid, insertInts) {
			t.Fatalf("mid = %v, want %v", mid, insertInts)
		}
	}
}

func TestRemove(t *testing.T) {
	insertInts := generateRandomInts(50, 0, 100)
	bst := New(insertInts...)

	compare := func(bst *BSTNode[int], insertInts []int) {
		mid := find(bst)
		insertInts_copy := make([]int, len(insertInts))
		copy(insertInts_copy, insertInts)
		slices.Sort(insertInts_copy)
		if !slices.Equal(mid, insertInts_copy) {
			t.Fatalf("mid = %v, want %v", mid, insertInts_copy)
		}
	}

	// 删除叶子节点
	x := slices.Min(insertInts)
	bst.Remove(x)
	insertInts = slices.DeleteFunc(insertInts, func(e int) bool { return e == x })
	compare(bst, insertInts)

	x = slices.Max(insertInts)
	bst.Remove(x)
	insertInts = slices.DeleteFunc(insertInts, func(e int) bool { return e == x })
	compare(bst, insertInts)

	// 删除同时具有左右分支节点
	insertInts = []int{5, 1, 2, 3, 4, 6, 7, 8, 9, 10}
	bst = New(insertInts...)
	x = 5
	bst.Remove(x)
	insertInts = slices.DeleteFunc(insertInts, func(e int) bool { return e == x })
	compare(bst, insertInts)

	// 删除只具有单分支节点
	insertInts = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	bst = New(insertInts...)
	x = 9
	bst.Remove(x)
	insertInts = slices.DeleteFunc(insertInts, func(e int) bool { return e == x })
	compare(bst, insertInts)
}

func TestFind(t *testing.T) {
	insertInts := generateRandomInts(10, 0, 100)
	bst := New(insertInts...)
	for _, x := range insertInts {
		if bst.Find(x) == nil {
			t.Fatalf("Find(%d) = false, want true", x)
		}
	}
}
