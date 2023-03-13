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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) {
            return NULL;
        }
        for (int i = 1; i < lists.size(); i++)
        {
            lists[0] = merge(lists[0], lists[i]);
        }
        return lists[0];
    }
};