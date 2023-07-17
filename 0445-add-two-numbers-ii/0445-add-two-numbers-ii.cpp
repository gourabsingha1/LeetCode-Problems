class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL, *cur = head;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* addTwoNumbersI(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *res = dummy;
        int carry = 0;
        while(l1 || l2 || carry) {
            int val1 = 0, val2 = 0;
            if(l1) val1 = l1->val;
            if(l2) val2 = l2->val;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            res->next = newNode;
            res = res->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return reverse(dummy->next);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        return addTwoNumbersI(l1, l2);
    }
};