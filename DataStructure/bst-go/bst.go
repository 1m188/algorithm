/*

二叉查找树

*/

package bstgo

// 二叉查找树节点定义
type BSTNode[T comparable] struct {
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
