/*
基于 Golang 的栈实现
*/

package stackgo

// 栈接口
type Stack[T any] interface {
	Push(v *T)    // 入栈
	Pop() *T      // 出栈
	Top() *T      // 栈顶元素
	Size() uint64 // 栈大小
	Clear()       // 清空栈
}

// 基于切片的栈实现
type StackSlice[T any] struct {
	data []T
}

func (s *StackSlice[T]) Push(v *T) {
	s.data = append(s.data, *v)
}

func (s *StackSlice[T]) Pop() *T {
	if len(s.data) == 0 {
		return nil
	} else {
		v := s.data[len(s.data)-1]
		s.data = s.data[:len(s.data)-1]
		return &v
	}
}

func (s *StackSlice[T]) Top() *T {
	if len(s.data) == 0 {
		return nil
	} else {
		return &s.data[len(s.data)-1]
	}
}

func (s *StackSlice[T]) Size() uint64 {
	return uint64(len(s.data))
}

func (s *StackSlice[T]) Clear() {
	s.data = []T{}
}

// 链表节点
type Node[T any] struct {
	Val  T        // 节点值
	Next *Node[T] // 下一个节点
}

// 基于链表的栈实现
type StackLinkedList[T any] struct {
	TopNode *Node[T] // 栈顶节点
	Len     uint64   // 栈大小
}

func (s *StackLinkedList[T]) Push(v *T) {

}

func (s *StackLinkedList[T]) Pop() *T {

}

func (s *StackLinkedList[T]) Top() *T {

}

func (s *StackLinkedList[T]) Size() uint64 {

}

func (s *StackLinkedList[T]) Clear() {

}
