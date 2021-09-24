/*
 * @Description: 堆栈 后进先出LIFO 链式堆栈
 * @Author: aLittleMango
 * @Date: 2021-09-23 18:51:34
 * @LastEditTime: 2021-09-24 10:39:27
 * @FilePath: \VScode_C\Demo\1-9\5.c
 */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define FALSE 0

typedef struct STACK_NODE
{
    STACK_TYPE value;
    struct STACK_NODE *next;
} StackNode;

/*指向堆栈中第一个节点的指针*/
static StackNode *stack;

void creat_stack(size_t size)
{
}

void destory_stack(void)
{
    while (!is_empty())
        pop();
}

void push_stack(STACK_TYPE value)
{
    StackNode *new_node;
    new_node = malloc(siezof(StackNode));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->next = stack;
    stack = new_node;
}

void pop_stack(void)
{
    StackNode *first_node;
    assert(!is_empty());
    first_node = stack;
    stack = first_node->next;
    free(first_node);
}

STACK_TYPE top(void)
{
    assert(!is_empty());
    return stack->value;
}

int is_empty(void)
{
    return stack == NULL;
}

int is_full(void)
{
    return FALSE;
}