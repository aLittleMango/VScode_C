/*
 * @Description: 队列FIFO 静态数组中实现
 * @Author: aLittleMango
 * @Date: 2021-09-23 19:42:15
 * @LastEditTime: 2021-09-24 10:39:22
 * @FilePath: \VScode_C\Demo\1-9\7.c
 */

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define QUEUE_SIZE 100              /*队列中元素的最大数量*/
#define ARRAY_SIZE (QUEUE_SIZE + 1) /*数组的长度*/

static QUEUE_TYPE queue[ARRAY_SIZE];
static size_t front = 1;
static size_t rear = 0;

void insert(QUEUE_TYPE value)
{
    assert(!is_full());
    rear = (rear + 1) % ARRAY_SIZE;
    queue[rear] = value;
}

void delete (void)
{
    assert(!is_empty());
    front = (front + 1) % ARRAY_SIZE;
}

QUEUE_TYPE first(void)
{
    assert(!is_empty());
    return queue[front];
}

int is_empty(void)
{
    return (rear + 1) % ARRAY_SIZE == front;
}

int is_full(void)
{
    return (rear + 2) % ARRAY_SIZE == front;
}