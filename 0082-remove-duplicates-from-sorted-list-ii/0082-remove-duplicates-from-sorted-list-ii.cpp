class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        ListNode *dummy = new ListNode(0);
        head = dummy;
        int c = 0;
        while(temp){
            if(temp->next && temp->val == temp->next->val){
                c++;
            }
            else{
                if(!c){
                    head->next = new ListNode(temp->val);
                    head = head->next;
                }
                c = 0;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};