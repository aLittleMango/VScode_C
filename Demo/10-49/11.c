/*
 * @Description: 
 * @Author: aLittleMango
 * @Date: 2021-09-24 10:40:31
 * @LastEditTime: 2021-09-24 16:13:02
 * @FilePath: \VScode_C\Demo\10-49\11.c
 */

/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

*/

struct ListNode
{
    struct ListNode *next;
    int val;
};

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

int value = 0;
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *cur;

    if (l1 == NULL && l2 == NULL && value == 0)
        return NULL;
    l1 = (l1 != NULL) ? (value += l1->val, l1->next) : (l1);
    l2 = l2 != NULL ? (value += l2->val, l2->next) : (l2);

    cur = (struct ListNode *)malloc(sizeof(struct ListNode));
    cur->val = value % 10;
    value /= 10;
    cur->next = addTwoNumbers(l1, l2);
    return cur;
}

void main()
{
    // struct ListNode *cur, *l1, *l2;
    // l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    // l1->val = 1;
    // l1->next = NULL;
    // l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    // l2->val = 2;
    // l2->next = NULL;
    // cur = addTwoNumbers(l1, l2);
    // printf("%d", cur->val);
    // system("pause");

    /*数组转化为链表*/
    int a[] = {1};
    int len = sizeof(a) / sizeof(a[0]);
    struct ListNode *l1 = NULL;
    struct ListNode *head = NULL;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *end = head;
    for (int i = 0; i < len; i++)
    {
        l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
        l1->val = a[i];
        end->next = l1;
        end = l1;
    }
    end->next = 0;

    int b[] = {3};
    int lenb = sizeof(b) / sizeof(b[0]);
    struct ListNode *l2 = NULL;
    struct ListNode *head2 = NULL;
    head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *end2 = head2;
    for (int i = 0; i < lenb; i++)
    {
        l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        l2->val = b[i];
        end2->next = l2;
        end2 = l2;
    }
    end2->next = 0;

    struct ListNode *cur = addTwoNumbers(head, head2);

    //从头节点的下一节点开始打印
    struct ListNode *x = cur->next;
    for (int i = 0; i < (len >= lenb ? len : lenb); i++)
    {
        printf("%d->", x->val);
        x = x->next;
    }
    system("pause");
}