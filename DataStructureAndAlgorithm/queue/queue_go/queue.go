/*
基于 Golang 的队列实现
*/

package queuego

// Queue 队列接口
type Queue[T any] interface {
	Enqueue(item *T) // 入队
	Dequeue() *T     // 出队，队列为空返回 nil
	Peek() *T        // 查看队首元素，队列为空返回 nil
	Tail() *T        // 查看队尾元素，队列为空返回 nil
	Len() uint64     // 队列中元素数量
	Clear()          // 清空队列
}

// 基于切片的队列实现
type QueueSlice[T any] struct {
	data []*T
}

func (q *QueueSlice[T]) Enqueue(item *T) {
	if item == nil {
		return
	}
	q.data = append(q.data, item)
}

func (q *QueueSlice[T]) Dequeue() *T {
	if len(q.data) == 0 {
		return nil
	}
	item := q.data[0]
	q.data = q.data[1:]
	return item
}

func (q *QueueSlice[T]) Peek() *T {
	if len(q.data) == 0 {
		return nil
	}
	return q.data[0]
}

func (q *QueueSlice[T]) Tail() *T {
	if len(q.data) == 0 {
		return nil
	}
	return q.data[len(q.data)-1]
}

func (q *QueueSlice[T]) Len() uint64 {
	return uint64(len(q.data))
}

func (q *QueueSlice[T]) Clear() {
	q.data = q.data[:0]
}

// 链表节点
type Node[T any] struct {
	data *T
	next *Node[T]
}

// 基于链表的队列实现
type QueueLinkedList[T any] struct {
	head *Node[T]
	tail *Node[T]
	len  uint64
}

func (q *QueueLinkedList[T]) Enqueue(item *T) {
	if item == nil {
		return
	}
	if q.head == nil {
		q.head = &Node[T]{data: item}
		q.tail = q.head
	} else {
		q.tail.next = &Node[T]{data: item}
		q.tail = q.tail.next
	}
	q.len++
}

func (q *QueueLinkedList[T]) Dequeue() *T {
	if q.head == nil {
		return nil
	}
	item := q.head.data
	q.head = q.head.next
	if q.head == nil {
		q.tail = nil
	}
	q.len--
	return item
}

func (q *QueueLinkedList[T]) Peek() *T {
	if q.head == nil {
		return nil
	}
	return q.head.data
}

func (q *QueueLinkedList[T]) Tail() *T {
	if q.tail == nil {
		return nil
	}
	return q.tail.data
}

func (q *QueueLinkedList[T]) Len() uint64 {
	return q.len
}

func (q *QueueLinkedList[T]) Clear() {
	q.head = nil
	q.tail = nil
	q.len = 0
}
