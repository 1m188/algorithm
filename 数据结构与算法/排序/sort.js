/*

排序算法

*/

/**
 * 生成一个随机整数组
 * @param {number} len 数组长度
 * @param {number} left 随机整数的下界范围
 * @param {number} right 随机整数的上界范围
 * @returns {number[]} 一个生成的随机整数组
 */
function genRandVec(len, left, right) {
    let vec = [];
    while (len > 0) {
        vec.push(parseInt(Math.random() * (right - left + 1) + left));
        len--;
    }
    return vec;
}

/**
 * 输出一个数组
 * @param {Array} vec 待输出数组
 * @param {string} prefix 输出前缀
 */
function printVec(vec, prefix) {
    process.stdout.write(prefix + ":");
    for (const e of vec)
        process.stdout.write(' ' + e);
    console.log();
}

// /*********************************************************************************************************************/

// 插入类排序

/**
 * 直接插入排序
 * @param {Array} vec 待排序数组
 */
// 时间复杂度最好O(n)，最坏O(n^2)，平均O(n^2)
// 空间复杂度O(1)
// 稳定
function insertSort(vec) {
    for (let i = 1; i < vec.length; i++) {
        let tmp = vec[i];
        let idx = i - 1;
        for (; idx >= 0 && vec[idx] > tmp; idx--)
            vec[idx + 1] = vec[idx];
        vec[idx + 1] = tmp;
    }
}

/**
 * 从数组的顺序部分[left,right]寻找下一个元素要被插入的位置
 * @param {Array} vec 待寻找数组
 * @param {number} left 寻找范围左闭边界索引
 * @param {number} right 寻找范围右闭边界索引
 * @param {any} target 待插入的元素
 * @returns {number} 待插入索引
 */
