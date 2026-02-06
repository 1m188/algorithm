/*
基于 typescript 实现的二叉树及其常用操作
*/

export { };

/** 二叉树节点 */
class Node<T> {
    public data: T;
    public left: Node<T> | null = null;
    public right: Node<T> | null = null;

    constructor(data: T) { this.data = data; }
};

/**
 * 二叉树先序遍历
 * @param root 树根节点
 * @param doSomething 对每个节点执行的操作
 */
function preOrderTraversal<T>(root: Node<T> | null, doSomething: (node: Node<T>) => void): void {
    if (!root) return;
    doSomething(root);
    preOrderTraversal(root.left, doSomething);
    preOrderTraversal(root.right, doSomething);
}

/**
 * 二叉树先序遍历(非递归)
 * @param root 树根节点
 * @param doSomething 对每个节点执行的操作
 */
function preOrderTraversalNoRecur<T>(root: Node<T> | null, doSomething: (node: Node<T>) => void): void {
    if (!root) return;
    const stack: Node<T>[] = [root];
    while (stack.length > 0) {
        const node = stack.pop()!; // 弹出
        doSomething(node); // 访问
        if (node.right) stack.push(node.right); // 右子节点入栈
        if (node.left) stack.push(node.left); // 左子节点入栈
    }
}

/**
 * 二叉树中序遍历
 * @param root 树根节点
 * @param doSomething 对每个节点执行的操作
 */
function inOrderTraversal<T>(root: Node<T> | null, doSomething: (node: Node<T>) => void): void {
    if (!root) return;
    inOrderTraversal(root.left, doSomething);
    doSomething(root);
    inOrderTraversal(root.right, doSomething);
}

/**
 * 二叉树中序遍历(非递归)
 * @param root 树根节点
 * @param doSomething 对每个节点执行的操作
 */
function inOrderTraversalNoRecur<T>(root: Node<T> | null, doSomething: (node: Node<T>) => void): void {
    if (!root) return;
    const stack: Node<T>[] = [];
    let cur: Node<T> | null = root;
    while (cur || stack.length > 0) {
        while (cur) {
            stack.push(cur);
            cur = cur.left;
        }
        cur = stack.pop()!;
        doSomething(cur);
        cur = cur.right;
    }
}

/**
 * 二叉树后序遍历
 * @param root 树根节点
 * @param doSomething 对每个节点执行的操作
 */
function postOrderTraversal<T>(root: Node<T> | null, doSomething: (node: Node<T>) => void): void {
    if (!root) return;
    postOrderTraversal(root.left, doSomething);
    postOrderTraversal(root.right, doSomething);
    doSomething(root);
}

/**
 * 二叉树后序遍历(非递归)
 * @param root 树根节点
 * @param doSomething 对每个节点执行的操作
 */
function postOrderTraversalNoRecur<T>(root: Node<T> | null, doSomething: (node: Node<T>) => void): void {
    if (!root) return;

    // 双栈法
    const stack1: Node<T>[] = [root]; // 根-左-右 顺序入栈
    const stack2: Node<T>[] = []; // 根-右-左 顺序入栈
    while (stack1.length > 0) {
        const node = stack1.pop()!;
        stack2.push(node);
        if (node.left) stack1.push(node.left);
        if (node.right) stack1.push(node.right);
    }
    while (stack2.length > 0) { // 左-右-根 顺序出栈即为后序遍历顺序
        doSomething(stack2.pop()!);
    }
}

/**
 * 二叉树层序遍历
 * @param root 树根节点
 * @param doSomething 对每个节点执行的操作
 */
function layerOrderTraversal<T>(root: Node<T> | null, doSomething: (node: Node<T>) => void): void {
    if (!root) return;
    let queue: Node<T>[] = [root];
    while (queue.length > 0) {
        let node = queue.shift();
        doSomething(node!);
        if (node!.left) queue.push(node!.left);
        if (node!.right) queue.push(node!.right);
    }
}

/**
 * 断言函数
 * @param condition 条件
 * @param msg 错误信息
 */
function assert(condition: boolean, msg?: string): void { if (!condition) throw new Error(msg); }

/**
 * 判断两个数组是否值相等
 * @param a 数组1
 * @param b 数组2
 * @returns 是否值相等
 */
function arrEq(a: number[], b: number[]): boolean { return a.length === b.length && a.every((value, index) => value === b[index]); }

/** 用来存放节点值的数组, 用以判定遍历结果 */
const arr: number[] = [];

/**
 * doSomething 函数
 * @param node 节点
 */
function doSomething(node: Node<number>): void { arr.push(node.data); }

/**
 * 测试先序遍历
 * @param preOrderTraversal 先序遍历函数
 */
function testPreOrderTraversal(
    preOrderTraversal: (root: Node<number> | null, doSomething: (node: Node<number>) => void) => void
): void {

    arr.splice(0, arr.length);
    let root: Node<number> | null = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.left = new Node(4);
    root.left.right = new Node(5);
    preOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1, 2, 4, 5, 3]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.left = new Node(4);
    root.left.right = new Node(5);
    root.right.left = new Node(6);
    root.right.right = new Node(7);
    preOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1, 2, 4, 5, 3, 6, 7]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.left.left = new Node(3);
    root.left.left.left = new Node(4);
    root.left.left.left.left = new Node(5);
    root.left.left.left.left.left = new Node(6);
    preOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1, 2, 3, 4, 5, 6]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.left.right = new Node(3);
    root.left.right.left = new Node(4);
    root.left.right.left.right = new Node(5);
    preOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1, 2, 3, 4, 5]));

    arr.splice(0, arr.length);
    root = new Node(1);
    preOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1]));

    arr.splice(0, arr.length);
    root = null;
    preOrderTraversal(root, doSomething);
    assert(arrEq(arr, []));

}

