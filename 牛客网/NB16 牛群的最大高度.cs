/*
描述
农场里有一群牛，牛群的成员分布在山坡上，形成了一个二叉树结构。每头牛都有一个高度值，表示它在山坡上的高度。请你编写一个程序，找出牛群中的最高牛。

说明：最高牛是指高度值最大的牛。

示例1
输入：
{1, 2, 3, #, #, 4, 5}
复制
返回值：
5
复制
示例2
输入：
{1, 2, 3}
复制
返回值：
3
复制
备注：
输入包含一个二叉树，表示牛群的分布。二叉树由一组整数表示，其中 # 表示空节点。节点按层序遍历的顺序给出。
二叉树节点数[1, 100]
*/

using System;
using System.Collections.Generic;


public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(int x)
    {
        val = x;
    }
}


class Solution
{
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    public int findMaxHeight(TreeNode root)
    {
        if (root == null) return 0;
        int a = findMaxHeight(root.left);
        int b = findMaxHeight(root.right);
        return Math.Max(Math.Max(a, b), root.val);
    }
}