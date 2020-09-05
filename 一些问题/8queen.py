'''

八皇后

'''

from typing import Tuple


class NQueen:
    '''
    N皇后
    '''
    def __init__(self):
        self.__qpos = []
        self.__num = 0

    def __qpjud(self, qp: Tuple[int]) -> bool:
        for p in self.__qpos:
            if p[0] == qp[0] or p[1] == qp[1] \
               or abs(p[0] - qp[0]) == abs(p[1] - qp[1]):
                return False
        return True

    def __calc(self, n: int, r: int = 0):
        if r >= n:
            self.__num += 1
            return
        for i in range(n):
            p = (i, r)
            if self.__qpjud(p):
                self.__qpos.append(p)
                self.__calc(n, r + 1)
                self.__qpos.pop()

    def nqueen(self, n: int) -> int:
        if n <= 0:
            return 0
        self.__qpos.clear()
        self.__num = 0
        self.__calc(n)
        return self.__num


if __name__ == "__main__":
    nqueen = NQueen()
    print(nqueen.nqueen(8))
    print(nqueen.nqueen(10))
