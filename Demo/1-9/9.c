/*
 * @Description: 动态分配的链式结构实现二叉树
 * @Author: aLittleMango
 * @Date: 2021-09-24 10:00:13
 * @LastEditTime: 2021-09-24 10:39:10
 * @FilePath: \VScode_C\Demo\1-9\9.c
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "tree.h"

typedef struct TREE_NODE
{
    TREE_TYPE value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
} TreeNode;

static TreeNode *tree;
static TreeNode *current;

void insert(TREE_TYPE value)
{
    TreeNode **link;
    link = &tree;
    while ((current = *link) != NULL)
    {
        if (value < current->value)
            link = &current->left;
        else
        {
            assert(value != current->value);
            link = &current->right;
        }
    }
    /*分配一个新节点，使适当节点的link指向它*/
    current = malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    *link = current;
}

TREE_TYPE *find(TREE_TYPE value)
{
    current = tree;
    while (current != NULL && current->value != value)
    {
        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }
    if (current != NULL)
        return &current->value;
    else
        return NULL;
}

static void do_pre_order_traverse(TreeNode *current, void (*callback)(TREE_TYPE value))
{
    if (current != NULL)
    {
        callback(current->vlaue);
        do_pre_order_traverse(current->left, callback);
        do_pre_order_traverse(current->right, callback);
    }
}

void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
    do_pre_order_traverse(tree, callback);
}