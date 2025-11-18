/*

基于 Rust 的单链表实现

*/

use std::fmt;

// 链表节点定义
struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

impl<T: fmt::Display> fmt::Display for Node<T> {
    // 链表的字符串表示
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        let mut vec: Vec<String> = Vec::new();
        vec.push(self.data.to_string());
        let mut cur = self;
        while cur.next.is_some() {
            cur = cur.next.as_ref().unwrap();
            vec.push(cur.data.to_string());
        }
        let txt = vec.join("->");
        write!(f, "{}", txt)
    }
}

impl<T: Clone> Node<T> {
    // 创建一个链表
    fn new(datas: &Vec<T>) -> Option<Box<Node<T>>> {
        if datas.is_empty() {
            return None;
        }

        let mut head = Node {
            data: datas[0].clone(),
            next: None,
        };
        let mut cur = &mut head;
        for i in 1..datas.len() {
            let node = Node {
                data: datas[i].clone(),
                next: None,
            };
            cur.next = Some(Box::new(node));
            cur = cur.next.as_mut().unwrap();
        }

        Some(Box::new(head))
    }
}

// 追加节点
fn add_node<T: Eq>(mut head: Option<Box<Node<T>>>, data: T) -> Option<Box<Node<T>>> {
    if head.is_none() {
        return Some(Box::new(Node { data, next: None }));
    }

    let mut cur = &mut head;
    while cur.as_ref().unwrap().next.is_some() {
        cur = &mut cur.as_mut().unwrap().next;
    }

    cur.as_mut().unwrap().next = Some(Box::new(Node { data, next: None }));

    head
}

// 删除链表节点
fn delete_node<T: Eq>(mut head: Option<Box<Node<T>>>, data: &T) -> Option<Box<Node<T>>> {
    if head.is_none() {
        return None;
    }
    if head.as_ref().unwrap().data == *data {
        return head.unwrap().next;
    }

    let mut cur = &mut head;
    while cur.as_ref().unwrap().next.is_some() {
        if cur.as_ref().unwrap().next.as_ref().unwrap().data == *data {
            let next = &mut cur.as_mut().unwrap().next;
            let nnext = &mut next.as_mut().unwrap().next;
            cur.as_mut().unwrap().next = nnext.take();
            return head;
        }
        cur = &mut cur.as_mut().unwrap().next;
    }

    head
}

// 修改节点数据
fn change_node<T: Eq>(
    mut head: Option<Box<Node<T>>>,
    data: &T,
    new_data: T,
) -> Option<Box<Node<T>>> {
    let mut cur = &mut head;
    while cur.is_some() {
        if cur.as_ref().unwrap().data == *data {
            cur.as_mut().unwrap().data = new_data;
            break;
        }
        cur = &mut cur.as_mut().unwrap().next;
    }
    head
}

// 查找节点
fn find_node<'a, T: Eq>(head: &'a Option<Box<Node<T>>>, data: &T) -> Option<&'a Box<Node<T>>> {
    let mut cur = head;
    while cur.is_some() {
        if cur.as_ref().unwrap().data == *data {
            return Some(cur.as_ref().unwrap());
        }
        cur = &cur.as_ref().unwrap().next;
    }
    None
}

// 测试
fn main() {
    let mut head = Node::new(&vec![5, 4, 3, 7, 8, 9, 10]);
    assert_eq!(head.as_ref().unwrap().to_string(), "5->4->3->7->8->9->10");

    head = delete_node(head, &5);
    assert_eq!(head.as_ref().unwrap().to_string(), "4->3->7->8->9->10");
    head = delete_node(head, &9);
    assert_eq!(head.as_ref().unwrap().to_string(), "4->3->7->8->10");
    head = delete_node(head, &10);
    assert_eq!(head.as_ref().unwrap().to_string(), "4->3->7->8");
    head = delete_node(head, &11);
    assert_eq!(head.as_ref().unwrap().to_string(), "4->3->7->8");
    head = add_node(head, 11);
    assert_eq!(head.as_ref().unwrap().to_string(), "4->3->7->8->11");

    let mut node = find_node(&head, &4);
    assert_eq!(node.unwrap().data, 4);
    node = find_node(&head, &7);
    assert_eq!(node.unwrap().data, 7);
    node = find_node(&head, &11);
    assert_eq!(node.unwrap().data, 11);

    head = change_node(head, &4, 5);
    assert_eq!(head.as_ref().unwrap().to_string(), "5->3->7->8->11");
    head = change_node(head, &11, 12);
    assert_eq!(head.as_ref().unwrap().to_string(), "5->3->7->8->12");
    head = change_node(head, &7, 9);
    assert_eq!(head.as_ref().unwrap().to_string(), "5->3->9->8->12");
}
