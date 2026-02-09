/*
基于 typescript 的斐波那契数列计算实现

求 斐波那契数列的第 n 项
*/

export { };

/**
 * 斐波那契数列(非递归)
 * @param n 第 n 项
 * @returns 第 n 项的值
 */
function fibonacci_circle(n: bigint): bigint {
    if (n < 1n) throw new Error('n must be greater than 0');
    if (n === 1n) return 1n;
    if (n === 2n) return 1n;

    let a = 1n, b = 1n;
    for (let i = 3n; i <= n; i++) {
        [a, b] = [b, a + b];
    }
    return b;
}

/**
 * 斐波那契数列(递归)
 * @param n 第 n 项
 * @returns 第 n 项的值
 */
function fibonacci_recursion(n: bigint): bigint {
    if (n < 1n) throw new Error('n must be greater than 0');
    if (n === 1n) return 1n;
    if (n === 2n) return 1n;
    return fibonacci_recursion(n - 1n) + fibonacci_recursion(n - 2n);
}

/**
 * 斐波那契数列(递归尾调用)
 * @param n 第 n 项
 * @returns 第 n 项的值
 */
function fibonacci_recursion_tail(n: bigint): bigint {
    if (n < 1n) throw new Error('n must be greater than 0');
    if (n === 1n) return 1n;

    function loop(n: bigint, a: bigint, b: bigint): bigint {
        return n === 2n ? b : loop(n - 1n, b, a + b);
    }

    return loop(n, 1n, 1n);
}

/**
 * 测试函数
 * @param fib 斐波那契数列计算函数
 */
function test(fib: (n: bigint) => bigint): void {

    /**
     * 断言函数
     * @param condition 条件
     * @param message 错误信息
     */
    function assert(condition: boolean, message: string): void { if (!condition) throw new Error(message); }

    try { fib(0n); throw new Error('test failed'); } catch (e) { }
    try { fib(-1n); throw new Error('test failed'); } catch (e) { }

    assert(fib(1n) === 1n, 'test failed');
    assert(fib(2n) === 1n, 'test failed');
    assert(fib(3n) === 2n, 'test failed');
    assert(fib(4n) === 3n, 'test failed');
    assert(fib(5n) === 5n, 'test failed');
    assert(fib(6n) === 8n, 'test failed');
    assert(fib(7n) === 13n, 'test failed');
    assert(fib(8n) === 21n, 'test failed');
    assert(fib(9n) === 34n, 'test failed');
    assert(fib(10n) === 55n, 'test failed');

    console.log(fib(30n).toString());
}

test(fibonacci_circle);
test(fibonacci_recursion);
test(fibonacci_recursion_tail);
console.log('All tests passed!');

let x = 114514n;
console.log(`fibonacci_circle(${x.toString()}) = ${fibonacci_circle(x).toString()}`);
