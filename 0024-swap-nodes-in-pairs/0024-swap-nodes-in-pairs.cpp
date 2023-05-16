class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *prev = NULL, *cur = head, *nex = head->next;
        head = head->next;
        
        while(cur && cur->next){
            ListNode *temp = nex->next;
            if(prev) {
                prev->next = nex;
            }
            nex->next = cur;
            cur->next = temp;
            
            prev = cur;
            cur = temp;
            if(cur) {
                nex = cur->next;
            }
        }
        return head;
    }
};