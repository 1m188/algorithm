package bstgo

import (
	"math/rand"
	"slices"
	"testing"
	"time"
)

// 升序返回 bst 里的数值
func find[T comparable](root *BSTNode[T]) []T {
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

}

func TestFind(t *testing.T) {

}
