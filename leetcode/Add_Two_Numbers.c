/**You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.You may assume the two numbers do
 * not contain any leading zero, except the number 0 itself.
 */

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p, *head, *new;
    int carry, val1, val2, tmpVal;

    carry = val1 = val2 = 0;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = head;

    while (l1 != NULL || l2 != NULL || carry) {
        if (l1 != NULL) {
            val1 = l1->val;
        } else {
            val1 = 0;
        }

        if (l2 != NULL) {
            val2 = l2->val;
        } else {
            val2 = 0;
        }

        tmpVal = val1 + val2 + carry;
        if (tmpVal >= 10) {
            carry = 1;
            tmpVal = 0;
        } else {
            carry = 0;
        }

        new = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = tmpVal;
        p->next = new;
        p = new;
        p->next = NULL;
    }
    free(p);
    return head;
}

void test()
{

}