"""
描述
你正在为一个火爆的网络游戏设计玩家积分榜系统。系统启动时，积分榜是空的。

服务器需要处理来自游戏客户端的各种操作请求，以维护每个玩家的最高积分记录。

具体而言，操作请求分为以下四种类型：

∙

∙更新或插入积分：参数为一个字符串 NAME 和一个正整数 SCORE，如果名为 NAME 的玩家已存在，则将其积分更新为 SCORE；否则新建一个名为 NAME，积分为 SCORE 的新玩家。没有返回值。

∙

∙查询积分：参数为一个字符串 NAME。如果名为 NAME 的玩家已存在，输出其当前积分；否则输出 `Not found`。没有返回值。

∙

∙删除玩家记录：参数为一个字符串 NAME。如果名为 NAME 的玩家已存在，则删除该玩家的积分记录，输出 `Deleted successfully`；否则输出 `Not found`。没有返回值。

∙

∙统计玩家总数：没有参数。输出当前积分榜中玩家的总数量。没有返回值。

注意，需要实现的所有函数均没有返回值，操作的结果（如果有的话）需要直接进行标准输出！
输入描述：
输入数据仅用于主函数获取数据后调用你实现的函数，你其实可以不用管。

第一行输入一个整数
Q
Q（
1
≦
Q
≦
1
0
5
1≦Q≦10
5
 ），表示需要处理的操作总数。

接下来
Q
Q 行，每行输入一个操作，分为以下四种类型：

∙

∙更新或插入积分：格式为 `1 NAME SCORE`，其中 `NAME` 为由字母和数字组成、区分大小写、长度不超过 20 的字符串，`SCORE` 为正整数（
0
<
SCORE
<
2
31
0<SCORE<2
31
 ）。如果 `NAME` 已存在，则更新其积分；否则插入新玩家。

∙

∙查询积分：格式为 `2 NAME`。如果玩家 `NAME` 存在，输出其当前积分；否则输出 `Not found`。

∙

∙删除玩家记录：格式为 `3 NAME`。如果玩家 `NAME` 存在并删除成功，输出 `Deleted successfully`；否则输出 `Not found`。

∙

∙统计玩家总数：格式为 `4`。输出当前积分榜中玩家的总数量。
输出描述：

输出数据仅用于主函数获取返回值后于评测机交互，你其实可以不用管。

针对每个操作，输出对应结果，每个结果占一行：

∙

∙操作类型 1：输出 `OK`。

∙

∙操作类型 2：输出玩家积分或 `Not found`。

∙

∙操作类型 3：输出 `Deleted successfully` 或 `Not found`。

∙

∙操作类型 4：输出当前玩家总数。
示例1
输入：
5
1 wangzai 10
2 wangzai
3 wangzai
2 wangzai
4
复制
输出：
OK
10
Deleted successfully
Not found
0
复制
说明：
操作 1：插入玩家 `wangzai` 积分 10，输出 `OK`；

操作 2：查询 `wangzai`，输出 `10`；

操作 3：删除 `wangzai`，输出 `Deleted successfully`；

操作 4：查询 `wangzai`，未找到，输出 `Not found`；

操作 5：统计玩家总数，当前无玩家，输出 `0`。
"""

import sys

m = {}


def insert_or_update_score(name: str, score: int) -> None:
    """插入或更新玩家的分数"""
    # 实现插入或更新逻辑

    m[name] = score
    print("OK")


def query_score(name: str) -> None:
    """查询玩家的分数"""
    # 实现查询逻辑

    print(m[name] if name in m else "Not found")


def delete_player(name: str) -> None:
    """删除玩家记录"""
    # 实现删除逻辑

    if name in m:
        del m[name]
        print("Deleted successfully")
    else:
        print("Not found")


def count_players() -> None:
    """统计玩家总数"""
    # 实现统计逻辑

    print(len(m))


def main():
    """读取输入并分发操作"""
    q = int(sys.stdin.readline())

    for _ in range(q):
        line = sys.stdin.readline().split()
        op = int(line[0])

        if op == 1:
            name = line[1]
            score = int(line[2])
            insert_or_update_score(name, score)
        elif op == 2:
            name = line[1]
            query_score(name)
        elif op == 3:
            name = line[1]
            delete_player(name)
        elif op == 4:
            count_players()


if __name__ == "__main__":
    main()
