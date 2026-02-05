/*
基于 JavaScript 实现的常用查找算法
*/

export { };

/**
 * 线性查找
 * @param {number[]} arr 数组
 * @param {number} value 要查找的值
 * @return {number} 返回值在数组中的索引，如果不存在则返回 -1
 */
function seqSearch(arr, value) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === value) { return i; }
    }
    return -1;
}

/**
 * 二分查找
 * @param {number[]} arr 数组
 * @param {number} value 要查找的值
 * @return {number} 返回值在数组中的索引，如果不存在则返回 -1
 */
function binSearch(arr, value) {
    let left = 0, right = arr.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] === value) { return mid; }
        else if (arr[mid] < value) { left = mid + 1; }
        else { right = mid - 1; }
    }
    return -1;
}

/**
 * 断言函数
 * @param {boolean} condition 条件
 * @param {string} msg 错误信息
 * @returns {void}
 */
function assert(condition, msg = '') { if (!condition) throw new Error(msg); }

// 测试 线性查找
let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
assert(seqSearch(arr, 1) === 0);
assert(seqSearch(arr, 10) === 9);
assert(seqSearch(arr, 5) === 4);
assert(seqSearch(arr, 11) === -1);

arr = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
assert(seqSearch(arr, 1) === 9);
assert(seqSearch(arr, 10) === 0);
assert(seqSearch(arr, 5) === 5);
assert(seqSearch(arr, 11) === -1);

arr = [1];
assert(seqSearch(arr, 1) === 0);
assert(seqSearch(arr, 2) === -1);

arr = [];
assert(seqSearch(arr, 1) === -1);

// 测试 二分查找
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
assert(binSearch(arr, 1) === 0);
assert(binSearch(arr, 10) === 9);
assert(binSearch(arr, 5) === 4);
assert(binSearch(arr, 11) === -1);

arr = [1];
assert(binSearch(arr, 1) === 0);
assert(binSearch(arr, 2) === -1);

arr = [];
assert(binSearch(arr, 1) === -1);

console.log('All tests passed!');
