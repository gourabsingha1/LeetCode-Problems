class Solution {
public:
    Node* flatten(Node* head) {
        Node* dummy = head;
        while(head){
            if(head->child){
                Node* nex = head->next;
                head->child->prev = head;
                head->next = head->child;
                head->child = NULL;
                Node* temp = head->next;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = nex;
                if(nex){
                    nex->prev = temp;
                }
            }
            head = head->next;
        }
        return dummy;
    }
};