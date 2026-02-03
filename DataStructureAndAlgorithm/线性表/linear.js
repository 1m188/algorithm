/*

基于 js 的线性表实现

*/

(() => {

    /** 线性表接口 */
    class ILinear {

        constructor() { if (this.constructor === ILinear) throw new Error('抽象类不能实例化'); }

        /**
         * 只读属性：线性表元素个数
         * @type {number}
         */
        get size() { throw new Error('必须重写 size 方法') }

        /**
         * 在线性表尾部添加元素
         * @param {*} element 待添加的数据
         * @returns {boolean} 添加成功返回 true，否则返回 false
         */
        push(element) { throw new Error('必须重写 push 方法'); }

        /**
         * 从线性表尾部删除元素，当线性表为空时返回 false
         * @returns {boolean} 删除成功返回 true，否则返回 false
         */
        pop() { throw new Error('必须重写 pop 方法'); }

        /**
         * 在线性表中插入元素
         * @param {number} index 插入位置
         * @param {*} element 待插入的数据
         * @returns {boolean} 插入成功返回 true，否则返回 false
         */
        insert(index, element) { throw new Error('必须重写 insert 方法') }

        /**
         * 在线性表中删除元素
         * @param {*} index 待删除的位置索引
         * @returns {boolean} 删除成功返回 true，否则返回 false
         */
        remove(index) { throw new Error('必须重写 remove 方法') }

        /**
         * 查找某个元素第一次出现的索引
         * @param {*} element 待查找的元素
         * @returns {number} 返回元素第一次出现的索引，如果不存在则返回 -1
         */
        search(element) { throw new Error('必须重写 search 方法') }

        /**
         * 获取指定索引处的元素，如果索引不存在则抛出异常
         * @param {*} index 索引
         * @return {*} 返回指定索引处的元素
         */
        get(index) { throw new Error('必须重写 get 方法') }

        /**
         * 设置指定索引处的元素，如果索引不存在则返回 false
         * @param {*} index 索引
         * @param {*} element 待设置的元素
         * @return {boolean} 设置成功返回 true，否则返回 false
         */
        set(index, element) { throw new Error('必须重写 set 方法') }

    }

    /** 链表节点 */
    class Node {

        /**
         * 节点元素
         * @type {*}
         */
        val;

        /**
         * 指向下一个节点的指针
         * @type {Node|null}
         */
        next;

        /**
         * 构造函数
         * @param {*} val 初始化元素值
         */
        constructor(val) {
            this.val = val;
            this.next = null;
        }

    }

    /** 基于链表的线性表实现 */
    class LinearList extends ILinear {

        /**
         * 节点数目
         * @type {number}
         */
        #size = 0;

        /**
         * 头节点
         * @type {Node|null}
         */
        #head = null;

        /**
         * 尾节点
         * @type {Node|null}
         */
        #tail = null;

        constructor() { super(); }

        get size() { return this.#size }

        push(element) {
            let node = null;
            try { node = new Node(element); }
            catch (error) { return false; }
            if (this.#size === 0) {
                this.#head = node;
                this.#tail = node;
            } else {
                this.#tail.next = node;
                this.#tail = node;
            }
            this.#size++;
            return true; // 返回true表示添加成功
        }

        pop() {
            if (this.#size === 0) return false; // 返回false表示删除失败

            if (this.#size === 1) {
                this.#head = null;
                this.#tail = null;
            } else {
                let prev = this.#head;
                while (prev.next !== this.#tail) prev = prev.next;
                prev.next = null;
                this.#tail = prev;
            }
            this.#size--;
            return true;
        }

        insert(index, element) {
            if (!Number.isInteger(index) || index < 0 || index > this.#size) return false; // 返回false表示插入失败

            let node = null;
            try { node = new Node(element); }
            catch (error) { return false; }
            if (index === 0 && this.#size === 0) {
                this.#head = node;
                this.#tail = node;
            } else if (index === 0) {
                node.next = this.#head;
                this.#head = node;
            } else if (index === this.#size) {
                this.#tail.next = node;
                this.#tail = node;
            } else {
                let prev = this.#head;
                for (let i = 0; i < index - 1; i++) prev = prev.next;
                node.next = prev.next;
                prev.next = node;
            }
            this.#size++;
            return true;
        }

        remove(index) {
            if (!Number.isInteger(index) || index < 0 || index >= this.#size) return false; // 返回false表示删除失败

            if (this.#size === 1) {
                this.#head = null;
                this.#tail = null;
            }

            if (index === 0) {
                this.#head = this.#head.next;
            } else {
                let prev = this.#head;
                for (let i = 0; i < index - 1; i++) prev = prev.next;
                prev.next = prev.next.next;
            }
            this.#size--;
            return true;
        }

        search(element) {
            let node = this.#head;
            for (let i = 0; i < this.#size; i++, node = node.next) {
                if (node.val === element) return i;
            }
            return -1;
        }

        get(index) {
            if (!Number.isInteger(index) || index < 0 || index >= this.#size) throw new Error('Index out of range');
            let node = this.#head;
            for (let i = 0; i < index; i++) node = node.next;
            return node.val;
        }

        set(index, element) {
            if (!Number.isInteger(index) || index < 0 || index >= this.#size) return false;
            let node = this.#head;
            for (let i = 0; i < index; i++) node = node.next;
            node.val = element;
            return true;
        }

    }

    /** 基于数组的线性表实现 */
    class LinearArray extends ILinear {

        /**
         * 数组
         * @type {Array}
         */
        #arr = [];

        constructor() { super(); }

        get size() { return this.#arr.length; }

        push(element) {
            try { this.#arr.push(element); }
            catch (error) { return false; }
            return true;
        }

        pop() {
            if (this.#arr.length === 0) return false;
            this.#arr.pop();
            return true;
        }

        insert(index, element) {
            if (!Number.isInteger(index) || index < 0 || index > this.#arr.length) return false;
            if (index === this.#arr.length) return this.push(element);
            this.#arr.splice(index, 0, element);
            return true;
        }

        remove(index) {
            if (!Number.isInteger(index) || index < 0 || index >= this.#arr.length) return false;
            this.#arr.splice(index, 1);
            return true;
        }

        search(element) { return this.#arr.indexOf(element); }

        get(index) {
            if (!Number.isInteger(index) || index < 0 || index >= this.#arr.length) throw new Error('Index out of range');
            return this.#arr[index];
        }

        set(index, element) {
            if (!Number.isInteger(index) || index < 0 || index >= this.#arr.length) return false;
            this.#arr[index] = element;
            return true;
        }

    }

    /**
     * 测试函数
     * @param {ILinear} linear 线性表实例
     * @returns {void}
     */
    function test(linear) {

        /**
         * 断言
         * @param {boolean} condition 条件
         * @param {string} message 错误信息
         */
        function assert(condition, message) { if (!condition) throw new Error(message); }

        for (let i = 0; i < 10; i++) {
            linear.push(i);
            assert(linear.size === i + 1, `Push failed, expected linear.size === ${i} + 1`);
            assert(linear.get(i) === i, `Push failed, expected linear.get(${i}) === ${i}, got ${linear.get(i)} === ${i}`);
            assert(linear.search(i) === i, `Push failed, expected linear.search(${i}) === ${i}, got ${linear.search(i)} === ${i}`);
        }

        linear.insert(5, 100);
        assert(linear.get(5) === 100, `Insert failed, expected linear.get(5) === 100`);
        assert(linear.search(100) === 5, `Insert failed, expected linear.search(100) === 5`);

        linear.set(5, 200);
        assert(linear.get(5) === 200, `Set failed, expected linear.get(5) === 200`);
        assert(linear.search(100) == -1, `Set failed, expected linear.search(100) === -1`);
        assert(linear.search(200) === 5, `Set failed, expected linear.search(200) === 5`);

        linear.remove(5);
        assert(linear.get(5) === 5, `Remove failed, expected linear.get(5) === 5, got ${linear.get(5)} === 5`);
        assert(linear.search(100) === -1, `Remove failed, expected linear.search(100) === -1`);

        for (let i = 10; i > 0; i--) {
            assert(linear.size === i, `Pop failed, expected linear.size === ${i}`);
            assert(linear.get(linear.size - 1) === i - 1, `Pop failed, expected linear.get(${linear.size - 1}) === ${i - 1}`);
            assert(linear.search(i - 1) === linear.size - 1, `Pop failed, expected linear.search(${i - 1}) === ${linear.size - 1}`);
            linear.pop();
        }

    }


    /** 测试 */

    console.log('Testing LinearList...');
    test(new LinearList());
    console.log('All tests passed!');

    console.log('Testing LinearArray...');
    test(new LinearArray());
    console.log('All tests passed!');

})();
