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
