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
