/*
基于 typescript 的栈实现
*/

export { };

/**
 * 栈接口
 * @template T 栈中元素类型
 */
interface IStack<T> {

    /** 栈大小 */
    readonly size: number;

    /**
     * 入栈
     * @param item 待入栈元素
     */
    push(item: T): void;

    /**
     * 出栈
     * @returns 出栈元素
     * @throws 栈为空时抛出异常
     */
    pop(): T;

    /**
     * 获取栈顶元素
     * @returns 栈顶元素
     * @throws 栈为空时抛出异常
     */
    peek(): T;

}

/**
 * 链表节点
 * @template T 节点数据类型
 */
class Node<T> {

    /** 节点数据 */
    data: T;

    /** 下一个节点 */
    next: Node<T> | null;

    constructor(data: T, next: Node<T> | null = null) {
        this.data = data;
        this.next = next;
    }

}

/**
 * 基于链表的栈实现
 * @template T 栈中元素类型
 */
class StackList<T> implements IStack<T> {

    /** 栈大小 */
    private _size: number = 0;

    /** 栈顶节点 */
    private _top: Node<T> | null = null;

    get size(): number {
        return this._size;
    }

    push(item: T): void {
        const node = new Node(item, this._top);
        this._top = node;
        this._size++;
    }

    pop(): T {
        if (this._top === null) { throw new Error("Stack is empty"); }
        const item = this._top.data;
        this._top = this._top.next;
        this._size--;
        return item;
    }

    peek(): T {
        if (this._top === null) { throw new Error("Stack is empty"); }
        return this._top.data;
    }

}

class StackArray<T> implements IStack<T> {

    /** 栈数据 */
    private _data: T[] = [];

    get size(): number {
        return this._data.length;
    }

    push(item: T): void {
        this._data.push(item);
    }

    pop(): T {
        if (this._data.length === 0) { throw new Error("Stack is empty"); }
        return this._data.pop()!;
    }

    peek(): T {
        if (this._data.length === 0) { throw new Error("Stack is empty"); }
        return this._data[this._data.length - 1];
    }

}

/**
 * 断言函数
 * @param condition 断言条件
 * @param message 断言失败时的错误信息
 */
function assert(condition: boolean, message: string): void { if (!condition) { throw new Error(message); } }

/**
 * 测试函数
 * @param stack 待测试的栈
 */
function test(stack: IStack<number>): void {
    assert(stack.size === 0, "Stack is not empty");

    for (let i = 0; i < 10; i++) {
        stack.push(i);
        assert(stack.size === i + 1, "Stack size is not correct");
        assert(stack.peek() === i, "Stack peek is not correct");
    }

    for (let i = 9; i >= 0; i--) {
        assert(stack.pop() === i, "Stack pop is not correct");
        assert(stack.size === i, "Stack size is not correct");
    }

    try { stack.pop(); } catch (e) { }
    try { stack.peek(); } catch (e) { }
}

test(new StackList<number>());
test(new StackArray<number>());
console.log("All tests passed!")
