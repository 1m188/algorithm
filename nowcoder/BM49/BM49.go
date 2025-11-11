/*
BM49 表达式求值

描述
请写一个整数计算器，支持加减乘三种运算和括号。

数据范围：
0
≤
∣
s
∣
≤
100
0≤∣s∣≤100，保证计算结果始终在整型范围内

要求：空间复杂度：
O
(
n
)
O(n)，时间复杂度
O
(
n
)
O(n)
示例1
输入：
"1+2"
复制
返回值：
3
复制
示例2
输入：
"(2*(3-4))*5"
复制
返回值：
-10
复制
示例3
输入：
"3+2*3*4-1"
复制
返回值：
26
*/

package main

import (
	"strconv"
)

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 返回表达式的值
 * @param s string字符串 待计算的表达式
 * @return int整型
 */
func solve(s string) int {
	// write code here

	// 字符串转中缀表达式
	exp_mid := make([]string, 0)
	tmp := make([]byte, 0)
	for _, c := range []byte(s) {
		if c >= '0' && c <= '9' {
			tmp = append(tmp, c)
		} else {
			if len(tmp) > 0 {
				exp_mid = append(exp_mid, string(tmp))
				tmp = tmp[:0]
			}
			exp_mid = append(exp_mid, string(c))
		}
	}
	if len(tmp) > 0 {
		exp_mid = append(exp_mid, string(tmp))
		tmp = nil
	}

	// 中缀表达式转后缀表达式
	exp_post := make([]string, 0)
	stack := make([]string, 0)
	for _, s := range exp_mid {
		_, err := strconv.ParseInt(s, 10, 0)
		if err == nil {
			exp_post = append(exp_post, s)
		} else if s == "(" {
			stack = append(stack, s)
		} else if s == ")" {
			for stack[len(stack)-1] != "(" {
				exp_post = append(exp_post, stack[len(stack)-1])
				stack = stack[:len(stack)-1]
			}
			stack = stack[:len(stack)-1]
		} else {
			if s == "+" || s == "-" {
				for len(stack) > 0 {
					x := stack[len(stack)-1]
					if x == "(" {
						break
					} else {
						stack = stack[:len(stack)-1]
						exp_post = append(exp_post, x)
					}
				}
				stack = append(stack, s)
			} else {
				for len(stack) > 0 {
					x := stack[len(stack)-1]
					if x == "+" || x == "-" || x == "(" {
						break
					} else {
						stack = stack[:len(stack)-1]
						exp_post = append(exp_post, x)
					}
				}
				stack = append(stack, s)
			}
		}
	}
	for len(stack) > 0 {
		exp_post = append(exp_post, stack[len(stack)-1])
		stack = stack[:len(stack)-1]
	}

	// 后缀表达式求值
	stack_num := make([]int, 0)
	for _, s := range exp_post {
		switch s {
		case "+":
			a := stack_num[len(stack_num)-1]
			b := stack_num[len(stack_num)-2]
			stack_num = stack_num[:len(stack_num)-2]
			stack_num = append(stack_num, b+a)
		case "-":
			a := stack_num[len(stack_num)-1]
			b := stack_num[len(stack_num)-2]
			stack_num = stack_num[:len(stack_num)-2]
			stack_num = append(stack_num, b-a)
		case "*":
			a := stack_num[len(stack_num)-1]
			b := stack_num[len(stack_num)-2]
			stack_num = stack_num[:len(stack_num)-2]
			stack_num = append(stack_num, b*a)
		default:
			x, _ := strconv.Atoi(s)
			stack_num = append(stack_num, x)
		}
	}

	return stack_num[0]
}
