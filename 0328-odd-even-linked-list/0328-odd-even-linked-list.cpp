class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* secondHead = even;
        while(odd->next && even->next){
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = secondHead;
        return head;
    }
};