/**
 * 测试中序遍历
 * @param inOrderTraversal 中序遍历函数
 */
function testInOrderTraversal(
    inOrderTraversal: (root: Node<number> | null, doSomething: (node: Node<number>) => void) => void
): void {

    arr.splice(0, arr.length);
    let root: Node<number> | null = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.left = new Node(4);
    root.left.right = new Node(5);
    inOrderTraversal(root, doSomething);
    assert(arrEq(arr, [4, 2, 5, 1, 3]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.left = new Node(4);
    root.left.right = new Node(5);
    root.right.left = new Node(6);
    root.right.right = new Node(7);
    inOrderTraversal(root, doSomething);
    assert(arrEq(arr, [4, 2, 5, 1, 6, 3, 7]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.left.left = new Node(3);
    root.left.left.left = new Node(4);
    root.left.left.left.left = new Node(5);
    root.left.left.left.left.left = new Node(6);
    inOrderTraversal(root, doSomething);
    assert(arrEq(arr, [6, 5, 4, 3, 2, 1]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.left.right = new Node(3);
    root.left.right.left = new Node(4);
    root.left.right.left.right = new Node(5);
    inOrderTraversal(root, doSomething);
    assert(arrEq(arr, [2, 4, 5, 3, 1]));

    arr.splice(0, arr.length);
    root = new Node(1);
    inOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1]));

    arr.splice(0, arr.length);
    root = null;
    inOrderTraversal(root, doSomething);
    assert(arrEq(arr, []));

}

/**
 * 测试后序遍历
 * @param postOrderTraversal 后序遍历函数
 */
function testPostOrderTraversal(
    postOrderTraversal: (root: Node<number> | null, doSomething: (node: Node<number>) => void) => void
): void {

    arr.splice(0, arr.length);
    let root: Node<number> | null = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.left = new Node(4);
    root.left.right = new Node(5);
    postOrderTraversal(root, doSomething);
    assert(arrEq(arr, [4, 5, 2, 3, 1]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.left = new Node(4);
    root.left.right = new Node(5);
    root.right.left = new Node(6);
    root.right.right = new Node(7);
    postOrderTraversal(root, doSomething);
    assert(arrEq(arr, [4, 5, 2, 6, 7, 3, 1]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.left.left = new Node(3);
    root.left.left.left = new Node(4);
    root.left.left.left.left = new Node(5);
    root.left.left.left.left.left = new Node(6);
    postOrderTraversal(root, doSomething);
    assert(arrEq(arr, [6, 5, 4, 3, 2, 1]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.left.right = new Node(3);
    root.left.right.left = new Node(4);
    root.left.right.left.right = new Node(5);
    postOrderTraversal(root, doSomething);
    assert(arrEq(arr, [5, 4, 3, 2, 1]));

    arr.splice(0, arr.length);
    root = new Node(1);
    postOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1]));

    arr.splice(0, arr.length);
    root = null;
    postOrderTraversal(root, doSomething);
    assert(arrEq(arr, []));

}

/**
 * 测试层序遍历
 * @param layerOrderTraversal 层序遍历函数
 */
function testLayerOrderTraversal(
    layerOrderTraversal: (root: Node<number> | null, doSomething: (node: Node<number>) => void) => void
): void {

    arr.splice(0, arr.length);
    let root: Node<number> | null = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.left = new Node(4);
    root.left.right = new Node(5);
    layerOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1, 2, 3, 4, 5]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.left = new Node(4);
    root.left.right = new Node(5);
    root.right.left = new Node(6);
    root.right.right = new Node(7);
    layerOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1, 2, 3, 4, 5, 6, 7]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.left.left = new Node(3);
    root.left.left.left = new Node(4);
    root.left.left.left.left = new Node(5);
    root.left.left.left.left.left = new Node(6);
    layerOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1, 2, 3, 4, 5, 6]));

    arr.splice(0, arr.length);
    root = new Node(1);
    root.left = new Node(2);
    root.left.right = new Node(3);
    root.left.right.left = new Node(4);
    root.left.right.left.right = new Node(5);
    layerOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1, 2, 3, 4, 5]));

    arr.splice(0, arr.length);
    root = new Node(1);
    layerOrderTraversal(root, doSomething);
    assert(arrEq(arr, [1]));

    arr.splice(0, arr.length);
    root = null;
    layerOrderTraversal(root, doSomething);
    assert(arrEq(arr, []));

}

// 测试先序遍历
testPreOrderTraversal(preOrderTraversal);
testPreOrderTraversal(preOrderTraversalNoRecur);

// 测试中序遍历
testInOrderTraversal(inOrderTraversal);
testInOrderTraversal(inOrderTraversalNoRecur);

// 测试后序遍历
testPostOrderTraversal(postOrderTraversal);
testPostOrderTraversal(postOrderTraversalNoRecur);

// 测试层序遍历
testLayerOrderTraversal(layerOrderTraversal);

console.log('All tests passed!');
