/*

二叉查找树

*/

package bstgo

type Ordered interface {
	~int | ~int8 | ~int16 | ~int32 | ~int64 |
		~uint | ~uint8 | ~uint16 | ~uint32 | ~uint64 |
		~float32 | ~float64 |
		~string
}

// 二叉查找树节点定义
type BSTNode[T Ordered] struct {
	Left  *BSTNode[T] // 左子树
	Right *BSTNode[T] // 右子树
	Val   T           // 节点值
}

// 构建
func New[T comparable](vals ...T) *BSTNode[T] {
	return nil
}

// 插入
func (node *BSTNode[T]) Insert(val T) *BSTNode[T] {
	return nil
}

// 删除
func (node *BSTNode[T]) Remove(val T) *BSTNode[T] {
	return nil
}

// 查找
func (node *BSTNode[T]) Find(val T) *BSTNode[T] {
	return nil
}
