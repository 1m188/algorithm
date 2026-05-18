"""

有如下的加法算式。其中每个汉字代表一个数字。
（如存在对齐问题，可参见【图1.png】）

               年
             大年
           过大年
         能过大年
       怎能过大年
     我怎能过大年
+  让我怎能过大年
------------------
   能能能能能能能

请填写“让我怎能过大年” 所代表的整数。
所有数字连在一起，中间不要空格。例如："3125697"。当然，这个不是正确的答案。

注意：只填写一个整数，不要填写任何多余的内容。




"""


def solve():
    # 7个汉字：让(a) 我(b) 怎(c) 能(d) 过(e) 大(f) 年(g)
    # 算式：g + fg + efg + defg + cdefg + bcdefg + abcdefg = ddddddd
    # 即：1000000a + 200000b + 30000c + 4000d + 500e + 60f + 7g = 1111111d
    # 化简：1000000a + 200000b + 30000c + 500e + 60f + 7g = 1107111d
    for d in range(1, 10):
        rhs = 1107111 * d
        for a in range(1, 10):
            if a == d:
                continue
            rem1 = rhs - 1000000 * a
            if rem1 <= 0:
                continue
            for b in range(10):
                if b in (a, d):
                    continue
                rem2 = rem1 - 200000 * b
                if rem2 <= 0:
                    continue
                for c in range(10):
                    if c in (a, b, d):
                        continue
                    rem3 = rem2 - 30000 * c
                    if rem3 <= 0:
                        continue
                    for e in range(10):
                        if e in (a, b, c, d):
                            continue
                        rem4 = rem3 - 500 * e
                        if rem4 <= 0:
                            continue
                        for f in range(10):
                            if f in (a, b, c, d, e):
                                continue
                            rem5 = rem4 - 60 * f
                            if rem5 <= 0 or rem5 % 7 != 0:
                                continue
                            g = rem5 // 7
                            if g > 9 or g in (a, b, c, d, e, f):
                                continue
                            # 验证
                            nums = [
                                g,
                                10 * f + g,
                                100 * e + 10 * f + g,
                                1000 * d + 100 * e + 10 * f + g,
                                10000 * c + 1000 * d + 100 * e + 10 * f + g,
                                100000 * b
                                + 10000 * c
                                + 1000 * d
                                + 100 * e
                                + 10 * f
                                + g,
                                1000000 * a
                                + 100000 * b
                                + 10000 * c
                                + 1000 * d
                                + 100 * e
                                + 10 * f
                                + g,
                            ]
                            total = sum(nums)
                            expected = d * 1111111
                            if total == expected:
                                print(f"{a}{b}{c}{d}{e}{f}{g}")
                                return


if __name__ == "__main__":
    solve()
