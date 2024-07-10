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

struct Node {
    Node *left = nullptr, *right = nullptr;
    int val = 0;
    int h = 1; // 以该节点为根的树的高度

    /** 获取平衡因子 */
    int balance() {
        int left = this->left ? this->left->h : 0;
        int right = this->right ? this->right->h : 0;
        return left - right;
    }
};

/** 获取高度 */
inline int height(Node *node) {
    return node == nullptr ? 0 : node->h;
}

/** 释放内存 */
void free(Node *root) {
    if (!root) return;
    if (root->left) free(root->left);
    if (root->right) free(root->right);
    delete root;
}

/** 查找 */
Node *find(Node *root, int val) {
    if (!root) return nullptr;
    if (val < root->val) return find(root->left, val);
    if (val > root->val) return find(root->right, val);
    return root;
}

/** 插入 */
Node *insert(Node *root, int val) {
    if (!root) {
        Node *node = new Node();
        node->val = val;
        return node;
    }

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    root->h = std::max(height(root->left), height(root->right)) + 1; // 更新高度
    return root;
}

/** 删除 */
Node *del(Node *root, int val) {
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
            Node *min = root->right;
            while (min->left)
                min = min->left;
            std::swap(min->val, root->val);
            root->right = del(root->right, min->val);
        } else {
            Node *res = root->left ? root->left : root->right;
            delete root;
            return res;
        }
    }

    root->h = std::max(height(root->left), height(root->right)) + 1; // 更新高度
    return root;
}

/** 更新树中所有节点的高度 */
// int update_height(Node *root) {
//     if (!root) return 0;
//     int left = update_height(root->left);
//     int right = update_height(root->right);
//     int max = std::max(left, right);
//     root->h = max + 1;
//     return root->h;
// }

/******************************************************************************************************** */

/** 判断是否每个节点都平衡 */
bool is_avl(Node *root) {
    if (!root) return true;

    if (std::abs(root->balance()) > 1) return false;

    if (!is_avl(root->left)) return false;
    if (!is_avl(root->right)) return false;

    return true;
}

/** 判断是否为二叉查找树 */
bool is_bst(Node *root) {

    Node *prenode = nullptr;

    std::function<bool(Node *)> mid = [&prenode, &mid](Node *node) -> bool {
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
        Node *root = nullptr;
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

        Node *root = nullptr;
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

        Node *root = nullptr;
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

        Node *root = nullptr;
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

        Node *root = nullptr;
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
    Node *root = nullptr;
    for (const int &e : {3, 1, 5, 0, 4, 6, 7})
        root = insert(root, e);

    root = del(root, 4);
    EXPECT_EQ(true, is_bst(root));
    EXPECT_EQ(true, is_avl(root));
    EXPECT_EQ((Node *)nullptr, find(root, 4));

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