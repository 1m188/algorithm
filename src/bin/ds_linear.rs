/*

基于 Rust 的线性表实现

*/

use std::ops::{Index, IndexMut};

// 线性表接口
trait Linear<T>: Index<usize, Output = T> + IndexMut<usize, Output = T> {
    fn new() -> Self;
    fn len(&self) -> usize;
    fn add(&mut self, data: T) -> bool;
    fn insert(&mut self, index: usize, data: T) -> bool;
    fn del_v(&mut self, val: &T) -> Option<T>
    where
        T: Eq;
    fn del_i(&mut self, index: usize) -> Option<T>;
    fn index_of(&self, val: &T) -> Option<usize>
    where
        T: Eq;
    fn clear(&mut self);
}

// 单向链表节点定义
struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

// 基于单向链表的线性表实现
struct LinearLinkList<T> {
    head: Option<Box<Node<T>>>, // 头节点
    size: usize,                // 链表长度
}

impl<T> Linear<T> for LinearLinkList<T> {
    fn new() -> Self {
        LinearLinkList {
            head: None,
            size: 0,
        }
    }

    fn len(&self) -> usize {
        self.size
    }

    fn add(&mut self, data: T) -> bool {
        if self.head.is_none() {
            self.head = Some(Box::new(Node {
                data: data,
                next: None,
            }))
        } else {
            let mut cur = &mut self.head;
            while cur.as_ref().unwrap().next.is_some() {
                cur = &mut cur.as_mut().unwrap().next;
            }
            cur.as_mut().unwrap().next = Some(Box::new(Node {
                data: data,
                next: None,
            }))
        }
        self.size += 1;
        true
    }

    fn insert(&mut self, index: usize, data: T) -> bool {
        if index >= self.size {
            return false; // 索引超出范围
        }
        if index == 0 {
            let mut new_head = Some(Box::new(Node {
                data: data,
                next: self.head.take(),
            }));
            self.head = new_head.take();
        } else {
            let mut cur = &mut self.head;
            for _ in 0..index - 1 {
                cur = &mut cur.as_mut().unwrap().next;
            }
            let mut node = Some(Box::new(Node {
                data: data,
                next: None,
            }));
            node.as_mut().unwrap().next = cur.as_mut().unwrap().next.take();
            cur.as_mut().unwrap().next = node.take();
        }
        self.size += 1;
        true
    }

    fn del_v(&mut self, val: &T) -> Option<T>
    where
        T: Eq,
    {
        if self.head.is_none() {
            return None;
        }
        if self.head.as_ref().unwrap().data == *val {
            let mut node = self.head.take();
            self.head = node.as_mut().unwrap().next.take();
            self.size -= 1;
            return Some(node.unwrap().data);
        }

        let mut cur = &mut self.head;
        while cur.as_ref().unwrap().next.is_some() {
            if cur.as_ref().unwrap().next.as_ref().unwrap().data == *val {
                let mut next = cur.as_mut().unwrap().next.take();
                let mut nnext = next.as_mut().unwrap().next.take();
                cur.as_mut().unwrap().next = nnext.take();
                self.size -= 1;
                return Some(next.unwrap().data);
            } else {
                cur = &mut cur.as_mut().unwrap().next;
            }
        }

        None
    }

    fn del_i(&mut self, index: usize) -> Option<T> {
        if index >= self.size {
            return None;
        }
        if index == 0 {
            let mut node = self.head.take();
            self.head = node.as_mut().unwrap().next.take();
            self.size -= 1;
            return Some(node.unwrap().data);
        } else {
            let mut cur = &mut self.head;
            for _ in 0..index - 1 {
                cur = &mut cur.as_mut().unwrap().next;
            }
            let mut next = cur.as_mut().unwrap().next.take();
            cur.as_mut().unwrap().next = next.as_mut().unwrap().next.take();
            self.size -= 1;
            return Some(next.unwrap().data);
        }
    }

    fn index_of(&self, val: &T) -> Option<usize>
    where
        T: Eq,
    {
        let mut cur = self.head.as_ref();
        let mut res = None;
        let mut index: usize = 0;
        while cur.is_some() {
            if cur.unwrap().data == *val {
                res = Some(index);
                break;
            } else {
                index += 1;
                cur = cur.unwrap().next.as_ref();
            }
        }
        res
    }

    fn clear(&mut self) {
        self.head = None;
        self.size = 0;
    }
}

