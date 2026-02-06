/*
基于 golang 实现的二叉树及其常用算法
*/

package btreego

import "container/list"

// 二叉树节点
type Node[T any] struct {
	Val   T        // 节点存储数据
	Left  *Node[T] // 左子节点
	Right *Node[T] // 右子节点
}

// 先序遍历
func preOrder[T any](root *Node[T], doSomething func(*Node[T])) {
	if root == nil {
		return
	}
	doSomething(root)
	preOrder(root.Left, doSomething)
	preOrder(root.Right, doSomething)
}

// 先序遍历(非递归)
func preOrderNoRecursion[T any](root *Node[T], doSomething func(*Node[T])) {
	if root == nil {
		return
	}
	stack := make([]*Node[T], 0)
	stack = append(stack, root)
	for len(stack) > 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		doSomething(node)
		if node.Right != nil {
			stack = append(stack, node.Right)
		}
		if node.Left != nil {
			stack = append(stack, node.Left)
		}
	}
}

// 中序遍历
func inOrder[T any](root *Node[T], doSomething func(*Node[T])) {
	if root == nil {
		return
	}
	inOrder(root.Left, doSomething)
	doSomething(root)
	inOrder(root.Right, doSomething)
}

// 中序遍历(非递归)
func inOrderNoRecursion[T any](root *Node[T], doSomething func(*Node[T])) {
	if root == nil {
		return
	}
	stack := make([]*Node[T], 0)
	cur := root
	for cur != nil || len(stack) > 0 {
		for cur != nil {
			stack = append(stack, cur)
			cur = cur.Left
		}
		cur = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		doSomething(cur)
		cur = cur.Right
	}
}

// 后序遍历
func postOrder[T any](root *Node[T], doSomething func(*Node[T])) {
	if root == nil {
		return
	}
	postOrder(root.Left, doSomething)
	postOrder(root.Right, doSomething)
	doSomething(root)
}

// 后序遍历(非递归)
func postOrderNoRecursion[T any](root *Node[T], doSomething func(*Node[T])) {
	if root == nil {
		return
	}
	stack := make([]*Node[T], 0)
	stack = append(stack, root)
	stack2 := make([]*Node[T], 0)
	for len(stack) > 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		stack2 = append(stack2, node)
		if node.Left != nil {
			stack = append(stack, node.Left)
		}
		if node.Right != nil {
			stack = append(stack, node.Right)
		}
	}
	for len(stack2) > 0 {
		doSomething(stack2[len(stack2)-1])
		stack2 = stack2[:len(stack2)-1]
	}
}

// 层序遍历
func levelOrder[T any](root *Node[T], doSomething func(*Node[T])) {
	if root == nil {
		return
	}
	queue := list.New()
	queue.PushBack(root)
	for queue.Len() > 0 {
		node := queue.Front()
		queue.Remove(node)
		doSomething(node.Value.(*Node[T]))
		if node.Value.(*Node[T]).Left != nil {
			queue.PushBack(node.Value.(*Node[T]).Left)
		}
		if node.Value.(*Node[T]).Right != nil {
			queue.PushBack(node.Value.(*Node[T]).Right)
		}
	}
}
