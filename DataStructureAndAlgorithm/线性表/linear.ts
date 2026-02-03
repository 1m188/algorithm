/*

基于 ts 实现的线性表

*/

export { }

/** 线性表接口 */
interface ILinear<T> {

    /** 获取线性表长度 */
    readonly length: number;

    /**
     * 在线性表尾部添加元素
     * @param item 待添加的元素
     * @return 添加成功返回 true ，否则返回 false
     */
    push(item: NonNullable<T>): boolean;

    /**
     * 在线性表尾部删除元素，并且返回被删除的元素
     * @return 删除成功返回被删除的元素，否则返回 null
     */
    pop(): T | null;

    /**
     * 在指定位置插入元素
     * @param index 插入位置
     * @param item 待插入的元素
     * @return 插入成功返回 true，否则返回 false
     */
    insert(index: number, item: NonNullable<T>): boolean;

    /**
     * 在指定位置删除元素
     * @param index 删除位置
     * @return 删除成功返回被删除的元素，否则返回 null
     */
    remove(index: number): T | null;

    /**
     * 查找元素第一次出现的位置索引
     * @param item 待查找的元素
     * @return 返回元素第一次出现的位置索引，如果不存在则返回 -1
     */
    search(item: NonNullable<T>): number;

    /**
     * 获取指定位置的元素，如果位置不合法则返回 null
     * @param index 指定位置
     * @return 返回指定位置的元素，如果位置不合法则返回 null
     */
    get(index: number): T | null;

    /**
     * 设置指定位置的元素，如果位置不合法则返回 false
     * @param index 指定位置
     * @param item 待设置的元素
     * @return 设置成功返回 true，否则返回 false
     */
    set(index: number, item: NonNullable<T>): boolean;

}

/** 链表节点 */
class Node<T> {
    public val: NonNullable<T>;
    public next: Node<T> | null;
    constructor(val: NonNullable<T>) {
        this.val = val;
        this.next = null;
    }
}

/** 基于链表的线性表实现 */
class LinearList<T> implements ILinear<T> {

    /** 线性表长度 */
    private _length: number = 0;

    /** 头结点 */
    private _head: Node<T> | null = null;

    /** 尾结点 */
    private _tail: Node<T> | null = null;

    get length() { return this._length; }

    push(item: NonNullable<T>): boolean {
        const node = new Node(item);
        if (this._head === null) {
            this._head = node;
            this._tail = node;
        } else {
            this._tail!.next = node;
            this._tail = node;
        }
        this._length++;
        return true;
    }

    pop(): T | null {
        if (this._length === 0) return null; // 空表

        if (this._length === 1) {
            const val = this._head!.val;
            this._head = null;
            this._tail = null;
            this._length--;
            return val;
        } else {
            let pre = this._head;
            while (pre!.next !== this._tail) {
                pre = pre!.next;
            }
            const val = this._tail!.val;
            pre!.next = null;
            this._tail = pre;
            this._length--;
            return val;
        }
    }

    insert(index: number, item: NonNullable<T>): boolean {
        if (!Number.isInteger(index) || index < 0 || index > this._length) return false;

        const node = new Node(item);
        if (this._length === 0) {
            this._head = node;
            this._tail = node;
        } else if (index === 0) {
            node.next = this._head;
            this._head = node;
        } else if (index === this._length) {
            this._tail!.next = node;
            this._tail = node;
        } else {
            let pre = this._head;
            for (let i = 0; i < index - 1; i++) {
                pre = pre!.next;
            }
            node.next = pre!.next;
            pre!.next = node;
        }
        this._length++;
        return true;
    }

    remove(index: number): T | null {
        if (!Number.isInteger(index) || index < 0 || index >= this._length) return null;

        if (this._length === 1) {
            const val = this._head!.val;
            this._head = null;
            this._tail = null;
            this._length--;
            return val;
        } else if (index === 0) {
            const val = this._head!.val;
            this._head = this._head!.next;
            this._length--;
            return val;
        } else {
            let pre = this._head;
            for (let i = 0; i < index - 1; i++) {
                pre = pre!.next;
            }
            const val = pre!.next!.val;
            pre!.next = pre!.next!.next;
            this._length--;
            return val;
        }
    }

