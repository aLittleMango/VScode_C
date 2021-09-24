/*
 * @Description: 静态数组实现二叉搜索树
 * @Author: aLittleMango
 * @Date: 2021-09-23 21:07:44
 * @LastEditTime: 2021-09-24 10:39:18
 * @FilePath: \VScode_C\Demo\1-9\8.c
 */

#include "tree.h"

#include <stdio.h>
#include <assert.h>

#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE + 1)

static TREE_TYPE tree[ARRAY_SIZE];
int current;
/*计算节点的左孩子下标*/
static int left_child(int current)
{
    return current * 2
}
/*计算节点的右孩子下标*/
static int right_child(int current)
{
    return current * 2 + 1
}

void insert(TREE_TYPE value)
{
    assert(value != 0);
    current = 1;
    while (tree[current] != 0)
    {
        if (value < tree[current])
            current = left_child(current);
        else
        {
            assert(value != tree[current]);
            current = right_child(current);
        }
        assert(current < ARRAY_SIZE);
    }
    tree[current] = value;
}

TREE_TYPE *find(TREE_TYPE value)
{
    current = 1;

    while (current < ARRAY_SIZE && tree[current] != value)
    {
        if (value < tree[current])
            current = left_child(current);
        else
            current = right_child(current);
    }
    if (current < ARRAY_SIZE)
        return tree + current;
    else
        return 0;
}
/*前序遍历，递归遍历左子树和右子树*/
static void do_pre_order_traverse(int current, void (*callback)(TREE_TYPE value))
{
    if (current < ARRAY_SIZE && tree[current] != 0)
    {
        callback(tree[current]);
        do_pre_order_traverse(left_child(current), callback);
        do_pre_order_traverse(right_child(current), callback);
    }
}

void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
    do_pre_order_traverse(1, callback);
}