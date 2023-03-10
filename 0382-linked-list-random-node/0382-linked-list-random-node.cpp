class Solution {
public:
    ListNode* head;
    int n = 0;
    Solution(ListNode* head) {
        this->head = head;
        while(head) {
            n++;
            head = head->next;
        }
    }
    
    int getRandom() {
        int ind = rand() % n;
        ListNode* temp = head;
        for (int i = 0; i < ind; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }
};