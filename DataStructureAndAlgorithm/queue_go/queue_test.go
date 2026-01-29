package queuego

import "testing"

func test(t *testing.T, queue Queue[int]) {
	queue.Enqueue(nil)
	if queue.Len() != 0 {
		t.Fatalf("queue size is %d, want %d", queue.Len(), 0)
	}
	if queue.Dequeue() != nil {
		t.Fatalf("queue dequeue is %v, want %v", queue.Dequeue(), nil)
	}
	if queue.Peek() != nil {
		t.Fatalf("queue peek is %v, want %v", queue.Peek(), nil)
	}
	if queue.Tail() != nil {
		t.Fatalf("queue tail is %v, want %v", queue.Tail(), nil)
	}

	for i := 0; i < 10; i++ {
		queue.Enqueue(&i)
		if queue.Len() != uint64(i+1) {
			t.Fatalf("queue size is %d, want %d", queue.Len(), i+1)
		}
		if *queue.Peek() != 0 {
			t.Fatalf("queue peek is %v, want %v", queue.Peek(), 0)
		}
		if *queue.Tail() != i {
			t.Fatalf("queue tail is %v, want %v", queue.Tail(), i)
		}
	}

	for i := 0; i < 10; i++ {
		if *queue.Peek() != i {
			t.Fatalf("queue peek is %v, want %v", queue.Peek(), i)
		}
		if *queue.Tail() != 9 {
			t.Fatalf("queue tail is %v, want %v", queue.Tail(), 9)
		}
		if *queue.Dequeue() != i {
			t.Fatalf("queue dequeue is %v, want %v", queue.Dequeue(), i)
		}
		if queue.Len() != uint64(10-i-1) {
			t.Fatalf("queue size is %d, want %d", queue.Len(), 10-i-1)
		}
	}

	queue.Clear()
	if queue.Len() != 0 {
		t.Fatalf("queue size is %d, want %d", queue.Len(), 0)
	}
	if queue.Dequeue() != nil {
		t.Fatalf("queue dequeue is %v, want %v", queue.Dequeue(), nil)
	}
	if queue.Peek() != nil {
		t.Fatalf("queue peek is %v, want %v", queue.Peek(), nil)
	}
	if queue.Tail() != nil {
		t.Fatalf("queue tail is %v, want %v", queue.Tail(), nil)
	}
}

func TestQueue(t *testing.T) {
	test(t, &QueueSlice[int]{})
	test(t, &QueueLinkedList[int]{})
}
