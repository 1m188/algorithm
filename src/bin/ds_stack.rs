/*
基于 Rust 的栈实现
*/

// 栈接口
trait Stack<T> {
    fn push(&mut self, item: T);
    fn pop(&mut self) -> Option<T>;
    fn top(&self) -> Option<&T>;
    fn size(&self) -> usize;
    fn clear(&mut self);
}

// 单向链表节点定义
struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

// 基于单向链表的栈实现
struct StackLinkList<T> {
    top: Option<Box<Node<T>>>,
    size: usize,
}

impl<T> StackLinkList<T> {
    fn new() -> Self {
        StackLinkList { top: None, size: 0 }
    }
}

impl<T> Stack<T> for StackLinkList<T> {
    fn push(&mut self, item: T) {
        let mut node = Some(Box::new(Node {
            data: item,
            next: None,
        }));
        node.as_mut().unwrap().next = self.top.take();
        self.top = node.take();
        self.size += 1;
    }

    fn pop(&mut self) -> Option<T> {
        if self.top.is_none() {
            return None;
        }
        let mut node = self.top.take();
        self.top = node.as_mut().unwrap().next.take();
        self.size -= 1;
        Some(node.unwrap().data)
    }

    fn top(&self) -> Option<&T> {
        match self.size {
            0 => None,
            _ => Some(&self.top.as_ref().unwrap().data),
        }
    }

    fn size(&self) -> usize {
        self.size
    }

    fn clear(&mut self) {
        self.top = None;
        self.size = 0;
    }
}

// 基于数组的栈实现
struct StackArray<T> {
    data: Box<[T]>,
    size: usize,
    cap: usize,
}

impl<T: Default> StackArray<T> {
    fn new() -> Self {
        StackArray {
            data: Box::new([T::default(); 1]),
            size: 0,
            cap: 1,
        }
    }
}

impl<T: Default + Clone> Stack<T> for StackArray<T> {
    fn push(&mut self, item: T) {
        if self.size == self.cap {
            let mut new_data: Box<[T]> = (0..self.cap * 2).map(|_| T::default()).collect();
            self.cap *= 2;
            new_data[0..self.size].clone_from_slice(&self.data[0..self.size]);
            self.data = new_data;
        }
        self.data[self.size] = item;
        self.size += 1;
    }

    fn pop(&mut self) -> Option<T> {
        if self.size == 0 {
            return None;
        }
        self.size -= 1;
        Some(self.data[self.size].clone())
    }

    fn top(&self) -> Option<&T> {
        match self.size {
            0 => None,
            _ => Some(&self.data[self.size - 1]),
        }
    }

    fn size(&self) -> usize {
        self.size
    }

    fn clear(&mut self) {
        *self = Self::new();
    }
}

fn test(mut stack: impl Stack<i32>) {
    for i in 0..10 {
        stack.push(i);
        assert_eq!(stack.size(), (i + 1) as usize);
        assert_eq!(stack.top(), Some(&i));
    }
    assert_eq!(stack.pop(), Some(9));
    assert_eq!(stack.size(), 9);
    assert_eq!(stack.top(), Some(&8));
    stack.clear();
    assert_eq!(stack.size(), 0);
    assert_eq!(stack.pop(), None);
    assert_eq!(stack.top(), None);
}

fn main() {
    test(StackLinkList::<i32>::new());
    test(StackArray::<i32>::new());
    println!("All tests passed.");
}
