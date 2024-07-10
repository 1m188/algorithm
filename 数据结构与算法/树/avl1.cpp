/**
 * @file avl1.cpp
 * @date 2024-07-09

 时隔多年，重新实现AVL自平衡树

 */

#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>

template <typename T>
struct Node {
    Node *left = nullptr, *right = nullptr;
    T val;
    int h = 1; // 以该节点为根的树的高度

    /** 获取节点的平衡因子 */
    int balance() {
        int left = this->left ? this->left->h : 0;
        int right = this->right ? this->right->h : 0;
        return left - right;
    }

    /** 更新节点高度 */
    void update_h() {
        int left = this->left ? this->left->h : 0;
        int right = this->right ? this->right->h : 0;
        this->h = std::max(left, right) + 1;
    }
};

/** 左旋 */
template <typename T>
Node<T> *rotate_L(Node<T> *root) {
    Node<T> *right = root->right;
    root->right = right->left;
    right->left = root;

    root->update_h();
    right->update_h();

    return right;
}

/** 右旋 */
template <typename T>
Node<T> *rotate_R(Node<T> *root) {
    Node<T> *left = root->left;
    root->left = left->right;
    left->right = root;

    root->update_h();
    left->update_h();

    return left;
}

/** 左右旋 */
template <typename T>
Node<T> *rotate_LR(Node<T> *root) {
    root->left = rotate_L(root->left);
    return rotate_R(root);
}

/** 右左旋 */
template <typename T>
Node<T> *rotate_RL(Node<T> *root) {
    root->right = rotate_R(root->right);
    return rotate_L(root);
}

/** 旋转调整 */
template <typename T>
Node<T> *rotate(Node<T> *root) {
    if (root->balance() > 1) {
        if (root->left->balance() > 0)
            return rotate_R(root);
        else
            return rotate_LR(root);
    } else if (root->balance() < -1) {
        if (root->right->balance() < 0)
            return rotate_L(root);
        else
            return rotate_RL(root);
    }
    return root;
}

/** 释放内存 */
template <typename T>
void free(Node<T> *root) {
    if (!root) return;
    if (root->left) free(root->left);
    if (root->right) free(root->right);
    delete root;
}

/** 查找 */
template <typename T>
Node<T> *find(Node<T> *root, int val) {
    if (!root) return nullptr;
    if (val < root->val) return find(root->left, val);
    if (val > root->val) return find(root->right, val);
    return root;
}

/** 插入 */
template <typename T>
Node<T> *insert(Node<T> *root, int val) {
    if (!root) {
        Node<T> *node = new Node<T>();
        node->val = val;
        return node;
    }

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    root = rotate(root); // 旋转调整
    root->update_h();    // 更新高度
    return root;
}

/** 删除 */
template <typename T>
Node<T> *del(Node<T> *root, int val) {
    if (!root) return nullptr;

    if (val < root->val)
        root->left = del(root->left, val);
    else if (val > root->val)
        root->right = del(root->right, val);
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (root->left && root->right) {
            Node<T> *min = root->right;
            while (min->left)
                min = min->left;
            std::swap(min->val, root->val);
            root->right = del(root->right, min->val);
        } else {
            Node<T> *res = root->left ? root->left : root->right;
            delete root;
            return res;
        }
    }

    root = rotate(root); // 旋转调整
    root->update_h();    // 更新高度
    return root;
}

/******************************************************************************************************** */

/** 判断是否每个节点都平衡 */
template <typename T>
bool is_avl(Node<T> *root) {
    if (!root) return true;

    if (std::abs(root->balance()) > 1) return false;

    if (!is_avl(root->left)) return false;
    if (!is_avl(root->right)) return false;

    return true;
}

/** 判断是否为二叉查找树 */
template <typename T>
bool is_bst(Node<T> *root) {

    Node<T> *prenode = nullptr;

    std::function<bool(Node<T> *)> mid = [&prenode, &mid](Node<T> *node) -> bool {
        if (!node) return true;

        if (!mid(node->left)) return false;

        if (prenode == nullptr)
            prenode = node;
        else {
            if (prenode->val >= node->val) return false;
            prenode = node;
        }

        if (!mid(node->right)) return false;

        return true;
    };

    return mid(root);
}

int main_ret = 0;
int test_cases = 0;
int test_passed = 0;

template <typename T>
void expect_eq_base(bool eq, const T &expect, const T &actual, const char *file, int line) {
    test_cases++;
    if (eq) {
        test_passed++;
    } else {
        std::cerr << "expect: " << expect << " actual: " << actual << " " << file << ":" << line << '\n';
        main_ret = 1;
    }
}
template <typename T>
void expect_eq(const T &expect, const T &actual, const char *file, int line) {
    expect_eq_base(expect == actual, expect, actual, file, line);
}
#define EXPECT_EQ(expect, actual) expect_eq(expect, actual, __FILE__, __LINE__)

void test_insert() {
    {
        Node<int> *root = nullptr;
        for (int i = 6; i >= 1; i--) {
            root = insert(root, i);

            EXPECT_EQ(true, is_bst(root));
            EXPECT_EQ(true, is_avl(root));
        }
        free(root);
        root = nullptr;
    }

    {
        /*
                  8
                 / \
                6   9
               / \
              4   7
             /
            3
        */

        Node<int> *root = nullptr;
        for (const int &e : {8, 9, 6, 7, 4, 3}) {
            root = insert(root, e);

            EXPECT_EQ(true, is_bst(root));
            EXPECT_EQ(true, is_avl(root));
        }
        free(root);
        root = nullptr;
    }

    {
        /*
                  4
                 / \
                3   6
                   / \
                  5   7
                       \
                        8
        */

        Node<int> *root = nullptr;
        for (const int &e : {4, 3, 6, 5, 7, 8}) {
            root = insert(root, e);

            EXPECT_EQ(true, is_bst(root));
            EXPECT_EQ(true, is_avl(root));
        }
        free(root);
        root = nullptr;
    }

    {
        /*
                  9
                 / \
                6   10
               / \
              5   7
                   \
                    8
        */

        Node<int> *root = nullptr;
        for (const int &e : {9, 10, 6, 5, 7, 8}) {
            root = insert(root, e);

            EXPECT_EQ(true, is_bst(root));
            EXPECT_EQ(true, is_avl(root));
        }
        free(root);
        root = nullptr;
    }

    {
        /*
                  3
                 / \
                2   6
                   / \
                  5   7
                 /
                4
        */

        Node<int> *root = nullptr;
        for (const int &e : {3, 2, 6, 7, 5, 4}) {
            root = insert(root, e);

            EXPECT_EQ(true, is_bst(root));
            EXPECT_EQ(true, is_avl(root));
        }
        free(root);
        root = nullptr;
    }
}

void test_del() {
    Node<int> *root = nullptr;
    for (const int &e : {3, 1, 5, 0, 4, 6, 7})
        root = insert(root, e);

    root = del(root, 4);
    EXPECT_EQ(true, is_bst(root));
    EXPECT_EQ(true, is_avl(root));
    EXPECT_EQ((Node<int> *)nullptr, find(root, 4));

    free(root);
    root = nullptr;
}

int main(int argc, char **argv) {

    test_insert();
    test_del();

    double rate = test_passed * 1. / test_cases * 100;
    std::cout << "passed " << test_passed << " / " << test_cases
              << " (" << std::fixed << std::setprecision(3) << rate << "%)\n";
    return main_ret;
}