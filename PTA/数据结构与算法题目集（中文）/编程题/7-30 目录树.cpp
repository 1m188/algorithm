/**
 * @file 7-30 目录树.cpp
 * @date 2022-05-11
 */

/*
在ZIP归档文件中，保留着所有压缩文件和目录的相对路径和名称。
当使用WinZIP等GUI软件打开ZIP归档文件时，可以从这些信息中重建目录的树状结构。
请编写程序实现目录的树状结构的重建工作。

输入格式:
输入首先给出正整数N（≤10^4），表示ZIP归档文件中的文件和目录的数量。
随后N行，每行有如下格式的文件或目录的相对路径和名称（每行不超过260个字符）：

路径和名称中的字符仅包括英文字母（区分大小写）；
符号“\”仅作为路径分隔符出现；
目录以符号“\”结束；
不存在重复的输入项目；
整个输入大小不超过2MB。
输出格式:
假设所有的路径都相对于root目录。从root目录开始，在输出时每个目录首先输出自己的名字，然后以字典序输出所有子目录，然后以字典序输出所有文件。注意，在输出时，应根据目录的相对关系使用空格进行缩进，每级目录或文件比上一级多缩进2个空格。

输入样例:
7
b
c\
ab\cd
a\bc
ab\d
a\d\a
a\d\z\

输出样例:
root
  a
    d
      z
      a
    bc
  ab
    cd
    d
  c
  b

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 挺麻烦的，关键在于如何建模，如何构建起正确的模型，如何处理输出格式和排序问题，
如何构建最开始的树 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief 树节点
 */
struct Node {
    string str;                 // 当前目录或文件的名字
    vector<Node *> files, dirs; // 子文件或子目录
};

/**
 * @brief 字符串按照'\'分割，并且目录后面都会带有'\'
 * @param str 传入的路径字符串
 * @return vector<string> 按照\分割的数组
 */
vector<string> str2vec(const string &str) {
    vector<string> ans;

    string tmp;
    for (const char &c : str) {
        tmp.push_back(c);
        if (c == '\\') {
            ans.push_back(tmp);
            tmp.clear();
        }
    }
    if (!tmp.empty())
        ans.push_back(tmp);

    return ans;
}

/**
 * @brief 根据传入根节点，从根节点一直建立节点到叶子上，将一条路径建立完
 * @param vec 由字符串分割而来的数组
 * @param root 根节点
 */
void add_node(vector<string> &vec, Node *root) {

    while (!vec.empty()) {
        string t = vec[0];
        vec.erase(vec.begin());

        // 根据目录和文件分别讨论
        if (t.back() == '\\') {
            t.pop_back();
            bool f = false;
            for (const auto &e : root->dirs) {
                if (e->str == t) { // 如果找得到则直接进入到下一个层级
                    root = e;
                    f = true;
                    break;
                }
            }
            if (!f) { // 否则建立
                Node *node = new Node();
                node->str = t;
                root->dirs.push_back(node);
                root = node;
            }
        } else {
            bool f = false;
            for (const auto &e : root->files) {
                if (e->str == t) {
                    root = e;
                    f = true;
                    break;
                }
            }
            if (!f) {
                Node *node = new Node();
                node->str = t;
                root->files.push_back(node);
                root = node;
            }
        }
    }
}

/**
 * @brief 按照输入建立树
 * @return Node* 返回树根节点
 */
Node *build_tree() {

    Node *root = new Node(); // 最初的数根节点
    root->str = "root";

    int N = 0;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        vector<string> x = str2vec(s);
        add_node(x, root);
    }

    return root;
}

/**
 * @brief 打印节点值
 * @param root 当前待打印的值的节点
 * @param sp 突出空格数
 */
void print(Node *root, int sp = 0) {
    if (root) {
        for (int i = 0; i < sp; i++) // 提前打印好空格
            cout << ' ';
        cout << root->str << '\n';

        // 这里对子目录和子文件进行排序，满足按照字典序打印的要求
        sort(root->dirs.begin(), root->dirs.end(), [](const auto &e1, const auto &e2) { return e1->str < e2->str; });
        sort(root->files.begin(), root->files.end(), [](const auto &e1, const auto &e2) { return e1->str < e2->str; });

        // 先打印目录再打印文件
        for (const auto &e : root->dirs)
            print(e, sp + 2); // 子目录和子文件相较于父目录都要更多两个空格
        for (const auto &e : root->files)
            print(e, sp + 2);
    }
}

int main() {
    Node *root = build_tree();
    print(root);
    return 0;
}