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
 * @param root 二叉树根节点
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
 * @param root 二叉树根节点
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
 * @param root 二叉树根节点
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
 * @param root 二叉树根节点
 */
function levelorder(root) {
    if (!root)
        return;

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
}

main();