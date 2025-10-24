package bstgo

import (
	"testing"
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
	return res
}

func TestNew(t *testing.T) {

}

func TestInsert(t *testing.T) {

}

func TestRemove(t *testing.T) {

}

func TestFind(t *testing.T) {

}
