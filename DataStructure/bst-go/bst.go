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
func New[T Ordered](vals ...T) *BSTNode[T] {
	if len(vals) == 0 {
		return nil
	}
	root := &BSTNode[T]{Val: vals[0]}
	for i := 1; i < len(vals); i++ {
		root = root.Insert(vals[i])
	}
	return root
}

// 插入
func (node *BSTNode[T]) Insert(val T) *BSTNode[T] {
	if node == nil {
		return &BSTNode[T]{Val: val}
	}
	if val < node.Val {
		node.Left = node.Left.Insert(val)
	} else if val > node.Val {
		node.Right = node.Right.Insert(val)
	}
	return node
}

// 删除
func (node *BSTNode[T]) Remove(val T) *BSTNode[T] {
	return nil
}

// 查找
func (node *BSTNode[T]) Find(val T) *BSTNode[T] {
	if node == nil {
		return nil
	}
	if val < node.Val {
		return node.Left.Find(val)
	} else if val > node.Val {
		return node.Right.Find(val)
	}
	return node
}
