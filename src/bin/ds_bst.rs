/*
基于 Rust 的二叉查找树实现
*/

// 二叉查找树接口
trait BST<T>
where
    T: Ord + Clone,
{
    fn insert(&mut self, val: T);
    fn delete(&mut self, val: &T);
    fn find(&self, val: &T) -> bool;
    fn in_order_traversal(&self) -> Vec<T>;
    fn len(&self) -> usize;
}

// 二叉查找树节点
struct Node<T> {
    val: T,
    left: Option<Box<Node<T>>>,
    right: Option<Box<Node<T>>>,
}

struct BSTTree<T> {
    root: Option<Box<Node<T>>>,
    len: usize,
}

impl<T> BSTTree<T> {
    fn new() -> Self {
        Self { root: None, len: 0 }
    }
}

impl<T> BST<T> for BSTTree<T>
where
    T: Ord + Clone,
{
    fn insert(&mut self, val: T) {
        mod local {
            use super::*;
            pub fn insert<T>(
                root: Option<Box<Node<T>>>,
                val: T,
                len: &mut usize,
            ) -> Option<Box<Node<T>>>
            where
                T: Ord,
            {
                match root {
                    Some(mut node) => {
                        if val < node.val {
                            node.left = insert(node.left.take(), val, len);
                        } else if val > node.val {
                            node.right = insert(node.right.take(), val, len);
                        }
                        Some(node)
                    }
                    None => {
                        *len += 1;
                        return Some(Box::new(Node {
                            val,
                            left: None,
                            right: None,
                        }));
                    }
                }
            }
        }

        self.root = local::insert(self.root.take(), val, &mut self.len);
    }

    fn delete(&mut self, val: &T) {
        mod local {
            use super::*;
            pub fn delete<T>(
                root: Option<Box<Node<T>>>,
                val: &T,
                len: &mut usize,
            ) -> Option<Box<Node<T>>>
            where
                T: Ord + Clone,
            {
                match root {
                    Some(mut node) => {
                        if val < &node.val {
                            node.left = delete(node.left.take(), val, len);
                        } else if val > &node.val {
                            node.right = delete(node.right.take(), val, len);
                        } else {
                            if node.left.is_none() && node.right.is_none() {
                                *len -= 1;
                                return None;
                            }
                            if node.left.is_none() || node.right.is_none() {
                                *len -= 1;
                                return node.left.or(node.right);
                            }

                            let mut min_node = node.right.as_ref().unwrap();
                            while min_node.left.is_some() {
                                min_node = min_node.left.as_ref().unwrap();
                            }
                            node.val = min_node.val.clone();
                            let val = min_node.val.clone();
                            node.right = delete(node.right.take(), &val, len);
                        }
                        Some(node)
                    }
                    None => root,
                }
            }
        }

        self.root = local::delete(self.root.take(), val, &mut self.len);
    }

    fn find(&self, val: &T) -> bool {
        mod local {
            use super::*;
            pub fn find<T>(root: &Option<Box<Node<T>>>, val: &T) -> bool
            where
                T: Ord,
            {
                match root {
                    Some(node) => {
                        if node.val == *val {
                            return true;
                        } else if node.val > *val {
                            return find(&node.left, val);
                        } else {
                            return find(&node.right, val);
                        }
                    }
                    None => false,
                }
            }
        }

        local::find(&self.root, val)
    }

    fn in_order_traversal(&self) -> Vec<T> {
        mod local {
            use super::*;
            pub fn in_order_traversal<T>(root: &Option<Box<Node<T>>>, vec: &mut Vec<T>)
            where
                T: Clone,
            {
                match root {
                    Some(node) => {
                        in_order_traversal(&node.left, vec);
                        vec.push(node.val.clone());
                        in_order_traversal(&node.right, vec);
                    }
                    None => (),
                }
            }
        }

        let mut res = Vec::<T>::new();
        local::in_order_traversal(&self.root, &mut res);
        res
    }

    fn len(&self) -> usize {
        self.len
    }
}

fn test() {
    let mut tree = BSTTree::<i32>::new();
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    assert_eq!(tree.len(), 7);
    assert!(tree.find(&5));
    assert!(!tree.find(&9));
    assert_eq!(tree.in_order_traversal(), vec![1, 3, 4, 5, 6, 7, 8]);
    tree.delete(&5);
    assert_eq!(tree.len(), 6);
    assert!(!tree.find(&5));
    assert_eq!(tree.in_order_traversal(), vec![1, 3, 4, 6, 7, 8]);
    tree.insert(9);
    tree.delete(&8);
    assert_eq!(tree.len(), 6);
    assert!(!tree.find(&8));
    assert_eq!(tree.in_order_traversal(), vec![1, 3, 4, 6, 7, 9]);
    tree.delete(&9);
    assert_eq!(tree.len(), 5);
    assert!(!tree.find(&9));
    assert_eq!(tree.in_order_traversal(), vec![1, 3, 4, 6, 7]);
}

fn main() {
    test();
    println!("All tests passed.")
}
