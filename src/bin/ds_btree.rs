/*
基于 Rust 实现的二叉树及其常用操作
*/

use std::{cell::RefCell, collections::VecDeque};

// 二叉树节点
struct Node<T> {
    data: T,
    left: *mut Node<T>,
    right: *mut Node<T>,
}

impl<T> Node<T> {
    // 构建单个节点并返回
    fn new(data: T) -> Self {
        Node {
            data,
            left: std::ptr::null_mut(),
            right: std::ptr::null_mut(),
        }
    }
}

// 析构
fn drop<T>(root: &mut *mut Node<T>) {
    if (*root).is_null() {
        return;
    }
    unsafe {
        drop(&mut (*(*root)).left);
        drop(&mut (*(*root)).right);
        let _ = Box::from_raw(*root);
        *root = std::ptr::null_mut();
    }
}

// 先序遍历
fn preorder_traversal<T, F>(root: *mut Node<T>, do_something: &mut F)
where
    F: FnMut(*mut Node<T>),
{
    if root.is_null() {
        return;
    }
    do_something(root);
    unsafe {
        preorder_traversal((*root).left, do_something);
        preorder_traversal((*root).right, do_something);
    }
}

// 先序遍历(非递归)
fn preorder_traversal_iter<T, F>(root: *mut Node<T>, do_something: &mut F)
where
    F: FnMut(*mut Node<T>),
{
    let mut stack: Vec<*mut Node<T>> = vec![];
    if !root.is_null() {
        stack.push(root);
    }
    while !stack.is_empty() {
        let node = stack.pop().unwrap();
        do_something(node);
        unsafe {
            if !(*node).right.is_null() {
                stack.push((*node).right);
            }
            if !(*node).left.is_null() {
                stack.push((*node).left);
            }
        }
    }
}

// 中序遍历
fn inorder_traversal<T, F>(root: *mut Node<T>, do_something: &mut F)
where
    F: FnMut(*mut Node<T>),
{
    if root.is_null() {
        return;
    }
    unsafe {
        inorder_traversal((*root).left, do_something);
    }
    do_something(root);
    unsafe {
        inorder_traversal((*root).right, do_something);
    }
}

// 中序遍历(非递归)
fn inorder_traversal_iter<T, F>(root: *mut Node<T>, do_something: &mut F)
where
    F: FnMut(*mut Node<T>),
{
    let mut stack: Vec<*mut Node<T>> = vec![];
    let mut cur: *mut Node<T> = root;

    while !cur.is_null() || !stack.is_empty() {
        unsafe {
            while !cur.is_null() {
                stack.push(cur);
                cur = (*cur).left;
            }
        }
        if let Some(node) = stack.pop() {
            do_something(node);
            unsafe {
                cur = (*node).right;
            }
        } else {
            cur = std::ptr::null_mut();
        }
    }
}

// 后序遍历
fn postorder_traversal<T, F>(root: *mut Node<T>, do_something: &mut F)
where
    F: FnMut(*mut Node<T>),
{
    if root.is_null() {
        return;
    }
    unsafe {
        postorder_traversal((*root).left, do_something);
        postorder_traversal((*root).right, do_something);
    }
    do_something(root);
}

// 后序遍历(非递归)
fn postorder_traversal_iter<T, F>(root: *mut Node<T>, do_something: &mut F)
where
    F: FnMut(*mut Node<T>),
{
    if root.is_null() {
        return;
    }

    let mut stack1: Vec<*mut Node<T>> = vec![root];
    let mut stack2: Vec<*mut Node<T>> = vec![];
    while !stack1.is_empty() {
        let node = stack1.pop().unwrap();
        stack2.push(node);
        unsafe {
            if !(*node).left.is_null() {
                stack1.push((*node).left);
            }
            if !(*node).right.is_null() {
                stack1.push((*node).right);
            }
        }
    }

    while !stack2.is_empty() {
        let node = stack2.pop().unwrap();
        do_something(node);
    }
}

// 层序遍历
fn layer_traversal<T, F>(root: *mut Node<T>, do_something: &mut F)
where
    F: FnMut(*mut Node<T>),
{
    if root.is_null() {
        return;
    }
    let mut queue: VecDeque<*mut Node<T>> = VecDeque::new();
    queue.push_back(root);
    while !queue.is_empty() {
        let node = queue.pop_front().unwrap();
        do_something(node);
        unsafe {
            if !(*node).left.is_null() {
                queue.push_back((*node).left);
            }
            if !(*node).right.is_null() {
                queue.push_back((*node).right);
            }
        }
    }
}

