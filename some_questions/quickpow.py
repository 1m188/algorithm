"""
基于 Python 的快速幂实现
"""


def quickpow(x: float, n: int) -> float:
    if x == 0:
        return 0
    if n < 0:
        return quickpow(1 / x, -n)
    if n == 0:
        return 1
    if n == 1:
        return x
    return quickpow(x * x, n >> 1) * (1 if n & 0x1 == 0 else x)


def quickpow_circle(x: float, n: int) -> float:
    """
    快速幂(非递归)

    :param x: 底数
    :type x: float
    :param n: 指数
    :type n: int
    :return: x^n
    :rtype: float
    """

    if x == 0:
        return 0
    if n < 0:
        return quickpow_circle(1 / x, -n)
    if n == 0:
        return 1
    if n == 1:
        return x

    result = 1
    while n > 0:
        if n & 0x1 == 1:
            result *= x
        x *= x
        n >>= 1
    return result


if __name__ == "__main__":
    assert quickpow(2, 0) == 1
    assert quickpow(2, 1) == 2
    assert quickpow(2, 2) == 4
    assert quickpow(2, 3) == 8
    assert quickpow(2, 4) == 16
    assert quickpow(2, 5) == 32
    assert quickpow(2, 6) == 64
    assert quickpow(2, 7) == 128
    assert quickpow(2, 8) == 256
    assert quickpow(2, 9) == 512
    assert quickpow(2, 10) == 1024

    assert quickpow_circle(2, 0) == 1
    assert quickpow_circle(2, 1) == 2
    assert quickpow_circle(2, 2) == 4
    assert quickpow_circle(2, 3) == 8
    assert quickpow_circle(2, 4) == 16
    assert quickpow_circle(2, 5) == 32
    assert quickpow_circle(2, 6) == 64
    assert quickpow_circle(2, 7) == 128
    assert quickpow_circle(2, 8) == 256
    assert quickpow_circle(2, 9) == 512
    assert quickpow_circle(2, 10) == 1024

    print(quickpow_circle(3, 3**3))

    print("All tests passed!")
