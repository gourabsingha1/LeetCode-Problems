class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        ListNode* ahead = new ListNode(0);
        ListNode* bhead = head;
        while(bhead && bhead->val < x){
            bhead = bhead->next;
        }
        ListNode* a = ahead;
        ListNode* b = bhead;
        while(temp){
            if(temp->val < x){
                a->next = temp;
                a = a->next;
                temp = temp->next;
                a->next = NULL;
            }
            else{
                if(temp != bhead){
                    b->next = temp;
                    b = b->next;
                }
                temp = temp->next;
                b->next = NULL;
            }
        }
        a->next = bhead;
        return ahead->next;
    }
};