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
                head->child->prev = head;
                head->next = head->child;
                head->child = NULL;
            }
            if(!head->next && st.size()){
                head->next = st.top();
                st.top()->prev = head;
                st.pop();
            }
            head = head->next;
        }
        return dummy;
    }
};