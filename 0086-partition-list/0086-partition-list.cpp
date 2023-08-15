
// lesserHead = list of nodes with val < x
// greaterHead = list of nodes with val >= x
// return lesserHead + greaterHead

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) {
            return NULL;
        }
        
        ListNode* temp = head, *lesserHead = NULL, *greaterHead = NULL;
        ListNode*lesserCur = NULL, *greaterCur = NULL;
        while(temp) {
            ListNode* newNode = new ListNode(temp->val);
            if(temp->val < x) {
                if(!lesserCur) {
                    lesserHead = lesserCur = newNode;
                }
                else {
                    lesserCur->next = newNode;
                    lesserCur = lesserCur->next;
                }
            }
            else {
                if(!greaterCur) {
                    greaterHead = greaterCur = newNode;
                }
                else {
                    greaterCur->next = newNode;
                    greaterCur = greaterCur->next;
                }
            }
            temp = temp->next;
        }
        
        if(lesserCur) {
            lesserCur->next = greaterHead;
            return lesserHead;
        }
        else {
            return greaterHead;
        }
    }
};