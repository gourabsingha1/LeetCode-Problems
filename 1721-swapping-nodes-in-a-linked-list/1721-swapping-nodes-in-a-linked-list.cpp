class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *node1, *node2 = head, *temp = head;
        for (int i = 0; i < k - 1; i++)
        {
            temp = temp->next;
        }
        node1 = temp;
        temp = temp->next;
        while(temp) {
            node2 = node2->next;
            temp = temp->next;
        }
        swap(node1->val, node2->val);
        return head;
    }
};