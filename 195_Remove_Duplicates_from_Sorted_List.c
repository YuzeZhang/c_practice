/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    struct ListNode* next = cur->next;
    while(cur){
        if(prev!=NULL && prev->val == cur->val){
            prev->next = next;
            free(cur);
        }else{
            prev = cur;
        }
        cur = next;
        if(cur)
            next = cur->next;
    }
    return head;
}

