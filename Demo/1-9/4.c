/*
 * @Description: 有序单链表的插入
 * @Author: aLittleMango
 * @Date: 2021-09-23 16:33:59
 * @LastEditTime: 2021-09-24 10:39:31
 * @FilePath: \VScode_C\Demo\1-9\4.c
 */

/*单链表节点*/
typedef struct NODE
{
    struct NODE *link;
    int value;
} Node;

#include <stdio.h>
#include <stdlib.h>
#include "sll_node.h"

#define FALSE 0
#define TRUE 1
/*节点current指向下一个节点*linkp */
int sll_insert(register Node **linkp; int new_value)
{
    Node *current;
    Node *new;

    while ((current = *linkp) != NULL && current->value < new_value)
        linkp = &current->link;

    new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
        return FALSE;
    new->value = new_value;

    new->link = currnet;
    *linkp = new;
    return TRUE;
}