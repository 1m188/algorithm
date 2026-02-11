/*
基于 JavaScript 的队列实现
*/

export { };

/** 队列接口 */
class IQueue {

    /**
     * 获取队列的长度
     * @returns {number}
     */
    get length() {
        throw new Error('Method not implemented.');
    }

    /**
     * 入队
     * @param {any} val 待入队的元素
     * @return {void}
     */
    enqueue(val) {
        throw new Error('Method not implemented.');
    }

    /**
     * 出队, 如果队列为空则抛出异常
     * @return {any} 出队的元素
     */
    dequeue() {
        throw new Error('Method not implemented.');
    }

    /**
     * 获取队列头部元素, 如果队列为空则抛出异常
     * @return {any} 队列头部元素
     */
    front() {
        throw new Error('Method not implemented.');
    }

}

/** 链表节点 */
class Node {

    constructor(value) {
        /**
         * 节点值
         * @type {any}
         */
        this.value = value;

        /**
         * 下一个节点
         * @type {Node|null}
         */
        this.next = null;
    }

}

/** 基于链表的队列实现 */
class QueueList extends IQueue {

    constructor() {
        super();

        /**
         * 队列头节点
         * @type {Node|null}
         */
        this._head = null;

        /**
         * 队列尾节点
         * @type {Node|null}
         */
        this._tail = null;

        /**
         * 队列长度
         * @type {number}
         */
        this._length = 0;
    }

    get length() {
        return this._length;
    }

    enqueue(val) {
        const node = new Node(val);
        if (this._head === null) {
            this._head = node;
            this._tail = node;
        } else {
            this._tail.next = node;
            this._tail = node;
        }
        this._length++;
    }

    dequeue() {
        if (this._length === 0) { throw new Error('Queue is empty'); }
        if (this._length === 1) {
            const val = this._head.value;
            this._head = this._tail = null;
            this._length--;
            return val;
        } else {
            const val = this._head.value;
            this._head = this._head.next;
            this._length--;
            return val;
        }
    }

    front() {
        if (this._length === 0) { throw new Error('Queue is empty'); }
        return this._head.value;
    }

}

/** 基于数组的队列实现 */
class QueueArray extends IQueue {

    constructor() {
        super();

        /**
         * 队列数组
         * @type {Array}
         */
        this.arr = [];
    }

    get length() {
        return this.arr.length;
    }

    enqueue(val) {
        this.arr.push(val);
    }

    dequeue() {
        if (this.arr.length === 0) { throw new Error('Queue is empty'); }
        return this.arr.shift();
    }

    front() {
        if (this.arr.length === 0) { throw new Error('Queue is empty'); }
        return this.arr[0];
    }

}

/**
 * 测试函数
 * @param {IQueue} queue 待测试队列
 * @returns {void}
 */
function test(queue) {

    /**
     * 断言函数
     * @param {boolean} b 断言条件
     * @param {string} msg 错误信息
     * @return {void}
     */
    function assert(b, msg = '') { if (!b) { throw new Error(msg); } }

    assert(queue.length === 0, 'Queue should be empty');

    for (let i = 0; i < 10; i++) {
        queue.enqueue(i);
        assert(queue.length === i + 1, `Queue length should be ${i + 1}`);
        assert(queue.front() === 0, `Queue front should be 0`);
    }

    for (let i = 0; i < 10; i++) {
        assert(queue.dequeue() === i, `Queue dequeue should be ${i}`);
        assert(queue.length === 10 - i - 1, `Queue length should be ${10 - i - 1}`);
    }

}

test(new QueueList());
test(new QueueArray());
console.log('All tests passed!');
