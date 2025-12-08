/*
基于 Golang 的线性表实现
*/

package lineargo

import "errors"

// 线性表接口
type ILinear[T comparable] interface {
	Append(v *T) error
	Insert(i int, v *T) error
	Remove(i int) (*T, error)
	Set(i int, v *T) error
	IndexOf(v *T) (int, error)
	At(i int) (*T, error)
	Length() int
}

// 链表节点
type Node[T comparable] struct {
	Val  *T
	Next *Node[T]
}

// 基于链表实现的线性表
type LinearList[T comparable] struct {
	head   *Node[T] // 头节点
	tail   *Node[T] // 尾节点
	length int      // 链表长度
}

func (li *LinearList[T]) Append(v *T) error {
	node := Node[T]{Val: v}
	li.length++
	if li.head == nil {
		li.head = &node
		li.tail = &node
	} else {
		li.tail.Next = &node
		li.tail = &node
	}
	return nil
}

func (li *LinearList[T]) Insert(i int, v *T) error {
	if i < 0 || i > li.length {
		return errors.New("index out of range")
	}

	li.length++
	if i == 0 {
		li.head = &Node[T]{Val: v, Next: li.head}
	} else if i == li.length {
		li.Append(v)
	} else {
		node := li.head
		for j := 0; j < i-1; j++ {
			node = node.Next
		}
		node.Next = &Node[T]{Val: v, Next: node.Next}
	}

	return nil
}

func (li *LinearList[T]) Remove(i int) (*T, error) {
	if i < 0 || i >= li.length {
		return nil, errors.New("index out of range")
	}

	li.length--
	if i == 0 {
		node := li.head
		li.head = li.head.Next
		return node.Val, nil
	} else {
		node := li.head
		for j := 0; j < i-1; j++ {
			node = node.Next
		}
		node.Next = node.Next.Next
		return node.Next.Val, nil
	}
}

func (li *LinearList[T]) Set(i int, v *T) error {
	if i < 0 || i >= li.length {
		return errors.New("index out of range")
	}

	node := li.head
	for j := 0; j < i; j++ {
		node = node.Next
	}
	node.Val = v
	return nil
}

func (li *LinearList[T]) IndexOf(v *T) (int, error) {
	index := 0
	for node := li.head; node != nil; node = node.Next {
		if node.Val == v {
			return index, nil
		}
		index++
	}
	return -1, errors.New("not found")
}

func (li *LinearList[T]) At(i int) (*T, error) {
	if i < 0 || i >= li.length {
		return nil, errors.New("index out of range")
	}

	node := li.head
	for j := 0; j < i; j++ {
		node = node.Next
	}
	return node.Val, nil
}

func (li *LinearList[T]) Length() int {
	return li.length
}

// 基于可变数组实现的线性表
type LinearArray[T comparable] struct {
	vec []T
}

func (li *LinearArray[T]) Append(v *T) error {

}

func (li *LinearArray[T]) Insert(i int, v *T) error {
}

func (li *LinearArray[T]) Remove(i int) (*T, error) {
}

func (li *LinearArray[T]) Set(i int, v *T) error {
}

func (li *LinearArray[T]) IndexOf(v *T) (int, error) {
}

func (li *LinearArray[T]) At(i int) (*T, error) {

}

func (li *LinearArray[T]) Length() int {
	return len(li.vec)
}

// 基于不可变数组实现的线性表
type LinearImmutableArray[T comparable] struct {
	arr  [1]T
	cap  int
	size int
}

func (li *LinearImmutableArray[T]) Append(v *T) error {

}

func (li *LinearImmutableArray[T]) Insert(i int, v *T) error {
}

func (li *LinearImmutableArray[T]) Remove(i int) (*T, error) {
}

func (li *LinearImmutableArray[T]) Set(i int, v *T) error {
}

func (li *LinearImmutableArray[T]) IndexOf(v *T) (int, error) {
}

func (li *LinearImmutableArray[T]) At(i int) (*T, error) {

}

func (li *LinearImmutableArray[T]) Length() int {
	return li.size
}
