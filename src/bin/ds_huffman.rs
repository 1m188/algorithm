/*
基于 Rust 的 Huffman 树实现
*/

use std::{cell::RefCell, collections::VecDeque, ops::Add, rc::Rc};

// Huffman 树节点定义
struct Node<T>
where
    T: Ord + Add<Output = T> + Clone,
{
    data: T,
    left: Rc<RefCell<Option<Box<Node<T>>>>>,
    right: Rc<RefCell<Option<Box<Node<T>>>>>,
}

impl<T> Node<T>
where
    T: Ord + Add<Output = T> + Clone,
{
    fn new(data: T) -> Self {
        Node {
            data,
            left: Rc::new(RefCell::new(None)),
            right: Rc::new(RefCell::new(None)),
        }
    }
}

fn build_huffman<T>(mut datas: Vec<T>) -> Rc<RefCell<Option<Box<Node<T>>>>>
where
    T: Ord + Add<Output = T> + Clone,
{
    if datas.is_empty() {
        return Rc::new(RefCell::new(None));
    }

    let mut nodes: VecDeque<Rc<RefCell<Option<Box<Node<T>>>>>> = VecDeque::new();
    datas.sort();
    for data in datas {
        nodes.push_back(Rc::new(RefCell::new(Some(Box::new(Node::new(data))))));
    }

    while nodes.len() > 1 {
        let left = nodes.pop_front().unwrap();
        let right = nodes.pop_front().unwrap();
        let root = Rc::new(RefCell::new(Some(Box::new(Node::new(
            left.borrow().as_ref().unwrap().data.clone()
                + right.borrow().as_ref().unwrap().data.clone(),
        )))));
        root.borrow_mut().as_mut().unwrap().left = left;
        root.borrow_mut().as_mut().unwrap().right = right;
        if nodes.is_empty()
            || nodes
                .back()
                .as_ref()
                .unwrap()
                .borrow()
                .as_ref()
                .unwrap()
                .data
                <= root.borrow().as_ref().unwrap().data
        {
            nodes.push_back(root);
        } else {
            for i in 0..nodes.len() {
                if nodes[i].borrow().as_ref().unwrap().data >= root.borrow().as_ref().unwrap().data
                {
                    nodes.insert(i, root);
                    break;
                }
            }
        }
    }

    nodes.pop_front().unwrap()
}

fn layer_traversal<T>(root: &Rc<RefCell<Option<Box<Node<T>>>>>) -> Vec<T>
where
    T: Ord + Add<Output = T> + Clone,
{
    let mut res = Vec::new();

    let mut que = VecDeque::new();
    if root.borrow().is_some() {
        que.push_back(root.clone());
    }
    while !que.is_empty() {
        let node = que.pop_front().unwrap();
        res.push(node.borrow().as_ref().unwrap().data.clone());
        if node.borrow().as_ref().unwrap().left.borrow().is_some() {
            que.push_back(node.borrow().as_ref().unwrap().left.clone());
        }
        if node.borrow().as_ref().unwrap().right.borrow().is_some() {
            que.push_back(node.borrow().as_ref().unwrap().right.clone());
        }
    }

    res
}

fn main() {
    let root = build_huffman(vec![10, 9, 8, 7, 6, 5, 4, 3, 2, 1]);
    let seq = layer_traversal(&root);
    assert_eq!(
        &seq,
        &vec![
            55, 22, 33, 10, 12, 15, 18, 6, 6, 7, 8, 9, 9, 3, 3, 4, 5, 1, 2
        ]
    );
    println!("All tests passed!")
}
