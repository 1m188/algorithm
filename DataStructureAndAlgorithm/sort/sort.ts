/*
基于 typescript 实现的常用排序算法
*/

export { };

/**
 * 插入排序
 * @param arr 待排序数组
 */
function insertSort<T>(arr: T[]): void {
    for (let i = 1; i < arr.length; i++) {
        for (let j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                [arr[j], arr[j - 1]] = [arr[j - 1], arr[j]]
            }
        }
    }
}

/**
 * 希尔排序
 * @param arr 待排序数组
 */
function shellSort<T>(arr: T[]): void {
    for (let gap = Math.floor(arr.length / 2); gap > 0; gap = Math.floor(gap / 2)) {
        for (let i = gap; i < arr.length; i++) {
            for (let j = i; j >= gap; j -= gap) {
                if (arr[j] < arr[j - gap]) {
                    [arr[j], arr[j - gap]] = [arr[j - gap], arr[j]]
                }
            }
        }
    }
}

/**
 * 选择排序
 * @param arr 待排序数组
 */
function selectSort<T>(arr: T[]): void {
    for (let i = 0; i < arr.length; i++) {
        let minIndex = i
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j
            }
        }
        if (minIndex !== i) {
            [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]]
        }
    }
}

/**
 * 冒泡排序
 * @param arr 待排序数组
 */
function bubbleSort<T>(arr: T[]): void {
    for (let i = arr.length - 1; i >= 0; i--) {
        let f = false;
        for (let j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                f = true;
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]]
            }
        }
        if (!f) break;
    }
}

/**
 * 快速排序
 * @param arr 待排序数组
 */
function quickSort<T>(arr: T[]): void {
    function quick(left: number, right: number): void {
        if (left >= right) return;
        let i = left, j = right;
        let pivot = arr[left];
        while (i < j) {
            while (i < j && arr[j] >= pivot) j--;
            if (i < j) arr[i++] = arr[j];
            while (i < j && arr[i] < pivot) i++;
            if (i < j) arr[j--] = arr[i];
        }
        arr[i] = pivot;
        quick(left, i - 1);
        quick(i + 1, right);
    }
    quick(0, arr.length - 1);
}

/**
 * 归并排序
 * @param arr 待排序数组
 */
function mergeSort<T>(arr: T[]): void {
    /**
     * 归并两个有序的数组部分
     * @param left 左边开始的索引（闭区间）
     * @param mid 左边结束的索引（开区间）
     * @param right 右边结束的索引（开区间）
     */
    function mergeArr(left: number, mid: number, right: number): void {
        let i = left, j = mid;
        let tmp: T[] = [];
        while (i < mid && j < right) {
            tmp.push(arr[i] < arr[j] ? arr[i++] : arr[j++]);
        }
        while (i < mid) tmp.push(arr[i++]);
        while (j < right) tmp.push(arr[j++]);
        for (let k = 0; k < tmp.length; k++) {
            arr[left + k] = tmp[k];
        }
    }

    /**
     * 归并一个数组区间内的数据
     * @param left 左边开始的索引（闭区间）
     * @param right 右边结束的索引（开区间）
     */
    function merge(left: number, right: number): void {
        if (left >= right - 1) return;
        let mid = (left + right) >> 1;
        merge(left, mid);
        merge(mid, right);
        mergeArr(left, mid, right);
    }

    merge(0, arr.length);
}

/**
 * 堆排序
 * @param arr 待排序数组
 */
