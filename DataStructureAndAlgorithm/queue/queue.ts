/*
基于 typescript 的队列实现
*/

export { };

interface IQueue<T> {

    /** 队列长度 */
    readonly length: number;

    /**
     * 向队列尾部添加一个元素
     * @param element 要添加的元素
     */
    enqueue(element: T): void;

    /**
     * 移除队列的第一个元素，并返回该元素, 如果队列为空，则抛出异常
     * @returns 移除的元素
     */
    dequeue(): T;

    /**
     * 返回队列的第一个元素，不改变队列, 如果队列为空，则抛出异常
     * @returns 队列的第一个元素
     */
    front(): T;

}

/**
 * 链表节点
 * @template T 节点存储的数据类型
 */
class Node<T> {

    /** 节点存储的数据 */
    public value: T;

    /** 下一个节点 */
    public next: Node<T> | null = null;

    public constructor(value: T) {
        this.value = value;
    }

}

/**
 * 基于链表的队列实现
 * @template T 队列存储的数据类型
 */
class QueueList<T> implements IQueue<T> {

    /** 头部节点 */
    private _head: Node<T> | null = null;

    /** 尾部节点 */
    private _tail: Node<T> | null = null;

    /** 队列长度 */
    private _length: number = 0;

    public get length(): number {
        return this._length;
    }

    public enqueue(element: T): void {
        const node = new Node(element);
        if (this._length === 0) {
            this._head = node;
            this._tail = node;
        } else {
            this._tail!.next = node;
            this._tail = node;
        }
        this._length++;
    }

    public dequeue(): T {
        if (this._length === 0) { throw new Error('Queue is empty'); }
        const value = this._head!.value;
        this._head = this._head!.next;
        this._length--;
        if (this._length === 0) { this._tail = null; }
        return value;
    }

    public front(): T {
        if (this._length === 0) { throw new Error('Queue is empty'); }
        return this._head!.value;
    }

}

/**
 * 基于数组的队列实现
 * @template T 队列存储的数据类型
 */
class QueueArray<T> implements IQueue<T> {

    private _arr: T[] = [];

    public get length(): number {
        return this._arr.length;
    }

    public enqueue(element: T): void {
        this._arr.push(element);
    }

    public dequeue(): T {
        if (this._arr.length === 0) { throw new Error('Queue is empty'); }
        return this._arr.shift()!;
    }

    public front(): T {
        if (this._arr.length === 0) { throw new Error('Queue is empty'); }
        return this._arr[0];
    }

}

/**
 * 测试函数
 * @param queue 待测试的队列
 */
function test(queue: IQueue<number>): void {

    /**
     * 断言函数
     * @param b 断言条件
     * @param msg 错误信息
     */
    function assert(b: boolean, msg?: string): void { if (!b) { throw new Error(msg); } }

    assert(queue.length === 0, 'queue length should be 0');

    for (let i = 0; i < 10; i++) {
        queue.enqueue(i);
        assert(queue.length === i + 1, `queue length should be ${i + 1}`);
        assert(queue.front() === 0, `queue front should be 0`);
    }

    for (let i = 0; i < 10; i++) {
        assert(queue.dequeue() === i, `queue dequeue should be ${i}`);
        assert(queue.length === 9 - i, `queue length should be ${9 - i}`);
    }

}

test(new QueueList<number>());
test(new QueueArray<number>());
console.log('All tests passed!')
