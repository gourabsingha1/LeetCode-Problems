// to evenly distribute sizes, we use the formula
// int size = (n + k - 1) / k and n -= size, k-- everytime

class Solution {
public:
    int sizeOfList(ListNode* head) {
        int res = 0;
        while(head) {
            head = head->next, res++;
        }
        return res;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int n = sizeOfList(head);
        ListNode* lastNode = head;
        while(k) {
            int size = (n + k - 1) / k;
            n -= size, k--;
            res.push_back(head);
            while(size--) {
                lastNode = head;
                head = head->next;
            }
            if(lastNode) {
                lastNode->next = NULL;
            }
        }
        return res;
    }
};