function heapSort<T>(arr: T[]): void {
    /**
     * 调整大根堆
     * @param heap 待调整的堆
     * @param start 调整起始位置索引
     * @param end 调整结束位置索引
     */
    function adjust(heap: T[], start: number, end: number): void {
        while (true) {
            let index = start;
            if (start * 2 + 1 <= end && heap[index] < heap[start * 2 + 1]) { index = start * 2 + 1; }
            if (start * 2 + 2 <= end && heap[index] < heap[start * 2 + 2]) { index = start * 2 + 2; }
            if (index === start) break;
            [heap[start], heap[index]] = [heap[index], heap[start]];
            start = index;
        }
    }

    /**
     * 构建大根堆
     * @param arr 待构建为堆的数组
     */
    function buildHeap(arr: T[]): void {
        for (let i = (arr.length - 1 - 1) >> 1; i >= 0; i--) {
            adjust(arr, i, arr.length - 1);
        }
    }

    buildHeap(arr);
    for (let i = arr.length - 1; i > 0; i--) {
        [arr[0], arr[i]] = [arr[i], arr[0]];
        adjust(arr, 0, i - 1);
    }
}

/**
 * 桶排序
 * @param arr 待排序数组
 */
function bottleSort(arr: number[]): void {
    if (arr.length === 0) return;

    for (let i = 0; i < arr.length; i++) {
        const n = arr[i];
        if (!(Number.isInteger(n) && n >= 0)) throw new Error("桶排序只支持非负整数");
    }

    const bitNum = Math.max(...arr).toString().length;
    for (let i = 0; i < bitNum; i++) {
        const buckets: number[][] = Array.from({ length: 10 }, () => []);
        for (let j = 0; j < arr.length; j++) {
            const index = Math.floor(arr[j] % Math.pow(10, i + 1) / Math.pow(10, i));
            buckets[index].push(arr[j]);
        }
        arr.splice(0, arr.length, ...buckets.flat());
    }
}

/**
 * 计数排序
 * @param arr 待排序数组
 */
function countingSort(arr: number[]): void {
    if (arr.length === 0) return;

    for (let i = 0; i < arr.length; i++) {
        if (!Number.isInteger(arr[i])) throw new Error("计数排序只支持整数");
    }

    const min = Math.min(...arr), max = Math.max(...arr);
    const offset = min;
    const length = max - min + 1;

    let array: number[] = Array.from({ length: length }, () => 0);
    for (let i = 0; i < arr.length; i++) {
        array[arr[i] - offset]++;
    }

    arr.splice(0, arr.length);
    for (let i = 0; i < length; i++) {
        arr.push(...Array.from({ length: array[i] }, () => i + offset));
    }
}

/**
 * 断言函数
 * @param condition 条件
 * @param msg 错误信息
 */
function assert(condition: boolean, msg?: string): void { if (!condition) { throw new Error(msg); } }

/**
 * 测试函数
 * @param sortFunc 待测试的排序函数
 */
function test(sortFunc: (arr: number[]) => void): void {

    /**
     * 判断两个数组是否值相等
     * @param a 数组a
     * @param b 数组b
     * @returns 是否值相等
     */
    function arrEqual(a: number[], b: number[]): boolean { return a.length === b.length && a.every((v, i) => v === b[i]); }

    // 基础排序测试
    let arr = [1, 10, 2, 9, 3, 8, 4, 7, 5, 6];
    sortFunc(arr);
    assert(arrEqual(arr, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]));

    arr = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
    sortFunc(arr);
    assert(arrEqual(arr, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]));

    // 测试已经排序好了的情况
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    sortFunc(arr);
    assert(arrEqual(arr, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]));

    // 测试重复元素情况
    arr = [3, 1, 2, 2, 3, 1, 4, 1, 2];
    sortFunc(arr);
    assert(arrEqual(arr, [1, 1, 1, 2, 2, 2, 3, 3, 4]));

    // 测试单个元素情况
    arr = [1];
    sortFunc(arr);
    assert(arrEqual(arr, [1]));

    // 测试空数组
    arr = [];
    sortFunc(arr);
    assert(arrEqual(arr, []));
}

test(insertSort);
test(shellSort);
test(selectSort);
test(bubbleSort);
test(quickSort);
test(mergeSort);
test(heapSort);
test(bottleSort);
test(countingSort);

console.log('All tests passed!');
