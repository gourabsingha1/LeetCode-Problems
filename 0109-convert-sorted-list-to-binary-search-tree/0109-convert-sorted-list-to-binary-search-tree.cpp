class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) {
            return NULL;
        }
        if(!head->next) {
            return new TreeNode(head->val);
        }
        ListNode* slow = head, *fast = head, *mid = head;
        while(fast && fast->next) {
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        mid->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};