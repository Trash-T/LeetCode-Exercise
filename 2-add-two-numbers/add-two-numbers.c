/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int simpanan = 0;

    struct ListNode res;
    res.val = 0;
    res.next = NULL;
    struct ListNode* curr = &res;

    while (l1 != NULL || l2 != NULL || simpanan != 0) {
        int sum = simpanan;

        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        simpanan = sum / 10;

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        curr->next = newNode;
        curr = curr->next;
    }
    return res.next;
}