/**You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.You may assume the two numbers do
 * not contain any leading zero, except the number 0 itself.
 */

#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *p1, *p2, *p3, *pNewNode, *pHead;
    int val1, val2, val3, carry;
    if (l1 == NULL || l2 == NULL ) {
        return NULL;
    }

    p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHead = p3;
    p1 = l1;
    p2 = l2;
    carry = 0;

    while (p1 || p2 || carry) {
        if (p1 != NULL) {
            val1 = p1->val;
        } else {
            val1 = 0;
        }

        if (p2 != NULL) {
            val2 = p2->val;
        } else {
            val2 = 0;
        }

        val3 = val1 + val2 + carry;
        carry = val3 / 10;
        val3 = val3 % 10;

        pNewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        pNewNode->val = val3;
        pNewNode->next = NULL;
        printf("%d\tcarry=%d\n", val3, carry);
        p3->next = pNewNode;
        p3 = p3->next;
        if (p1) {
            p1 = p1->next;
        }
        if (p2) {
            p2 = p2->next;
        }
    }
    p3 = pHead;
    pHead = pHead->next;
    free(p3);
    return pHead;
}

/**
 * testcase:
 * input    [2,4,3]
 *          [5,6,4]
 * expected [7,0,8]
 */