/*
基于 typescript 实现的常用查找算法
*/

export { }

/**
 * 线性查找
 * @param arr 待查找数组
 * @param target 待查找目标元素
 * @return 目标元素在数组中的下标，如果不存在则返回 -1
 */
function seqSearch<T>(arr: T[], target: T): number {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) { return i; }
    }
    return -1;
}

/**
 * 二分查找
 * @param arr 待查找数组
 * @param target 待查找目标元素
 * @return 目标元素在数组中的下标，如果不存在则返回 -1
 */
function binSearch<T>(arr: T[], target: T): number {
    let left = 0, right = arr.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] === target) { return mid; }
        else if (arr[mid] < target) { left = mid + 1; }
        else { right = mid - 1; }
    }
    return -1;
}

/**
 * 断言函数
 * @param condition 断言条件
 * @param msg 断言失败时的提示信息
 * @throws 断言失败时抛出异常
 */
function assert(condition: boolean, msg: string = ''): void { if (!condition) throw new Error(msg); }

let arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
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