// 测试
fn test() {
    let arr: RefCell<Vec<i32>> = RefCell::new(Vec::new());
    let mut do_something = |node: *mut Node<i32>| {
        if !node.is_null() {
            unsafe {
                arr.borrow_mut().push((*node).data);
            }
        }
    };

    let mut x = Box::into_raw(Box::new(Node::new(1)));
    unsafe {
        (*x).left = Box::into_raw(Box::new(Node::new(2)));
        (*x).right = Box::into_raw(Box::new(Node::new(3)));
        (*(*x).left).left = Box::into_raw(Box::new(Node::new(4)));
        (*(*x).left).right = Box::into_raw(Box::new(Node::new(5)));
        (*(*x).right).left = Box::into_raw(Box::new(Node::new(6)));
        (*(*x).right).right = Box::into_raw(Box::new(Node::new(7)));
    }
    // 先序遍历
    arr.borrow_mut().clear();
    preorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 4, 5, 3, 6, 7]);
    arr.borrow_mut().clear();
    preorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 4, 5, 3, 6, 7]);
    // 中序遍历
    arr.borrow_mut().clear();
    inorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![4, 2, 5, 1, 6, 3, 7]);
    arr.borrow_mut().clear();
    inorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![4, 2, 5, 1, 6, 3, 7]);
    // 后序遍历
    arr.borrow_mut().clear();
    postorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![4, 5, 2, 6, 7, 3, 1]);
    arr.borrow_mut().clear();
    postorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![4, 5, 2, 6, 7, 3, 1]);
    // 层序遍历
    arr.borrow_mut().clear();
    layer_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 3, 4, 5, 6, 7]);
    drop(&mut x);

    x = Box::into_raw(Box::new(Node::new(1)));
    unsafe {
        (*x).left = Box::into_raw(Box::new(Node::new(2)));
        (*x).right = Box::into_raw(Box::new(Node::new(3)));
        (*(*x).left).left = Box::into_raw(Box::new(Node::new(4)));
        (*(*x).left).right = Box::into_raw(Box::new(Node::new(5)));
    }
    // 先序遍历
    arr.borrow_mut().clear();
    preorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 4, 5, 3]);
    arr.borrow_mut().clear();
    preorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 4, 5, 3]);
    // 中序遍历
    arr.borrow_mut().clear();
    inorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![4, 2, 5, 1, 3]);
    arr.borrow_mut().clear();
    inorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![4, 2, 5, 1, 3]);
    // 后序遍历
    arr.borrow_mut().clear();
    postorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![4, 5, 2, 3, 1]);
    arr.borrow_mut().clear();
    postorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![4, 5, 2, 3, 1]);
    // 层序遍历
    arr.borrow_mut().clear();
    layer_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 3, 4, 5]);
    drop(&mut x);

    x = Box::into_raw(Box::new(Node::new(1)));
    unsafe {
        (*x).left = Box::into_raw(Box::new(Node::new(2)));
        (*(*x).left).left = Box::into_raw(Box::new(Node::new(3)));
        (*(*(*x).left).left).left = Box::into_raw(Box::new(Node::new(4)));
        (*(*(*(*x).left).left).left).left = Box::into_raw(Box::new(Node::new(5)));
    }
    // 先序遍历
    arr.borrow_mut().clear();
    preorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 3, 4, 5]);
    arr.borrow_mut().clear();
    preorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 3, 4, 5]);
    // 中序遍历
    arr.borrow_mut().clear();
    inorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![5, 4, 3, 2, 1]);
    arr.borrow_mut().clear();
    inorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![5, 4, 3, 2, 1]);
    // 后序遍历
    arr.borrow_mut().clear();
    postorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![5, 4, 3, 2, 1]);
    arr.borrow_mut().clear();
    postorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![5, 4, 3, 2, 1]);
    // 层序遍历
    arr.borrow_mut().clear();
    layer_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 3, 4, 5]);
    drop(&mut x);

    x = Box::into_raw(Box::new(Node::new(1)));
    unsafe {
        (*x).left = Box::into_raw(Box::new(Node::new(2)));
        (*(*x).left).right = Box::into_raw(Box::new(Node::new(3)));
        (*(*(*x).left).right).left = Box::into_raw(Box::new(Node::new(4)));
        (*(*(*(*x).left).right).left).right = Box::into_raw(Box::new(Node::new(5)));
    }
    // 先序遍历
    arr.borrow_mut().clear();
    preorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 3, 4, 5]);
    arr.borrow_mut().clear();
    preorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 3, 4, 5]);
    // 中序遍历
    arr.borrow_mut().clear();
    inorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![2, 4, 5, 3, 1]);
    arr.borrow_mut().clear();
    inorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![2, 4, 5, 3, 1]);
    // 后序遍历
    arr.borrow_mut().clear();
    postorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![5, 4, 3, 2, 1]);
    arr.borrow_mut().clear();
    postorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![5, 4, 3, 2, 1]);
    // 层序遍历
    arr.borrow_mut().clear();
    layer_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1, 2, 3, 4, 5]);
    drop(&mut x);

    x = Box::into_raw(Box::new(Node::new(1)));
    // 先序遍历
    arr.borrow_mut().clear();
    preorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1]);
    arr.borrow_mut().clear();
    preorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1]);
    // 中序遍历
    arr.borrow_mut().clear();
    inorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1]);
    arr.borrow_mut().clear();
    inorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1]);
    // 后序遍历
    arr.borrow_mut().clear();
    postorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1]);
    arr.borrow_mut().clear();
    postorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1]);
    // 层序遍历
    arr.borrow_mut().clear();
    layer_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![1]);
    drop(&mut x);

    x = std::ptr::null_mut();
    // 先序遍历
    arr.borrow_mut().clear();
    preorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![]);
    arr.borrow_mut().clear();
    preorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![]);
    // 中序遍历
    arr.borrow_mut().clear();
    inorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![]);
    arr.borrow_mut().clear();
    inorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![]);
    // 后序遍历
    arr.borrow_mut().clear();
    postorder_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![]);
    arr.borrow_mut().clear();
    postorder_traversal_iter(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![]);
    // 层序遍历
    arr.borrow_mut().clear();
    layer_traversal(x, &mut do_something);
    assert_eq!(&*arr.borrow(), &vec![]);
    drop(&mut x);
}

fn main() {
    test();
    println!("All tests passed!")
}
