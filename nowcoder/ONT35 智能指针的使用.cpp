/*
描述
在C++中，智能指针是一种对象，它可以存储指向动态分配（堆）的对象的指针，当智能指针生命周期结束时，它会自动删除它所指向的对象。智能指针是一种保证对象被适当释放的方法，可以帮助防止内存泄漏。

你的任务是，使用已经实现的shared_ptr，完成以下功能：

创建一个Student类，包含id和age两个属性。
创建一个shared_ptr，指向一个Student对象。
实现一个函数print，接受一个shared_ptr<Student>，打印学生的id和age，以及shared_ptr的引用计数。
输入描述：
输入第一行为一个整数T，表示有T个测试用例。

每个测试用例包含两行，第一行为一个整数N，表示有N个操作。

接下来N行，每行包含一个操作，操作可能为以下三种之一：

"new id age"：创建一个新的Student对象，id和age为该对象的属性，创建一个shared_ptr指向该对象。
"copy"：创建一个新的shared_ptr，指向同一个Student对象。
"print"：打印当前shared_ptr指向的Student对象的id和age，以及shared_ptr的引用计数。
输出描述：
对于每个"print"操作，输出一行，包含三个整数，分别为Student的id和age，以及shared_ptr的引用计数。
示例1
输入：
2
3
new 1 20
copy
print
2
new 2 21
print
复制
输出：
1 20 1
2 21 1
 */

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Student {
public:
    int id;
    int age;

    Student() = default;
    Student(int id, int age) : id(id), age(age){};
};

void print(const shared_ptr<Student> &ptr) {
    cout << ptr->id << ' ' << ptr->age << ' ' << ptr.use_count() << '\n';
}

int main() {

    int T = 0;
    cin >> T;
    while (T--) {

        int N = 0;
        cin >> N;

        shared_ptr<Student> ptr;
        string op;

        while (N--) {

            cin >> op;
            if (op == "new") {
                int id = 0, age = 0;
                cin >> id >> age;
                ptr.reset(new Student(id, age));
            } else if (op == "copy") {
            } else if (op == "print") {
                print(ptr);
            }
        }
    }
}