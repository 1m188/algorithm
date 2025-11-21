/*
基于 Rust 的队列实现
*/

// 队列接口
trait Queue<T> {
    fn enqueue(&mut self, item: T);
    fn dequeue(&mut self) -> Option<T>;
    fn head(&self) -> Option<&T>;
    fn tail(&self) -> Option<&T>;
    fn len(&self) -> usize;
    fn clear(&mut self);
}

// 链表节点
struct Node<T> {
    val: T,
    next: Option<Box<Node<T>>>,
}

// 基于链表的队列实现
struct QueueLinkList<T> {
    head: Option<Box<Node<T>>>,
    len: usize,
}

impl<T> QueueLinkList<T> {
    fn new() -> Self {
        QueueLinkList { head: None, len: 0 }
    }
}

impl<T> Queue<T> for QueueLinkList<T> {
    fn enqueue(&mut self, item: T) {
        let new_node = Box::new(Node {
            val: item,
            next: None,
        });

        if self.head.is_none() {
            self.head = Some(new_node);
        } else {
            // O(N) 的插入复杂度
            // 因为不用unsafe写个链表太麻烦了
            let mut cur = self.head.as_mut().unwrap();
            while cur.next.is_some() {
                cur = cur.next.as_mut().unwrap();
            }
            cur.next = Some(new_node);
        }
        self.len += 1;
    }

    fn dequeue(&mut self) -> Option<T> {
        if self.len == 0 {
            return None;
        }
        let mut node = self.head.take();
        self.head = node.as_mut().unwrap().next.take();
        self.len -= 1;
        Some(node.unwrap().val)
    }

    fn head(&self) -> Option<&T> {
        if self.len == 0 {
            return None;
        } else {
            Some(&self.head.as_ref().unwrap().val)
        }
    }

    fn tail(&self) -> Option<&T> {
        if self.len == 0 {
            return None;
        } else {
            let mut cur = self.head.as_ref().unwrap();
            while cur.next.is_some() {
                cur = cur.next.as_ref().unwrap();
            }
            Some(&cur.val)
        }
    }

    fn len(&self) -> usize {
        self.len
    }

    fn clear(&mut self) {
        self.head = None;
        self.len = 0;
    }
}

// 基于动态数组的队列实现
struct QueueList<T> {
    list: Box<[T]>,
    len: usize,
}

impl<T: Default + Clone> QueueList<T> {
    fn new() -> Self {
        QueueList {
            list: Box::new([T::default(); 1]),
            len: 0,
        }
    }
}

impl<T: Default + Clone> Queue<T> for QueueList<T> {
    fn enqueue(&mut self, item: T) {
        if self.len == self.list.len() {
            let mut new_list: Box<[T]> = (0..self.list.len() * 2).map(|_| T::default()).collect();
            new_list[0..self.list.len()].clone_from_slice(&self.list);
            self.list = new_list;
        }
        self.list[self.len] = item;
        self.len += 1;
    }

    fn dequeue(&mut self) -> Option<T> {
        if self.len == 0 {
            return None;
        }
        let item = self.list[0].clone();
        for i in 1..self.len {
            self.list[i - 1] = self.list[i].clone();
        }
        self.len -= 1;
        Some(item)
    }

    fn head(&self) -> Option<&T> {
        match self.len {
            0 => None,
            _ => Some(&self.list[0]),
        }
    }

    fn tail(&self) -> Option<&T> {
        match self.len {
            0 => None,
            _ => Some(&self.list[self.len - 1]),
        }
    }

    fn len(&self) -> usize {
        self.len
    }

    fn clear(&mut self) {
        *self = Self::new();
    }
}

// 基于静态数组的循环队列实现
struct QueueArray<T> {
    list: Box<[T]>,
    head: usize,
    tail: usize,
}

impl<T: Default> QueueArray<T> {
    fn new(cap: usize) -> Self {
        assert!(cap > 1);
        QueueArray {
            list: (0..cap + 1).map(|_| T::default()).collect::<Box<[T]>>(),
            head: 0,
            tail: 0,
        }
    }
}

impl<T: Default + Clone> Queue<T> for QueueArray<T> {
    fn enqueue(&mut self, item: T) {
        if self.len() == self.list.len() - 1 {
            panic!("Queue is full");
        }
        self.list[self.tail] = item;
        self.tail = (self.tail + 1) % self.list.len();
    }

    fn dequeue(&mut self) -> Option<T> {
        if self.len() == 0 {
            return None;
        }
        let item = self.list[self.head].clone();
        self.head = (self.head + 1) % self.list.len();
        Some(item)
    }

    fn head(&self) -> Option<&T> {
        if self.len() == 0 {
            return None;
        }
        Some(&self.list[self.head])
    }

    fn tail(&self) -> Option<&T> {
        if self.len() == 0 {
            return None;
        }
        match self.tail {
            0 => Some(&self.list[self.list.len() - 1]),
            _ => Some(&self.list[self.tail - 1]),
        }
    }

    fn len(&self) -> usize {
        match self.tail >= self.head {
            true => self.tail - self.head,
            _ => self.list.len() - self.head + self.tail,
        }
    }

    fn clear(&mut self) {
        self.head = 0;
        self.tail = 0;
    }
}

fn test(mut queue: impl Queue<i32>, msg: &str) {
    for i in 0..10 {
        queue.enqueue(i);
        assert_eq!(queue.len(), (i + 1) as usize, "{}", msg);
        assert_eq!(queue.head(), Some(&0), "{}", msg);
        assert_eq!(queue.tail(), Some(&i), "{}", msg);
    }
    assert_eq!(queue.dequeue(), Some(0), "{}", msg);
    assert_eq!(queue.len(), 9, "{}", msg);
    assert_eq!(queue.head(), Some(&1), "{}", msg);
    assert_eq!(queue.tail(), Some(&9), "{}", msg);
    queue.enqueue(32);
    assert_eq!(queue.len(), 10, "{}", msg);
    assert_eq!(queue.head(), Some(&1), "{}", msg);
    assert_eq!(queue.tail(), Some(&32), "{}", msg);
    queue.clear();
    assert_eq!(queue.len(), 0, "{}", msg);
    assert_eq!(queue.head(), None, "{}", msg);
    assert_eq!(queue.tail(), None, "{}", msg);
    assert_eq!(queue.dequeue(), None, "{}", msg);
}

fn main() {
    test(QueueLinkList::<i32>::new(), "QueueLinkList");
    test(QueueList::<i32>::new(), "QueueList");
    test(QueueArray::<i32>::new(10), "QueueArray");
    println!("All tests passed.");
}
