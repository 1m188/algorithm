#include "iostream"
#include "string"
#include "sstream"
#include "queue"

struct Node //树的结点
{
    int num;
    bool isMarked;
    Node *left, *right;

    Node() : num(0), isMarked(false), left(nullptr), right(nullptr) {}
};
bool ThroughNode(Node *head); //遍历树看有没有没有给出的结点
void Del(Node *head);         //递归删除结点

int main() //动态建树
{
    bool isExtra = false;    //判断是否多给了值
    Node *head = new Node(); //根结点
    std::string input = "";
    while (std::cin >> input && input != "()")
    {
        std::stringstream ss(input.substr(1, input.find(',') - 1));
        int value = 0;
        ss >> value;
        std::string dir = input.substr(input.find(',') + 1);
        dir.pop_back();

        if (dir.empty()) //空的方向，则是根结点
        {
            if (head->isMarked)
            {
                isExtra = true;
                break;
            }
            else
            {
                head->num = value;
                head->isMarked = true;
            }
        }
        else
        {
            Node *cursor = head;
            for (char i : dir)
            {
                if (i == 'L') //往下顺着方向走，一边建树
                {
                    if (!cursor->left)
                    {
                        cursor->left = new Node();
                    }
                    cursor = cursor->left;
                }
                else if (i == 'R')
                {
                    if (!cursor->right)
                    {
                        cursor->right = new Node();
                    }
                    cursor = cursor->right;
                }
            }
            if (!cursor->isMarked) //赋值
            {
                cursor->num = value;
                cursor->isMarked = true;
            }
            else
            {
                isExtra = true;
                break;
            }
        }
    }

    if (isExtra || !ThroughNode(head)) //判断是否多给了值还是少给了值
    {
        std::cout << -1 << std::endl;
        Del(head);
    }
    else
    {
        std::queue<Node *> print{};
        print.push(head);
        while (!print.empty()) //BFS输出
        {
            Node *cursor = print.front();
            print.pop();
            if (cursor->left)
            {
                print.push(cursor->left);
            }
            if (cursor->right)
            {
                print.push(cursor->right);
            }
            std::cout << cursor->num << ' ';
            delete cursor; //顺便释放内存
        }
        std::cout << std::endl;
    }

    return 0;
}

bool ThroughNode(Node *head)
{
    bool isLeft = true, isRight = true, isThis = true;
    if (head->left)
    {
        isLeft = ThroughNode(head->left);
    }
    if (head->right)
    {
        isRight = ThroughNode(head->right);
    }
    if (!head->isMarked)
    {
        isThis = false;
    }
    return isLeft && isRight && isThis;
}

void Del(Node *head)
{
    if (head->left)
    {
        Del(head->left);
    }
    if (head->right)
    {
        Del(head->right);
    }
    delete head;
}