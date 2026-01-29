'''

二叉树

'''


class BTNode:
    '''
    二叉树节点
    '''
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def preorder(root: BTNode):
    '''
    先序遍历
    '''
    if root:
        print(root.val, end=' ')
        preorder(root.left)
        preorder(root.right)


def inorder(root: BTNode):
    '''
    中序遍历
    '''
    if root:
        inorder(root.left)
        print(root.val, end=' ')
        inorder(root.right)


def postorder(root: BTNode):
    '''
    后序遍历
    '''
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.val, end=' ')


def levelorder(root: BTNode):
    '''
    层序遍历
    '''
    if not root:
        return
    st = [root]
    while st:
        p = st.pop(0)
        print(p.val, end=' ')
        if p.left:
            st.append(p.left)
        if p.right:
            st.append(p.right)


def preorder_c(root: BTNode):
    '''
    非递归版先序遍历
    '''
    st = []
    while root or st:
        if root:
            print(root.val, end=' ')
            st.append(root)
            root = root.left
        else:
            root = st.pop().right


def inorder_c(root: BTNode):
    '''
    非递归版中序遍历
    '''
    st = []
    while root or st:
        if root:
            st.append(root)
            root = root.left
        else:
            root = st.pop()
            print(root.val, end=' ')
            root = root.right


def postorder_c(root: BTNode):
    '''
    非递归版后序遍历
    '''
    r = None
    st = []
    while root or st:
        if root:
            st.append(root)
            root = root.left
        else:
            root = st[-1]
            if root.right and r != root.right:
                root = root.right
            else:
                st.pop()
                print(root.val, end=' ')
                r = root
                root = None


if __name__ == "__main__":
    '''
        1
       / \
      2   3
     /     \
    4       5
    '''

    root = BTNode(1)
    root.left = BTNode(2)
    root.right = BTNode(3)
    root.left.left = BTNode(4)
    root.right.right = BTNode(5)

    preorder(root)
    print()
    inorder(root)
    print()
    postorder(root)
    print()
    levelorder(root)
    print()

    print()

    preorder_c(root)
    print()
    inorder_c(root)
    print()
    postorder_c(root)
    print()
