/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* cur1 = l1;
    struct ListNode* cur2 = l2;
    struct ListNode* prev = NULL;
    struct ListNode* head = NULL;
    if(l1 == NULL&&l2!=NULL){
        return l2;
    }
    if(l1!=NULL&&l2==NULL){
        return l1;
    }
    if(l1==NULL&&l2==NULL){
        return NULL;
    }
    prev = head;
    while(cur1!=NULL&&cur2!=NULL){
        if(prev == NULL){
            if(cur1->val<cur2->val){
                prev = cur1;
                cur1 = cur1->next;
                head = prev;
                continue;
            }else{
                prev = cur2;
                cur2 = cur2->next;
                head = prev;
                continue;
            }
        }
        if(cur1->val<cur2->val){
            prev->next = cur1;
            cur1 = cur1->next;
        }else{
            prev->next = cur2;
            cur2 = cur2->next;
        }
        prev = prev->next;
    }
    if(cur1==NULL){
        prev->next = cur2;
    }else{
        prev->next = cur1;
    }
    return head;
}
