/*
基于 JavaScript 的二叉查找树(BST, Binary Search Tree)实现
*/

export { };

/** bst节点 */
class Node {

    constructor(data, left = null, right = null) {

        /**
         * 节点数据
         * @type {any}
         */
        this.data = data;

        /**
         * 左子树
         * @type {Node|null}
         */
        this.left = left;

        /**
         * 右子树
         * @type {Node|null}
         */
        this.right = right;

    }

}

/**
 * 往bst中插入一个节点
 * @param {Node|null} root bst根节点
 * @param {any} data 节点数据
 * @return {Node|null} bst根节点
 */
function insert(root, data) {
    if (root === null) { return new Node(data); }
    if (data < root.data) { root.left = insert(root.left, data); }
    else { root.right = insert(root.right, data); }
    return root;
}

/**
 * 删除bst中的节点
 * @param {Node|null} root bst根节点
 * @param {any} data 节点数据
 * @return {Node|null} bst根节点
 */
function del(root, data) {
    if (root === null) { return null; }
    if (data < root.data) { root.left = del(root.left, data); }
    else if (data > root.data) { root.right = del(root.right, data); }
    else {
        if (root.left === null && root.right === null) { root = null; }
        else if (root.left === null) { root = root.right; }
        else if (root.right === null) { root = root.left; }
        else {
            let cur = root.left;
            while (cur.right !== null) { cur = cur.right; }
            root.data = cur.data;
            root.left = del(root.left, cur.data);
        }
    }
    return root;
}

/**
 * 查找bst中的节点
 * @param {Node|null} root bst根节点
 * @param {any} data 节点数据
 * @return {Node|null} 目标节点
 */
function search(root, data) {
    if (root === null) { return null; }
    if (root.data === data) { return root; }
    if (root.data > data) { return search(root.left, data); }
    return search(root.right, data);
}

/**
 * 根据数组构建bst
 * @param {Array} arr 数组
 * @return {Node|null} bst根节点
 */
function bulid_bst(arr) {
    if (arr.length === 0) { return null; }
    let root = new Node(arr[0]);
    for (let i = 1; i < arr.length; i++) { root = insert(root, arr[i]); }
    return root;
}

/**
 * 遍历bst, 返回一个有序列表
 * @param {Node|null} root bst根节点
 * @return {Array} 有序列表
 */
function traverse(root) {

    /**
     * 有序列表
     * @type {Array}
     */
    const ans = [];

    /**
     * 递归中序遍历
     * @param {Node|null} root bst根节点
     * @return {void}
     */
    function mid(root) {
        if (root === null) { return; }
        mid(root.left);
        ans.push(root.data);
        mid(root.right);
    }

    mid(root);
    return ans;

}

/**
 * 测试
 * @returns {void}
 */
function test() {

    /**
     * 断言
     * @param {boolean} b 判断条件
     * @param {string} msg 错误信息
     * @return {void}
     */
    function assert(b, msg = '') { if (!b) { throw new Error(msg); } }

    let arr = [5, 1, 7, 6, 9];
    let root = bulid_bst(arr);
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
