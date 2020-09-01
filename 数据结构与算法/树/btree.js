/*

二叉树

*/

/** 二叉树节点 */
class BNode {
    constructor(val = 0) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

/**
 * 先序遍历
 * @param {BNode} root 二叉树根节点
 */
function preorder(root) {
    if (root) {
        process.stdout.write(root.val + ' ');
        preorder(root.left);
        preorder(root.right);
    }
}

/**
 * 中序遍历
 * @param {BNode} root 二叉树根节点
 */
function inorder(root) {
    if (root) {
        inorder(root.left);
        process.stdout.write(root.val + ' ');
        inorder(root.right);
    }
}

/**
 * 后序遍历
 * @param {BNode} root 二叉树根节点
 */
function postorder(root) {
    if (root) {
        postorder(root.left);
        postorder(root.right);
        process.stdout.write(root.val + ' ');
    }
}

/**
 * 层序遍历
 * @param {BNode} root 二叉树根节点
 */
function levelorder(root) {
    if (!root) return;

    let que = new Array();
    que.push(root);
    while (que.length) {
        let n = que.shift();
        process.stdout.write(n.val + ' ');
        if (n.left)
            que.push(n.left);
        if (n.right)
            que.push(n.right);
    }
}

/**
 * 非递归先序遍历
 * @param {BNode} root 二叉树根节点
 */
function preorder_c(root) {
    let st = [];
    while (root || st.length) {
        if (root) {
            process.stdout.write(root.val + ' ');
            st.push(root);
            root = root.left;
        } else {
            root = st.pop();
            root = root.right;
        }
    }
}

/**
 * 非递归中序遍历
 * @param {BNode} root 二叉树根节点
 */
function inorder_c(root) {
    let st = [];
    while (root || st.length) {
        if (root) {
            st.push(root);
            root = root.left;
        } else {
            root = st.pop();
            process.stdout.write(root.val + ' ');
            root = root.right;
        }
    }
}

/**
 * 非递归后序遍历
 * @param {BNode} root 二叉树根节点
 */
function postorder_c(root) {
    let st = [], r = null;
    while (root || st.length) {
        if (root) {
            st.push(root);
            root = root.left;
        } else {
            root = st[st.length - 1];
            if (root.right && r != root.right) root = root.right;
            else {
                st.pop();
                process.stdout.write(root.val + ' ');
                [r, root] = [root, null];
            }
        }
    }
}

function main() {

    let root = new BNode(1);
    root.left = new BNode(2);
    root.right = new BNode(3);
    root.left.left = new BNode(4);
    root.right.left = new BNode(5);

    /*
    
            1
           / \
          2   3
         /   /
        4   5  

    */

    preorder(root);
    console.log();

    inorder(root);
    console.log();

    postorder(root);
    console.log();

    levelorder(root);
    console.log();

    console.log();

    preorder_c(root);
    console.log();

    inorder_c(root);
    console.log();

    postorder_c(root);
    console.log();
}

main();