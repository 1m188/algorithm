"""
基于 Python 的斐波那契数列计算

求 第 n 项斐波那契数列的值
"""

import sys
from typing import Callable


def fibonacci_circle(n: int) -> int:
    if n <= 0:
        raise ValueError("n must be positive")
    if n == 1:
        return 1
    if n == 2:
        return 1
    a, b = 1, 1
    for _ in range(3, n + 1):
        a, b = b, a + b
    return b


def fibonacci_recursive(n: int) -> int:
    if n <= 0:
        raise ValueError("n must be positive")
    if n == 1:
        return 1
    if n == 2:
        return 1
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)


def fibonacci_tail(n: int) -> int:
    if n <= 0:
        raise ValueError("n must be positive")
    if n == 1:
        return 1
    if n == 2:
        return 1

    def fib_tail(n: int, a: int, b: int) -> int:
        if n == 2:
            return b
        return fib_tail(n - 1, b, a + b)

    return fib_tail(n, 1, 1)


def test(fib: Callable[[int], int]) -> None:
    try:
        fib(0)
    except Exception as e:
        print(f"fib(0) raise {e}")

    try:
        fib(-1)
    except Exception as e:
        print(f"fib(-1) raise {e}")

    assert fib(1) == 1
    assert fib(2) == 1
    assert fib(3) == 2
    assert fib(4) == 3
    assert fib(5) == 5
    assert fib(6) == 8
    assert fib(7) == 13
    assert fib(8) == 21
    assert fib(9) == 34
    assert fib(10) == 55
    assert fib(11) == 89
    assert fib(12) == 144


if __name__ == "__main__":
    sys.set_int_max_str_digits(0)
    test(fibonacci_circle)
    test(fibonacci_recursive)
    test(fibonacci_tail)
    print("All tests passed!")

    print(fibonacci_circle(114514))
