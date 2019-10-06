/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* InsertPos(struct ListNode* head){
    struct ListNode* tortoise = head;
    struct ListNode* hare = head;
    while(hare!= NULL && hare->next != NULL){
        tortoise = tortoise->next;
        hare = hare->next->next;
        if(tortoise == hare)
            return tortoise;
    }
    return NULL;
}
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL)
        return NULL;
    struct ListNode* insertPos = InsertPos(head);
    if(insertPos == NULL)
        return NULL;
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = insertPos;
    while(ptr1!=ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}