impl<T> Index<usize> for LinearLinkList<T> {
    type Output = T;
    fn index(&self, index: usize) -> &Self::Output {
        if index >= self.size {
            panic!("Index out of range");
        }

        let mut cur = self.head.as_ref();
        for _ in 0..index {
            cur = cur.unwrap().next.as_ref();
        }
        &cur.unwrap().data
    }
}
impl<T> IndexMut<usize> for LinearLinkList<T> {
    fn index_mut(&mut self, index: usize) -> &mut Self::Output {
        if index >= self.size {
            panic!("Index out of range");
        }

        let mut cur = self.head.as_mut();
        for _ in 0..index {
            cur = cur.unwrap().next.as_mut();
        }
        &mut cur.unwrap().data
    }
}

// 基于数组的线性表实现
struct LinearArray<T> {
    data: Box<[T]>,
    size: usize,
    cap: usize,
}

impl<T: Clone + Default> Linear<T> for LinearArray<T> {
    fn new() -> Self {
        LinearArray {
            data: Box::new([T::default(); 1]),
            size: 0,
            cap: 1,
        }
    }

    fn len(&self) -> usize {
        self.size
    }

    fn add(&mut self, data: T) -> bool {
        // 扩容
        if self.size >= self.cap {
            let mut data = vec![T::default(); self.cap * 2].into_boxed_slice();
            self.cap *= 2;
            for i in 0..self.size {
                data[i] = self.data[i].clone();
            }
            self.data = data;
        }
        self.data[self.size] = data;
        self.size += 1;
        true
    }

    fn insert(&mut self, index: usize, data: T) -> bool {
        if index >= self.size {
            return false;
        }
        self.add(T::default());
        for i in (index..self.size - 1).rev() {
            self.data[i + 1] = self.data[i].clone();
        }
        self.data[index] = data;
        true
    }

    fn del_v(&mut self, val: &T) -> Option<T>
    where
        T: Eq,
    {
        for i in 0..self.size {
            if self.data[i] == *val {
                return self.del_i(i);
            }
        }
        None
    }

    fn del_i(&mut self, index: usize) -> Option<T> {
        if index >= self.size {
            return None;
        }
        let ret = self.data[index].clone();
        for i in index..self.size - 1 {
            self.data[i] = self.data[i + 1].clone();
        }
        self.size -= 1;
        Some(ret)
    }

    fn index_of(&self, val: &T) -> Option<usize>
    where
        T: Eq,
    {
        self.data.iter().position(|x| x == val)
    }

    fn clear(&mut self) {
        *self = LinearArray::new();
    }
}

impl<T> Index<usize> for LinearArray<T> {
    type Output = T;

    fn index(&self, index: usize) -> &Self::Output {
        if index >= self.data.len() {
            panic!("index out of range");
        }
        self.data.get(index).unwrap()
    }
}

impl<T> IndexMut<usize> for LinearArray<T> {
    fn index_mut(&mut self, index: usize) -> &mut Self::Output {
        if index >= self.data.len() {
            panic!("index out of range");
        }
        self.data.get_mut(index).unwrap()
    }
}

// 测试
fn test(mut linear: impl Linear<i32>) {
    for i in (1..=10).step_by(2) {
        assert!(linear.add(i));
    }
    let mut str = String::new();
    for i in 0..linear.len() {
        str.push_str(&format!("{} ", linear[i]));
    }
    str.pop();
    assert_eq!(str, "1 3 5 7 9");
    assert_eq!(linear.len(), 5);

    linear.insert(0, 2);
    linear.insert(1, 4);
    linear.insert(2, 6);
    linear.insert(3, 8);
    linear.insert(4, 10);
    str.clear();
    for i in 0..linear.len() {
        str.push_str(&format!("{} ", linear[i]));
    }
    str.pop();
    assert_eq!(str, "2 4 6 8 10 1 3 5 7 9");
    assert_eq!(linear.len(), 10);

    assert!(linear.index_of(&2).is_some() && linear.index_of(&2).unwrap() == 0);
    assert!(linear.index_of(&4).is_some() && linear.index_of(&4).unwrap() == 1);
    assert!(linear.index_of(&9).is_some() && linear.index_of(&9).unwrap() == 9);

    assert_eq!(linear.del_i(0).unwrap(), 2);
    assert_eq!(linear.len(), 9);
    str.clear();
    for i in 0..linear.len() {
        str.push_str(&format!("{} ", linear[i]));
    }
    str.pop();
    assert_eq!(str, "4 6 8 10 1 3 5 7 9");

    assert_eq!(linear.del_v(&10).unwrap(), 10);
    assert_eq!(linear.len(), 8);
    str.clear();
    for i in 0..linear.len() {
        str.push_str(&format!("{} ", linear[i]));
    }
    str.pop();
    assert_eq!(str, "4 6 8 1 3 5 7 9");

    linear[0] = 11;
    assert_eq!(linear[0], 11);

    linear.clear();
    assert_eq!(linear.len(), 0);
}

fn main() {
    test(LinearLinkList::<i32>::new());
    test(LinearArray::<i32>::new());

    println!("All tests passed.");
}
