class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        ListNode *dummy = new ListNode(0, head);
        head = dummy;
        while(temp){
            if(temp->next && temp->val == temp->next->val){
                while(temp->next && temp->val == temp->next->val){
                    temp = temp->next;
                }
                head->next = temp->next;
            }
            else{
                head = head->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};