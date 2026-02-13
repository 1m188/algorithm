/*
基于 typescript 的二叉查找树(BST, Binary Search Tree)的实现
*/

export { };

/**
 * bst节点
 * @template T 节点数据类型
 */
class Node<T> {

    /** 节点存储数据 */
    public data: T;

    /** 左子树 */
    public left: Node<T> | null;

    /** 右子树 */
    public right: Node<T> | null;

    public constructor(data: T, left: Node<T> | null = null, right: Node<T> | null = null) {
        this.data = data;
        this.left = left;
        this.right = right;
    }

}

/**
 * 往bst中插入一个节点
 * @param root bst根节点
 * @param data 待插入数据
 * @return 插入后的bst根节点
 */
function insert<T>(root: Node<T> | null, data: T): Node<T> | null {
    if (!root) { return new Node(data); }
    if (data < root.data) { root.left = insert(root.left, data); }
    else if (data > root.data) { root.right = insert(root.right, data); }
    return root;
}

/**
 * 从bst中删除一个节点
 * @param root bst根节点
 * @param data 待删除数据
 * @return 删除后的bst根节点
 */
function del<T>(root: Node<T> | null, data: T): Node<T> | null {
    if (!root) { return null; }
    if (data < root.data) { root.left = del(root.left, data); }
    else if (data > root.data) { root.right = del(root.right, data); }
    else {
        if (!root.left && !root.right) { root = null; }
        else if (!root.left) { root = root.right; }
        else if (!root.right) { root = root.left; }
        else {
            let cur = root.left;
            while (cur.right) { cur = cur.right; }
            root.data = cur.data;
            root.left = del(root.left, cur.data)
        }
    }
    return root;
}

/**
 * 在bst中查找一个节点
 * @param root bst根节点
 * @param data 待查找数据
 * @return 查找到的节点
 */
function search<T>(root: Node<T> | null, data: T): Node<T> | null {
    if (!root) { return null; }
    if (root.data === data) { return root; }
    if (root.data < data) { return search(root.right, data); }
    return search(root.left, data);
}

/**
 * 根据数组构建bst
 * @param arr 数组
 * @return 构建好的bst根节点
 */
function build_bst<T>(arr: T[]): Node<T> | null {
    if (!arr.length) { return null; }
    let root = new Node<T>(arr[0]);
    for (let i = 1; i < arr.length; i++) { root = insert(root, arr[i])!; }
    return root;
}

/**
 * 遍历bst, 返回一个有序序列
 * @param root bst根节点
 * @return 有序序列
 */
function traverse<T>(root: Node<T> | null): T[] {

    const ans: T[] = [];

    /**
     * 中序遍历
     * @param root bst根节点
     */
    function mid(root: Node<T> | null): void {
        if (!root) { return; }
        mid(root.left);
        ans.push(root.data);
        mid(root.right);
    }

    mid(root);
    return ans;

}

/**
 * 测试函数
 */
function test(): void {

    /**
     * 断言函数
     * @param b 条件
     * @param msg 错误信息
     */
    function assert(b: boolean, msg?: string): void { if (!b) { throw new Error(msg); } }

    let arr = [5, 1, 7, 6, 9];
    let root = build_bst(arr);
    assert(traverse(root).join(' ') === '1 5 6 7 9');
    assert(search(root, 5) === root);

    root = del(root, 1);
    assert(traverse(root).join(' ') === '5 6 7 9');
    root = del(root, 7);
    assert(traverse(root).join(' ') === '5 6 9');
    root = del(root, 5);
    assert(traverse(root).join(' ') === '6 9');

}

test();
console.log('All tests passed!');
