#include <stdlib.h>


typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;


ListNode * add_two_numbers(ListNode *l1, ListNode *l2) {
    ListNode *head_sum = NULL;
    ListNode *tail_sum = NULL;

    ListNode *cur_l1 = l1;
    ListNode *cur_l2 = l2;
    int carry = 0;

    while (cur_l1 || cur_l2 || carry) {
        int sum = carry;
        if (cur_l1) {
            sum += cur_l1->val;
            cur_l1 = cur_l1->next;
        }
        if (cur_l2) {
            sum += cur_l2->val;
            cur_l2 = cur_l2->next;
        }

        ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
        new_node->val = sum % 10;
        carry = sum / 10;

        if (!head_sum) {
            head_sum = tail_sum = new_node;
        } else {
            tail_sum->next = new_node;
            tail_sum = new_node;
        }
    }
    tail_sum->next = NULL;
    return head_sum;
}