function bindex(vec, left, right, target) {
    let mid = parseInt((left + right) / 2);
    while (left < right) {
        if (vec[mid] === target)
            return mid + 1;
        else if (vec[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
        mid = parseInt((left + right) / 2);
    }
    return vec[mid] <= target ? mid + 1 : mid;
}

/**
 * 折半插入排序
 * @param {Array} vec 待排序数组
 */
// 时间复杂度最好O(nlog2n)，最坏O(n^2)，平均O(n^2)
// 空间复杂度O(1)
// 稳定
function binsertSort(vec) {
    for (let i = 1; i < vec.length; i++) {
        let index = bindex(vec, 0, i - 1, vec[i]);
        let tmp = vec[i];
        let idx = i - 1;
        for (; idx >= index; idx--)
            vec[idx + 1] = vec[idx];
        vec[idx + 1] = tmp;
    }
}

/**
 * 希尔排序
 * @param {Array} vec 待排序数组
 * @param {number} k 初始增量
 * @param {Function} kfun 增量选取函数
 */
// 时间复杂度和增量选取有关，平均O(nlog2n)
// 空间复杂度O(1)
// 不稳定
function shellSort(vec, k, kfun) {
    while (k > 1) {
        for (let i = 0; i < k; i++)
            for (let j = i + k; j < vec.length; j += k) {
                let tmp = vec[j];
                let idx = j - k;
                for (; idx >= i && vec[idx] > tmp; idx -= k) // 这里注意要和vec[j]即tmp比较，为它寻找一个插入的地方，而不是和vec[idx+1]比较，会出错
                    vec[idx + k] = vec[idx];
                vec[idx + k] = tmp;
            }
        k = kfun(k);
    }
    for (let i = 1; i < vec.length; i++) {
        let tmp = vec[i];
        let idx = i - 1;
        for (; idx >= 0 && vec[idx] > tmp; idx--) // 同上
            vec[idx + 1] = vec[idx];
        vec[idx + 1] = tmp;
    }
}

// 交换类排序

/**
 * 冒泡排序
 * @param {Array} vec 待排序数组
 */
// 时间复杂度最好O(n)，最坏O(n^2)，平均O(n^2)
// 空间复杂度O(1)
// 稳定
function bubbleSort(vec) {
    for (let i = vec.length - 1; i >= 1; i--) {
        let flag = false;
        for (let j = 0; j < i; j++)
            if (vec[j] > vec[j + 1]) {
                [vec[j], vec[j + 1]] = [vec[j + 1], vec[j]];
                flag = true;
            }
        if (!flag)
            return;
    }
}

/**
 * 快速排序
 * @param {Array} vec 待排序数组
 * @param {number} left 待排序部分的左闭区间边界索引
 * @param {number} right 待排序部分的右闭区间边界索引
 */
// 时间复杂度最好O(nlog2n)，最坏O(n^2)，数据越无序越好，越有序越差，在所有O(nlog2n)的算法中基本操作次数多项式最高次项最小
// 空间复杂度O(log2n)
// 不稳定
function quickSort(vec, left, right) {
    if (left >= right)
        return;
    let tmp = vec[left];
    let low = left, high = right;
    while (low < high) {
        while (low < high && vec[high] > tmp)
            high--;
        if (low < high)
            vec[low++] = vec[high]; // 注意high不能够动，它的值给出去了其本身就空着了，找一个low那边比它小的赋给它
        while (low < high && vec[low] < tmp)
            low++;
        if (low < high)
            vec[high--] = vec[low]; // 同上
    }
    vec[low] = tmp;
    quickSort(vec, left, low - 1);
    quickSort(vec, low + 1, right);
}

// 选择类排序

/**
 * 直接选择排序
 * @param {Array} vec 待排序数组
 */
// 时间复杂度O(n^2)
// 空间复杂度O(1)
// 不稳定
function selectSort(vec) {
    for (let i = 0; i < vec.length - 1; i++) {
        let idx = i;
        for (let j = i + 1; j < vec.length; j++)
            if (vec[j] < vec[idx])
                idx = j;
        [vec[idx], vec[i]] = [vec[i], vec[idx]];
    }
}

/**
 * 调整堆数组
 * @param {Array} vec 待排序数组
 * @param {number} left 数组中待调整部分闭区间左边界索引
 * @param {number} right 数组中待调整部分闭区间右边界索引
 */
function heapAdjust(vec, left, right) {
    let tmp = vec[left];
    let m = left * 2 + 1;
    while (m <= right) {
        if (m + 1 <= right && vec[m + 1] > vec[m])
            m++;
        if (vec[m] > tmp) {
            vec[left] = vec[m];
            left = m;
            m = left * 2 + 1;
        } else
            break;
    }
    vec[left] = tmp;
}

/**
 * 堆排序
 * @param {Array} vec 待排序数组
 */
// 时间复杂度O(nlog2n)
// 空间复杂度O(1)，在相同时间的算法里是最好的
// 不稳定
function heapSort(vec) {
    for (let i = parseInt((vec.length - 2) / 2); i >= 0; i--)
        heapAdjust(vec, i, vec.length - 1); // 注意这里是从最后一个不为叶节点的节点开始，每次以当前节点为根节点进行调整
    for (let i = vec.length - 1; i >= 1; i--) {
        [vec[0], vec[i]] = [vec[i], vec[0]];
        heapAdjust(vec, 0, i - 1);
    }
}

// 其他排序算法

/**
 * 将数组中两个有序部分归并起来
 * @param {Array} vec 待排序数组
 * @param {number} left 左待归并部分左边界索引
 * @param {number} mid 左右待归并部分分界索引，左部分的右边界索引，右部分的左边界索引-1
 * @param {number} right 右待归并部分右边界索引
 */
function merge(vec, left, mid, right) {
    let lvec = vec.slice(left, mid + 1);
    let rvec = vec.slice(mid + 1, right + 1);
    let li = 0, ri = 0;
    while (li < lvec.length && ri < rvec.length)
        if (lvec[li] <= rvec[ri])
            vec[left++] = lvec[li++];
        else
            vec[left++] = rvec[ri++];
    while (li < lvec.length)
        vec[left++] = lvec[li++];
    while (ri < rvec.length)
        vec[left++] = rvec[ri++];
}

/**
 * 归并排序
 * @param {Array} vec 待排序数组
 * @param {number} left 数组中待归并部分左闭区间边界索引
 * @param {number} right 数组中待归并部分右闭区间边界索引
 */
// 时间复杂度O(nlog2n)
// 空间复杂度O(n)
// 稳定
function mergeSort(vec, left, right) {
    if (left >= right)
        return;
    let mid = parseInt((left + right) / 2);
    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

/**
 * 基数排序每趟分桶排序
 * @param {Array} vec 待排序数组
 * @param {number} k 从低位开始按照第几位数进行排序
 */
function radix(vec, k) {
    let qvec = new Array();
    for (let i = 0; i < 10; i++)
        qvec.push(new Array());
    let m = Math.pow(10, k - 1);
    vec.forEach(e => {
        qvec[parseInt(e / m) % 10].push(e);
    });
    vec.splice(0);
    qvec.forEach(e => {
        while (e.length > 0)
            vec.push(e.shift());
    });
}

/**
 * 基数排序
 * @param {Array} vec 待排序数组
 * @param {number} k 关键字位数
 */
// 时间复杂度为O(d*(rd+n))，其中d为关键字位数（排序几趟），rd为关键字基个数（0-9），n为元素个数
// 空间复杂度为O(rd)，rd个队列
// 稳定
function radixSort(vec, k) {
    for (let i = 1; i <= k; i++)
        radix(vec, i);
}

/**
 * 双向冒泡排序
 * @param {Array} vec 待排序数组
 */
// 时间复杂度最好O(n)，最坏O(n^2)
// 空间复杂度O(1)
// 稳定
function dbubbleSort(vec) {
    let left = 0, right = vec.length - 1;
    while (left < right) {
        let flag = false;
        for (let i = left; i < right; i++)
            if (vec[i] > vec[i + 1]) {
                [vec[i], vec[i + 1]] = [vec[i + 1], vec[i]];
                flag = true;
            }
        right--;
        for (let i = right; i > left; i--)
            if (vec[i] < vec[i - 1]) {
                [vec[i], vec[i - 1]] = [vec[i - 1], vec[i]];
                flag = true;
            }
        left++;
        if (!flag)
            return;
    }
}

/**
 * 计数排序
 * @param {Array} vec 待排序数组
 * @param {Array} rvec 结果放置数组
 */
// 时间复杂度O(n^2)
// 空间复杂度O(n)
function calcSort(vec, rvec) {
    if (rvec.length != vec.length) {
        rvec.splice(0);
        for (let i = 0; i < vec.length; i++)
            rvec.push(0);
    }
    vec.forEach(e => {
        let index = 0;
        vec.forEach(ee => {
            if (ee < e)
                index++;
        });
        rvec[index] = e;
    });
}

// /*********************************************************************************************************************/

/**
 * 主函数
 */
function main() {
    const len = 10;
    let randvec = genRandVec(len, 0, 100);
    printVec(randvec, "original vec");
    let vec;

    vec = JSON.parse(JSON.stringify(randvec));
    insertSort(vec);
    printVec(vec, "after insert sort");

    vec = JSON.parse(JSON.stringify(randvec));
    binsertSort(vec);
    printVec(vec, "after binary insert sort");

    vec = JSON.parse(JSON.stringify(randvec));
    shellSort(vec, 3, k => { return parseInt(k / 2); });
    printVec(vec, "after shell sort");

    vec = JSON.parse(JSON.stringify(randvec));
    bubbleSort(vec);
    printVec(vec, "after bubble sort");

    vec = JSON.parse(JSON.stringify(randvec));
    quickSort(vec, 0, len - 1);
    printVec(vec, "after quick sort");

    vec = JSON.parse(JSON.stringify(randvec));
    selectSort(vec);
    printVec(vec, "after select sort");

    vec = JSON.parse(JSON.stringify(randvec));
    heapSort(vec);
    printVec(vec, "after heap sort");

    vec = JSON.parse(JSON.stringify(randvec));
    mergeSort(vec, 0, len - 1);
    printVec(vec, "after merge sort");

    vec = JSON.parse(JSON.stringify(randvec));
    radixSort(vec, 3);
    printVec(vec, "after radix sort");

    vec = JSON.parse(JSON.stringify(randvec));
    dbubbleSort(vec);
    printVec(vec, "after dbubble sort");

    vec = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
    let rvec = new Array();
    calcSort(vec, rvec);
    printVec(rvec, "after calc sort");
}

main();