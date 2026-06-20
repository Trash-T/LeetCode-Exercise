/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize == 0)
    {
        return NULL;
    }
    
    int values[10000];
    int nEff = 0;

    for (int i = 0; i < listsSize; i++)
    {
        struct ListNode* current = lists[i];
        while (current != NULL)
        {
            values[nEff] = current->val;
            nEff++;
            current = current->next;
        }
    }

    if (nEff == 0)
    {
        return NULL;
    }

    for (int i = 0; i < nEff - 1; i++)
    {
        for (int j = 0; j < nEff - i - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                int dum = values[j];
                values[j] = values[j + 1];
                values[j + 1] = dum;
            }
        }
    }
    
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* curr = dummy;
    for (int i = 0; i < nEff; i++)
    {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = values[i];
        newNode->next = NULL;
        curr->next = newNode;
        curr = curr->next;
    }
    
    return dummy->next;
}