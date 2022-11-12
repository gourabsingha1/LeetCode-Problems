class Solution {
public:
    Node* flatten(Node* head) {
        Node* dummy = head;
        stack<Node*> st;
        while(head){
            if(head->child){
                if(head->next){
                    st.push(head->next);
                }
                head->next = head->child;
                head->child = NULL;
            }
            if(!head->next && st.size()){
                head->next = st.top();
                st.pop();
            }
            head = head->next;
        }
        head = dummy;
        while(head){
            Node* nex = head->next;
            if(nex){
                nex->prev = head;
            }
            head = nex;
        }
        return dummy;
    }
};