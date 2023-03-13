class Solution {
public:
    // merge sort
    ListNode* merge(ListNode* low, ListNode* mid) {
        ListNode* left = low, *right = mid, *temp = new ListNode(0), *head = temp;
        while (left && right) {
            if (left->val < right->val){
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if (left) {
            temp->next = left;
        }
        if(right) {
            temp->next = right;
        }
        return head->next;
    }
    ListNode* sortList(ListNode* head) {
        // base case
        if(!head || !head->next) {
            return head;
        }
        // divide
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        // merge
        return merge(sortList(head), sortList(mid));
    }
};