    search(item: NonNullable<T>): number {
        for (let i = 0, node = this._head; i < this._length; i++, node = node!.next) {
            if (node!.val === item) return i;
        }
        return -1;
    }

    get(index: number): T | null {
        if (!Number.isInteger(index) || index < 0 || index >= this._length) return null;
        let node = this._head;
        for (let i = 0; i < index; i++) {
            node = node!.next;
        }
        return node!.val;
    }

    set(index: number, item: NonNullable<T>): boolean {
        if (!Number.isInteger(index) || index < 0 || index >= this._length) return false;
        let node = this._head;
        for (let i = 0; i < index; i++) {
            node = node!.next;
        }
        node!.val = item;
        return true;
    }

}

/** 基于数组的线性表实现 */
class LinearArray<T> implements ILinear<T> {

    /** 数组 */
    private _array: T[] = [];

    get length(): number { return this._array.length; }

    push(item: NonNullable<T>): boolean {
        this._array.push(item);
        return true;
    }

    pop(): T | null {
        return this._array.pop() || null;
    }

    insert(index: number, item: NonNullable<T>): boolean {
        if (!Number.isInteger(index) || index < 0 || index > this._array.length) return false;
        if (index === this._array.length) return this.push(item);
        this._array.splice(index, 0, item);
        return true;
    }

    remove(index: number): T | null {
        if (!Number.isInteger(index) || index < 0 || index >= this._array.length) return null;
        return this._array.splice(index, 1)[0];
    }

    search(item: NonNullable<T>): number {
        return this._array.indexOf(item);
    }

    get(index: number): T | null {
        if (!Number.isInteger(index) || index < 0 || index >= this._array.length) return null;
        return this._array[index];
    }

    set(index: number, item: NonNullable<T>): boolean {
        if (!Number.isInteger(index) || index < 0 || index >= this._array.length) return false;
        this._array[index] = item;
        return true;
    }

}

/**
 * 测试函数
 * @param linear 线性表
 */
function test(linear: ILinear<number>): void {

    /**
     * 断言
     * @param condition 条件
     * @param message 错误信息
     */
    function assert(condition: boolean, message: string): void { if (!condition) throw new Error(message); }

    for (let i = 0; i < 10; i++) {
        linear.push(i);
        assert(linear.length === i + 1, `Push failed, expected linear.length === ${i} + 1`);
        assert(linear.get(i) === i, `Push failed, expected linear.get(${i}) === ${i}, got ${linear.get(i)} === ${i}`);
        assert(linear.search(i) === i, `Push failed, expected linear.search(${i}) === ${i}, got ${linear.search(i)} === ${i}`);
    }

    linear.insert(5, 100);
    assert(linear.get(5) === 100, `Insert failed, expected linear.get(5) === 100`);
    assert(linear.search(100) === 5, `Insert failed, expected linear.search(100) === 5`);

    linear.set(5, 200);
    assert(linear.get(5) === 200, `Set failed, expected linear.get(5) === 200`);
    assert(linear.search(100) === -1, `Set failed, expected linear.search(100) === -1`);
    assert(linear.search(200) === 5, `Set failed, expected linear.search(200) === 5`);

    linear.remove(5);
    assert(linear.get(5) === 5, `Remove failed, expected linear.get(5) === 5, got ${linear.get(5)} === 5`);
    assert(linear.search(100) === -1, `Remove failed, expected linear.search(100) === -1`);

    for (let i = 10; i > 0; i--) {
        assert(linear.length === i, `Pop failed, expected linear.length === ${i}`);
        assert(linear.get(linear.length - 1) === i - 1, `Pop failed, expected linear.get(${linear.length - 1}) === ${i - 1}`);
        assert(linear.search(i - 1) === linear.length - 1, `Pop failed, expected linear.search(${i - 1}) === ${linear.length - 1}`);
        linear.pop();
    }

}

(() => {

    console.log('Testing LinearList...');
    test(new LinearList());
    console.log('All tests passed!');

    console.log('Testing LinearArray...');
    test(new LinearArray());
    console.log('All tests passed!');

})();
