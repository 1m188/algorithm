package btreego

import (
	"fmt"
	"runtime/debug"
	"testing"
)

// 断言函数
func assert(t *testing.T, condition bool, message string) {
	if !condition {
		t.Fatalf("%v\n\n%v", message, string(debug.Stack()))
	}
}

// 判断两个切片是否相等
func arrEq(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i, v := range a {
		if v != b[i] {
			return false
		}
	}
	return true
}

// 测试先序遍历
func testPreOrder(t *testing.T, preOrder func(root *Node[int], doSomething func(*Node[int]))) {

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Right = &Node[int]{3, nil, nil}
		root.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Right = &Node[int]{5, nil, nil}
		preOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1, 2, 4, 5, 3}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Right = &Node[int]{3, nil, nil}
		root.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Right = &Node[int]{5, nil, nil}
		root.Right.Left = &Node[int]{6, nil, nil}
		root.Right.Right = &Node[int]{7, nil, nil}
		preOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1, 2, 4, 5, 3, 6, 7}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Left.Left = &Node[int]{3, nil, nil}
		root.Left.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Left.Left.Left = &Node[int]{5, nil, nil}
		root.Left.Left.Left.Left.Left = &Node[int]{6, nil, nil}
		preOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1, 2, 3, 4, 5, 6}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Left.Right = &Node[int]{3, nil, nil}
		root.Left.Right.Left = &Node[int]{4, nil, nil}
		root.Left.Right.Left.Right = &Node[int]{5, nil, nil}
		preOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1, 2, 3, 4, 5}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		preOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		var root *Node[int] = nil
		preOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

}

// 测试中序遍历
func testInOrder(t *testing.T, inOrder func(root *Node[int], doSomething func(*Node[int]))) {

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Right = &Node[int]{3, nil, nil}
		root.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Right = &Node[int]{5, nil, nil}
		inOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{4, 2, 5, 1, 3}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Right = &Node[int]{3, nil, nil}
		root.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Right = &Node[int]{5, nil, nil}
		root.Right.Left = &Node[int]{6, nil, nil}
		root.Right.Right = &Node[int]{7, nil, nil}
		inOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{4, 2, 5, 1, 6, 3, 7}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Left.Left = &Node[int]{3, nil, nil}
		root.Left.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Left.Left.Left = &Node[int]{5, nil, nil}
		root.Left.Left.Left.Left.Left = &Node[int]{6, nil, nil}
		inOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{6, 5, 4, 3, 2, 1}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Left.Right = &Node[int]{3, nil, nil}
		root.Left.Right.Left = &Node[int]{4, nil, nil}
		root.Left.Right.Left.Right = &Node[int]{5, nil, nil}
		inOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{2, 4, 5, 3, 1}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		inOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		var root *Node[int] = nil
		inOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

}

// 测试后序遍历
func testPostOrder(t *testing.T, postOrder func(root *Node[int], doSomething func(*Node[int]))) {

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Right = &Node[int]{3, nil, nil}
		root.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Right = &Node[int]{5, nil, nil}
		postOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{4, 5, 2, 3, 1}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Right = &Node[int]{3, nil, nil}
		root.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Right = &Node[int]{5, nil, nil}
		root.Right.Left = &Node[int]{6, nil, nil}
		root.Right.Right = &Node[int]{7, nil, nil}
		postOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{4, 5, 2, 6, 7, 3, 1}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Left.Left = &Node[int]{3, nil, nil}
		root.Left.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Left.Left.Left = &Node[int]{5, nil, nil}
		root.Left.Left.Left.Left.Left = &Node[int]{6, nil, nil}
		postOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{6, 5, 4, 3, 2, 1}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Left.Right = &Node[int]{3, nil, nil}
		root.Left.Right.Left = &Node[int]{4, nil, nil}
		root.Left.Right.Left.Right = &Node[int]{5, nil, nil}
		postOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{5, 4, 3, 2, 1}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		postOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		var root *Node[int] = nil
		postOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

}

// 测试层序遍历
func testLevelOrder(t *testing.T, levelOrder func(root *Node[int], doSomething func(*Node[int]))) {

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Right = &Node[int]{3, nil, nil}
		root.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Right = &Node[int]{5, nil, nil}
		levelOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1, 2, 3, 4, 5}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Right = &Node[int]{3, nil, nil}
		root.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Right = &Node[int]{5, nil, nil}
		root.Right.Left = &Node[int]{6, nil, nil}
		root.Right.Right = &Node[int]{7, nil, nil}
		levelOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1, 2, 3, 4, 5, 6, 7}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Left.Left = &Node[int]{3, nil, nil}
		root.Left.Left.Left = &Node[int]{4, nil, nil}
		root.Left.Left.Left.Left = &Node[int]{5, nil, nil}
		root.Left.Left.Left.Left.Left = &Node[int]{6, nil, nil}
		levelOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1, 2, 3, 4, 5, 6}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		root.Left = &Node[int]{2, nil, nil}
		root.Left.Right = &Node[int]{3, nil, nil}
		root.Left.Right.Left = &Node[int]{4, nil, nil}
		root.Left.Right.Left.Right = &Node[int]{5, nil, nil}
		levelOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1, 2, 3, 4, 5}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		root := &Node[int]{1, nil, nil}
		levelOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{1}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

	{
		arr := make([]int, 0)
		var root *Node[int] = nil
		levelOrder(root, func(node *Node[int]) {
			arr = append(arr, node.Val)
		})
		res := []int{}
		assert(t, arrEq(arr, res), fmt.Sprintf("arr: %v, expect: %v", arr, res))
	}

}

// 测试函数
func TestBTree(t *testing.T) {
	// 测试先序遍历
	testPreOrder(t, preOrder)
	testPreOrder(t, preOrderNoRecursion)

	// 测试中序遍历
	testInOrder(t, inOrder)
	testInOrder(t, inOrderNoRecursion)

	// 测试后序遍历
	testPostOrder(t, postOrder)
	testPostOrder(t, postOrderNoRecursion)

	// 测试层序遍历
	testLevelOrder(t, levelOrder)
}
