'''

八皇后

'''

from typing import Tuple


class NQueen:
    '''
    N皇后
    '''
    def __init__(self):
        self.qpos = []
        self.num = 0

    def qpjud(self, qp: Tuple[int]) -> bool:
        for p in self.qpos:
            if p[0] == qp[0] or p[1] == qp[1] \
               or abs(p[0] - qp[0]) == abs(p[1] - qp[1]):
                return False
        return True

    def calc(self, n: int, r: int = 0):
        if r >= n:
            self.num += 1
            return
        for i in range(n):
            p = (i, r)
            if self.qpjud(p):
                self.qpos.append(p)
                self.calc(n, r + 1)
                self.qpos.pop()

    def nqueen(self, n: int) -> int:
        if n <= 0:
            return 0
        self.qpos.clear()
        self.num = 0
        self.calc(n)
        return self.num


if __name__ == "__main__":
    nqueen = NQueen()
    print(nqueen.nqueen(8))
    print(nqueen.nqueen(10))
