package stackgo

import "testing"

func test(t *testing.T, s Stack[int]) {

	for i := 0; i < 10; i++ {
		s.Push(&i)
		if s.Size() != uint64(i+1) {
			t.Fatal("size is not correct")
		}
	}

	for i := 9; i >= 0; i-- {
		if *s.Top() != i {
			t.Fatal("top is not correct")
		}
		if s.Size() != uint64(i+1) {
			t.Fatal("size is not correct")
		}
		if *s.Pop() != i {
			t.Fatal("pop is not correct")
		}
	}

	if s.Pop() != nil {
		t.Fatal("pop is not correct")
	}
	if s.Top() != nil {
		t.Fatal("top is not correct")
	}
	if s.Size() != 0 {
		t.Fatal("size is not correct")
	}

	for i := 0; i < 10; i++ {
		s.Push(&i)
	}
	if s.Size() != 10 {
		t.Fatal("size is not correct")
	}
	s.Clear()
	if s.Size() != 0 {
		t.Fatal("size is not correct")
	}
}

func TestStack(t *testing.T) {
	stackSlice := StackSlice[int]{}
	test(t, &stackSlice)

	stackLinkedList := StackLinkedList[int]{}
	test(t, &stackLinkedList)
}
