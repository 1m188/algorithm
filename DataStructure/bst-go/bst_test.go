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
	if length <= 0 || max <= min {
		return []int{}
	}

	// 设置种子：用当前时间的纳秒数，确保每次运行序列不同
	r := rand.New(rand.NewSource(time.Now().UnixNano()))

	seq := make([]int, length)
	for i := range length {
		// 生成 [min, max) 范围的随机数
		seq[i] = min + r.Intn(max-min)
	}
	return seq
}

func TestNew(t *testing.T) {
	insertInts := generateRandomInts(10, 0, 100)
	bst := New(insertInts...)
	mid := find(bst)
	slices.Sort(insertInts)
	if len(mid) != len(insertInts) {
		t.Errorf("len(mid) = %d, want %d", len(mid), len(insertInts))
	}
	for i := range mid {
		if mid[i] != insertInts[i] {
			t.Errorf("mid[%d] = %d, want %d", i, mid[i], insertInts[i])
		}
	}
}

func TestInsert(t *testing.T) {

}

func TestRemove(t *testing.T) {

}

func TestFind(t *testing.T) {

}
