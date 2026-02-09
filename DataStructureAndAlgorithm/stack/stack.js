/*
基于 JavaScript 的栈实现
*/

export { };

/** 栈接口 */
class IStack {

    /**
     * 获取栈的大小
     * @returns {number} 栈的大小
     */
    size() {
        throw new Error('Stack interface not implemented');
    }

    /**
     * 压栈
     * @param {*} element 待压入栈顶的元素
     * @returns {void}
     */
    push(element) {
        throw new Error('Stack interface not implemented');
    }

    /**
     * 出栈
     * @returns {*} 栈顶元素
     * @throws {Error} 栈为空时抛出异常
     */
    pop() {
        throw new Error('Stack interface not implemented');
    }

    /**
     * 获取栈顶元素
     * @returns {*} 栈顶元素
     * @throws {Error} 栈为空时抛出异常
     */
    peek() {
        throw new Error('Stack interface not implemented');
    }

}

/** 链表节点 */
class Node {
    constructor(element) {
        this.element = element;
        this.next = null;
    }
}

/** 基于链表的栈实现 */
class StackList extends IStack {

    /**
     * 栈顶节点
     * @type {Node|null}
     */
    _top = null;

    /**
     * 获取栈的大小
     * @returns {number} 栈的大小
     */
    _size = 0;

    size() { return this._size; }

    push(element) {
        const node = new Node(element);
        node.next = this._top;
        this._top = node;
        this._size++;
    }

    pop() {
        if (this._top === null) { throw new Error('Stack is empty'); }
        const element = this._top.element;
        this._top = this._top.next;
        this._size--;
        return element;
    }

    peek() {
        if (this._top === null) { throw new Error('Stack is empty'); }
        return this._top.element;
    }

}

/** 基于数组的栈实现 */
class StackArray extends IStack {

    /**
     * 栈数组
     * @type {any[]}
     */
    arr = [];

    size() { return this.arr.length; }

    push(element) {
        this.arr.push(element);
    }

    pop() {
        if (this.arr.length === 0) { throw new Error('Stack is empty'); }
        return this.arr.pop();
    }

    peek() {
        if (this.arr.length === 0) { throw new Error('Stack is empty'); }
        return this.arr[this.arr.length - 1];
    }

}

/**
 * 断言函数
 * @param {boolean} condition 断言条件
 * @param {string} message 断言失败时的错误信息
 */
function assert(condition, message) { if (!condition) { throw new Error(message); } }

/**
 * 测试函数
 * @param {IStack} stack 待测试的栈
 * @returns {void}
 */
function test(stack) {
    assert(stack.size() === 0, 'Stack should be empty');

    for (let i = 0; i < 10; i++) {
        stack.push(i);
        assert(stack.size() === i + 1, `Stack size should be ${i + 1}`);
        assert(stack.peek() === i, `Stack peek should be ${i}`);
    }

    for (let i = 9; i >= 0; i--) {
        assert(stack.pop() === i, `Stack pop should be ${i}`);
        assert(stack.size() === i, `Stack size should be ${i}`);
    }

    try { stack.pop(); } catch (error) { }
    try { stack.peek(); } catch (error) { }
}

test(new StackList());
test(new StackArray());
console.log('All tests passed!');
